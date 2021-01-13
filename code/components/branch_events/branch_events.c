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
void add_branch_event(BUILDINGS *buildings, BRANCH_EVENTS **head, unsigned id, DATE date_inicio, DATE date_fim,
                      TYPE_BRANCH_EVENT branchEvent, PEOPLE *pPeople) {
    BRANCH_EVENTS *current = *head;
    BRANCH_EVENTS *temp = create_branch_event(id, date_inicio, date_fim, branchEvent, pPeople);

    if (current == NULL) {
        *head = temp;
        (*head)->price = calculate_event_price(buildings, id);
        return;
    }
    EXISTENTE(compare_date(current->date_begin, date_inicio) == 0, "[BRANCH EVENT EXISTENTE]");
    if (compare_date(current->date_begin, date_inicio) == 1) {
        temp->next = *head;
        *head = temp;
        (*head)->price = calculate_event_price(buildings, id);
        return;
    }
    while (current != NULL) {
        if (current->next == NULL) {
            current->next = temp;
            current->next->price = calculate_event_price(buildings, id);
            return;
        }
        EXISTENTE(compare_date(current->next->date_begin, date_inicio) == 0, "[BRANCH EVENT EXISTENTE]");

        if (compare_date(current->next->date_begin, date_inicio) == 1) {
            temp->next = current->next;
            current->next = temp;
            current->next->price = calculate_event_price(buildings, id);
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
void delete_branch_event(MASTER_EVENTS ** masterEvents,BRANCH_EVENTS **head,PLATFORM platform,DATE date) {
    BRANCH_EVENTS *current = *head;
    EXISTENTE(current == NULL, "[BRANCH EVENT NAO ENCONTRADO]");
    if (compare_date(current->date_begin, date) == 0) {
        *head = current->next;
        delete_master_event(masterEvents,date,platform);
        return;
    }
    EXISTENTE(current->next == NULL, "[BRANCH EVENT NAO ENCONTRADO]");
    while (current != NULL) {
        if (compare_date(current->next->date_begin, date) == 0) {
            current->next = current->next->next;
            delete_master_event(masterEvents,date,platform);
            return;
        }
        EXISTENTE(current->next->next == NULL, "[BRANCH EVENT NAO ENCONTRADO]");

        current = current->next;
    }
}


void delete_branch_event_only(BRANCH_EVENTS **head,DATE date) {
    BRANCH_EVENTS *current = *head;
    if (compare_date(current->date_begin, date) == 0) {
        *head = current->next;
        return;
    }
    EXISTENTE(current->next == NULL, "[BRANCH EVENT NAO ENCONTRADO]");
    while (current != NULL) {
        if (compare_date(current->next->date_begin, date) == 0) {
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
BRANCH_EVENTS *create_branch_event(unsigned id, DATE date_inicio, DATE date_fim,
                                   TYPE_BRANCH_EVENT branchEvent, PEOPLE *people) {
    BRANCH_EVENTS *temp = (BRANCH_EVENTS *) malloc(sizeof(BRANCH_EVENTS));
    ERRORMESSAGE(temp == NULL, "[CREATE BRANCH EVENT]");

    temp->id = id;
    temp->people = people;
    temp->price = 0.0f;
    temp->date_begin = date_inicio;
    temp->date_end = date_fim;
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
        printf("ID:%i\n", current->id);
        printf("PRECO: %.2f\n", current->price);
        printf("TIPO DO EVENTO: %s\n", strTypeBranchEvent(current->bevent));
       // print_people(current->people);
        print_date(current->date_begin);
        print_date(current->date_end);
        current = current->next;
    }
}
void print_branch_event(BRANCH_EVENTS *branchEvents) {
    BRANCH_EVENTS *current = branchEvents;
    EXISTENTE(current == NULL, "[NAO EXISTE NENHUM BRANCH EVENT]");

        printf("ID:%i\n", current->id);
        printf("PRECO: %.2f\n", current->price);
        printf("TIPO DO EVENTO: %s\n", strTypeBranchEvent(current->bevent));
        print_date(current->date_begin);
        print_date(current->date_end);
        current = current->next;
    }

void clean_branch_event( BRANCH_CALENDAR * branchCalendar,int size){
    for (int i = 0; i < size;++i)
        branchCalendar[i].branch_event=NULL;

}

BRANCH_EVENTS * find_branch_event(BRANCH_CALENDAR* branchCalendar,DATE begin){
    BRANCH_EVENTS *branchEvents=branchCalendar->branch_event;
    while (branchEvents!=NULL){
        if (compare_date(branchEvents->date_begin,begin)==0)
            return branchEvents;
        branchEvents=branchEvents->next;
    }
    return NULL;
}

void update_branch_event(BRANCH_EVENTS* branchEvents,DATE begin,float price){
    BRANCH_EVENTS *curent=branchEvents;
    while (curent!=NULL){
        if(compare_date(curent->date_begin,begin)==0) {
            curent->price = price;
            return;
        }
        curent=curent->next;
    }



}