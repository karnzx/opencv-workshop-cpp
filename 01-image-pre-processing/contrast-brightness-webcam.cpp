/**
 * g(i,j)=α⋅f(i,j)+β
 * @param alpha contrast
 * @param beta brightness
 * Example value: alpha=1.5, beta=24
 */

#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    VideoCapture cap(0);
    if (!cap.isOpened()) // check if we succeeded
        return -1;
    namedWindow("frame", 1);
    for (;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera

        double alpha = 1.0;
        int beta = 0;
        cout << "* Enter the alpha value [1.0-3.0]: ";
        cin >> alpha;
        cout << "* Enter the beta value [0-100]: ";
        cin >> beta;
        for (int y = 0; y < frame.rows; y++)
        {
            for (int x = 0; x < frame.cols; x++)
            {
                for (int c = 0; c < frame.channels(); c++)
                {
                    // g(i,j)=α⋅f(i,j)+β
                    frame.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * frame.at<Vec3b>(y, x)[c] + beta);
                }
            }
        }
        imshow("frame", frame);
        if (waitKey(30) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
