#include <iostream>
#include <thread>

#include <opencv2/opencv.hpp>
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio.hpp>

#include "WebcamStream.h"

WebcamStream::WebcamStream() 
{
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

WebcamStream::WebcamStream(int device, int api)
: device_id(device), apiID(api)
{
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

WebcamStream& WebcamStream::start()
{
    std::thread t1(&WebcamStream::update, this);
    t1.detach();
    // this->update();
    // t1.join();
    return *this;
}

void WebcamStream::update()
{
    while (true) {
        // std::cout << "Update\n";
        if (this->stopped)
            return;

        this->stream.read(this->frame);
        // std::cout << "wcs.c: " << &this->frame << std::endl;
        // if (this->frame.empty()) {
        //     std::cerr << "(!)Error2: Blank frame grabbed\n";
        //     return;
        // }

    }
}


// return the frame most recently read
cv::Mat *WebcamStream::read()
{
    // std::cout << "read():" << &this->frame << std::endl;
    return &this->frame;
}


// make thread stop
void WebcamStream::stop()
{ 
    this->stopped = true;
}