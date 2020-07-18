#include <chrono>
#include "utils.h"

int FPS::getNumFrames()
{
    return this->numFrames;
}


FPS& FPS::start()
{
    this->timeStart = std::chrono::high_resolution_clock::now();
    return *this;
}


void FPS::stop()
{
    this->timeStop = std::chrono::high_resolution_clock::now();
}


void FPS::update()
{
    this->numFrames++;
}


std::chrono::duration<float> FPS::elapsed()
{
    std::chrono::duration<float> diff = this->timeStart - this->timeStop;
    return diff;
}


float FPS::fps() 
{
    float fps = this->numFrames / this->elapsed().count();
    return fps;
}