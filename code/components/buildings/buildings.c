//
// Created by Bruno Miguel on 18/11/2020.
//

#include "buildings.h"


void add_building(BUILDINGS **head, char *name, LOCATION *location) {
    if (find_hotel(*head, name) == 1) {
        printf("[AVISO]:EDIFICIO EXISTENTE: %s\n", name);
        return;
    }
    BUILDINGS *temp = (BUILDINGS *) malloc(sizeof(BUILDINGS));
    if (temp == NULL) {
        perror("[ADD EDIFICIO]");
        exit(-1);
    }
    temp->name = name;
    temp->location = location;
    temp->studios = (STUDIOS *) malloc(INICIAL * sizeof(STUDIOS));
    temp->next = *head;
    *head = temp;
}

void print_building_all(BUILDINGS *head) {
    BUILDINGS *curent;
    curent = head;
    printf("EDIFICIOS\n");
    while (curent != NULL) {
        printf("%s\n", curent->name);
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

}

