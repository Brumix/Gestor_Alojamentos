//
// Created by Bruno Miguel on 18/11/2020.
//

#include "edificios.h"


void add_edificio(EDIFICIOS **head, char *nome, LOCALIZACAO *localizacao) {
    if (find_hotel(*head, nome) == 1) {
        printf("[AVISO]:EDIFICIO EXISTENTE: %s\n", nome);
        return;
    }
    EDIFICIOS *temp = (EDIFICIOS *) malloc(sizeof(EDIFICIOS));
    if (temp == NULL) {
        perror("[ADD EDIFICIO]");
        exit(-1);
    }
    temp->nome = nome;
    temp->localizacao = localizacao;
    temp->estudios = (ESTUDIOS *) malloc(INICIAL * sizeof(ESTUDIOS));
    temp->next = *head;
    *head = temp;
}

void print_edificios_all(EDIFICIOS *head) {
    EDIFICIOS *curent;
    curent = head;
    printf("EDIFICIOS\n");
    while (curent != NULL) {
        printf("%s\n", curent->nome);
        print_localizacao(curent->localizacao);
        curent = curent->next;
    }

}


short int find_hotel(EDIFICIOS *head, char *nome) {
    EDIFICIOS *current;
    current = head;
    while (current != NULL) {

        if (strcmp(current->nome, nome) == 0)
            return 1;
        if (current->next == NULL)
            return 0;
        current = current->next;
    }

}

