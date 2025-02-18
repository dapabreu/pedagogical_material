cmake_minimum_required(VERSION 3.22)
project(stackImp C)

set(CMAKE_C_STANDARD 11)

add_executable(stackImp main.c myStack.c myStack.h)
