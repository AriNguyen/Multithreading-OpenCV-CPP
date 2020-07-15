#ifndef WEBCAMSTREAM_H
#define WEBCAMSTREAM_H

#include <opencv2/opencv.hpp>

class WebcamStream {
private:
    int device_id = 0;
    bool stopped = false;
    cv::Mat frame;
public:
    WebcamStream(int device);
    void start();
    void update();
    cv::Mat read();
    void stop();
};

#endif