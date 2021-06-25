cmake_minimum_required(VERSION 3.19)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(game_of_life main.cpp Cell.cpp Cell.h Grid.cpp Grid.h Render.cpp Render.h)
target_link_libraries(game_of_life sfml-graphics sfml-audio)