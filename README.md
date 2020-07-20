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

## Webcam Stream and measure FPS
Use **chrono** library to measure time and number of frame per second. 


## Face Dection using dlib
http://dlib.net/webcam_face_pose_ex.cpp.html


## Analysis


## References
https://www.pyimagesearch.com/2015/12/21/increasing-webcam-fps-with-python-and-opencv/