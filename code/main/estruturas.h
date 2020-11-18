//
// Created by Bruno Miguel on 01/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_ESTRUTURAS_H
#define GESTOR_ALOJAMENTOS_ESTRUTURAS_H

/**************************************
************ CONSTANTES ***************
**************************************/

#define INICIAL 5


/**************************************
*************** ENUM *****************
**************************************/

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


/**************************************
************ ESTRUTURAS **************
**************************************/


typedef struct data {
    unsigned short  min;
    unsigned short  hora;
    unsigned short  dia;
    unsigned short  mes;
    unsigned short  ano;
} DATA;

typedef struct gps {
    char *latitude;
    char *longuitude;
} GPS;

typedef struct localizacao {
    char *morada;
    GPS *gps;
} LOCALIZACAO;

typedef struct pessoa {
    unsigned id;
    char *nome;
    TIPO_PESSOA *tipo_pessoa;
} PESSOA;

typedef struct precos {
    //ver regras
} PRECOS;

typedef struct master_eventos {
    PLATAFORMA *plataforma;
    PESSOA *pessoa;
    unsigned duracao;
    PRECOS *preco;
    MASTER_EVENTO *mevento;
    struct master_eventos *pnext;
} MEVENTOS;

typedef struct branch_eventos {
    PESSOA *pessoa;
    unsigned duracao;
    PRECOS *preco;
    BRANCH_EVENTO *bevento;
    struct branch_eventos *pnext;
} BEVENTOS;

typedef struct master_calendar {
    DATA *data;
    MEVENTOS *master_evento;
} MASTER_CALENDAR;

typedef struct branch_calendar {
    DATA *data;
    PLATAFORMA *plataforma;
    BEVENTOS *branch_evento;
} BRANCH_CALENDAR;

typedef struct estudios {
    TIPO_ESTUDIO *tipo_estudio;
    unsigned short capacidade;
    unsigned short num_porta;
    MASTER_CALENDAR *master_calendar;
    BRANCH_CALENDAR *branch_calendar;
} ESTUDIOS;

typedef struct edificios {
    char *nome;
    LOCALIZACAO *localizacao;
    ESTUDIOS *estudios;
    struct edificios *next;
} EDIFICIOS;

typedef struct historial {
    PESSOA *pessoa;
    MEVENTOS *eventos;
} HISTORIAL;


/**************************************
************ INCLUDES *****************
**************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>


#include"../componentes/localizacao/localizacao.h"
#include"../componentes/edificios/edificios.h"


#endif //GESTOR_ALOJAMENTOS_ESTRUTURAS_H