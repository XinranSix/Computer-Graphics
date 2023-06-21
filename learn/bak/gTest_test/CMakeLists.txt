cmake_minimum_required(VERSION 3.22.1)
project(test2)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include DIR_INC)
link_directories(./lib)

add_executable(main src/main.cpp)

target_link_libraries(main libgtest.a libgtest_main.a libgmock.a libgmock_main.a)