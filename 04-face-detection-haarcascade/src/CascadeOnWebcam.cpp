/*
 * Copyright (c) 2011. Philipp Wagner <bytefish[at]gmx[dot]de>.
 * Released to public domain under terms of the BSD Simplified license.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the organization nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *   See <http://www.opensource.org/licenses/bsd-license>
 */
//
//#include "opencv2/core.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/objdetect.hpp"
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <stdio.h>
#include <io.h>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

static void read_csv(const string &filename, vector<string> &paths, char separator = ';')
{
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file)
    {
        string error_message = "No valid input file was given, please check the given filename.";
    }
    string line, path, classlabel;
    while (getline(file, line))
    {

        if (!line.empty())
        {
            paths.push_back(line);
        }
    }
}

int main(int argc, const char *argv[])
{

    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " </path/to/haar_cascade>" << endl;
        cout << "\t </path/to/haar_cascade> -- Path to the Haar Cascade for lpr detection." << endl;
        exit(1);
    }

    string fn_haar = string(argv[1]);
    // string fn_haar = string("C:\\Users\\karnz\\source\\repos\\OpenCVTest\\x64\\Debug\\cascade.xml");
    VideoCapture cap(0);
    if (!cap.isOpened())
    { // check if we succeeded
        return -1;
    }
    CascadeClassifier haar_cascade;
    haar_cascade.load(fn_haar);

    int i = 0;
    for (;;)
    {
        Mat original;
        cap >> original;
        if (original.data == NULL)
            break;
        Mat gray;
        cv::resize(original, original, Size(640, 480), 1.0, 1.0, INTER_CUBIC);

        cvtColor(original, gray, COLOR_BGR2GRAY);

        vector<Rect_<int>> lprs;
        haar_cascade.detectMultiScale(gray, lprs);

        for (int i = 0; i < lprs.size(); i++)
        {
            Rect lpr_i = lprs[i];
            Mat lpr = gray(lpr_i);

            rectangle(original, lpr_i, Scalar(0, 255, 0), 1);

            int pos_x = std::max(lpr_i.tl().x - 10, 0);
            int pos_y = std::max(lpr_i.tl().y - 10, 0);

            putText(original, "P", Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, Scalar(0, 255, 0), 2.0);
        }

        imshow("cascade-with-webcam", original);

        char key = (char)waitKey(1000);

        if (key == 27)
            break;
    }
    return 0;
}