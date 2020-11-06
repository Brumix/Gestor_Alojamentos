//
// Created by Bruno Miguel on 01/11/2020.
//

#include "andares.h"

unsigned int Total_andares = INICIAL;

void add_andar(EDIFICIOS *head,unsigned int andar) {
    resize_andares(head);
    ANDARES *temp = (ANDARES *) malloc(sizeof(ANDARES));
    temp->andar=andar;
    temp->num_estudios =0;
    head->andar[head->num_andares] = *temp;
    head->num_andares++;
    head->andar->estudio = (ESTUDIOS *) malloc(INICIAL * sizeof(ESTUDIOS));
}

void add_andar_hotel(char *nome, unsigned int val, EDIFICIOS *head) {
    EDIFICIOS *current;
    current = head;
    while (current != NULL) {

        if (strcmp(current->nome, nome) == 0) {
            add_andar(current, val);
            break;
        }
        if (current->next == NULL)
            printf("[AVISO]:EDIFICIO NAO ENCONTRADO: %s\n", nome);
        current = current->next;
    }

}

void print_andar(EDIFICIOS *head) {
    printf("\tANDARES:");
    for (int i = 0; i < head->num_andares; i++) {
        printf("\n\t%d ", head->andar[i].andar);
        print_estudios(&head->andar[i]);
    }
    printf("\n");
}

void resize_andares(EDIFICIOS *head) {
    if (head->num_andares >= (unsigned int) Total_andares * 0.8) {
        Total_andares *= 2;
        head->andar = (ANDARES *) realloc(head->andar, Total_andares * sizeof(ANDARES));
        if (head->andar == NULL) {
            perror("[REALLOC ANDARES]");
            exit(-1);
        }

    }
}


