//
// Created by Bruno Miguel on 28/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_HISTORY_H
#define GESTOR_ALOJAMENTOS_HISTORY_H


#include "../../main/structures.h"

unsigned short hash(char *name);

HISTORY *create_hash_table();

void add_history(HISTORY *history, PLATFORM platform, PEOPLE people, unsigned duration, float price, DATE date,
                 TYPE_MASTER_EVENT typeMasterEvent);

HISTORY add_hystory_event(PLATFORM platform, PEOPLE people, unsigned duration, float price, DATE date,
                          TYPE_MASTER_EVENT typeMasterEvent);

void ordena_history(HISTORY *history, HISTORY *history1);

void print_history(HISTORY *history);

#endif //GESTOR_ALOJAMENTOS_HISTORY_H