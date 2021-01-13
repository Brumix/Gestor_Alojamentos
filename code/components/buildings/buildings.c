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
void add_building(BUILDINGS **head, unsigned index, char *name, float price, LOCATION location) {
    BUILDINGS *current = *head;
    BUILDINGS *temp = create_building(index, name, price, location);
    if (current == NULL) {
        *head = temp;
        return;
    }
    EXISTENTE(strcmp(current->name, temp->name) == 0, "[EDIFICIO EXISTENTE]");

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
BUILDINGS *create_building(unsigned index, char *name, float price, LOCATION location) {

    BUILDINGS *temp = (BUILDINGS *) malloc(sizeof(BUILDINGS));
    ERRORMESSAGE(temp == NULL, "[CREATE EDIFICIO]");
    temp->index = index;
    temp->name = malloc(25 * sizeof(char *));
    strcpy(temp->name, name);
    temp->price_day = price;
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
    printf("INDEX: %u\n", current->index);
    printf("NOME: %s\n", current->name);
    printf("NUMERO DE ESTUDIOS: %i\n", current->num_studios);
    printf("PRECO POR DIA: %.2f\n", current->price_day);
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
BUILDINGS *find_building(BUILDINGS *head, int index) {
    BUILDINGS *current;
    current = head;
    while (current != NULL) {

        if (current->index==index)
            return current;
        if (current->next == NULL)
            return NULL;
        current = current->next;
    }
    return NULL;
}

BUILDINGS *find_building_by_name(BUILDINGS *head, char *name) {
    BUILDINGS *current;
    current = head;
    while (current != NULL) {

        if (strcmp(current->name,name)==0)
            return current;
        if (current->next == NULL)
            return NULL;
        current = current->next;
    }
    return NULL;
}

void update_building(BUILDINGS* buildings,char *name,char *new){
    BUILDINGS *current=buildings;
    while (current!=NULL){
        if(strcmp(current->name,name)==0)
            strcpy(current->name,new);

        current=current->next;
    }


}