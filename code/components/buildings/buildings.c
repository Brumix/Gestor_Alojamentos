//
// Created by Bruno Miguel on 18/11/2020.
//

#include "buildings.h"


void add_building(BUILDINGS **head, char *name, LOCATION location) {
    if (find_hotel(*head, name) == 1) {
        printf("[AVISO]:EDIFICIO EXISTENTE: %s\n", name);
        return;
    }
    BUILDINGS *temp = (BUILDINGS *) malloc(sizeof(BUILDINGS));
    if (temp == NULL) {
        perror("[ADD EDIFICIO]");
        exit(EXIT_FAILURE);
    }
    temp->name = name;
    temp->location = location;
    temp->studios = (STUDIOS *) malloc(INICIAL * sizeof(STUDIOS));
    temp->num_studios = 0;
    temp->sizeArray=INICIAL;
    temp->next = *head;
    *head = temp;
}

void print_building_all(BUILDINGS *head) {
    BUILDINGS *curent = head;
    printf("EDIFICIOS\n");
    while (curent != NULL) {
        printf("NOME: %s\n", curent->name);
        printf("NUMERO DE ESTUDIOS: %i\n", curent->num_studios);
        print_location(curent->location);
        print_studio_all(curent);
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

