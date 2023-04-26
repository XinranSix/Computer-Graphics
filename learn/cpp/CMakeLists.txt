cmake_minimum_required(VERSION 3.10)

project(CPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(./include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_executable(thread ./src/thread.cpp)
add_executable(test ./test/test.cpp ./test/foo.c)
