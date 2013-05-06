cmake_minimum_required(VERSION 2.8)

set(PROJECT lehman)

project(${PROJECT})

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O3")

set(SOURCES
  src/main.cpp
)

include_directories(
  include
)

add_executable(${PROJECT} ${SOURCES})
