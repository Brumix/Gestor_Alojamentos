//
// Created by Bruno Miguel on 21/11/2020.
//

#include "branch_events.h"


void add_branch_event(BRANCH_EVENTS **pBranchEvents, PEOPLE people, unsigned duration, PRICE price,
                      TYPE_BRANCH_EVENT branchEvent) {
    BRANCH_EVENTS *temp = (BRANCH_EVENTS *) malloc(sizeof(BRANCH_EVENTS));
    if (temp == NULL) {
        perror("[ADD BRANCH EVENT]");
        exit(-1);
    }
    temp->people = people;
    temp->price = price;
    temp->duration = duration;
    temp->bevent = (TYPE_MASTER_EVENT) branchEvent;
    temp->pnext = (struct branch_eventos *) *pBranchEvents;
    *pBranchEvents = temp;

}