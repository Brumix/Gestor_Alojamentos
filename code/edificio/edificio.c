//
// Created by Bruno Miguel on 01/11/2020.
//

#include "edificio.h"


void add_edificio(EDIFICIOS **head, char *nome, LOCALIZACAO *localizacao) {
    if (find_hotel(*head,nome) == 1)
        return;
    EDIFICIOS *temp = (EDIFICIOS *) malloc(sizeof(EDIFICIOS));
    if (temp == NULL) {
        perror("[ADD EDIFICIO]");
        exit(-1);
    }
    temp->num_andares = 0;
    temp->nome = nome;
    temp->andar = malloc(INICIAL * sizeof(ANDARES));
    if (temp->andar == NULL) {
        perror("[MALLOC TEMP->ANDAR]");
        exit(-1);
    }
    temp->localizacao = localizacao;
    temp->next = *head;
    *head = temp;
}

void print_edificios(EDIFICIOS *head) {
    EDIFICIOS *curent;
    curent = head;
    while (curent != NULL) {
        printf("%s\n", curent->nome);
        printf("\tLOCALIZACAO:%s  %s  %d\n", curent->localizacao->cidade, curent->localizacao->rua,
               curent->localizacao->num_porta);
        print_andar(curent);
        curent = curent->next;
    }

}

LOCALIZACAO *add_localizacao(char *cidade, char *rua, int porta) {
    LOCALIZACAO *temp = (LOCALIZACAO *) malloc(sizeof(LOCALIZACAO));
    temp->cidade = cidade;
    temp->num_porta = porta;
    temp->rua = rua;
    return temp;
}

short int find_hotel(EDIFICIOS *head,char * nome){
    EDIFICIOS  *current;
    current=head;
    while (current != NULL) {

        if (strcmp(current->nome, nome) == 0) {
            printf("[AVISO]:EDIFICIO EXISTENTE: %s\n",nome);
            return 1;
        }
        if(current->next== NULL)
            return 0;
        current= current->next;
    }

}

