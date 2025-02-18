cmake_minimum_required(VERSION 3.22)
project(ficha1111 C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(ficha1111 main.c myQueue.c myQueue.h)
