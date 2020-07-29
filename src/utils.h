#ifndef OPENCV_UTILS_H
#define OPENCV_UTILS_H

#include <ctime>

class FPS
{
private:
    clock_t timeStart, timeStop;
    int numFrames = 0;
public:
    // FPS();
    int getNumFrames();
    void start();
    void stop();
    void update();
    double elapsed();
    double fps();
};

#endif