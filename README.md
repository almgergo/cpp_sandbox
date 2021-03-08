# Simulator project with SDL, Eigen, OpenGL, OpenCL, SYCL
## Setup
Add SDL lib/x64 to PATH  
Set SDL2_DIR environment variable to where SDL2 dev zip was extracted to  
Set EIGEN3_INCLUDE_DIR and/or EIGEN3_ROOT_DIR variable to Eigen location  
Set GLEW_ROOT_PATH and GLFW_ROOT_PATH to lib location  
Set COMPUTECPP_DIR variable  

## SYCL
To add new sycl source files, they have to be added in cmake with 
``` add_sycl_to_target ``` as well