//
// Created by Bruno Miguel on 22/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_MASTER_EVENTS_H
#define GESTOR_ALOJAMENTOS_MASTER_EVENTS_H


#include "../../main/structures.h"


void add_master_event(MASTER_EVENTS **pMasterEvents, PLATFORM platform, PEOPLE people, unsigned duration, float price,
                      TYPE_MASTER_EVENT masterEvent, DATE date);

void delete_master_event(MASTER_EVENTS **head, DATE date);

MASTER_EVENTS *create_master_event(PLATFORM platform, PEOPLE people, unsigned duration, float price,
                                   TYPE_MASTER_EVENT masterEvent, DATE date);

void print_master_events(MASTER_EVENTS *masterEvents);

void ordena_master_event(MASTER_EVENTS **head, MASTER_EVENTS *temp);

#endif //GESTOR_ALOJAMENTOS_MASTER_EVENTS_H
