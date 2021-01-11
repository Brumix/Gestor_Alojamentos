//
// Created by Bruno Miguel on 23/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_PRICE_H
#define GESTOR_ALOJAMENTOS_PRICE_H

#include "../../main/structures.h"




float calculate_price( float, float);

float calculate_event_price(BUILDINGS * buildings, unsigned );

float calculate_config_price(BRANCH_CALENDAR * branchCalendar,float );

#endif //GESTOR_ALOJAMENTOS_PRICE_H
