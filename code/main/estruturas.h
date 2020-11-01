//
// Created by Bruno Miguel on 01/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_ESTRUTURAS_H
#define GESTOR_ALOJAMENTOS_ESTRUTURAS_H

/**
 * CONSTANTES
 */

#define ANDARESINICIAL 10


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
    int min;
    int hora;
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct pessoa {
    int id;
    char *nome;
    int cc;
    char *tipo_pessoa;
    DATA data_nasciemnto;
} PESSOA;

typedef struct localizacao {
    char *cidade;
    char *rua;
    int num_porta;
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
    int capacidade;
    int num_porta;
    DIAS dia;
} ESTUDIOS;

typedef struct andares {
    char* id;
    int num_estudios;
    ESTUDIOS estudio;
} ANDARES;

typedef struct edificios {
    char *nome;
    int num_andares;
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


#include "C:\Users\Bruno Miguel\CLionProjects\Gestor_Alojamentos\code\edificio\edificio.h"
#include "C:\Users\Bruno Miguel\CLionProjects\Gestor_Alojamentos\code\andares\andares.h"


#endif //GESTOR_ALOJAMENTOS_ESTRUTURAS_H
