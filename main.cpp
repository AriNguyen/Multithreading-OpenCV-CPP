/**
 *  @file main.cpp
 *  @brief opencv webcam stream and testing multithreading efficiency
 *  @author Ari Nguyen 
 */
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "src/WebcamStream.h"
#include "src/utils.h"

int main() {
    int numFrames = 100;  // default
    WebcamStream ws;
    FPS fps;
    cv::Mat *frame;

    // start streaming video
    ws.start();
    fps.start();
    while (fps.getNumFrames() < numFrames) {
        frame = ws.read();

        // show live and wait for a key with timeout long enough to show images
        cv::imshow("Live", *frame);
        if (cv::waitKey(5) >= 0) {
            break;
        }

        fps.update();
    }

    // stop measuring fps
    fps.stop();

    // display info
    std::cout << "[INFO] elasped time: " << fps.elapsed() << " seconds\n";
    std::cout << "[INFO] approx. FPS: " << fps.fps() << std::endl;

    cv::destroyAllWindows();
    ws.stop();

    return 0;
}