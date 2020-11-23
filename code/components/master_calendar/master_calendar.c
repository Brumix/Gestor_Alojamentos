//
// Created by Bruno Miguel on 21/11/2020.
//

#include "master_calendar.h"


void add_master_calendar(STUDIOS *studios, DATE date) {
    resize_master_calendar(studios);
    MASTER_CALENDAR *temp = (MASTER_CALENDAR *) malloc(sizeof(MASTER_CALENDAR));
    if (temp == NULL) {
        perror("[ADD MASTER CALENDAR]");
        exit(EXIT_FAILURE);
    }
    temp->date = date;
    temp->master_event = NULL;
    studios->master_calendar[studios->number_master] = *temp;
    studios->number_master++;

}

void print_master_calendar(STUDIOS *studios) {
    printf("MASTER CALENDAR\n");
    for (int i = 0; i < studios->number_master; ++i) {
        MASTER_CALENDAR *masterCalendar = &studios->master_calendar[i];
        print_date(masterCalendar->date);
    }
}

void resize_master_calendar(STUDIOS *studios) {
    if (studios->sizeArrayMaster <= studios->number_master * 0.8) {
        studios->sizeArrayMaster *= 2;
        studios->master_calendar = (MASTER_CALENDAR *) realloc(studios->master_calendar,
                                                               studios->sizeArrayMaster * sizeof(MASTER_CALENDAR));
        if (studios->master_calendar == NULL) {
            perror("[REALLOC MASTER CALENDAR]");
            exit(EXIT_FAILURE);
        }
    }
}