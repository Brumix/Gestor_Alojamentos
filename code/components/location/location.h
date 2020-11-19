//
// Created by Bruno Miguel on 18/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_LOCATION_H
#define GESTOR_ALOJAMENTOS_LOCATION_H


/**************************************
************ INCLUDES *****************
**************************************/


#include "../../main/structures.h"


/**************************************
************ DECLARACOES *************
**************************************/

GPS *add_gps(char *lat, char *lon);

LOCATION *add_location(char *address, char *lat, char *lon);

void print_location(LOCATION *loc);

#endif //GESTOR_ALOJAMENTOS_LOCATION_H
