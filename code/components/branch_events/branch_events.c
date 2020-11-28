//
// Created by Bruno Miguel on 21/11/2020.
//

#include "branch_events.h"


void add_branch_event(BRANCH_EVENTS **head, PEOPLE people, DATE date, unsigned duration, float price,
                      TYPE_BRANCH_EVENT branchEvent) {
    BRANCH_EVENTS *current = *head;
    BRANCH_EVENTS *temp = create_branch_event(people, date, duration, price, branchEvent);

    if (current == NULL) {
        *head = temp;
        return;
    }
    if (compare_date(current->date, date) == 0) {
        printf("[BRANCH EVENT EXISTENTE]\n");
        return;
    }
    if (compare_date(current->date, date) == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }
    while (current != NULL) {
        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        if (compare_date(current->next->date, date) == 0) {
            printf("[BRANCH EVENT EXISTENTE]\n");
            return;
        }
        if (compare_date(current->next->date, date) == 1) {
            temp->next = current->next;
            current->next = temp;
            return;
        }
        current = current->next;
    }
}


void delete_branch_event(BRANCH_EVENTS **head, DATE date) {
    BRANCH_EVENTS *current = *head;

    if (compare_date(current->date, date) == 0) {
        *head = current->next;
        return;
    }
    while (current != NULL) {
        if (compare_date(current->next->date, date) == 0) {
            current->next = current->next->next;
            return;
        }
        if (current->next->next == NULL) {
            printf("[BRANCH EVENT NAO ENCONTRADO]\n");
            return;
        }
        current = current->next;
    }
}


BRANCH_EVENTS *create_branch_event(PEOPLE people, DATE date, unsigned duration, float price,
                                   TYPE_BRANCH_EVENT branchEvent) {
    BRANCH_EVENTS *temp = (BRANCH_EVENTS *) malloc(sizeof(BRANCH_EVENTS));
    if (temp == NULL) {
        perror("[CREATE BRANCH EVENT]");
        exit(EXIT_FAILURE);
    }
    temp->people = people;
    temp->date = date;
    temp->duration = duration;
    temp->price = price;
    temp->bevent = branchEvent;
    temp->next = NULL;
    return temp;

}

void print_branch_events(BRANCH_EVENTS *branchEvents) {
    BRANCH_EVENTS *current = branchEvents;
    if (current == NULL) {
        printf("[NAO EXISTE NENHUM BRANCH EVENT]\n");
        return;
    }
    printf("BRANCH EVENTS\n");
    while (current != NULL) {
        print_people(current->people);
        print_date(current->date);
        printf("DURACAO: %u\n", current->duration);
        printf("PRECO: %.2f\n", current->price);
        printf("TIPO DO EVENTO: %s\n", strTypeBranchEvent(current->bevent));
        current = current->next;
    }
}