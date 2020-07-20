#include <iostream>
#include <opencv2/opencv.hpp>

#include "WebcamStream.h"
#include "utils.h"

int main() 
{
    int numFrames = 100;  // default
    WebcamStream ws;
    FPS fps;
    cv::Mat *frame;

    // start the program
    ws = WebcamStream().start();
    fps.start();
    while (fps.getNumFrames() < numFrames) {
        frame = ws.read();
        // std::cout << "main.c:" << frame << std::endl;

        cv::imshow("Live", *frame);
        if (cv::waitKey(5) >= 0) {
            break;
        }

        fps.update();
    }
    // stop the frogram
    fps.stop();
    cv::destroyAllWindows();
    ws.stop();

    return 0;
}