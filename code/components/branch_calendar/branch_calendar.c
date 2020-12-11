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
        EXISTENTE(studios->branch_calendar[i].platform == platform, "[BRANCH CALENDAR EXISTENTE]");

        if (studios->branch_calendar[i].platform > platform) {
            shift_right_branchCalendar(studios->branch_calendar, i, temp, studios->number_branch);
            studios->number_branch++;
            return;
        }
    }
}


int find_branch_calendar(STUDIOS *studios, int low, int high, PLATFORM platform) {
    if (low >= high || high <= low)
        return -1;
    int mid = low + (high - low) / 2;
    if (studios->branch_calendar[mid].platform == platform)
        return mid;
    if (studios->branch_calendar[low].platform == platform)
        return low;
    if (studios->branch_calendar[high].platform == platform)
        return high;
    if (studios->branch_calendar[mid].platform > platform)
        return find_branch_calendar(studios, low, mid - 1, platform);

    return find_branch_calendar(studios, mid + 1, high, platform);
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

void resize_branch_calendar(STUDIOS *studios) {
    if (studios->sizeArrayBranch * 0.6 <= studios->number_branch) {
        studios->sizeArrayBranch *= 2;
        studios->branch_calendar = (BRANCH_CALENDAR *) realloc(studios->branch_calendar,
                                                               studios->sizeArrayBranch * sizeof(BRANCH_CALENDAR));
        ERRORMESSAGE(studios->branch_calendar == NULL, "[REALLOC BRANCH CALENDAR]");
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


