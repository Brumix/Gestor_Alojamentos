//
// Created by Bruno Miguel on 20/11/2020.
//

#include "branch_calendar.h"


void add_branch_calendar(STUDIOS *studios, PLATFORM platform) {
    resize_branch_calendar(studios);
    BRANCH_CALENDAR temp = create_branch_calendar(platform);
    for (int i = 0; i < studios->sizeArrayBranch; i++) {
        if (i == studios->number_branch) {
            studios->branch_calendar[studios->number_branch] = temp;
            studios->number_branch++;
            return;
        }
        if (studios->branch_calendar[i].platform == platform) {
            printf("[BRANCH CALENDAR EXISTENTE]\n");
            return;
        }
        if (studios->branch_calendar[i].platform > platform) {
            shift_right_branchCalendar(studios->branch_calendar, i, temp, studios->number_branch);
            studios->number_branch++;
            return;
        }
    }
    studios->branch_calendar[studios->number_branch] = temp;
    studios->number_branch++;
}

void delete_branchCalendar(STUDIOS *studios, PLATFORM platform) {
    for (int i = 0; i < studios->number_branch; i++) {
        if (studios->branch_calendar[i].platform == platform) {
            shift_left_branchCalendar(studios->branch_calendar, i, studios->number_branch);
            studios->number_branch--;
            return;
        }
    }
    printf("[BRANCH CALENDAR NAO ENCONTRADO]\n");
}

BRANCH_CALENDAR create_branch_calendar(PLATFORM platform) {
    BRANCH_CALENDAR temp;
    temp.platform = platform;
    temp.branch_event = NULL;
    return temp;
}

void print_branch_calendar(STUDIOS *studios) {
    printf("BRANCH CALENDAR\n");
    for (int i = 0; i < studios->number_branch; ++i) {
        BRANCH_CALENDAR *branchCalendar = &studios->branch_calendar[i];
        printf("PLATAFORMA: %s\n", strPlatform(branchCalendar->platform));
    }

}

void resize_branch_calendar(STUDIOS *studios){
    if (studios->sizeArrayBranch * 0.6 <= studios->number_branch) {
        studios->sizeArrayBranch *= 2;
        studios->branch_calendar = (BRANCH_CALENDAR *) realloc(studios->branch_calendar,
                                                               studios->sizeArrayBranch * sizeof(BRANCH_CALENDAR));
        if (studios->branch_calendar == NULL) {
            perror("[REALLOC BRANCH CALENDAR]");
            exit(EXIT_FAILURE);
        }
    }
}

void shift_right_branchCalendar(BRANCH_CALENDAR *a, int index, BRANCH_CALENDAR val, unsigned size) {
    if (index == size) {
        a[index] = val;
        return;
    }
    BRANCH_CALENDAR aux = a[index];
    a[index] = val;
    shift_right_branchCalendar(a, index + 1, aux, size);
}

void shift_left_branchCalendar(BRANCH_CALENDAR *a, int index, unsigned size) {
    if (index == size - 1) {
        a[index].platform = -1;
        return;
    }
    a[index] = a[index + 1];
    shift_left_branchCalendar(a, index + 1, size);
}
