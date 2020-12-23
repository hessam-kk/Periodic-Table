project(Periodic_table)
cmake_minimum_required(VERSION 3.0)
set(SOURCES
    src/Main.cpp
    src/Make-Set.cpp
    src/Show.cpp
    src/Search.cpp
)
add_executable(app ${SOURCES})
include_directories(header)
set(CMAKAE_CXX_STANDARD 11)