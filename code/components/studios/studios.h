//
// Created by Bruno Miguel on 19/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_STUDIOS_H
#define GESTOR_ALOJAMENTOS_STUDIOS_H


#include "../../main/structures.h"


void add_studio(BUILDINGS *buildings, TYPE_STUDIO typeStudio, unsigned short cap, unsigned short door);

void print_studio_all(BUILDINGS *buildings);

void resizeStudios(BUILDINGS *head);

char *strTypeStudio(TYPE_STUDIO ts);

#endif //GESTOR_ALOJAMENTOS_STUDIOS_H
