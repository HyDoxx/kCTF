cmake_minimum_required(VERSION 3.30)
project(kCTFTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(kCTFTest main.cpp kCTF.h kAES.h kUtils.h)