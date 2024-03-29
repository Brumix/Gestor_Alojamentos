//
// Created by Bruno Miguel on 28/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_HISTORY_H
#define GESTOR_ALOJAMENTOS_HISTORY_H


#include "../../main/structures.h"

unsigned short hash(char *name);

HISTORY *create_hash_table();

void add_history(HISTORY *history, PLATFORM platform, PEOPLE *people, DATE date_end, float price, DATE date_begin,
                 TYPE_MASTER_EVENT typeMasterEvent);

void delete_history_event(HISTORY *history, char *name, DATE date);

HISTORY create_hystory_event(PLATFORM platform, PEOPLE *people, DATE date_end, float price, DATE date_begin,
                             TYPE_MASTER_EVENT typeMasterEvent);

void ordena_history_events(HYSTORY_EVENTS **history, HYSTORY_EVENTS *temp);

void ordena_id_history(HYSTORY_EVENTS **history, HYSTORY_EVENTS *temp);

void remove_history_events(HYSTORY_EVENTS **history, char *name, DATE date);

void print_history(HISTORY *history);

#endif //GESTOR_ALOJAMENTOS_HISTORY_H
