cmake_minimum_required(VERSION 3.17)
project(Gestor_Alojamentos C)

set(CMAKE_C_STANDARD 99)


add_executable(Gestor_Alojamentos code/main/main.c code/main/structures.h code/components/buildings/buildings.c code/components/buildings/buildings.h code/components/location/location.c code/components/location/location.h code/components/studios/studios.c code/components/studios/studios.h)

