# Not a very backwards-compatible requirement. Oh well.
cmake_minimum_required(VERSION 3.11)

# Set the compiler to be clang-based as opposed to gcc-based.
if (APPLE)
  set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
  set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
endif (APPLE)

# Name of the root directory.
project(leonhard)

# Recursively compile the source files into the entire project.
add_subdirectory(src)
