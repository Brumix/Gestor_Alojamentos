//
// Created by Bruno Miguel on 01/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_STRUCTURES_H
#define GESTOR_ALOJAMENTOS_STRUCTURES_H

/**************************************
************ CONSTANTS ***************
**************************************/

#define INICIAL 5


/**************************************
*************** ENUM *****************
**************************************/

typedef enum type_people {
    HOSPEDE, EMPREGADO
} TYPE_PEOPLE;

typedef enum master_event {
    OCUPADO, LIMPEZA, MANUTENCAO, FATURACAO, GREACAO_DE_RELATORIOS
} TYPE_MASTER_EVENT;
typedef enum branch_event {
    RESERVADO, LIVRE
} TYPE_BRANCH_EVENT;

typedef enum type_studio {
    T1, T2, T3D, SUITE, SUITEPRESIDENCIAL
} TYPE_STUDIO;

typedef enum platform {
    AirBnc, AisBnD, AisBnE, AIRPlaces
} PLATFORM;


/**************************************
************ STRUCTURES **************
**************************************/


typedef struct date {
    unsigned short min;
    unsigned short hour;
    unsigned short day;
    unsigned short month;
    unsigned short Year;
} DATE;

typedef struct gps {
    char *latitude;
    char *longitude;
} GPS;

typedef struct location {
    char *address;
    GPS gps;
} LOCATION;

typedef struct people {
    unsigned id;
    char *nome;
    TYPE_PEOPLE typePeople;
} PEOPLE;

typedef struct price {
    //ver regras
} PRICE;

typedef struct master_events {
    PLATFORM platform;
    PEOPLE people;
    unsigned duration;
    PRICE price;
    TYPE_MASTER_EVENT mevent;
    struct master_events *pnext;
} MASTER_EVENTS;

typedef struct branch_events {
    PEOPLE people;
    unsigned duration;
    PRICE price;
    TYPE_MASTER_EVENT bevent;
    struct branch_eventos *pnext;
} BRANCH_EVENTS;

typedef struct master_calendar {
    DATE date;
    MASTER_EVENTS *master_event;
} MASTER_CALENDAR;

typedef struct branch_calendar {
    DATE date;
    PLATFORM platform;
    BRANCH_EVENTS *branch_event;
} BRANCH_CALENDAR;

typedef struct studios {
    TYPE_STUDIO typeStudio;
    unsigned short capacity;
    unsigned short num_door;
    unsigned int number_branch;
    unsigned int sizeArrayBranch;
    unsigned int sizeArrayMaster;
    unsigned int number_master;
    BRANCH_CALENDAR *branch_calendar;
    MASTER_CALENDAR *master_calendar;
} STUDIOS;

typedef struct buildings {
    char *name;
    LOCATION location;
    unsigned int num_studios;
   unsigned int sizeArray;
    STUDIOS *studios;
    struct buildings *next;
} BUILDINGS;


typedef struct history {
    PEOPLE *people;
    MASTER_EVENTS *events;
} HISTORY;


/**************************************
************ INCLUDES *****************
**************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include "../components/people/people.h"
#include "../components/enum/enum.h"
#include "../components/date/date.h"
#include"../components/location/location.h"
#include "../components/branch_events/branch_events.h"
#include "../components/master_calendar/master_calendar.h"
#include "../components/branch_calendar/branch_calendar.h"
#include "../components/studios/studios.h"
#include"../components/buildings/buildings.h"


#endif //GESTOR_ALOJAMENTOS_STRUCTURES_H