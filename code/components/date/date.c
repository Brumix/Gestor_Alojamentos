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
            }
            else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
                if (date.day > 30) {
                    is_valid = 0;
                }
            }
            else if (date.day > 31) {
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



