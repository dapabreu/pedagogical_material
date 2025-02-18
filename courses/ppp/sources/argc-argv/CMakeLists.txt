cmake_minimum_required(VERSION 3.25)
project(argc_argv C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(argc_argv main.c)
