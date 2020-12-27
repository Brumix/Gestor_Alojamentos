//
// Created by Bruno Miguel on 01/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_STRUCTURES_H
#define GESTOR_ALOJAMENTOS_STRUCTURES_H

/**************************************
************ CONSTANTS ***************
**************************************/

#define INICIAL 5
#define HASHSIZE 5

#define FILEBUILDINGS "C:\\Users\\Bruno Miguel\\CLionProjects\\Gestor_Alojamentos\\data\\edificios.csv"
#define FILESTUDIOS "C:\\Users\\Bruno Miguel\\CLionProjects\\Gestor_Alojamentos\\data\\estudios.csv"
#define FILEEVENTS  "C:\\Users\\Bruno Miguel\\CLionProjects\\Gestor_Alojamentos\\data\\eventos.csv"
#define FILEPOLITICS "C:\\Users\\Bruno Miguel\\CLionProjects\\Gestor_Alojamentos\\data\\politicas.csv"
#define FILESTUDIO_POLITICS "C:\\Users\\Bruno Miguel\\CLionProjects\\Gestor_Alojamentos\\data\\estudio_politicas.csv"

#define ERRORMESSAGE(ARGV, MSG)({if(ARGV){perror(MSG"\n");exit(EXIT_FAILURE);}})
#define EXISTENTE(ARGV, MSG)({if(ARGV){printf(MSG"\n");return;}})


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

typedef struct configuration{
    char *name;
    float value;
    struct configuration *next;
}CONFIGURATION;

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
    char *name;
    TYPE_PEOPLE typePeople;
    struct people *next;
} PEOPLE;

typedef struct holidays {
    char *nome;
    DATE *date;
} HOLIDAYS;

typedef struct price {
    char *type;
    float price;
} PRICE;

typedef struct master_events {
    PLATFORM platform;
    PEOPLE *people;
    float price;
    DATE date_begin;
    DATE date_end;
    TYPE_MASTER_EVENT typeMasterEvent;
    struct master_events *next;
} MASTER_EVENTS;

typedef struct branch_events {
    unsigned id;
    unsigned people;
    float price;
    DATE date_inicio;
    DATE date_fim;
    TYPE_BRANCH_EVENT bevent;
    struct branch_events *next;
} BRANCH_EVENTS;


typedef struct branch_calendar {
    PLATFORM platform;
    unsigned priority;
    char * politics;
    CONFIGURATION *configuration;
    BRANCH_EVENTS *branch_event;
} BRANCH_CALENDAR;

typedef struct studios {
    TYPE_STUDIO typeStudio;
    unsigned area;
    unsigned short capacity;
    unsigned short num_door;
    unsigned number_branch;
    unsigned sizeArrayBranch;
    BRANCH_CALENDAR *branch_calendar;
    MASTER_EVENTS *masterEvents;
} STUDIOS;

typedef struct buildings {
    unsigned index;
    char *name;
    LOCATION location;
    float price_day;
    unsigned short num_studios;
    unsigned sizeArray;
    STUDIOS *studios;
    struct buildings *next;
} BUILDINGS;

typedef struct hitory_events {
    PEOPLE *people;
    MASTER_EVENTS *events;
    struct hitory_events *next;
} HYSTORY_EVENTS;

typedef struct history {
    HYSTORY_EVENTS *hystoryEvents;
} HISTORY;


/**************************************
************ INCLUDES *****************
**************************************/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#include <fcntl.h>

#include "../components/price/price.h"
#include "../components/people/people.h"
#include "../components/enum/enum.h"
#include "../components/date/date.h"
#include "../components/holidays/holidays.h"
#include"../components/location/location.h"
#include "../components/branch_events/branch_events.h"
#include "../components/master_events/master_events.h"
#include "../components/branch_calendar/branch_calendar.h"
#include "../components/history/history.h"
#include "../components/studios/studios.h"
#include"../components/buildings/buildings.h"
#include "../components/files/write/write.h"
#include "../components/files/read/read.h"


#endif //GESTOR_ALOJAMENTOS_STRUCTURES_H