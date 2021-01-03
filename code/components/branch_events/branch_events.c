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
    if (compare_date(current->date_begin, date) == 0) {
        *head = current->next;
        delete_master_event(masterEvents,date,platform);
        return;
    }
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

/**
 * calcula o preco do evvento
 * @param buildings struct edificios
 * @param id ip do evento a calcular
 * @return float
 */
float calculate_event_price(BUILDINGS *buildings, unsigned id) {
    BUILDINGS *building = buildings;
    float price = buildings->price_day;
    while (building != NULL) {
        STUDIOS *studios = building->studios;
        price *= (float) studios->area;
        for (int i = 0; i < building->num_studios; i++) {
            BRANCH_CALENDAR *branchCalendar = studios[i].branch_calendar;
            for (int j = 0; j < studios->number_branch; j++) {
                BRANCH_EVENTS *branchEvents = branchCalendar[j].branch_event;
                while (branchEvents != NULL) {

                    if (branchEvents->id == id) {
                        price *= (float) getDifferenceDays(branchEvents->date_begin, branchEvents->date_end);
                        return calculate_config_price(branchCalendar, price);
                    }
                    branchEvents = branchEvents->next;
                }
            }
        }
        building = building->next;
    }
    return -1;
}

/**
 * calcula o preco com base nas comfiguracoes
 * @param branchCalendar struct branch_calendar
 * @param price float preco
 * @return float
 */
float calculate_config_price(BRANCH_CALENDAR *branchCalendar, float price) {
    CONFIGURATION *configuration = branchCalendar->configuration;
    BRANCH_EVENTS *branchEvents = branchCalendar->branch_event;
    while (configuration != NULL) {
        if (strcmp(configuration->name, "configuracao") == 0);

        else if
            (strcmp(configuration->name, "duracao") == 0){
            if (getDifferenceDays(branchEvents->date_begin, branchEvents->date_end) >= 5)
                price *= configuration->value;
        }
       else  if (strcmp(configuration->name, "epoca") == 0)
            if (holiday_secion(branchEvents->date_begin) || holiday_secion(branchEvents->date_end))
                price *= configuration->value;

       else if (strcmp(configuration->name, "ocupacao") == 0);


       else if (strcmp(configuration->name, "modalidade") == 0)
            if (branchEvents->people->typePeople == ORGANIZACAO)
                price *= configuration->value;


       else if (strcmp(configuration->name, "antecedencia") == 0)
            if (getDifferenceDays(now(), branchEvents->date_begin) > 7)
                price *= configuration->value;


        configuration = configuration->next;
    }
    return price;
}
