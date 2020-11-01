//
// Created by Bruno Miguel on 01/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_EDIFICIO_H
#define GESTOR_ALOJAMENTOS_EDIFICIO_H


#include "../code/estruturas.h"

void add_edificio(EDIFICIOS **head, char *nome,LOCALIZACAO *localizacao);

void print_edificios(EDIFICIOS **head);

LOCALIZACAO *addlocalizacao(char* cidade,char * rua,int porta);


#endif //GESTOR_ALOJAMENTOS_EDIFICIO_H
