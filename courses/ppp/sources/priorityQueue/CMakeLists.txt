cmake_minimum_required(VERSION 3.25)
project(priorityQueue C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(priorityQueue main.c myQueue.c myQueue.h)
