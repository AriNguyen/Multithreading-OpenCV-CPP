/**
 *  @file WebcamStream.h
 *  @brief header for the object WebcamStream which open camera, 
 *      streams, and do threading 
 *  @author Ari Nguyen 
 */
#ifndef WEBCAMSTREAM_H
#define WEBCAMSTREAM_H

#include <mutex>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

class WebcamStream {
private:
    int apiID = cv::CAP_ANY; // 0 = autodetect default API
    int device_id = 0;       // 0 = open default camera
    bool stopped = false;   
    cv::VideoCapture stream; //--- INITIALIZE VIDEOCAPTURE
    cv::Mat frame;
    std::mutex m;
    
    WebcamStream& operator=(const WebcamStream& o); // protect assignment
    WebcamStream(const WebcamStream&) {};           // protect copy constructor
    void init();                                    // base constructor 

public:    
    WebcamStream();
    WebcamStream(int device, int api);
    void start();
    void update();
    cv::Mat *read();
    void stop();
};

#endif