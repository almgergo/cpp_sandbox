# Make sure to define
# SDL2_DIR, GLFW_ROOT_PATH, GLEW_ROOT_PATH environment variables

cmake_minimum_required(VERSION 3.17)
project(simulator)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR $ENV{SDL2_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules ${CMAKE_SOURCE_DIR}/cmake/Find)

#find_package(SDL2 REQUIRED)
#find_package(GLEW REQUIRED)
#find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenCL REQUIRED)


find_package(ComputeCpp REQUIRED)
option(COMPUTECPP_SDK_USE_OPENMP "Enable OpenMP support in samples" OFF)
option(COMPUTECPP_SDK_BUILD_TESTS "Build the tests for the header utilities in include/" OFF)

include_directories($ENV{CMAKE_MODULES_DIR} ${OpenCL_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${ComputeCpp_INCLUDE_DIRS})

#add_executable(simulator src/main.cpp src/model/Particle.cpp src/model/Particle.h src/model/World.cpp src/model/World.h src/logic/Physics.cpp src/logic/Physics.h src/app/Graphics.cpp src/app/Graphics.h src/logic/SyclPhysics.cpp src/logic/SyclPhysics.h)
add_executable(simulator src/main.cpp src/logic/SyclPhysics.cpp src/logic/SyclPhysics.h)
add_sycl_to_target(TARGET simulator SOURCES src/logic/SyclPhysics.cpp src/logic/SyclPhysics.h)
target_link_libraries(simulator
        ${SDL2_LIBRARIES}
        ${OpenCL_LIBRARY}
        ${GLFW_GLFW_LIBRARY}
        ${GLEW_GLEW_LIBRARY}
        ${COMPUTECPP_RUNTIME_LIBRARY}
        OpenGL::GL)
