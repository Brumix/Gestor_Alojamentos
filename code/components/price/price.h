//
// Created by Bruno Miguel on 23/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_PRICE_H
#define GESTOR_ALOJAMENTOS_PRICE_H

#include "../../main/structures.h"




float calculate_price( float, float);

float calculate_event_price(BUILDINGS * buildings, unsigned );

float calculate_config_price(TYPE_STUDIO typeStudio, BRANCH_CALENDAR *branchCalendar,BRANCH_EVENTS *branchEvents,float price);

float configuratio_multiplier(TYPE_STUDIO typeStudio,float configprice);

#endif //GESTOR_ALOJAMENTOS_PRICE_H
