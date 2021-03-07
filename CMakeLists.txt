# Make sure to define
# SDL2_DIR, GLFW_ROOT_PATH, GLEW_ROOT_PATH environment variables

cmake_minimum_required(VERSION 3.17)
project(simulator)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR $ENV{SDL2_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories($ENV{CMAKE_MODULES_DIR} ${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})

add_executable(simulator src/main.cpp src/model/Particle.cpp src/model/Particle.h src/model/World.cpp src/model/World.h src/logic/Physics.cpp src/logic/Physics.h src/app/Graphics.cpp src/app/Graphics.h)
message(${GLFW_GLFW_LIBRARY})
target_link_libraries(simulator ${SDL2_LIBRARIES} ${GLFW_GLFW_LIBRARY} ${GLEW_GLEW_LIBRARY} OpenGL::GL)
