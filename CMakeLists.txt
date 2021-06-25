cmake_minimum_required(VERSION 3.19)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_of_life main.cpp Cell.cpp Cell.h Grid.cpp Grid.h)