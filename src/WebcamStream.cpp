#include <iostream>
#include <thread>
#include <mutex>

#include <opencv2/opencv.hpp>
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio.hpp>

#include "WebcamStream.h"


WebcamStream& WebcamStream::operator=(const WebcamStream& o) {
    if (this != &o) {
        frame = o.frame;
    }
    return *this;
}

void WebcamStream::init() {
    // Open selected camera using selected API
    this->stream.open(this->device_id, this->apiID);
    if (!this->stream.isOpened()) {
        std::cerr << "(!)ERROR: Unable to open camera\n";
        exit(EXIT_FAILURE);
    }

    this->stream.read(this->frame);
    if (this->frame.empty()) {
        std::cerr << "(!)Error1: Blank frame grabbed\n";
        return;
    }
}

WebcamStream::WebcamStream() {
    this->init();
}

WebcamStream::WebcamStream(int device, int api)
: device_id(device), apiID(api) {
    this->init();
}

void WebcamStream::start() {
    std::thread t1(&WebcamStream::update, this);
    t1.detach();
}

void WebcamStream::update() {
    //--- GRAB AND WRITE LOOP
    std::cout << "Start grabbing ..." << std::endl
        << "Press any key to terminate" << std::endl;

    while (true) {
        if (this->stopped)
            return;

        this->m.lock();

        // wait for a new frame from camera and store it into 'frame'
        this->stream.read(this->frame);
        if (this->frame.empty()) { //check if succeeded
            std::cerr << "(!)Error2: Blank frame grabbed\n";
            return;
        }
        
        this->m.unlock();
    }
}


// return the frame most recently read
cv::Mat *WebcamStream::read() {
    return &this->frame;
}


// make thread stop
void WebcamStream::stop() { 
    this->stopped = true;
}