cmake_minimum_required(VERSION 2.8)

set(PROJECT lehman)

project(${PROJECT})

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O3")

set(SOURCES
  src/main.cpp

  contrib/bigint/BigIntegerAlgorithms.cc
  contrib/bigint/BigInteger.cc
  contrib/bigint/BigIntegerUtils.cc
  contrib/bigint/BigUnsigned.cc
  contrib/bigint/BigUnsignedInABase.cc
)

include_directories(
  include

  contrib/bigint
)

add_executable(${PROJECT} ${SOURCES})
