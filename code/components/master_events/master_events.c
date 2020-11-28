//
// Created by Bruno Miguel on 22/11/2020.
//

#include "master_events.h"


void add_master_event(MASTER_EVENTS **head, PLATFORM platform, PEOPLE people, unsigned duration, float price,
                      TYPE_MASTER_EVENT masterEvent, DATE date) {

    MASTER_EVENTS *temp = create_master_event(platform, people, duration, price, masterEvent, date);
    ordena_master_event(head, temp);
}

void delete_master_event(MASTER_EVENTS **head, DATE date) {
    MASTER_EVENTS *current = *head;

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
            printf("[MASTER EVENT NAO ENCONTRADO]\n");
            return;
        }
        current = current->next;
    }
}

MASTER_EVENTS *create_master_event(PLATFORM platform, PEOPLE people, unsigned duration, float price,
                                   TYPE_MASTER_EVENT masterEvent, DATE date) {
    MASTER_EVENTS *temp = (MASTER_EVENTS *) malloc(sizeof(MASTER_EVENTS));
    if (temp == NULL) {
        perror("[ADD MASTER EVENT]");
        exit(EXIT_FAILURE);
    }
    temp->platform = platform;
    temp->people = people;
    temp->duration = duration;
    temp->price = price;
    temp->typeMasterEvent = masterEvent;
    temp->date = date;
    temp->next = NULL;
    return temp;
}


void print_master_events(MASTER_EVENTS *masterEvents) {
    MASTER_EVENTS *curent = masterEvents;
    printf("MASTER EVENTS\n");
    while (curent != NULL) {
        printf("PLATAFORMA:%s\n", strPlatform(curent->platform));
        print_people(curent->people);
        print_date(curent->date);
        printf("DURACAO: %u\n", curent->duration);
        printf("PRECO: %.2f\n", curent->price);
        printf("TIPO DO EVENTO: %s\n", strMasterEvent(curent->typeMasterEvent));
        curent = curent->next;
    }

}

void ordena_master_event(MASTER_EVENTS **head, MASTER_EVENTS *temp) {
    MASTER_EVENTS *current = *head;
    if (current == NULL) {
        *head = temp;
        return;
    }
    if (compare_date(current->date, temp->date) == 0) {
        printf("[MASTER EVENT EXISTENTE]\n");
        return;
    }
    if (compare_date(current->date, temp->date) == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }
    while (current != NULL) {
        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        if (compare_date(current->next->date, temp->date) == 0) {
            printf("[MASTER EVENT EXISTENTE]\n");
            return;
        }
        if (compare_date(current->next->date, temp->date) == 1) {
            temp->next = current->next;
            current->next = temp;
            return;
        }
        current = current->next;
    }
}

