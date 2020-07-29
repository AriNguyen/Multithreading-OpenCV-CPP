/**
 *  @file main.cpp
 *  @brief opencv webcam stream and testing multithreading efficiency
 *  @author Ari Nguyen 
 */
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <string>
#include <opencv2/opencv.hpp>

#include "src/WebcamStream.h"
#include "src/utils.h"

int main(int argc, char *argv[]) {
    int numFrames = 1000;  // default
    WebcamStream ws;
    FPS fps;
    cv::Mat *frame;

    // set numFrames;
    if (argc > 1) {
        try {
            numFrames = atoi(argv[1]);
        }
        catch (std::exception const & e) {
            std::cout<< "error: " << e.what() << std::endl;
            exit(1);
        }
    }

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
    std::cout << "[INFO] Total Frames: " << numFrames << std::endl;
    std::cout << "[INFO] Elasped time: " << fps.elapsed() << " seconds\n";
    std::cout << "[INFO] Approx. FPS: " << fps.fps() << std::endl;

    // cleanup
    cv::destroyAllWindows();
    ws.stop();

    exit(0);
}