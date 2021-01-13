//
// Created by Bruno Miguel on 12/01/2021.
//

#ifndef GESTOR_ALOJAMENTOS_BILLING_H
#define GESTOR_ALOJAMENTOS_BILLING_H

#include "../../main/structures.h"

typedef struct billing {
    int studioid;
    float profit;

} BILLING;


void billing(BUILDINGS *head, DATE begin, DATE end);

float calculate_studio_profit(BUILDINGS *buildings, DATE begin, DATE end);

void write_edificio_profit(char *name, float profit);

float profit_studio(STUDIOS *studios, DATE begin, DATE end);

void write_studio_profit(int index, float profit);


#endif //GESTOR_ALOJAMENTOS_BILLING_H
