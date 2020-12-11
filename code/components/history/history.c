//
// Created by Bruno Miguel on 28/11/2020.
//

#include "history.h"


HISTORY *create_hash_table() {
    HISTORY *history = (HISTORY *) malloc(HASHSIZE * sizeof(HISTORY));
    ERRORMESSAGE(history == NULL, "[CREATE HISTORY]");
    for (int i = 0; i < HASHSIZE; i++) {
        history[i].hystoryEvents = NULL;
    }
    return history;
}

unsigned short hash(char *name) {
    int length = strlen(name);
    unsigned int value = 0;
    for (int i = 0; i < length; ++i) {
        value += name[i];
        value = (value * name[i] * 2) % HASHSIZE;
    }
    return value;
}

void add_history(HISTORY *history, PLATFORM platform, PEOPLE people, unsigned duration, float price, DATE date,
                 TYPE_MASTER_EVENT typeMasterEvent) {
    HISTORY *current = history;
    HISTORY temp = add_hystory_event(platform, people, duration, price, date, typeMasterEvent);
    unsigned index = hash(temp.hystoryEvents->people.name);

    if (current[index].hystoryEvents == NULL)
        current[index].hystoryEvents = temp.hystoryEvents;
    else {
        ordena_history_events(&current[index].hystoryEvents, temp.hystoryEvents);
    }
}

void delete_history_event(HISTORY *history, char *name, DATE date) {
    HISTORY *current = history;
    unsigned index = hash(name);
    EXISTENTE(current[index].hystoryEvents == NULL, "[PESSOA NAO ENCONTRADA]");
    remove_history_events(&current[index].hystoryEvents, name, date);
}


HISTORY add_hystory_event(PLATFORM platform, PEOPLE people, unsigned duration, float price, DATE date,
                          TYPE_MASTER_EVENT typeMasterEvent) {
    HISTORY temp;
    temp.hystoryEvents = malloc(sizeof(HYSTORY_EVENTS));
    temp.hystoryEvents->events = malloc(sizeof(MASTER_EVENTS));
    temp.hystoryEvents->people = people;
    temp.hystoryEvents->events->people = people;
    temp.hystoryEvents->events->typeMasterEvent = typeMasterEvent;
    temp.hystoryEvents->events->platform = platform;
    temp.hystoryEvents->events->date = date;
    temp.hystoryEvents->events->duration = duration;
    temp.hystoryEvents->events->price = price;
    temp.hystoryEvents->events->next = NULL;
    temp.hystoryEvents->next = NULL;
    return temp;
}

void ordena_history_events(HYSTORY_EVENTS **history, HYSTORY_EVENTS *temp) {

    HYSTORY_EVENTS *current = *history;

    if (strcmp(current->people.name, temp->people.name) == 0) {
        ordena_master_event(&current->events, temp->events);
        return;
    }
    if (strcmp(current->people.name, temp->people.name) == 1) {

        temp->next = *history;
        *history = temp;
        return;
    }
    while (current != NULL) {
        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        if (strcmp(current->next->people.name, temp->people.name) == 0) {

            ordena_master_event(&current->next->events, temp->events);

            return;
        }
        if (strcmp(current->next->people.name, temp->people.name) == 1) {

            temp->next = current->next;
            current->next = temp;
            return;
        }
        current = current->next;
    }
}


void remove_history_events(HYSTORY_EVENTS **history, char *name, DATE date) {
    HYSTORY_EVENTS *current = *history;
    if (strcmp(current->people.name, name) == 0) {
        if (current->events->next == NULL)
            *history = current->next;
        else
            delete_master_event(&current->events, date);
        return;
    }
    while (current != NULL) {
        if (strcmp(current->next->people.name, name) == 0) {
            if (current->next == NULL)
                current->next = current->next->next;
            else
                delete_master_event(&current->next->events, date);
            return;
        }
        EXISTENTE(current->next->next == NULL, "[EDIFICIO NAO ENCONTRADO]");

        current = current->next;
    }
}

void print_history(HISTORY *history) {
    HISTORY *current = history;

    for (int i = 0; i < HASHSIZE; i++) {
        if (current[i].hystoryEvents == NULL)
            continue;
        else {
            HYSTORY_EVENTS *pHitoryEvents = current[i].hystoryEvents;
            while (pHitoryEvents != NULL) {
                print_master_events(pHitoryEvents->events);
                pHitoryEvents = pHitoryEvents->next;
            }
        }
    }
}
