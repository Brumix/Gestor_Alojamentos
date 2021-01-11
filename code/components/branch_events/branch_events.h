//
// Created by Bruno Miguel on 21/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H
#define GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H

#include "../../main/structures.h"


void add_branch_event(BUILDINGS *buildings, BRANCH_EVENTS **head, unsigned id, DATE date_inicio, DATE date_fim,
                      TYPE_BRANCH_EVENT branchEvent,PEOPLE *pPeople);

void delete_branch_event(MASTER_EVENTS **masterEvents,BRANCH_EVENTS **head,PLATFORM  platform,DATE date);

void delete_branch_event_only(BRANCH_EVENTS **head,DATE date);

BRANCH_EVENTS *create_branch_event(unsigned, DATE, DATE, TYPE_BRANCH_EVENT,PEOPLE *pPeople);

void print_branch_events(BRANCH_EVENTS *branchEvents);

void print_branch_event(BRANCH_EVENTS *branchEvents);

void clean_branch_event( BRANCH_CALENDAR * branchCalendar,int size);

BRANCH_EVENTS * find_branch_event(BRANCH_CALENDAR* branchCalendar,DATE begin);

#endif //GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H
