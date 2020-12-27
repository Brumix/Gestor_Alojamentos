//
// Created by Bruno Miguel on 21/11/2020.
//

#include "branch_events.h"

/**
 *  adiciona um branch evento
 * @param head  lista ligada de um branch event
 * @param people pessoa a qual realizou o evento
 * @param date  data do evento
 * @param duration  duracao do evento
 * @param price  custo do evento
 * @param branchEvent  tipo de evento
 */
void add_branch_event(BRANCH_EVENTS **head, int people, DATE date_inicio, DATE date_fim, float price,
                      TYPE_BRANCH_EVENT branchEvent,PEOPLE *pPeople) {
    BRANCH_EVENTS *current = *head;
    EXISTENTE(find_people(pPeople,people)==NULL,"[PESSOA INEXISTENTE]");
    BRANCH_EVENTS *temp = create_branch_event(people, date_inicio,date_fim, price, branchEvent);

    if (current == NULL) {
        *head = temp;
        return;
    }
    EXISTENTE(compare_date(current->date_inicio, date_inicio) == 0, "[BRANCH EVENT EXISTENTE]");
    if (compare_date(current->date_inicio, date_inicio) == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }
    while (current != NULL) {
        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        EXISTENTE(compare_date(current->next->date_inicio, date_inicio) == 0, "[BRANCH EVENT EXISTENTE]");

        if (compare_date(current->next->date_inicio, date_inicio) == 1) {
            temp->next = current->next;
            current->next = temp;
            return;
        }
        current = current->next;
    }
}

/**
 * apaga um evento
 * @param head  lista ligada dos eventos
 * @param date  data do evento
 */
void delete_branch_event(BRANCH_EVENTS **head, DATE date) {
    BRANCH_EVENTS *current = *head;

    if (compare_date(current->date_inicio, date) == 0) {
        *head = current->next;
        return;
    }
    while (current != NULL) {
        if (compare_date(current->next->date_inicio, date) == 0) {
            current->next = current->next->next;
            return;
        }
        EXISTENTE(current->next->next == NULL, "[BRANCH EVENT NAO ENCONTRADO]");

        current = current->next;
    }
}

/**
 * criacao do evento
 * @param people  pessoa que realiza o evento
 * @param date data do evento
 * @param duration duracao do evento
 * @param price  preco do evento
 * @param branchEvent  tipo do evento
 * @return  retorma um evento BRANCH_EVENTS
 */
BRANCH_EVENTS *create_branch_event(unsigned people, DATE date_inicio, DATE date_fim, float price,
                                   TYPE_BRANCH_EVENT branchEvent) {
    BRANCH_EVENTS *temp = (BRANCH_EVENTS *) malloc(sizeof(BRANCH_EVENTS));
    ERRORMESSAGE(temp == NULL, "[CREATE BRANCH EVENT]");

    temp->people = people;
    temp->date_inicio = date_inicio;
    temp->date_fim = date_fim;
    temp->price = price;
    temp->bevent = branchEvent;
    temp->next = NULL;
    return temp;

}

/**
 * imprime o array dos evento de uma dada plataforma
 * @param branchEvents  lista ligada que quer imprimir
 */
void print_branch_events(BRANCH_EVENTS *branchEvents) {
    BRANCH_EVENTS *current = branchEvents;
    EXISTENTE(current == NULL, "[NAO EXISTE NENHUM BRANCH EVENT]");

    printf("BRANCH EVENTS\n");
    while (current != NULL) {
       // print_people(current->people);
       // print_date(current->date);
       // printf("DURACAO: %u\n", current->duration);
        printf("PRECO: %.2f\n", current->price);
        printf("TIPO DO EVENTO: %s\n", strTypeBranchEvent(current->bevent));
        current = current->next;
    }
}