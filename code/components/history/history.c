//
// Created by Bruno Miguel on 28/11/2020.
//

#include "history.h"


HISTORY *create_hash_table() {
    HISTORY *history = malloc(HASHSIZE * sizeof(HISTORY));
    if (history == NULL) {
        perror("[CREATE HISTORY]");
        exit(EXIT_FAILURE);
    }
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
        value = (value * name[i]) % HASHSIZE;
    }
    return value;
}

void add_history(HISTORY *history, PLATFORM platform, PEOPLE people, unsigned duration, float price, DATE date,
                 TYPE_MASTER_EVENT typeMasterEvent) {

    HISTORY temp = add_hystory_event(platform, people, duration, price, date, typeMasterEvent);
    unsigned index = hash(temp.hystoryEvents->people.name);

    if (history[index].hystoryEvents == NULL) {
        history[index] = temp;
        return;
    } else {
        ordena_history(&history[index], &temp);

        return;
    }
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
    temp.hystoryEvents->next = NULL;
    return temp;
}

void ordena_history(HISTORY *history, HISTORY *history1) {

    if (strcmp(history->hystoryEvents->people.name, history1->hystoryEvents->people.name) == 0) {
       ordena_master_event(&history->hystoryEvents->events, history1->hystoryEvents->events);
    } else {
        history->hystoryEvents->events->next = history1->hystoryEvents->events;
    }
}

void print_history(HISTORY *history) {
    HISTORY *current = history;
    printf("HISTORY\n");
    for (int i = 0; i < HASHSIZE; ++i) {
        if (current[i].hystoryEvents == NULL)
            continue;
        else
            print_master_events(current[i].hystoryEvents->events);
    }
}
