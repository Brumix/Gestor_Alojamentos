//
// Created by Bruno Miguel on 20/11/2020.
//

#include "date.h"

/**
 * cria uma data
 * @param hour  hora da data
 * @param min  minuto da data
 * @param day  dia da data
 * @param month mes da data
 * @param year  ano da data
 * @return Data
 */
DATE add_date(unsigned short hour, unsigned short min, unsigned short day, unsigned short month, unsigned short year) {
    DATE temp;
    temp.min = min;
    temp.hour = hour;
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
    printf("DATE= %u:%u %u/%u/%u\n", date.hour, date.min, date.day, date.month, date.Year);
}

/**
 * compara datas
 * @param date1  data a comparar
 * @param date2 data a comparar
 * @return  1(data 1> data2) 0(data 1= data2) -1(data 1< data2)
 */
int compare_date(DATE date1, DATE date2) {
    if (date1.Year == date2.Year && date1.month == date2.month && date1.day == date2.day && date1.hour == date2.hour &&
            date1.min == date2.min)
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
    if (date1.hour > date2.hour)
        return 1;
    if (date1.hour < date2.hour)
        return -1;
    if (date1.min > date2.min)
        return 1;
    if (date1.min < date2.min)
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
    DATE now = add_date(timeinfo->tm_min, timeinfo->tm_hour, timeinfo->tm_mday, timeinfo->tm_mon + 1,
                        timeinfo->tm_year + 1900);
    return now;
}