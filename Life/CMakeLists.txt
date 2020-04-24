cmake_minimum_required(VERSION 3.15)

project(life C)

set(CMAKE_C_STANDARD 99)

add_executable(life life_driver.c life.c)