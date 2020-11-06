//
// Created by Bruno Miguel on 01/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_ESTRUTURAS_H
#define GESTOR_ALOJAMENTOS_ESTRUTURAS_H

/**
 * CONSTANTES
 */

#define INICIAL 5


/**
 * ENUM
 */


enum tipo_pessoa {
    HOSPEDE, EMPREGADO
};

enum tipo_evento {
    CHECK_IN, CHECK_OUT, LIMPEZA, MANUTENCAO
};


/**
 * ESTRUTURAS
 */

//todo politica de preços ????


typedef struct data {
    unsigned short int min;
    unsigned short int hora;
    unsigned short int dia;
    unsigned short int mes;
    unsigned short int ano;
} DATA;

typedef struct pessoa {
    unsigned int id;
    char *nome;
    unsigned int cc;
    char *tipo_pessoa;
    DATA data_nasciemnto;
} PESSOA;

typedef struct localizacao {
    char *cidade;
    char *rua;
    unsigned int num_porta;
} LOCALIZACAO;

typedef struct eventos {
    PESSOA pessoa;
    char *tipo_evento;
    struct eventos *pnext;
} EVENTOS;

typedef struct dias {
    EVENTOS evento;
    DATA data;
} DIAS;

typedef struct estudios {
    unsigned short int capacidade;
    unsigned short int num_porta;
    DIAS dia;
} ESTUDIOS;

typedef struct andares {
    unsigned int num_estudios;
    ESTUDIOS estudio;
} ANDARES;

typedef struct edificios {
    char *nome;
    unsigned int num_andares;
    ANDARES *andar;
    LOCALIZACAO *localizacao;
    struct edificios *next;
} EDIFICIOS;

// ver whiteboard
typedef struct historial {
    PESSOA pessoa;
    DATA data;
    EVENTOS evento;
    char *tipo_evento;
} HISTORIAL;


/**
 * INCLUDES
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>


#include "C:\Users\Bruno Miguel\CLionProjects\Gestor_Alojamentos\code\edificio\edificio.h"
#include "C:\Users\Bruno Miguel\CLionProjects\Gestor_Alojamentos\code\andares\andares.h"


#endif //GESTOR_ALOJAMENTOS_ESTRUTURAS_H