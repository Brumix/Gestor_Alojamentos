//
// Created by Bruno Miguel on 01/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_EDIFICIO_H
#define GESTOR_ALOJAMENTOS_EDIFICIO_H


#include "C:\Users\Bruno Miguel\CLionProjects\Gestor_Alojamentos\code\main\estruturas.h"

void add_edificio(EDIFICIOS **head, char *nome, LOCALIZACAO *localizacao);

void print_edificios(EDIFICIOS *head);

LOCALIZACAO *add_localizacao(char *cidade, char *rua, int porta);

short int find_hotel(EDIFICIOS *head,char * nome);


#endif //GESTOR_ALOJAMENTOS_EDIFICIO_H
