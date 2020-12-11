//
// Created by Bruno Miguel on 19/11/2020.
//

#include "studios.h"


void add_studio(BUILDINGS *buildings, TYPE_STUDIO typeStudio, unsigned short cap, unsigned short door, char *extra) {
    resizeStudios(buildings);
    STUDIOS temp = create_studio(typeStudio, cap, door, extra);
    for (int i = 0; i < buildings->sizeArray; i++) {
        if (i == buildings->num_studios) {
            buildings->studios[buildings->num_studios] = temp;
            buildings->num_studios++;
            return;
        }
        if (buildings->studios[i].num_door == door) {
            printf("[ESTUDIO EXISTENTE]\n");
            return;
        }
        if (buildings->studios[i].num_door > door) {
            shift_right_studio(buildings->studios, i, temp, buildings->num_studios);
            buildings->num_studios++;
            return;
        }
    }
}

void delete_studio(BUILDINGS *buildings, unsigned short door) {
    for (int i = 0; i < buildings->num_studios; i++) {
        if (buildings->studios[i].num_door == door) {
            shift_left_studio(buildings->studios, i, buildings->num_studios);
            buildings->num_studios--;
            return;
        }
    }
    printf("[ESTUDIO NAO ENCONTRADO]\n");
}

STUDIOS create_studio(TYPE_STUDIO typeStudio, unsigned short cap, unsigned short door, char *extra) {
    STUDIOS temp;
    temp.typeStudio = typeStudio;
    temp.num_door = door;
    temp.capacity = cap;
    temp.extra = extra;
    temp.sizeArrayBranch = INICIAL;
    temp.number_branch = 0;
    temp.branch_calendar = (BRANCH_CALENDAR *) malloc(INICIAL * sizeof(BRANCH_CALENDAR));
    temp.masterEvents = NULL;
    return temp;
}


void print_studio_all(BUILDINGS *buildings) {
    BUILDINGS *current = buildings;
    if (current == NULL) {
        printf("[NAO EXISTE NENHUM ESTUDIO]\n");
        return;
    }
    printf("ESTUDIOS\n");
    for (int i = 0; i < current->num_studios; i++) {
        STUDIOS *studio = &current->studios[i];
        printf("TIPO DE ESTUDIO: %s\n", strTypeStudio(studio->typeStudio));
        printf("PORTA: %i\n", studio->num_door);
        printf("CAPACIDADE: %i \n", studio->capacity);
        printf("EXTRA: %s \n", studio->extra);
    }

}

void resizeStudios(BUILDINGS *head) {
    if (head->sizeArray * 0.6 <= head->num_studios) {
        head->sizeArray *= 2;
        head->studios = realloc(head->studios, head->sizeArray * sizeof(STUDIOS));
        if (head->studios == NULL) {
            perror("[REALLOC STUDIOS]");
            exit(EXIT_FAILURE);
        }
    }

}


int find_studio(BUILDINGS *buildings, int low, int high, unsigned short door) {
    if (low >= high || high <= low)
        return -1;
    int mid = low + (high - low) / 2;
    if (buildings->studios[mid].num_door == door)
        return mid;
    if (buildings->studios[low].num_door == door)
        return low;
    if (buildings->studios[high].num_door == door)
        return high;
    if (buildings->studios[mid].num_door > door)
        return find_studio(buildings, low, mid - 1, door);

    return find_studio(buildings, mid + 1, high, door);
}


void shift_right_studio(STUDIOS *a, int index, STUDIOS val, unsigned size) {
    if (index == size) {
        a[index] = val;
        return;
    }
    STUDIOS aux = a[index];
    a[index] = val;
    shift_right_studio(a, index + 1, aux, size);
}

void shift_left_studio(STUDIOS *a, int index, unsigned size) {
    if (index == size - 1) {
        a[index].num_door = 0;
        return;
    }
    a[index] = a[index + 1];
    shift_left_studio(a, index + 1, size);
}