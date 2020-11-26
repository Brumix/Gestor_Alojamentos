//
// Created by Bruno Miguel on 20/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H
#define GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H

#include "../../main/structures.h"


void add_branch_calendar(STUDIOS *studios, PLATFORM platform);

void delete_branchCalendar(STUDIOS *studios, PLATFORM platform);

BRANCH_CALENDAR create_branch_calendar(PLATFORM platform);

void print_branch_calendar(STUDIOS *studios);

void resize_branch_calendar(STUDIOS *studios);

char *strPlatform(PLATFORM platform);

void shift_right_branchCalendar(BRANCH_CALENDAR *a, int index, BRANCH_CALENDAR val, unsigned size);

void shift_left_branchCalendar(BRANCH_CALENDAR *a, int index, unsigned size);

#endif //GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H
