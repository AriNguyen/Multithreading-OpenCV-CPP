#include <iostream>
#include <thread>

#include <opencv2/opencv.hpp>
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio.hpp>

#include "WebcamStream.h"

// WebcamVideoStream Constructor
WebcamStream::WebcamStream(int device) : device_id(device)
{
    // this.device_id = device;

    cv::VideoCapture stream(this.device_id);
    if (!stream.isOpened()) {
        std::cerr << "(!)ERROR: Unable to open camera\n";
        exit(EXIT_FAILURE);
    }

}

void WebcamStream::start() 
{
    std::thread t1(this.update());
    // return *this;
}


void WebcamStream::update() 
{
    while (true) {
        stream.read(this.frame);
        if (stream.empty()) {
            std::cerr << "(!)Error: Blank frame grabbed\n";
            break;
        }

        if (this.stopped)
            break;
    }
}


cv::Mat WebcamStream::read() 
{
    // return the frame most recently read
    return this.frame;
}

void WebcamStream::stop() 
{
    // make thread stop
    this.stopped = true;
}