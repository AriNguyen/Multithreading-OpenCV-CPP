#include <chrono>
#include "utils.h"

int FPS::getNumFrames() {
    return this->numFrames;
}


void FPS::start() {
    this->timeStart = clock();
}


void FPS::stop() {
    this->timeStop = clock();
}


void FPS::update() {
    this->numFrames++;
}


double FPS::elapsed() {
    double elapsed_secs = double(this->timeStop - this->timeStart) / CLOCKS_PER_SEC;;
    return elapsed_secs;
}


double FPS::fps() {
    double fps = this->numFrames / this->elapsed();
    return fps;
}