//
// Created by Bruno Miguel on 21/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H
#define GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H

#include "../../main/structures.h"


void add_branch_event(BRANCH_EVENTS **head, int people, DATE date_inicio, DATE date_fim, float price,
                      TYPE_BRANCH_EVENT branchEvent,PEOPLE *pPeople);

void delete_branch_event(BRANCH_EVENTS **head, DATE date);

BRANCH_EVENTS *create_branch_event(unsigned, DATE, DATE, float, TYPE_BRANCH_EVENT);

void print_branch_events(BRANCH_EVENTS *branchEvents);

#endif //GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H
