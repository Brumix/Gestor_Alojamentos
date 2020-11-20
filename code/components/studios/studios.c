//
// Created by Bruno Miguel on 19/11/2020.
//

#include "studios.h"



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
    temp->sizeArrayBranch=INICIAL;
    temp->sizeArrayMaster=INICIAL;
    temp->number_branch=0;
    temp->number_master=0;
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
    if (head->sizeArray <= head->num_studios * 0.8) {
        head->sizeArray *= 2;
        head->studios = realloc(head->studios, head->sizeArray);
        if (head->studios == NULL) {
            perror("[REALLOC STUDIOS]");
            exit(-1);
        }
    }

}


