//
// Created by Bruno Miguel on 20/11/2020.
//

#include "branch_calendar.h"


void add_branch_calendar(STUDIOS *studios, DATE date, PLATFORM platform){
    resize_branch_calendar(studios);
    BRANCH_CALENDAR *temp=(BRANCH_CALENDAR*)malloc(sizeof(BRANCH_CALENDAR));
    if(temp==NULL){
        perror("[ADD BRANCH CALENDAR]");
        exit(1);
    }
    temp->date=date;
    temp->platform=platform;
    temp->branch_event=NULL;
    studios->branch_calendar[studios->number_branch]=*temp;
    studios->number_branch++;
}

void print_branch_calendar(STUDIOS *studios) {
    printf("BRANCH CALENDAR\n");
    for (int i = 0; i < studios->number_branch; ++i) {
        BRANCH_CALENDAR *branchCalendar = &studios->branch_calendar[i];
        print_date(branchCalendar->date);
        printf("PLATAFORMA: %s\n", strPlatform(branchCalendar->platform));
    }

}

void resize_branch_calendar(STUDIOS *studios){
    if(studios->sizeArrayBranch<=studios->number_branch*0.8){
        studios->sizeArrayBranch *= 2;
        studios->branch_calendar = (BRANCH_CALENDAR *) realloc(studios->branch_calendar,
                                                               studios->sizeArrayBranch * sizeof(BRANCH_CALENDAR));
        if(studios->branch_calendar==NULL){
            perror("[REALLOC BRANCH CALENDAR]");
            exit(-1);
        }
    }
}
