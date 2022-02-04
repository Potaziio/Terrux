set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

cmake_minimum_required(VERSION 3.0.0)
project(Terrux VERSION 0.0.1)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

find_package(OpenGL REQUIRED)

file(GLOB GLEW_SOURCES
    "vendor/glew-2.2.0/src/*"
    )

add_subdirectory("vendor/glfw-3.3.5/")
add_library(glew_lib STATIC ${GLEW_SOURCES})

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(Terrux ${SOURCE_FILES})

target_link_libraries(Terrux glew_lib glfw OpenGL::GL ${CMAKE_DL_LIBS})

target_compile_features(Terrux PRIVATE cxx_std_17)

set_target_properties(Terrux PROPERTIES
            CXX_STANDARD 17
            CXX_EXTENSIONS ON
            )
