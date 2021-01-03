//
// Created by Bruno Miguel on 20/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H
#define GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H

#include "../../main/structures.h"


void add_branch_calendar(POLITICS *,STUDIOS *studios,PLATFORM platform,unsigned priority,char *politics);

int find_branch_calendar(STUDIOS *studios, int low, int high,PLATFORM platform);

void delete_branchCalendar(STUDIOS *studios, PLATFORM platform);

BRANCH_CALENDAR create_branch_calendar(POLITICS *,PLATFORM platform,unsigned priority,char *politics);

void print_branch_calendar(STUDIOS *studios);

void resize_branch_calendar(STUDIOS *studios);

void shift_right_branchCalendar(BRANCH_CALENDAR *a, int index, BRANCH_CALENDAR val, unsigned size);

void shift_left_branchCalendar(BRANCH_CALENDAR *a, int index, unsigned size);

void add_config(CONFIGURATION **pConfiguration,char *name,float value);

void print_config(CONFIGURATION * configuration);

void combine_config(POLITICS * politics,BRANCH_CALENDAR * branchCalendar);

void add_value_config(CONFIGURATION ** pConfiguration, float value);

#endif //GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H
