cmake_minimum_required(VERSION 3.22)
project(ficha1212 C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(ficha1212 main.c myStack.c myStack.h)
