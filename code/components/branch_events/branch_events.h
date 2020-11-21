//
// Created by Bruno Miguel on 21/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H
#define GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H

#include "../../main/structures.h"


void add_branch_event(BRANCH_EVENTS **pBranchEvents, PEOPLE people, unsigned duration, PRICE price,
                      TYPE_BRANCH_EVENT branchEvent);

#endif //GESTOR_ALOJAMENTOS_BRANCH_EVENTS_H
