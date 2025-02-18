cmake_minimum_required(VERSION 3.24)
project(dec2bin C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(dec2bin main.c)
