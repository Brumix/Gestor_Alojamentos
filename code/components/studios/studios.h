//
// Created by Bruno Miguel on 19/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_STUDIOS_H
#define GESTOR_ALOJAMENTOS_STUDIOS_H


#include "../../main/structures.h"


void add_studio(BUILDINGS *buildings, TYPE_STUDIO typeStudio, unsigned short cap, unsigned short door, char *extra);

void delete_studio(BUILDINGS *buildings, unsigned short door);

STUDIOS create_studio(TYPE_STUDIO typeStudio, unsigned short cap, unsigned short door, char *extra);

void print_studio_all(BUILDINGS *buildings);

void resizeStudios(BUILDINGS *head);

void shift_right_array(STUDIOS *a, int index, STUDIOS val, unsigned size);

void shift_left_array(STUDIOS *a, int index, unsigned size);

char *strTypeStudio(TYPE_STUDIO ts);

#endif //GESTOR_ALOJAMENTOS_STUDIOS_H
