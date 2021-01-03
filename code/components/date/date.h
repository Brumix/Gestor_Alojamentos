//
// Created by Bruno Miguel on 20/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_DATE_H
#define GESTOR_ALOJAMENTOS_DATE_H


#include "../../main/structures.h"


DATE add_date(unsigned short day, unsigned short month, unsigned short year);

void print_date(DATE date);

int compare_date(DATE date1, DATE date2);

DATE now();

void calculate_days(DATE date1, DATE date2);

int valid_date(DATE date);



int countLeapYears(DATE d);

int getDifferenceDays(DATE dt1, DATE dt2);

#endif //GESTOR_ALOJAMENTOS_DATE_H
