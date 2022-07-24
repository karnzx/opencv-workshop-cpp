/**
 * Display Webcam
 */
#include "opencv2/opencv.hpp"
using namespace cv;
int main(int argc, char **argv)
{
    VideoCapture cap(0); // open the default camera
    if (!cap.isOpened()) // check if we succeeded
        return -1;
    Mat edges;
    namedWindow("frame", 1);
    for (;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        imshow("frame", frame);
        if (waitKey(30) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}