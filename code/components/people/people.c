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
void add_people(PEOPLE **people, char *name, TYPE_PEOPLE typePeople) {
    PEOPLE *current = *people;
    PEOPLE *temp = create_people(name, typePeople);
    if (current == NULL) {
        *people = temp;
        return;
    }
    while (current->next!=NULL)
        current=current->next;

    current->next=temp;
}

/**
 * imprime uma pessoa
 * @param people pessoa
 */
void print_people(PEOPLE *people) {
    printf("PESSOA\n");
    printf("ID: %u\n", people->id);
    printf("NOME: %s\n", people->name);
    printf("TIPO DE PESSOA: %s\n", strTypePeople(people->typePeople));
}

/**
 * cria um pessoa
 * @param name
 * @param typePeople
 * @return
 */
PEOPLE* create_people(char *name, TYPE_PEOPLE typePeople) {
    PEOPLE *people=(PEOPLE*)malloc(sizeof (PEOPLE));
    people->id=idPessoa;
    idPessoa++;
    people->typePeople = typePeople;
    people->name=malloc(4* sizeof(char* ));
    strcpy(people->name,name);
    people->next=NULL;
    return people;
}

/**
 * imprime todas as pessoas
 * @param people struct people
 */
void print_all_people(PEOPLE *people){
    PEOPLE *current=people;
    while (current!=NULL){
        print_people(current);
        current=current->next;
    }
}

/**
 * encontrar uma pessoa
 * @param people struct people
 * @param id id da pessoa á procura
 * @return PEOPLE *
 */
PEOPLE * find_people(PEOPLE *people,unsigned id){
    PEOPLE *current=people;

    while (current!=NULL){
        if(current->id==id)
            return current;

        current=current->next;
    }
    return NULL;
}
