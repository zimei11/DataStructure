cmake_minimum_required(VERSION 3.24)
project(code)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(chapter_02_linearlist chapter_02_linearlist/Sqlist.cpp)
add_executable(Test chapter_02_linearlist/Test.cpp)
add_executable(Copy chapter_02_linearlist/Copy.cpp)