#ifndef WEBCAMSTREAM_H
#define WEBCAMSTREAM_H

#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

class WebcamStream {
public:
    int apiID = cv::CAP_ANY; 
    int device_id = 0;
    bool stopped = false;
    cv::VideoCapture stream;
    cv::Mat frame;
    
    WebcamStream();
    WebcamStream(int device, int api);
    WebcamStream& start();
    void update();
    cv::Mat *read();
    void stop();
};

#endif