cmake_minimum_required(VERSION 3.20)
project(SecuritySystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(SecuritySystem Program.cpp)

find_library(LIB_PATH libSecuritySystem
        PATHS
        ../lib/cmake-build-debug/)

target_include_directories(SecuritySystem PRIVATE ../lib)

TARGET_LINK_LIBRARIES(SecuritySystem ${LIB_PATH} )