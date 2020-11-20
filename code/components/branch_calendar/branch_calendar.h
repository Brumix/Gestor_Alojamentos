//
// Created by Bruno Miguel on 20/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H
#define GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H

#include "../../main/structures.h"


void add_branch_calendar(STUDIOS *studios, DATE date, PLATFORM platform);

void print_branch_calendat(STUDIOS *studios);

void resize_branch_calendar(STUDIOS *studios);

char *strPlatform(PLATFORM platform);

#endif //GESTOR_ALOJAMENTOS_BRANCH_CALENDAR_H
