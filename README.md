# Increase Webcam FPS with Multithreading in OpenCV C+
Status: ongoing

I want to improve the performance of webcam streaming using OpenCV. This [article](https://www.pyimagesearch.com/2015/12/21/increasing-webcam-fps-with-python-and-opencv/) suggesting using multithreading to improve the frame per second (FPS) rate but I'm not sure whether the perfomance difference would be significant or not. However, it worths doing some experiments though. I would be a great project to learn some new concepts on multithreading and practice coding in C++.

If the performance speeds up, then I would try to adding object detection feature to this project using [dlib](http://dlib.net/). I did a project using *dlib* in Python but the video speed is really bad. So I hope this project could results in some positive result!

Using Docker? https://medium.com/heuristics/docker-for-c-build-pipeline-7eeaaa461f97

## Instruction
Build and execute:
```shell
mkdir build
cd build
cmake ../
make

./../bin/thread_opencv_cpp  # execute bin file
```

Remove files in .gitignore:
```shell
chmod 700 utils/clean.bash
./utils/clean.bash < .gitignore
```

## Webcam Stream 
The detach method ```t1.detach()``` is used we don't need to wait for the thread 1 to finish. Instead, it will get the dataframe. The process happens simultaneously.

## Measuring FPS and Elapsed time
I first use **chrono** liberary to measure the time but found that it's hard to convert to seconds unit for calculating FPS. So, I use **ctime**.
```c
// in utils.cpp
#include <ctime>

numFrames = 100;

clock_t start = clock();
// some function here
clock_t end = clock();

double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
double fps = numFrames / elapsed_secs;
```

## Face Dection using dlib
http://dlib.net/webcam_face_pose_ex.cpp.html


## Analysis
### Just streaming webcam
Stream 1000 frames for 10 times and record the data:
```shell
# run in terminal
for i in {1..10}; do
    # execute and direct output to text file
    ./bin/thread_opencv_cpp 1000 >> output.txt
done
```

Test 10 times with multithreading
| frames        | Elapsed (Avg) | FPS (Avg)     |
| ------------- | ------------- | ------------- |
| 100           | 1.57126       | 63.6563       |
| 1000          | 14.5097       | 68.9689       |


Test 10 times w/o multithreading
| frames        | Elapsed (Avg) | FPS (Avg)     |
| ------------- | ------------- | ------------- |
| 100           | 1.95773       | 51.0956       |
| 1000          | 13.9149       | 52.4172       |


The elapsed time don't see any change; however, the FPS of streaming 100 and 1000 frames increase by 23.5% and 31.5%, respectively.

### Face Detection

### Object Detection

## References
https://www.pyimagesearch.com/2015/12/21/increasing-webcam-fps-with-python-and-opencv/