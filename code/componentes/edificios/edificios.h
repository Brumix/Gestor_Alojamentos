//
// Created by Bruno Miguel on 18/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_EDIFICIOS_H
#define GESTOR_ALOJAMENTOS_EDIFICIOS_H

/**************************************
************ INCLUDES *****************
**************************************/

#include "../../main/estruturas.h"
#include "../localizacao/localizacao.h"


/**************************************
************ DECLARACOES *************
**************************************/

void add_edificio(EDIFICIOS **head, char *nome, LOCALIZACAO *localizacao);

void print_edificios_all(EDIFICIOS *head);

short int find_hotel(EDIFICIOS *head, char *nome);


#endif //GESTOR_ALOJAMENTOS_EDIFICIOS_H
