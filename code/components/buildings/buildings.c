//
// Created by Bruno Miguel on 18/11/2020.
//

#include "buildings.h"


/**
 * adiciona um edificio
 * @param head lista ligada dos edificios
 * @param name nome do edificio
 * @param location  localizacao do edificio
 */
void add_building(BUILDINGS **head, char *name, LOCATION location) {
    BUILDINGS *current = *head;
    BUILDINGS *temp = create_building(name, location);
    if (current == NULL) {
        *head = temp;
        return;
    }
    EXISTENTE(strcmp(current->name, name) == 0, "[EDIFICIO EXISTENTE]");

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
        EXISTENTE(strcmp(current->next->name, name) == 0, "[EDIFICIO EXISTENTE]");

        if (strcmp(current->next->name, name) == 1) {
            temp->next = current->next;
            current->next = temp;
            return;
        }
        current = current->next;
    }
}

/**
 * apaga um edificio
 * @param head lista ligada dos edificios
 * @param name nome do edificio que quer apagar
 */
void delete_building(BUILDINGS **head, char *name) {
    BUILDINGS *current = *head;
    if (strcmp(current->name, name) == 0) {
        *head = current->next;
        return;
    }
    while (current != NULL) {
        if (strcmp(current->next->name, name) == 0) {
            current->next = current->next->next;
            return;
        }
        EXISTENTE(current->next->next == NULL, "[EDIFICIO NAO ENCONTRADO]");

        current = current->next;
    }
}

/**
 * cria um edifico
 * @param name  nome do edifico quie quer ligar
 * @param location localizacao do edifico ligado
 * @return  um edificio
 */
BUILDINGS *create_building(char *name, LOCATION location) {

    BUILDINGS *temp = (BUILDINGS *) malloc(sizeof(BUILDINGS));
    ERRORMESSAGE(temp == NULL, "[CREATE EDIFICIO]");

    temp->name = name;
    temp->location = location;
    temp->studios = (STUDIOS *) malloc(INICIAL * sizeof(STUDIOS));
    temp->num_studios = 0;
    temp->sizeArray = INICIAL;
    temp->next = NULL;
    return temp;
}


/**
 * imprime uma lista ligada de um edifico
 * @param head  cabeca da lista ligada
 */
void print_building_all(BUILDINGS *head) {
    BUILDINGS *current = head;
    EXISTENTE(current == NULL, "[NAO EXISTE NENHUM EDIFICIO]");

    printf("EDIFICIOS\n");
    while (current != NULL) {
        printf("NOME: %s\n", current->name);
        printf("NUMERO DE ESTUDIOS: %i\n", current->num_studios);
        print_location(current->location);
        current = current->next;
    }

}


/**
 * identifica se existe ou nao um dado edificio
 * @param head cabeca da lista ligada dos edificios
 * @param name  nome do edificios
 * @return 1(encontrou) ou 0(nao encontrou)
 */
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

