
#include "opencv2/opencv.hpp"

#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

// run with "video.avi"

int main(int argc, char **argv)
{
    Mat fgMaskMOG2;                  // fg mask fg mask generated by MOG2 method
    Ptr<BackgroundSubtractor> pMOG2; // MOG2 Background subtractor

    VideoCapture cap(argv[1]); // open the video from args 1
    if (!cap.isOpened())       // check if we succeeded
        return -1;

    // create Background Subtractor objects
    pMOG2 = createBackgroundSubtractorMOG2(); // MOG2 approach

    int personCount = 0;
    int linePixelTL = 390;
    int linePixelBR = 410;
    queue<bool> q;
    namedWindow("frame", 1);
    namedWindow("FG Mask MOG 2");
    for (;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        Mat canny_output;
        pMOG2->apply(frame, fgMaskMOG2);

        threshold(fgMaskMOG2, fgMaskMOG2, 200, 255, THRESH_BINARY);
        morphologyEx(fgMaskMOG2, fgMaskMOG2, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(21, 21)));
        imshow("FG Mask MOG 2", fgMaskMOG2);

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(fgMaskMOG2, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        vector<vector<Point>> contours_poly(contours.size());
        vector<Rect> boundRect(contours.size());
        vector<Point2f> center(contours.size());
        vector<float> radius(contours.size());
        int j = 0;

        for (size_t i = 0; i < contours.size(); i++)
        {
            approxPolyDP(contours[i], contours_poly[j], 5, true);
            if (contours_poly[j].size() > 5)
            {
                boundRect[j] = boundingRect(Mat(contours_poly[j]));
                minEnclosingCircle(contours_poly[j], center[j], radius[j]);
                j++;
            }
        }

        Mat drawing = Mat::zeros(fgMaskMOG2.size(), CV_8UC3);
        for (size_t i = 0; i < contours.size(); i++)
            drawContours(drawing, contours, (int)i, Scalar(0, 200, 0), 2, LINE_8, hierarchy, 0);

        for (int i = 0; i < j; i++)
        {
            rectangle(frame, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 200), 2, LINE_8, 0);
            rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 200), 2, LINE_8, 0);
            circle(frame, center[i], 5, Scalar(0, 200, 200), 2, 8, 0);

            if (center[i].y >= linePixelTL && center[i].y <= linePixelBR)
            {
                // not very accurated
                personCount += 1;
            }
        }
        putText(frame, "counting: " + to_string(personCount), Point(0, 380), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 200, 0), 2);
        rectangle(frame, Point(0, linePixelTL), Point(350, linePixelBR), Scalar(0, 200, 200), 3, LINE_8, 0);
        // line(frame, Point(0, 400), Point(350, 400), Scalar(0, 200, 0), 3);
        imshow("Contours", drawing);
        imshow("frame", frame);

        if (waitKey(30) >= 0)
            break;
    }
    return 0;
}