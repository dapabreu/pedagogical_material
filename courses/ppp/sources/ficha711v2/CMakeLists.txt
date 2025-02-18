cmake_minimum_required(VERSION 3.24)
project(ficha711v2 C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(ficha711v2 main.c dates.h)
