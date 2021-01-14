//
// Created by Bruno Miguel on 19/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_STUDIOS_H
#define GESTOR_ALOJAMENTOS_STUDIOS_H


#include "../../main/structures.h"


void add_studio(BUILDINGS *buildings, TYPE_STUDIO typeStudio, unsigned short ind, unsigned short door, unsigned area);

int find_studio(BUILDINGS *buildings, int low, int high, unsigned short index);

void delete_studio(BUILDINGS *buildings, unsigned short door);

STUDIOS create_studio(TYPE_STUDIO typeStudio, unsigned short ind, unsigned short door, unsigned area);

void print_studio_all(BUILDINGS *buildings);

void resizeStudios(BUILDINGS *head);

void shift_right_studio(STUDIOS *a, int index, STUDIOS val, unsigned size);

void shift_left_studio(STUDIOS *a, int index, unsigned size);

char *strTypeStudio(TYPE_STUDIO ts);

void print_studio(STUDIOS head);

STUDIOS *find_studio_everyhere(BUILDINGS *building, unsigned index);

void update_studio(BUILDINGS *buildings, int id, int new);

int unique_id(STUDIOS *studios, int size, int id);

void
add_studio_merge(BUILDINGS *buildings, TYPE_STUDIO typeStudio, unsigned short ind, unsigned short door, unsigned area);


void merge_array_studio(STUDIOS *a, STUDIOS *aux, int lo, int mid, int hi);

void mergesort_recursivo_studio(STUDIOS *a, STUDIOS *aux, int lo, int hi);

void mergesort_run_studio(STUDIOS *a, int n, int lo, int hi);

void sort_studio(BUILDINGS *head);

#endif //GESTOR_ALOJAMENTOS_STUDIOS_H
