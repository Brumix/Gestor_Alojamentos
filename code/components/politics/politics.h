//
// Created by Bruno Miguel on 02/01/2021.
//

#ifndef GESTOR_ALOJAMENTOS_POLITICS_H
#define GESTOR_ALOJAMENTOS_POLITICS_H


#include "../../main/structures.h"


void add_politics(char *name, PLATFORM platform, int size);

POLITICS *create_politics(char *name, PLATFORM platform, int size);

void print_politics();

POLITICS *find_politics(char *politic);


#endif //GESTOR_ALOJAMENTOS_POLITICS_H
