cmake_minimum_required(VERSION 3.14) # MSVC, GCC, Clang works
project(marxDB)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
file(GLOB_RECURSE src
     "source/*.hpp"
     "source/*.cpp"
)
add_library(melsdb SHARED ${src})
add_executable(test test/main.cpp)
add_executable(melsdbCLI cli/entryPoint.cpp)
target_link_libraries(test PRIVATE melsdb)
target_link_libraries(melsdbCLI PRIVATE melsdb)