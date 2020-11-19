//
// Created by Bruno Miguel on 18/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BUILDINGS_H
#define GESTOR_ALOJAMENTOS_BUILDINGS_H

/**************************************
************ INCLUDES *****************
**************************************/

#include "../../main/structures.h"
#include "../location/location.h"


/**************************************
************ DECLARACOES *************
**************************************/

void add_building(BUILDINGS **head, char *name, LOCATION *location);

void print_building_all(BUILDINGS *head);

short int find_hotel(BUILDINGS *head, char *name);


#endif //GESTOR_ALOJAMENTOS_BUILDINGS_H
