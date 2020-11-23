//
// Created by Bruno Miguel on 22/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_MASTER_EVENTS_H
#define GESTOR_ALOJAMENTOS_MASTER_EVENTS_H


#include "../../main/structures.h"


void add_master_event(MASTER_EVENTS **pMasterEvents, PLATFORM platform, PEOPLE people, unsigned duration, float price,
                      TYPE_MASTER_EVENT masterEvent);

void print_master_events(MASTER_EVENTS *masterEvents);

#endif //GESTOR_ALOJAMENTOS_MASTER_EVENTS_H