cmake_minimum_required(VERSION 3.13)
project(ProjectEuler)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectEuler Problem1/src/Problem1.cpp Problem2/src/Problem2.cpp main.cpp Util/src/Util.cpp Problem3/src/Problem3.cpp Problem3/src/Problem3.h Util/src/Util.h Problem2/src/Problem2.h Problem4/src/Problem4.cpp Problem4/src/Problem4.h Problem5/src/Problem5.cpp Problem5/src/Problem5.h)