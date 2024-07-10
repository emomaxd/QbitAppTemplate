cmake_minimum_required(VERSION 3.10)
project(QbitAppSolution)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(QbitApp)
add_subdirectory(QbitLite)

# Set Engine as the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT QbitApp)

# Remove ALL_BUILD and ZERO_CHECK targets
set(CMAKE_SUPPRESS_REGENERATION true)
