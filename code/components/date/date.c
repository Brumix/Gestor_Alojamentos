//
// Created by Bruno Miguel on 20/11/2020.
//

#include "date.h"


const int monthDays[12]
        = {31, 28, 31, 30, 31, 30,
           31, 31, 30, 31, 30, 31};

/**
 * cria uma data
 * @param hour  hora da data
 * @param min  minuto da data
 * @param day  dia da data
 * @param month mes da data
 * @param year  ano da data
 * @return Data
 */
DATE add_date(unsigned short day, unsigned short month, unsigned short year) {
    DATE temp;
    temp.day = day;
    temp.month = month;
    temp.Year = year;
    return temp;
}

/**
 * imprime uma data
 * @param date  data
 */
void print_date(DATE date) {
    printf("DATE= %u/%u/%u\n", date.day, date.month, date.Year);
}

/**
 * compara datas
 * @param date1  data a comparar
 * @param date2 data a comparar
 * @return  1(data 1> data2) 0(data 1= data2) -1(data 1< data2)
 */
int compare_date(DATE date1, DATE date2) {
    if (date1.Year == date2.Year && date1.month == date2.month && date1.day == date2.day)
        return 0;
    if (date1.Year > date2.Year)
        return 1;
    if (date1.Year < date2.Year)
        return -1;
    if (date1.month > date2.month)
        return 1;
    if (date1.month < date2.month)
        return -1;
    if (date1.day > date2.day)
        return 1;
    if (date1.day < date2.day)
        return -1;
    return EXIT_FAILURE;
}

/**
 * data do sistema
 * @return  data atual
 */
DATE now() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    DATE now = add_date(timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    return now;
}

/**
 * verifica se a data é valida
 * @param date data struct
 * @return  true ou false
 */
int valid_date(DATE date) {
    int is_valid = 1, is_leap = 0;
    if (date.Year >= 1800 && date.Year <= 9999) {
        if ((date.Year % 4 == 0 && date.Year % 100 != 0) || (date.Year % 400 == 0)) {
            is_leap = 1;
        }
        if (date.month >= 1 && date.month <= 12) {
            if (date.month == 2) {
                if (is_leap && date.day == 29) {
                    is_valid = 1;
                } else if (date.day > 28) {
                    is_valid = 0;
                }
            } else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
                if (date.day > 30) {
                    is_valid = 0;
                }
            } else if (date.day > 31) {
                is_valid = 0;
            }
        } else {
            is_valid = 0;
        }
    } else {
        is_valid = 0;
    }
    return is_valid;
}

/**
 * conta dias dos anos bissexto
 * @param d data struct
 * @return int
 */
int countLeapYears(DATE d) {
    int years = d.Year;

    if (d.month <= 2)
        years--;

    return years / 4
           - years / 100
           + years / 400;
}

/**
 * conta os dias entre duas datas
 * @param dt1  data struct
 * @param dt2  data struct
 * @return dias int
 */
int getDifferenceDays(DATE dt1, DATE dt2) {

    if (!valid_date(dt1) || !valid_date(dt2)) printf("[CLACULATE_DAYS:]DATA INVALIDA");


    long int n1 = dt1.Year * 365 + dt1.day;


    for (int i = 0; i < dt1.month - 1; i++)
        n1 += monthDays[i];


    n1 += countLeapYears(dt1);

    long int n2 = dt2.Year * 365 + dt2.day;
    for (int i = 0; i < dt2.month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
    return (n2 - n1);
}


int isLeap(int y) {
    if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
        return 1;
    return 0;
}

int offsetDays(DATE d) {
    int offset = d.day;

    switch (d.month - 1) {
        case 11:
            offset += 30;
        case 10:
            offset += 31;
        case 9:
            offset += 30;
        case 8:
            offset += 31;
        case 7:
            offset += 31;
        case 6:
            offset += 30;
        case 5:
            offset += 31;
        case 4:
            offset += 30;
        case 3:
            offset += 31;
        case 2:
            offset += 28;
        case 1:
            offset += 31;
    }
    if (isLeap(d.Year) && d.month > 2)
        offset += 1;
    return offset;
}

void revoffsetDays(int offset, int y, int *d, int *m) {
    int month[13] = {0, 31, 28, 31, 30, 31, 30,
                     31, 31, 30, 31, 30, 31};

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++) {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

DATE addDays(DATE date, int x) {
    int offset1 = offsetDays(date);
    int remDays = isLeap(date.Year) ? (366 - offset1) : (365 - offset1);

    int y2, offset2;
    if (x <= remDays) {
        y2 = date.Year;
        offset2 = offset1 + x;
    } else {
        x -= remDays;
        y2 = date.Year + 1;
        int y2days = isLeap(y2) ? 366 : 365;
        while (x >= y2days) {
            x -= y2days;
            y2++;
            y2days = isLeap(y2) ? 366 : 365;
        }
        offset2 = x;
    }
    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);
    DATE date1 = add_date(d2, m2, y2);
    return date1;
}

void next_date_avalabe(STUDIOS *studios, BRANCH_EVENTS **branchEvents, BRANCH_EVENTS *branchEvent,
                       BRANCH_CALENDAR *branchCalendar) {
    print_branch_event(branchEvent);
    delete_branch_event_only(branchEvents, branchEvent->date_begin);
    DATE dateAvalableBegin = branchEvent->date_begin;
    DATE dateAvalableEnd = branchEvent->date_end;
    while (1) {
        dateAvalableBegin = addDays(dateAvalableBegin,1);
        dateAvalableEnd = addDays(dateAvalableEnd, 1);
        BRANCH_CALENDAR *calendar = check_consistency_master(studios, studios->masterEvents, branchCalendar->platform,
                                                             dateAvalableBegin, dateAvalableEnd);
        if (calendar == NULL) {
            printf("A  PROXIMA DATA LIVRE E\n");
            print_date(dateAvalableBegin);
            print_date(dateAvalableEnd);
            break;
        }
    }
}


int colision_dates(DATE begin1, DATE end1, DATE begin2, DATE end2) {
    if (compare_date(end1, begin2) == -1)
        return 0;
    if (compare_date(end2, begin1) == -1)
        return 0;
    if (compare_date(end1, begin2) == 0)
        return 0;
    if (compare_date(end2, begin1) == 0)
        return 0;
    return 1;
}