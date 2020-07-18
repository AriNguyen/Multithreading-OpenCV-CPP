#include <iostream>
#include <opencv2/opencv.hpp>

#include "WebcamStream.h"
#include "utils.h"

int main() 
{
    int numFrames = 100;  // default
    std::cout << "Start1\n";
    WebcamStream ws;
    FPS fps;
    cv::Mat frame;

    // start the program
    ws = WebcamStream().start();
    fps.start();
    std::cout << "Start2\n";
    while (fps.getNumFrames() < numFrames) {
        frame = ws.read();

        cv::imshow("Live", frame);
        if (cv::waitKey(5) >= 0) {
            break;
        }

        fps.update();
    }
    std::cout << "out of while loop";
    // stop the frogram
    fps.stop();
    cv::destroyAllWindows();
    ws.stop();

    return 0;
}