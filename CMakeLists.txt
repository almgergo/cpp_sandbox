cmake_minimum_required(VERSION 3.17)
project(simulator)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR $ENV{SDL2_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories($ENV{CMAKE_MODULES_DIR} ${SDL2_INCLUDE_DIRS})

add_executable(simulator main.cpp model/Particle.cpp model/Particle.h model/World.cpp model/World.h logic/Physics.cpp logic/Physics.h app/CApp.cpp app/CApp.h)
target_link_libraries(simulator ${SDL2_LIBRARIES})
