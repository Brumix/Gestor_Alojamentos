//
// Created by Bruno Miguel on 21/11/2020.
//

#include "people.h"


PEOPLE add_people(unsigned id, char *nome, TYPE_PEOPLE typePeople) {
    PEOPLE people;
    people.name = nome;
    people.id = id;
    people.typePeople = typePeople;

    return people;
}

void print_people(PEOPLE people) {
    printf("PESSOA\n");
    printf("ID: %u\n", people.id);
    printf("NOME: %s\n", people.name);
    printf("TIPO DE PESSOA: %s\n", strTypePeople(people.typePeople));
}