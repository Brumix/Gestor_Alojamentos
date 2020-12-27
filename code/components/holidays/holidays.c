//
// Created by Bruno Miguel on 18/12/2020.
//

#include "holidays.h"

int HOLIDAYSSIZE = INICIAL;
int POSICIONHOLIDAY = 0;

HOLIDAYS *createHolidaysArray() {
    HOLIDAYS *temp = (HOLIDAYS *) malloc(HOLIDAYSSIZE * sizeof(HOLIDAYS));
    ERRORMESSAGE(temp == NULL, "[MALL0C HOLIDAYS]");
    return temp;
}

void add_holiday(HOLIDAYS *holidays, char *nome, DATE date1, DATE date2) {
    resize_holidays(&holidays);
    HOLIDAYS temp = create_holiday(nome, date1, date2);
    holidays[POSICIONHOLIDAY] = temp;
    POSICIONHOLIDAY++;
}


HOLIDAYS create_holiday(char *nome, DATE date1, DATE date2) {
    HOLIDAYS temp;
    temp.nome = nome;
    temp.date = malloc(2 * sizeof(DATE));
    ERRORMESSAGE(temp.date == NULL, "[MALLOC DATE HOLIDAY]");
    temp.date[0] = date1;
    temp.date[1] = date2;

    return temp;
}

void resize_holidays(HOLIDAYS **holidays) {
    if (HOLIDAYSSIZE * 0.6 <= POSICIONHOLIDAY) {
        HOLIDAYSSIZE *= 2;
        *holidays = (HOLIDAYS *) realloc(*holidays, HOLIDAYSSIZE * sizeof(HOLIDAYS));
        ERRORMESSAGE(holidays == NULL, "[REALLOC HOLIDAYS]");
    }
}

void print_holidays(HOLIDAYS *holidays) {
    HOLIDAYS *current = holidays;
    printf("HOLIDAYS\n");
    for (int i = 0; i < POSICIONHOLIDAY; i++) {
        printf("NOME:%s\n", current[i].nome);
        printf("\t");
        print_date(current[i].date[0]);
        printf("\t");
        print_date(current[i].date[1]);
    }
}

