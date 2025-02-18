cmake_minimum_required(VERSION 3.22)
project(stackPT C)

set(CMAKE_C_STANDARD 11)

add_executable(stackPT main.c myStack.c myStack.h)
