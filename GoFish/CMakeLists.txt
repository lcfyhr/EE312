cmake_minimum_required(VERSION 3.15)

project(GoFish)

set(CMAKE_CXX_STANDARD 11)

add_executable(GoFish card.cpp deck.cpp go_fish.cpp player.cpp)