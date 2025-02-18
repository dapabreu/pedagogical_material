cmake_minimum_required(VERSION 3.22)
project(ficha1325 C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(ficha1325 main.c myLista.c myLista.h)
