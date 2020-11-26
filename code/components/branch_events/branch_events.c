//
// Created by Bruno Miguel on 21/11/2020.
//

#include "branch_events.h"


void add_branch_event(BRANCH_EVENTS **head, PEOPLE people, unsigned duration, float price,
                      TYPE_BRANCH_EVENT branchEvent) {
    BRANCH_EVENTS *current = *head;
    BRANCH_EVENTS *temp = create_branch_event(people, duration, price, branchEvent);
    if (current == NULL) {
        *head = temp;
        return;
    }
    /* if (strcmp(current->name, name) == 0) {
         printf("[BRANCH EVENT]\n");
         return;
     }
     if (strcmp(current->name, name) == 1) {
         temp->next = *head;
         *head = temp;
         return;
     }
     if(current->next==NULL)
         printf("ola");
     while (current != NULL) {
         if (current->next == NULL) {
             current->next = temp;
             return;
         }
         if (strcmp(current->next->name, name) == 0) {
             printf("[EDIFICIO EXISTENTE]\n");
             return;
         }
         if (strcmp(current->next->name, name) == 1) {
             temp->next = current->next;
             current->next = temp;
             return;
         }

         current = current->next;
     }*/

}

BRANCH_EVENTS *create_branch_event(PEOPLE people, unsigned duration, float price,
                                   TYPE_BRANCH_EVENT branchEvent) {
    BRANCH_EVENTS *temp = (BRANCH_EVENTS *) malloc(sizeof(BRANCH_EVENTS));
    if (temp == NULL) {
        perror("[CREATE BRANCH EVENT]");
        exit(EXIT_FAILURE);
    }
    temp->people = people;
    temp->duration = duration;
    temp->price = price;
    temp->bevent = branchEvent;
    return temp;

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