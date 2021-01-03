//
// Created by Bruno Miguel on 18/12/2020.
//

#ifndef GESTOR_ALOJAMENTOS_HOLIDAYS_H
#define GESTOR_ALOJAMENTOS_HOLIDAYS_H

#include "../../main/structures.h"


HOLIDAYS *createHolidaysArray();

void add_holiday( char *nome, DATE date1, DATE date2);

HOLIDAYS create_holiday(char *nome, DATE date1, DATE date2);

void resize_holidays();

void print_holidays();

int holiday_secion(DATE date);

#endif //GESTOR_ALOJAMENTOS_HOLIDAYS_H
