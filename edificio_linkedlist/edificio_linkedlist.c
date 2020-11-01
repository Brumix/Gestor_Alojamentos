//
// Created by Bruno Miguel on 01/11/2020.
//

#include "edificio_linkedlist.h"


void add_edificio(EDIFICIOS *head, char *nome) {

    EDIFICIOS *temp ;
    temp = (EDIFICIOS *) malloc(sizeof(EDIFICIOS));
    temp->num_andares = 0;
    temp->nome = nome;
    temp->andar = malloc(ANDARESINICIAL * sizeof(ANDARES));
    temp->next = head;
    head=temp;
}

void print_edificios(EDIFICIOS *head) {
    EDIFICIOS *curent;
    curent = head;
    while (curent != NULL) {
        if (curent->next == NULL)
            printf("%s\n", curent->nome);
        else
            printf("%s-", curent->nome);
        curent = curent->next;
    }

}