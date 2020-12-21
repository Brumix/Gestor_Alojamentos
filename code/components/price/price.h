//
// Created by Bruno Miguel on 23/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_PRICE_H
#define GESTOR_ALOJAMENTOS_PRICE_H

#include "../../main/structures.h"

PRICE *createPriceArray();

void add_price(PRICE *array, char *type, float valor);

void printprice(PRICE *price);

float findprice(PRICE *price, char *type);

void resizeArray(PRICE **price);


float calculate_price(PRICE *price, float baseprice, int argc, ...);

#endif //GESTOR_ALOJAMENTOS_PRICE_H
