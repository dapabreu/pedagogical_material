cmake_minimum_required(VERSION 3.21)
project(decimal2bin C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(decimal2bin main.c)
