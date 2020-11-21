//
// Created by Bruno Miguel on 21/11/2020.
//

#include "people.h"


PEOPLE add_people(unsigned id, char *nome, TYPE_PEOPLE typePeople) {
    PEOPLE people;
    people.nome = nome;
    people.id = id;
    people.typePeople = typePeople;

    return people;
}

void print_people(PEOPLE people) {
    printf("PEOPLE\n");
    printf("ID: %u\n", people.id);
    printf("NOME: %s\n", people.nome);
    printf("TYPE PEOPLE: %s\n", strTypePeople(people.typePeople));
}