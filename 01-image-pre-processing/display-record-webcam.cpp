/**
 * Display and Record Webcam
 * @param outputVideo
 */
#include <iostream>                    // for standard I/O
#include <string>                      // for strings
#include <opencv2/core/core.hpp>       // Basic OpenCV structures(cv::Mat)
#include <opencv2/highgui/highgui.hpp> // Video write
using namespace std;
using namespace cv;
int main(int argc, char **argv)
{
    VideoCapture cap(0); // open the default camera
    if (!cap.isOpened()) // check if we succeeded
        return -1;
    namedWindow("frame", 1);
    Size S = Size((int)cap.get(CAP_PROP_FRAME_WIDTH), // Acquire input size
                  (int)cap.get(CAP_PROP_FRAME_HEIGHT));
    VideoWriter outputVideo;
    // Open the output
    outputVideo.open(argv[1],
                     VideoWriter::fourcc('M', 'J', 'P', 'G'), 25, S, true);
    if (!outputVideo.isOpened())
    {
        cout << "Could not open the output video for write: " << endl;
        return -1;
    }
    for (;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        imshow("frame", frame);
        outputVideo.write(frame);
        if (waitKey(30) >= 0)
            break;
    }
    cap.release();
    outputVideo.release();
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}