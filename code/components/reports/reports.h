//
// Created by Bruno Miguel on 11/01/2021.
//

#ifndef GESTOR_ALOJAMENTOS_REPORTS_H
#define GESTOR_ALOJAMENTOS_REPORTS_H


#include "../../main/structures.h"


void occupancy_rate(BUILDINGS *buildings, DATE begin, DATE end);

void studio_occupancy_rate(STUDIOS *studios, int studioevent, unsigned total);

int hasevent_studio(BUILDINGS *buildings, DATE begin, DATE end);

int has_event(STUDIOS *studios, DATE begin, DATE end);


#endif //GESTOR_ALOJAMENTOS_REPORTS_H
