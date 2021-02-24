cmake_minimum_required(VERSION 3.17)
project(simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{CMAKE_MODULES_DIR}/")

#find_package(Eigen3 REQUIRED)
#message(STATUS "Eigen3 included at $ENV{EIGEN3_INCLUDE_DIR}")

include_directories("$ENV{CMAKE_MODULES_DIR}")

add_executable(simulator main.cpp model/Particle.cpp model/Particle.h model/World.cpp model/World.h logic/Physics.cpp logic/Physics.h)