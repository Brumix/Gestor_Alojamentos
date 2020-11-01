cmake_minimum_required(VERSION 3.17)
project(Gestor_Alojamentos C)

set(CMAKE_C_STANDARD 99)

add_executable(Gestor_Alojamentos code/main.c code/estruturas.h edificio/edificio.c edificio/edificio.h)