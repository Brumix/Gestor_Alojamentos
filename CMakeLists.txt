cmake_minimum_required(VERSION 3.17)
project(Gestor_Alojamentos C)

set(CMAKE_C_STANDARD 99)


add_executable(Gestor_Alojamentos code/main/main.c code/main/structures.h code/components/buildings/buildings.c code/components/buildings/buildings.h code/components/location/location.c code/components/location/location.h code/components/studios/studios.c code/components/studios/studios.h code/components/branch_calendar/branch_calendar.c code/components/branch_calendar/branch_calendar.h code/components/date/date.c code/components/date/date.h code/components/enum/enum.c code/components/enum/enum.h code/components/branch_events/branch_events.c code/components/branch_events/branch_events.h code/components/people/people.c code/components/people/people.h code/components/master_events/master_events.c code/components/master_events/master_events.h code/components/price/price.c code/components/price/price.h)

