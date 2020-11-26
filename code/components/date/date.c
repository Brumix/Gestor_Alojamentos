//
// Created by Bruno Miguel on 20/11/2020.
//

#include "date.h"

DATE add_date(unsigned short min, unsigned short hour, unsigned short day, unsigned short month, unsigned short year) {
    DATE temp;
    temp.min = min;
    temp.hour = hour;
    temp.day = day;
    temp.month = month;
    temp.Year = year;
    return temp;
}

void print_date(DATE date) {
    printf("DATE= %u:%u %u/%u/%u\n", date.min, date.hour, date.day, date.month, date.Year);
}

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

}