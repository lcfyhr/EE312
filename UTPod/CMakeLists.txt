cmake_minimum_required(VERSION 3.15)

project(UTPod)

set(CMAKE_CXX_STANDARD 11)

add_executable(UTPod UTPodDriver.cpp UTPod.cpp Song.cpp)