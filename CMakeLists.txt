# CMakeList.txt : CMake project for nprimes, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Math2021_Spring_1")

set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED)

# Add source to this project's executable.
add_executable (nprimes "nprimes.cpp" "nprimes.h")

# add local include folder to nprimes target
target_include_directories(nprimes PRIVATE "./include")

target_compile_options(nprimes PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /O2>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -O2>
)

# TODO: Add tests and install targets if needed.
