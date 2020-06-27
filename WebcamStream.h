#ifndef WEBCAMSTREAM_H
#define WEBCAMSTREAM_H

#include <opencv2/opencv.hpp>

class WebcamStream {
private:
    int device_id;
    bool stopped = false;
    cv::Mat frame;
public:
    WebcamStream(int device=0);
    void start();
    void update();
    cv::Mat read();
    void stop();
};

#endif