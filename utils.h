#ifndef OPENCV_UTILS_H
#define OPENCV_UTILS_H

#include <chrono>

class FPS
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> timeStart, timeStop;
    int numFrames = 0;
public:
    // FPS();
    int getNumFrames();
    FPS& start();
    void stop();
    void update();
    std::chrono::duration<float> elapsed();
    float fps();
};

#endif