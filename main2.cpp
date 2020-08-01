/**
 *  @file main2.cpp
 *  @brief opencv webcam stream w/o multithreading
 *  @author Ari Nguyen 
 */
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <string>
#include <opencv2/opencv.hpp>

#include "src/utils.h"

int main(int argc, char *argv[]) {
    int numFrames = 100;  // default
    int apiID = cv::CAP_ANY; // 0 = autodetect default API
    int device_id = 0; 

    cv::VideoCapture ws;
    FPS fps;
    cv::Mat frame;

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
    ws.open(device_id, apiID);
    if (!ws.isOpened()) {
        std::cerr << "(!)ERROR: Unable to open camera\n";
        exit(2);
    }
    
    fps.start();
    while (fps.getNumFrames() < numFrames) {
        ws.read(frame);
        if (frame.empty()) { //check if succeeded
            std::cerr << "(!)Error2: Blank frame grabbed\n";
            exit(3);
        }

        // show live and wait for a key with timeout long enough to show images
        cv::imshow("Live", frame);
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

    exit(0);
}