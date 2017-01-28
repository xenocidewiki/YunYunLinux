cmake_minimum_required(VERSION 3.6)
project(YunYunLinux)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Utils.cpp Utils.h)
add_executable(YunYunLinux ${SOURCE_FILES})