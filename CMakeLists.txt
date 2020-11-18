cmake_minimum_required(VERSION 3.17)
project(Gestor_Alojamentos C)

set(CMAKE_C_STANDARD 99)


add_executable(Gestor_Alojamentos code/main/main.c code/main/estruturas.h code/edificios/edificios.c code/edificios/edificios.h code/localizacao/localizacao.c code/localizacao/localizacao.h)

