# Not a very backwards-compatible requirement. Oh well.
cmake_minimum_required(VERSION 3.11)

# Name of the subdirectory.
project(src)

# Add the files to be compiled from this subdirectory.
file(GLOB_RECURSE SOURCES "*.cpp")

# Loop over all of the sources in the directory.
foreach(problem ${SOURCES})
  # Create a base file name out of the source file.
  get_filename_component(base ${problem} NAME_WE)
  string(REGEX REPLACE "euler-" "" base "${base}")

  # Create a run-time executable based on these source files from above.
  add_executable(${base} ${problem})

  # Use C++14 to compile the source file.
  # Also build the .o executable file without any prefixes (e.g. 'bin').
  set_target_properties(
    ${base}
    PROPERTIES
      COMPILE_FLAGS            "-std=c++14 -O3"
      PREFIX                   ""
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
      OUTPUT_NAME              "${base}"
  )

  # Get proper shared-library behavior (where symbols are not necessarily
  # resolved when the shared library is linked) on Mac OS X.
  if (APPLE)
    set_target_properties(
      ${base}
      PROPERTIES
        LINK_FLAGS             "-undefined dynamic_lookup"
    )
  endif (APPLE)
endforeach(problem)
