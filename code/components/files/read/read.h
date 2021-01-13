//
// Created by Bruno Miguel on 21/12/2020.
//

#ifndef GESTOR_ALOJAMENTOS_READ_H
#define GESTOR_ALOJAMENTOS_READ_H

#include "../../../main/structures.h"


void read_file_buildigns(BUILDINGS **);

void read_file_studio_politics(BUILDINGS *buildings);

void read_file_estudio(BUILDINGS *buildings);

void read_politics();

void read_events(BUILDINGS *buildings, PEOPLE *people);

void read_people(PEOPLE **people);

void read_bin(char *file);

void read_building_bin();

void read_studio_bin();

void read_history_bin();

#endif //GESTOR_ALOJAMENTOS_READ_H
