//
// Created by Bruno Miguel on 18/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BUILDINGS_H
#define GESTOR_ALOJAMENTOS_BUILDINGS_H


#include "../../main/structures.h"
#include "../location/location.h"


void add_building(BUILDINGS **head,unsigned index,char *name, float price,LOCATION location);


void delete_building(BUILDINGS **head, char *name);

BUILDINGS *create_building(unsigned index,char *name,float price, LOCATION location);

void print_building_all(BUILDINGS *head);

short int find_hotel(BUILDINGS *head, char *name);


#endif //GESTOR_ALOJAMENTOS_BUILDINGS_H
