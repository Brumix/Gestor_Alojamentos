//
// Created by Bruno Miguel on 19/11/2020.
//

#include "studios.h"

int sizeStudio = INICIAL;

void add_studio(BUILDINGS *buildings, TYPE_STUDIO typeStudio, unsigned short cap, unsigned short door) {
    resizeStudios(buildings);
    STUDIOS *temp = (STUDIOS *) malloc(sizeof(STUDIOS));
    if (temp == NULL) {
        perror("[ADD STUDIOS]");
        exit(-1);
    }
    temp->typeStudio = typeStudio;
    temp->num_door = door;
    temp->capacity = cap;
    temp->master_calendar = (MASTER_CALENDAR *) malloc(INICIAL * sizeof(MASTER_CALENDAR));
    temp->branch_calendar = (BRANCH_CALENDAR *) malloc(INICIAL * sizeof(BRANCH_CALENDAR));
    buildings->studios[buildings->num_studios] = *temp;
    buildings->num_studios++;
}

void print_studio_all(BUILDINGS *buildings) {
    BUILDINGS *current = buildings;
    printf("ESTUDIOS\n");
    for (int i = 0; i < current->num_studios; i++) {
        STUDIOS *studio = &current->studios[i];
        printf("TIPO DE ESTUDIO %s\n", strTypeStudio(studio->typeStudio));
        printf("PORTA %i\n", studio->num_door);
        printf("CAPACIDADE %i \n", studio->capacity);
    }

}

void resizeStudios(BUILDINGS *head) {
    if (sizeStudio <= head->num_studios * 0.8) {
        sizeStudio *= 2;
        head->studios = realloc(head->studios, sizeStudio);
        if (head->studios == NULL) {
            perror("[REALLOC STUDIOS]");
            exit(-1);
        }
    }

}


char *strTypeStudio(TYPE_STUDIO ts) {
    switch (ts) {
        case T1:
            return "T1";
        case T2:
            return "T2";
        case T3D:
            return "T3D";
        case SUITE:
            return "SUITE";
        case SUITEPRESIDENCIAL:
            return "SUITEPRESIDENCIAL";
        default:
            return "Nao existente";
    }
}