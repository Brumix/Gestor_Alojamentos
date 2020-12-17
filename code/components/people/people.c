//
// Created by Bruno Miguel on 21/11/2020.
//

#include "people.h"

unsigned idPessoa = 1;

/**
 * cria um pessoa
 * @param id id da pessoa
 * @param nome  nome da pessoa
 * @param typePeople  tipo de pesso
 * @return pessoa
 */
PEOPLE add_people(char *nome, TYPE_PEOPLE typePeople) {
    PEOPLE people;
    people.name = nome;
    people.id = idPessoa;
    idPessoa++;
    people.typePeople = typePeople;
    return people;
}

/**
 * imprime uma pessoa
 * @param people pessoa
 */
void print_people(PEOPLE people) {
    printf("PESSOA\n");
    printf("ID: %u\n", people.id);
    printf("NOME: %s\n", people.name);
    printf("TIPO DE PESSOA: %s\n", strTypePeople(people.typePeople));
}