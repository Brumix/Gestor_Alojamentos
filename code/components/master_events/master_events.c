//
// Created by Bruno Miguel on 22/11/2020.
//

#include "master_events.h"


void add_master_event(MASTER_EVENTS **pMasterEvents, PLATFORM platform, PEOPLE people, unsigned duration, float price,
                      TYPE_MASTER_EVENT masterEvent) {
    MASTER_EVENTS *temp = (MASTER_EVENTS *) malloc(sizeof(MASTER_EVENTS));
    if (temp == NULL) {
        perror("[ADD MASTER EVENT]");
        exit(-1);
    }
    temp->platform = platform;
    temp->people = people;
    temp->duration = duration;
    temp->price = price;
    temp->mevent = masterEvent;
    temp->next = *pMasterEvents;
    *pMasterEvents = temp;
}


void print_master_events(MASTER_EVENTS *masterEvents) {
    MASTER_EVENTS *curent = masterEvents;
    printf("MASTER EVENTS\n");
    while (curent != NULL) {
        printf("PLATAFORMA:%s\n", strPlatform(curent->platform));
        print_people(curent->people);
        printf("DURACAO: %u\n", curent->duration);
        printf("PRECO: %.2f\n", curent->price);
        printf("TIPO DO EVENTO: %s\n", strMasterEvent(curent->mevent));
        curent = curent->next;
    }
}