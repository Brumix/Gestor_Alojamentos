//
// Created by Bruno Miguel on 18/11/2020.
//

#include "buildings.h"

void add_building(BUILDINGS **head, char *name, LOCATION location) {
    BUILDINGS *current = *head;
    BUILDINGS *temp = create_building(name, location);
    if (current == NULL) {
        *head = temp;
        return;
    }
    if (strcmp(current->name, name) == 0) {
        printf("[EDIFICIO EXISTENTE]\n");
        return;
    }
    if (strcmp(current->name, name) == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }
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
    }


}

BUILDINGS *create_building(char *name, LOCATION location) {

    BUILDINGS *temp = (BUILDINGS *) malloc(sizeof(BUILDINGS));
    if (temp == NULL) {
        perror("[CREATE EDIFICIO]");
        exit(EXIT_FAILURE);
    }
    temp->name = name;
    temp->location = location;
    temp->studios = (STUDIOS *) malloc(INICIAL * sizeof(STUDIOS));
    temp->num_studios = 0;
    temp->sizeArray = INICIAL;
    temp->next = NULL;
    return temp;
}

void print_building_all(BUILDINGS *head) {
    BUILDINGS *curent = head;
    printf("EDIFICIOS\n");
    while (curent != NULL) {
        printf("NOME: %s\n", curent->name);
        printf("NUMERO DE ESTUDIOS: %i\n", curent->num_studios);
        print_location(curent->location);
        curent = curent->next;
    }

}


short int find_hotel(BUILDINGS *head, char *name) {
    BUILDINGS *current;
    current = head;
    while (current != NULL) {

        if (strcmp(current->name, name) == 0)
            return 1;
        if (current->next == NULL)
            return 0;
        current = current->next;
    }
    return 0;
}

