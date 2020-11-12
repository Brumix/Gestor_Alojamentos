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


typedef enum tipo_pessoa {
    HOSPEDE, EMPREGADO
} TIPO_PESSOA;

typedef enum master_evento {
    OCUPADO, LIMPEZA, MANUTENCAO, FATURACAO, GREACAO_DE_RELATORIOS
} MASTER_EVENTO;
typedef enum branch_evento {
    RESERVADO, LIVRE
} BRANCH_EVENTO;

typedef enum tipo_estudio {
    T1, T2, T3D, SUITE, SUITEPRESIDENCIAL
} TIPO_ESTUDIO;

typedef enum plataforma {
    AirBnc, AisBnD, AisBnE, AIRPlaces
} PLATAFORMA;


/**
 * ESTRUTURAS
 */


typedef struct data {
    unsigned short int min;
    unsigned short int hora;
    unsigned short int dia;
    unsigned short int mes;
    unsigned short int ano;
} DATA;

typedef struct gps {
    char latitude[10];
    char longuitude[10];
} GPS;

typedef struct localizacao {
    char morada[45];
    GPS gps;
} LOCALIZACAO;

typedef struct pessoa {
    unsigned int id;
    char nome[45];
    TIPO_PESSOA tipo_pessoa;
} PESSOA;

typedef struct precos {
    //ver regras
} PRECOS;


typedef struct master_eventos {
    PESSOA pessoa;
    DATA data;
    int duracao;
    PRECOS preco;
    MASTER_EVENTO mevento;
    struct eventos *pnext;
} MEVENTOS;

typedef struct branch_eventos {
    PESSOA pessoa;
    DATA data;
    int duracao;
    PRECOS preco;
    BRANCH_EVENTO bevento;
    struct eventos *pnext;
} BEVENTOS;


typedef struct master_calendar {
    MEVENTOS *master_evento;
    PLATAFORMA plataforma;
} MASTER_CALENDAR;

typedef struct branch_calendar {
    BEVENTOS *branch_evento;
    PLATAFORMA plataforma;
} BRANCH_CALENDAR;

typedef struct estudios {
    TIPO_ESTUDIO tipo_estudio;
    unsigned short int capacidade;
    unsigned short int num_porta;
    MASTER_CALENDAR master_calendar;
    BRANCH_CALENDAR branch_calendar;
} ESTUDIOS;

typedef struct edificios {
    char nome[45];
    LOCALIZACAO localizacao;
    ESTUDIOS *estudios;
    struct edificios *next;
} EDIFICIOS;

typedef struct historial {
    PESSOA pessoa;
    MEVENTOS eventos;
} HISTORIAL;




/**
 * INCLUDES
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#endif //GESTOR_ALOJAMENTOS_ESTRUTURAS_H