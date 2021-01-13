//
// Created by Bruno Miguel on 12/01/2021.
//

#include "billing.h"

BILLING *billing1 = NULL;

void billing(BUILDINGS *head, DATE begin, DATE end) {

    BUILDINGS *buildings = head;
    inicial_declaration(FILEBILLING, begin, end);
    float studioprofit = 0, totalprofit = 0;
    while (buildings != NULL) {
        studioprofit = calculate_studio_profit(buildings, begin, end);
        write_edificio_profit(buildings->name, studioprofit);
        totalprofit += studioprofit;

        buildings = buildings->next;
    }
    char *string = malloc(100 * sizeof(char));
    if (totalprofit > 0)
        sprintf(string, "NO TOTAL HOUVE UM LUCRO DE %.2f\n", totalprofit);
    else
        sprintf(string, "NO TOTAL HOUVE UM PREJUIZO DE %.2f\n", totalprofit);

    write_file_append(FILEBILLING, string);
    printf("%s", string);

    end_declaration(FILEBILLING);
}


float calculate_studio_profit(BUILDINGS *buildings, DATE begin, DATE end) {
    STUDIOS *studios = buildings->studios;
    float profitStudio, totalstudio = 0;
    for (int i = 0; i < buildings->num_studios; ++i) {
        profitStudio = profit_studio(&studios[i], begin, end);
        write_studio_profit(studios[i].index, profitStudio);
        totalstudio += profitStudio;
    }

    return totalstudio;
}

float profit_studio(STUDIOS *studios, DATE begin, DATE end) {
    float totalStudio = 0;
    MASTER_EVENTS *masterEvents = studios->masterEvents;
    while (masterEvents != NULL) {

        if (colision_dates(masterEvents->date_begin, masterEvents->date_end, begin, end) == 1) {
            totalStudio += masterEvents->price;
        }
        masterEvents = masterEvents->next;
    }
    return totalStudio;
}


void write_edificio_profit(char *name, float profit) {

    char *string = malloc(100 * sizeof(char));
    if (profit > 0)
        sprintf(string, "\tO EDIFICIO %s TEVE UM LUCRO DE %.2f\n", name, profit);
    else
        sprintf(string, "\tO EDIFICIO %s TEVE UM PREJUIZO DE %.2f\n", name, profit);

    write_file_append(FILEBILLING, string);
    printf("%s", string);
}


void write_studio_profit(int index, float profit) {
    char *string = malloc(100);

    if (profit > 0)
        sprintf(string, "\t\tO ESTUDIO: %i\n \t\t\t TEVE UM LUCRO DE %.2f\n", index, profit);
    else
        sprintf(string, "\t\tO ESTUDIO: %i\n \t\t\tTEVE UM PREJUIZO DE %.2f\n", index, profit);
    printf("%s\n", string);
    write_file_append(FILEBILLING, string);

}

