//
// Created by Bruno Miguel on 22/11/2020.
//

#include "master_events.h"


/**
 * adiciona um master event
 * @param head lista ligada dos eventos
 * @param platform plartaforma do evento
 * @param people pessoa  do evento
 * @param duration duracao do evento
 * @param price custo  do evento
 * @param master Event tipo do evento
 * @param date data do evento
 */
void add_master_event(MASTER_EVENTS **head, PLATFORM platform, PEOPLE people, unsigned duration, float price,
                      TYPE_MASTER_EVENT masterEvent, DATE date) {

    MASTER_EVENTS *temp = create_master_event(platform, people, duration, price, masterEvent, date);
    ordena_master_event(head, temp);
}

/**
 * apaga um amster evento
 * @param head lista ligada dos master events
 * @param date data dop evento a apagar
 */
void delete_master_event(MASTER_EVENTS **head, DATE date) {
    MASTER_EVENTS *current = *head;

    if (compare_date(current->date, date) == 0) {
        *head = current->next;
        return;
    }
    while (current != NULL) {
        if (compare_date(current->next->date, date) == 0) {
            current->next = current->next->next;
            return;
        }
        EXISTENTE(current->next->next == NULL, "[MASTER EVENT NAO ENCONTRADO]");

        current = current->next;
    }
}

/**
 * cria um master event
 * @param platform plataforma do evento
 * @param people pessoa do evento
 * @param duration duracao do evento
 * @param price custo do evento
 * @param masterEvent tipo do evento
 * @param date data do evento
 * @return master_event
 */
MASTER_EVENTS *create_master_event(PLATFORM platform, PEOPLE people, unsigned duration, float price,
                                   TYPE_MASTER_EVENT masterEvent, DATE date) {
    MASTER_EVENTS *temp = (MASTER_EVENTS *) malloc(sizeof(MASTER_EVENTS));
    ERRORMESSAGE(temp == NULL, "[ADD MASTER EVENT]");

    temp->platform = platform;
    temp->people = people;
    temp->duration = duration;
    temp->price = price;
    temp->typeMasterEvent = masterEvent;
    temp->date = date;
    temp->next = NULL;
    return temp;
}


/**
 * imprime a lista dos eventos
 * @param masterEvents lista dos eventos
 */
void print_master_events(MASTER_EVENTS *masterEvents) {
    MASTER_EVENTS *curent = masterEvents;
    printf("MASTER EVENTS\n");
    while (curent != NULL) {
        printf("PLATAFORMA:%s\n", strPlatform(curent->platform));
        print_people(curent->people);
        print_date(curent->date);
        printf("DURACAO: %u\n", curent->duration);
        printf("PRECO: %.2f\n", curent->price);
        printf("TIPO DO EVENTO: %s\n", strMasterEvent(curent->typeMasterEvent));
        curent = curent->next;
    }

}

/**
 * reorganiza os evetos
 * @param head cabeca da lista ligada
 * @param temp evento a adicionar
 */
void ordena_master_event(MASTER_EVENTS **head, MASTER_EVENTS *temp) {
    MASTER_EVENTS *current = *head;
    if (current == NULL) {
        *head = temp;
        return;
    }
    EXISTENTE(compare_date(current->date, temp->date) == 0, "[MASTER EVENT EXISTENTE]");

    if (compare_date(current->date, temp->date) == 1) {

        temp->next = *head;
        *head = temp;
        return;
    }
    while (current != NULL) {

        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        EXISTENTE(compare_date(current->next->date, temp->date) == 0, "[MASTER EVENT EXISTENTE]");

        if (compare_date(current->next->date, temp->date) == 1) {
            temp->next = current->next;
            current->next = temp;
            return;
        }

        current = current->next;
    }
}

