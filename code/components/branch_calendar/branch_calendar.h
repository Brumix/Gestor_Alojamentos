//
// Created by Bruno Miguel on 20/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H
#define GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H

#include "../../main/structures.h"


void add_branch_calendar(STUDIOS *studios, PLATFORM platform, unsigned priority, char *politics);

BRANCH_CALENDAR *find_branch_calendar(STUDIOS *studios, int low, int high, PLATFORM platform);

void delete_branchCalendar(STUDIOS *studios, PLATFORM platform);

BRANCH_CALENDAR create_branch_calendar(PLATFORM platform, unsigned priority, char *politics);

void print_branch_calendar(STUDIOS *studios);

void print_branch_calendar_unique(BRANCH_CALENDAR *branchCalendar);

void resize_branch_calendar(STUDIOS *studios);

void shift_right_branchCalendar(BRANCH_CALENDAR *a, int index, BRANCH_CALENDAR val, unsigned size);

void shift_left_branchCalendar(BRANCH_CALENDAR *a, int index, unsigned size);

void add_config(CONFIGURATION **pConfiguration, char *name, float value);

void print_config(CONFIGURATION *configuration);

void combine_config(BRANCH_CALENDAR *branchCalendar);

void add_value_config(CONFIGURATION **pConfiguration, float value);

void add_specif_event(BUILDINGS *head, DATE begin, DATE end, int dias, char *buildingname, int n_pessoas);

int
check_people_can_have(DATE begin, DATE end, BUILDINGS *head, int dias, int n_people, PEOPLE_ALOCATED **peopleAlocated);

int people_alocated(DATE begin, DATE end, MASTER_EVENTS *masterEvents, TYPE_STUDIO typeStudio);

void add_people_alocated(PEOPLE_ALOCATED **peopleAlocated, DATE begin, DATE end, int n_people, int index);

void print_people_alocated(PEOPLE_ALOCATED *peopleAlocated, int n_people);

void add_branch_calendar_merge(STUDIOS *studios, PLATFORM platform, unsigned priority, char *politics);

void sort_branch_calendar(BUILDINGS * buildings);

int partitionQuicksort(BRANCH_CALENDAR a[], int lo, int hi);

void quicksort(BRANCH_CALENDAR a[], int lo, int hi);

#endif //GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H
