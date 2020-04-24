cmake_minimum_required(VERSION 3.15)

project(FloodFill C)

set(CMAKE_C_STANDARD 99)

add_executable(FloodFill driver.c stack312_ll.c)