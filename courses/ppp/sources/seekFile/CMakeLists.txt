cmake_minimum_required(VERSION 3.22)
project(seekFile C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(seekFile main.c)
