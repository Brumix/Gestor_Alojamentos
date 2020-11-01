cmake_minimum_required(VERSION 3.17)
project(Gestor_Alojamentos C)

set(CMAKE_C_STANDARD 99)

add_executable(Gestor_Alojamentos main.c estruturas.h edificio_linkedlist/edificio_linkedlist.c edificio_linkedlist/edificio_linkedlist.h)