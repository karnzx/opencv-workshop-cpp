/**
 * Display Video
 @param video Image to display
 Also can get video from ip camera for example: "http://49.229.158.81:82/mjpg/video.mjpg"
 */
#include "opencv2/opencv.hpp"
using namespace cv;
int main(int argc, char **argv)
{
    VideoCapture cap(argv[1]);
    if (!cap.isOpened()) // check if we succeeded
        return -1;
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