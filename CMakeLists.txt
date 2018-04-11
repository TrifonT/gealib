cmake_minimum_required(VERSION 2.8)

project(gealib) 

include_directories(gealib)
file(GLOB SOURCES "gealib/*.cpp")
add_executable(gealib ${SOURCES})



