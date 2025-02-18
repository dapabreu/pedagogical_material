cmake_minimum_required(VERSION 3.25)
project(ficha1223 C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(ficha1223 main.c myStack.c myStack.h)
