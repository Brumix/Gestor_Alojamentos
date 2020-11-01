//
// Created by Bruno Miguel on 01/11/2020.
//

#include "edificio.h"


void add_edificio(EDIFICIOS **head, char *nome, LOCALIZACAO *localizacao) {

    EDIFICIOS *temp = (EDIFICIOS *) malloc(sizeof(EDIFICIOS));
    temp->num_andares = 0;
    temp->nome = nome;
    temp->andar = malloc(ANDARESINICIAL * sizeof(ANDARES));
    temp->localizacao = localizacao;
    temp->next = *head;
    *head = temp;
}

void print_edificios(EDIFICIOS **head) {
    EDIFICIOS *curent;
    curent = *head;
    while (curent != NULL) {
        printf("%s\n", curent->nome);
        printf("\t loc:%s  %s  %d\n", curent->localizacao->cidade, curent->localizacao->rua,
               curent->localizacao->num_porta);
        curent = curent->next;
    }

}

LOCALIZACAO *addlocalizacao(char *cidade, char *rua, int porta) {
    LOCALIZACAO *temp = (LOCALIZACAO *) malloc(sizeof(LOCALIZACAO));
    temp->cidade = cidade;
    temp->num_porta = porta;
    temp->rua = rua;
    return temp;
}

