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

int isLeap(int y);

int offsetDays(DATE d);

void revoffsetDays(int offset, int y, int *d, int *m);

DATE addDays(DATE date, int x);

 void next_date_avalabe(STUDIOS *studios, BRANCH_EVENTS **branchEvents, BRANCH_EVENTS *branchEvent, BRANCH_CALENDAR * branchCalendar);

int colision_dates(DATE begin1,DATE end1, DATE begin2 ,DATE end2);

#endif //GESTOR_ALOJAMENTOS_DATE_H
