//
// Created by Bruno Miguel on 22/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_MASTER_EVENTS_H
#define GESTOR_ALOJAMENTOS_MASTER_EVENTS_H


#include "../../main/structures.h"


void add_master_event(MASTER_EVENTS **pMasterEvents, PLATFORM platform, PEOPLE *people, DATE date_end, float price,
                      TYPE_MASTER_EVENT masterEvent, DATE date_begin);

void delete_master_event(MASTER_EVENTS **head, DATE date, PLATFORM platform);

MASTER_EVENTS *create_master_event(PLATFORM platform, PEOPLE *people, DATE date_end, float price,
                                   TYPE_MASTER_EVENT masterEvent, DATE date_begin);

void print_master_events(MASTER_EVENTS *masterEvents);

void ordena_master_event(MASTER_EVENTS **head, MASTER_EVENTS *temp);

void refresh_master_event(BUILDINGS *buildings, HISTORY *history, PEOPLE *pPeople);

int equal_master_event(MASTER_EVENTS *masterEvents, PLATFORM platform, DATE begin);

BRANCH_CALENDAR *
check_consistency_master(STUDIOS *studios, MASTER_EVENTS *masterEvents, PLATFORM platform, DATE begin, DATE end);

void fix_colision(STUDIOS *studios, BRANCH_EVENTS **branchEvents, BRANCH_EVENTS *branchEvents1, BRANCH_CALENDAR *branchCalendar1,
                  BRANCH_EVENTS *branchEvents2, BRANCH_CALENDAR *branchCalendar2);

void merge_array_master(MASTER_EVENTS *a, MASTER_EVENTS *aux, int lo, int mid, int hi);

void mergesort_recursivo_master(MASTER_EVENTS *a, MASTER_EVENTS *aux, int lo, int hi);

void mergesort_master(MASTER_EVENTS *a, int n, int lo, int hi);

#endif //GESTOR_ALOJAMENTOS_MASTER_EVENTS_H
