CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# set project name
project(thread_opencv_cpp)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify dir path 
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

# headers
set(HEADER_FILES ${CMAKE_SOURCE_DIR}/WebcamStream.h)

# OpenCV library
set(OpenCV_LIBS "/usr/local/lib/opencv4")
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui objdetect videoio)

add_executable(thread_opencv_cpp ${CMAKE_SOURCE_DIR}/main.cpp)
target_link_libraries(thread_opencv_cpp ${OpenCV_LIBS})

