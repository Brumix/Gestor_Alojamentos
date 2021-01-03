//
// Created by Bruno Miguel on 21/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_PEOPLE_H
#define GESTOR_ALOJAMENTOS_PEOPLE_H


#include "../../main/structures.h"


void add_people(PEOPLE **people, char *name, TYPE_PEOPLE typePeople);

void print_people(PEOPLE *people);

PEOPLE* create_people(char * name,TYPE_PEOPLE typePeople);

void print_all_people(PEOPLE *people);

PEOPLE * find_people(PEOPLE *people,unsigned id);

#endif //GESTOR_ALOJAMENTOS_PEOPLE_H
