
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

// create bouding box and circle around object (Contour)
int main(int argc, char **argv)
{
    Mat grad, grad_x, grad_y, abs_grad_x, abs_grad_y;
    Mat cam, edge, gray_img, equal_hist_image, gaussian_blur_image;
    Mat threshold_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    int ddepth = CV_16S;
    int scale = 1;
    int delta = 0;

    RNG rng4(12345); // random number from 0 - 12345

    VideoCapture cap(0);
    if (!cap.isOpened()) // check if we succeeded
        return -1;
    for (;;)
    {
        cap >> cam; // get a new frame from camera
        // Covert image to gray
        cvtColor(cam, gray_img, COLOR_BGR2GRAY);

        // Improve image quality
        equalizeHist(gray_img, gray_img);                                   // stretch out the intensity range (To make it clearer)
        GaussianBlur(gray_img, gray_img, Size(7, 7), 0, 0, BORDER_DEFAULT); // decreasing noise (low-pass filter)
        // blur(gray_img, gray_img, Size(3, 3));

        // Find the edge
        // Can either use Thresholding or Canny edge detection
        /// Gradient X
        Sobel(gray_img, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
        convertScaleAbs(grad_x, abs_grad_x);
        /// Gradient Y
        Sobel(gray_img, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
        convertScaleAbs(grad_y, abs_grad_y);
        /// Total Gradient (approximate)
        addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
        /// apply value greather than thresholdValue to 255 (white) other is 0 (black)
        /// Thresholding turns the border of the object in the image completely white, with all pixels having the same intensity.
        /// The algorithm can now detect the borders of the objects from these white pixels.
        threshold(grad, edge, 40, 255, THRESH_BINARY);

        // Find contour and display bounding box of objects
        findContours(edge, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
        /// Approximate contours to polygons + get bounding rects and circles
        vector<vector<Point>> contours_poly(contours.size());
        vector<Rect> boundRect(contours.size());
        vector<Point2f> center(contours.size());
        vector<float> radius(contours.size());
        int j = 0;
        /// approximate the shape
        for (int i = 0; i < contours.size(); i++)
        {
            approxPolyDP(Mat(contours[i]), contours_poly[j], 10, true); //  accuracy +-5
            if (contours_poly[j].size() > 5)                            // filter
            {
                boundRect[j] = boundingRect(Mat(contours_poly[j]));
                minEnclosingCircle(contours_poly[j], center[j], radius[j]); // for circle
                j++;
            }
        }
        /// Draw polygonal contour + bonding rects + circles
        // Mat drawing = Mat::zeros(edge.size(), CV_8UC3);
        Mat drawing = cam.clone();
        for (int i = 0; i < j; i++)
        {
            int rectSize = boundRect[i].width * boundRect[i].height;
            if (rectSize > 20000 && rectSize < 100000) // filter
            {
                Scalar color = Scalar(rng4.uniform(0, 256), rng4.uniform(0, 256), rng4.uniform(0, 256));
                drawContours(drawing, contours_poly, i, color, 1, LINE_8, hierarchy, 0);
                rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
                // putText(drawing, to_string(rectSize), center[i], FONT_HERSHEY_SIMPLEX, 0.9, color, 2); // add rectSize to center of object
                circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
            }
        }

        imshow("Webcam", cam);
        // imshow("equalizeHist", equal_hist_image);
        // imshow("GaussianBlur", gaussian_blur_image);
        imshow("Threshold Binary image", edge);
        imshow("Gradient", grad);
        imshow("Contour", drawing);
        if (waitKey(30) >= 0)
            break;
    }
    return 0;
}