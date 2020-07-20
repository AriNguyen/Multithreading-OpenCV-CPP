CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# set project name
project(thread_opencv_cpp)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify dir path 
set(CMAKE_SOURCE_DIR src/)
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# headers
set(HEADER_FILES 
    ${CMAKE_SOURCE_DIR}/WebcamStream.h 
    ${CMAKE_SOURCE_DIR}/utils.h
)

# OpenCV library
set(OpenCV_LIBS "/usr/local/lib/opencv4")
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui objdetect videoio)

# target
add_executable(thread_opencv_cpp 
    main.cpp 
    ${CMAKE_SOURCE_DIR}/WebcamStream.cpp
    ${CMAKE_SOURCE_DIR}/utils.cpp
)

# external library
target_link_libraries(thread_opencv_cpp ${OpenCV_LIBS})

