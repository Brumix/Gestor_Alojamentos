//
// Created by Bruno Miguel on 11/01/2021.
//

#include "reports.h"


void occupancy_rate(BUILDINGS *head, DATE begin, DATE end) {
    BUILDINGS *buildings = head;
    inicial_declaration(FILEOCUPACION_RATE, begin, end);
    int totalidade = 0, count = 0;
    char *buildingstr = malloc(100 * sizeof(char));
    while (buildings != NULL) {
        count++;
        sprintf(buildingstr, "EDIFICIO %i\n", buildings->index);
        write_file_append(FILEOCUPACION_RATE, buildingstr);
        printf("%s", buildingstr);
        if (hasevent_studio(buildings, begin, end) == 1)
            totalidade++;

        buildings = buildings->next;
    }
    float taxa = ((float) totalidade / (float) count) * 100;
    char *string = malloc(100 * sizeof(char));
    sprintf(string, "TOTALIDADE DA TAXA DE OCUPACAO COM %i ESTUDIOS:%.2f\n\n", count, taxa);
    write_file_append(FILEOCUPACION_RATE, string);
    printf("%s", string);

    end_declaration(FILEOCUPACION_RATE);
}

int hasevent_studio(BUILDINGS *buildings, DATE begin, DATE end) {

    STUDIOS *studios = buildings->studios;
    int daysEvent, happendEvent = 0;
    for (int i = 0; i < buildings->num_studios; ++i) {
        daysEvent = has_event(&studios[i], begin, end);

        studio_occupancy_rate(&studios[i], daysEvent, getDifferenceDays(begin, end));
        if (daysEvent > 0)
            happendEvent = 1;
    }
    return happendEvent == 1 ? 1 : 0;
}

int has_event(STUDIOS *studios, DATE begin, DATE end) {
    int hasEvent = 0;
    DATE dataCheck = begin;

    while (1) {
        MASTER_EVENTS *masterEvents = studios->masterEvents;
        while (masterEvents != NULL) {
            if (colision_dates(masterEvents->date_begin, masterEvents->date_end, dataCheck, dataCheck) == 1) {
                hasEvent++;
                break;
            }
            masterEvents = masterEvents->next;
        }
        dataCheck = addDays(dataCheck, 1);
        if (compare_date(dataCheck, end) == 1)
            break;
    }

    return hasEvent;
}

void studio_occupancy_rate(STUDIOS *studios, int studioevent, unsigned total) {
    float ocupancy_rate = ((float) studioevent / (float) total) * 100;
    char *string = malloc(100);
    sprintf(string, "\tESTUDIO: %i\n\t\t TOTAL %i com uma taxa de ocupacao de %.2f \n", studios->index, total,
            ocupancy_rate);
    printf("%s\n", string);
    write_file_append(FILEOCUPACION_RATE, string);
}