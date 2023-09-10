cmake_minimum_required(VERSION 3.14) # MSVC 
project(marxDB)
set(CMAKE_CXX_FLAGS "/Ot")
set(CMAKE_CXX_FLAGS "/Zi")
set(CMAKE_CXX_FLAGS "/EHsc")
#set(CMAKE_CXX_FLAGS "/analyze")
file(GLOB_RECURSE src
     "source/*.hpp"
     "source/*.cpp"
     "test/*.hpp"
     "test/*.cpp"
)
add_executable(test ${src})