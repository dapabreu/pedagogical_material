cmake_minimum_required(VERSION 3.21)
project(headerFile C)

set(CMAKE_C_STANDARD 11)

add_executable(headerFile main.c calculateAge.c calculateAge.h)
