//
// Created by Bruno Miguel on 20/11/2020.
//

#include "date.h"

DATE add_date(unsigned short min,unsigned short hour,unsigned short day, unsigned short month, unsigned short year){
    DATE temp;
    temp.min=min;
    temp.hour=hour;
    temp.day=day;
    temp.month=month;
    temp.Year=year;
    return temp;
}

void print_date(DATE date){
    printf("DATE= %u:%u %u/%u/%u\n",date.min,date.hour,date.day,date.month,date.Year);
}