#add_executable(test2 main.cpp)

#target_link_libraries(test1)


#cmake_minimum_required(VERSION 2.8)
#project(myprj)
#
#set(CMAKE_CXX_FLAGS "-fpermissive")
#set(CMAKE_BUILD_TYPE "Debug")

#include_directories(./)
#include_directories(./MiscLib/)
#FILE(GLOB SRC "./*.cpp")
#FILE(GLOB MISC_SRC "./MiscLib/*.cpp")

aux_source_directory(./ SRC)

add_library(mylib STATIC ${SRC})
