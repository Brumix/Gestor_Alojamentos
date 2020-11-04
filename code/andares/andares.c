//
// Created by Bruno Miguel on 01/11/2020.
//

#include "andares.h"

void addandar(EDIFICIOS *head, int val, int pos) {

    struct andares temp = *(ANDARES *) malloc(sizeof(ANDARES));
    temp.num_estudios = val;
    head->andar[pos] = temp;
    head->num_andares++;
}

void printandar(EDIFICIOS *head){
printf("\tANDARES:");
    for (int i = 0; i < head->num_andares; i++) {
        printf("%d ",head->andar[i].num_estudios);
    }
    printf("\n");
}