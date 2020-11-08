//
// Created by Bruno Miguel on 06/11/2020.
//

#include "estudios.h"

unsigned int Total_estudios = INICIAL;


void add_estudio(ANDARES *andar,int capacidade){
    resize_estudios(andar);
     ESTUDIOS *temp= ( ESTUDIOS *) malloc(sizeof(ESTUDIOS));
     temp->capacidade=capacidade;
     andar->estudio[andar->num_estudios]=*temp;
     andar->num_estudios++;
}

void print_estudios(ANDARES *andar){
    printf("\n\t\tEstudios:%d\n",andar->num_estudios);
    for (int i = 0; i < andar->num_estudios; i++) {
        printf("%d",andar->estudio[i].capacidade);
    }
    printf("\n");
}

void resize_estudios(ANDARES *andar) {
    if (andar->num_estudios >= (unsigned int) Total_estudios * 0.8) {
        Total_estudios *= 2;
        andar->estudio = (ESTUDIOS *) realloc(andar->estudio, Total_estudios * sizeof(ESTUDIOS));
        if (andar->estudio == NULL) {
            perror("[REALLOC ESTUDIOS]");
            exit(-1);
        }

    }
}