# Not a very backwards-compatible requirement. Oh well.
cmake_minimum_required(VERSION 3.11)

# Name of the root directory.
project(leonhard)

# Find all of the required configurations needed for Boost in this project.
find_package(Boost 1.67.0 REQUIRED)

# Add the Boost definitions and include directories to build the project.
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# Recursively compile the source files into the entire project.
add_subdirectory(src)
