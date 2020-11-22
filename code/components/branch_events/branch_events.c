//
// Created by Bruno Miguel on 21/11/2020.
//

#include "branch_events.h"


void add_branch_event(BRANCH_EVENTS **pBranchEvents, PEOPLE people, unsigned duration, float price,
                      TYPE_BRANCH_EVENT branchEvent) {
    BRANCH_EVENTS *temp = (BRANCH_EVENTS *) malloc(sizeof(BRANCH_EVENTS));
    if (temp == NULL) {
        perror("[ADD BRANCH EVENT]");
        exit(-1);
    }
    temp->people = people;
    temp->duration = duration;
    temp->price = price;
    temp->bevent = branchEvent;
    temp->next = *pBranchEvents;
    *pBranchEvents = temp;
}

void print_branch_events(BRANCH_EVENTS *branchEvents) {
    BRANCH_EVENTS *curent = branchEvents;
    printf("BRANCH EVENTS\n");
    while (curent != NULL) {
        print_people(curent->people);
        printf("DURACAO: %u\n", curent->duration);
        printf("PRECO: %.2f\n", curent->price);
        printf("TIPO DO EVENTO: %s\n", strTypeBranchEvent(curent->bevent));
        curent = curent->next;
    }
}