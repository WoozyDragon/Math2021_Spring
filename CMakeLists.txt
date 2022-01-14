# CMakeList.txt : CMake project for nprimes, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Math2021_Spring_1")

set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED)

# include local "include" folder with libraires
include_directories ("./include")

# Add source to this project's executable.
add_executable (nprimes "nprimes.cpp" "nprimes.h")

# TODO: Add tests and install targets if needed.
