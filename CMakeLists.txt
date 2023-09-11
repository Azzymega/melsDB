cmake_minimum_required(VERSION 3.14) # MSVC, GCC, Clang works
project(marxDB)
#set(CMAKE_CXX_FLAGS "-std=c++17")
#set(CMAKE_CXX_FLAGS "-O3")
#set(CMAKE_CXX_FLAGS "/Ot")
#set(CMAKE_CXX_FLAGS "/Zi")
#set(CMAKE_CXX_FLAGS "/EHsc")
#set(CMAKE_CXX_FLAGS "/analyze")
file(GLOB_RECURSE src
     "source/*.hpp"
     "source/*.cpp"
     "test/*.hpp"
     "test/*.cpp"
)
file(GLOB_RECURSE entry
     "source/*.hpp"
     "source/*.cpp"
)
add_executable(test ${src})
#add_executable(melsDB ${entry})