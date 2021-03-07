# Copyright (c) 2009 Boudewijn Rempt <boud@valdyas.org>                                                                                          
#                                                                                                                                                
# Redistribution and use is allowed according to the terms of the BSD license.                                                                   
# For details see the accompanying COPYING-CMAKE-SCRIPTS file. 
# 
# - try to find GLFW library and include files
#  GLFW_INCLUDE_DIR, where to find GL/GLFW.h, etc.
#  GLFW_LIBRARIES, the libraries to link against
#  GLFW_FOUND, If false, do not try to use GLFW.
# Also defined, but not for general use are:
#  GLFW_GLFW_LIBRARY = the full path to the GLFW library.

FIND_PATH( GLFW_INCLUDE_DIR GLFW/glfw3.h
  $ENV{GLFW_ROOT_PATH}/include
)

FIND_LIBRARY( GLFW_GLFW_LIBRARY
  NAMES glfw3 glfw3dll
  PATHS $ENV{GLFW_ROOT_PATH}/lib-static-ucrt
)

message(OPENGL: ${OPENGL_LIBRARY_DIR} )
message(${GLFW_INCLUDE_DIR} ${GLFW_GLFW_LIBRARY})

SET( GLFW_FOUND "NO" )
IF(GLFW_INCLUDE_DIR)
  IF(GLFW_GLFW_LIBRARY)
    # Is -lXi and -lXmu required on all platforms that have it?
    # If not, we need some way to figure out what platform we are on.
    SET( GLFW_LIBRARIES
      ${GLFW_GLFW_LIBRARY}
      ${GLFW_cocoa_LIBRARY}
    )
    SET( GLFW_FOUND "YES" )

#The following deprecated settings are for backwards compatibility with CMake1.4
    SET (GLFW_LIBRARY ${GLFW_LIBRARIES})
    SET (GLFW_INCLUDE_PATH ${GLFW_INCLUDE_DIR})

  ENDIF(GLFW_GLFW_LIBRARY)
ENDIF(GLFW_INCLUDE_DIR)

IF(GLFW_FOUND)
  IF(NOT GLFW_FIND_QUIETLY)
    MESSAGE(STATUS "Found GLFW: ${GLFW_LIBRARIES}")
  ENDIF(NOT GLFW_FIND_QUIETLY)
ELSE(GLFW_FOUND)
  IF(GLFW_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could not find GLFW")
  ENDIF(GLFW_FIND_REQUIRED)
ENDIF(GLFW_FOUND)

MARK_AS_ADVANCED(
  GLFW_INCLUDE_DIR
  GLFW_GLFW_LIBRARY
  GLFW_Xmu_LIBRARY
  GLFW_Xi_LIBRARY
)
