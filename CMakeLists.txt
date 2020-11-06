cmake_minimum_required(VERSION 3.17)
project(Gestor_Alojamentos C)

set(CMAKE_C_STANDARD 99)


add_executable(Gestor_Alojamentos code/main/main.c code/main/estruturas.h code/edificio/edificio.c code/edificio/edificio.h code/andares/andares.c code/andares/andares.h code/estudios/estudios.c code/estudios/estudios.h)

