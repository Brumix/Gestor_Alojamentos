//
// Created by Bruno Miguel on 19/11/2020.
//

#include "studios.h"


/**
 * adicionar um estudio
 * @param buildings array de estudios
 * @param typeStudio tipo de estudios
 * @param ind capacidade do estudio
 * @param door numero da porta
 * @param extra detalhes da poprieadade
 */
void add_studio(BUILDINGS *buildings, TYPE_STUDIO typeStudio, unsigned short ind, unsigned short door, unsigned area) {
    resizeStudios(buildings);
    STUDIOS temp = create_studio(typeStudio, ind, door, area);
    for (int i = 0; i < buildings->sizeArray; i++) {
        if (i == buildings->num_studios) {
            buildings->studios[buildings->num_studios] = temp;
            buildings->num_studios++;
            return;
        }
        EXISTENTE(buildings->studios[i].num_door == door, "[ESTUDIO EXISTENTE]");
        if (buildings->studios[i].num_door > door) {
            shift_right_studio(buildings->studios, i, temp, buildings->num_studios);
            buildings->num_studios++;
            return;
        }
    }
}

/**
 * apaga um estudio
 * @param buildings struct buildings
 * @param door int door
 */
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

/**
 * cria um estudio
 * @param typeStudio enum tipo de estudio
 * @param ind int index
 * @param door unsigned door
 * @param area unsigned area
 * @return STUDIO
 */
STUDIOS create_studio(TYPE_STUDIO typeStudio, unsigned short ind, unsigned short door, unsigned area) {
    STUDIOS temp;
    temp.typeStudio = typeStudio;
    temp.num_door = door;
    temp.index = ind;
    temp.area = area;
    temp.sizeArrayBranch = INICIAL;
    temp.number_branch = 0;
    temp.branch_calendar = (BRANCH_CALENDAR *) malloc(INICIAL * sizeof(BRANCH_CALENDAR));
    clean_branch_event(temp.branch_calendar, INICIAL);
    temp.masterEvents = NULL;
    return temp;
}

/**
 * imprime todos os estudios
 * @param buildings struct buildings
 */
void print_studio_all(BUILDINGS *buildings) {
    BUILDINGS *current = buildings;
    if (current == NULL) {
        printf("[NAO EXISTE NENHUM ESTUDIO]\n");
        return;
    }
    printf("ESTUDIOS\n");
    for (int i = 0; i < current->num_studios; i++) {
        STUDIOS *studio = &current->studios[i];
        printf("INDEX: %i \n", studio->index);
        printf("TIPO DE ESTUDIO: %s\n", strTypeStudio(studio->typeStudio));
        printf("PORTA: %i\n", studio->num_door);
        printf("EXTRA: %u \n", studio->area);
        printf("\n");
    }

}

void print_studio(STUDIOS head) {
    STUDIOS studio = head;

    printf("ESTUDIOS\n");
        printf("INDEX: %i \n", studio.index);
        printf("TIPO DE ESTUDIO: %s\n", strTypeStudio(studio.typeStudio));
        printf("PORTA: %i\n", studio.num_door);
        printf("EXTRA: %u \n", studio.area);
        printf("\n");

}

/**
 * aumenta o tamanho do array
 * @param head struct buildings
 */
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

/**
 * encontra um estudio
 * @param buildings struct buildings
 * @param low int
 * @param high int
 * @param index unsigned
 * @return int index
 */
int find_studio(BUILDINGS *buildings, int low, int high, unsigned short index) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (buildings->studios[mid].index == index)
        return mid;
    if (buildings->studios[low].index == index)
        return low;
    if (buildings->studios[high].index == index)
        return high;
    if (buildings->studios[mid].index > index)
        return find_studio(buildings, low, mid - 1, index);

    return find_studio(buildings, mid + 1, high, index);
}

/**
 * reajusta as posicoes do array
 * @param a struct STUDIOS
 * @param index posicao no array
 * @param val valor que queremos adicionar
 * @param size taamanho
 */
void shift_right_studio(STUDIOS *a, int index, STUDIOS val, unsigned size) {
    if (index == size) {
        a[index] = val;
        return;
    }
    STUDIOS aux = a[index];
    a[index] = val;
    shift_right_studio(a, index + 1, aux, size);
}

/**
 * realusta o array para eliminar uma posicao
 * @param a  struct studis
 * @param index int
 * @param size int
 */
void shift_left_studio(STUDIOS *a, int index, unsigned size) {
    if (index == size - 1) {
        a[index].num_door = 0;
        return;
    }
    a[index] = a[index + 1];
    shift_left_studio(a, index + 1, size);
}

/**
 * pesquisa um estudio
 * @param building struct buildings
 * @param index unsigned
 * @return STUDIOS *
 */
STUDIOS *find_studio_everyhere(BUILDINGS *building, unsigned ind) {
    BUILDINGS *current = building;
    while (current != NULL) {
        int index = find_studio(current, 0, current->num_studios, ind);
        if (index != -1)
            return &current->studios[index];
        current = current->next;
    }
    return NULL;
}


void update_studio(BUILDINGS *buildings, int id, int new) {
    STUDIOS *studios = buildings->studios;
    if (unique_id(studios, buildings->num_studios, new) == 1) {
        printf("INDEX ALREADY EXITS\n");
        return;
    }
    for (int i = 0; i < buildings->num_studios; ++i) {
        if (studios[i].index == id)
            studios[i].index = new;
    }

}

int unique_id(STUDIOS *studios, int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (studios[i].index == id)
            return 1;
    }
    return 0;
}


void
add_studio_merge(BUILDINGS *buildings, TYPE_STUDIO typeStudio, unsigned short ind, unsigned short door, unsigned area) {
    resizeStudios(buildings);
    STUDIOS temp = create_studio(typeStudio, ind, door, area);
    buildings->studios[buildings->num_studios] = temp;
    buildings->num_studios++;
}


void merge_array_studio(STUDIOS *a, STUDIOS *aux, int lo, int mid, int hi) {
    int k;
    for (k = lo; k <= hi; k++)
        *(aux + k) = *(a + k);
    int i = lo, j = mid + 1;
    for (k = lo; k <= hi; k++) {
        if (i > mid)
            *(a + k) = *(aux + (j++));
        else if (j > hi)
            *(a + k) = *(aux + (i++));
        else if ((aux + j)->num_door < (aux + i)->num_door)
            *(a + k) = *(aux + (j++));
        else
            *(a + k) = *(aux + (i++));
    }
}

void mergesort_recursivo_studio(STUDIOS *a, STUDIOS *aux, int lo, int hi) {
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    mergesort_recursivo_studio(a, aux, lo, mid);
    mergesort_recursivo_studio(a, aux, mid + 1, hi);
    if ((a + (mid + 1))->num_door >= (a + mid)->num_door)
        return; // improvement
    merge_array_studio(a, aux, lo, mid, hi);
}

void mergesort_run_studio(STUDIOS *a, int n, int lo, int hi) {
    STUDIOS *aux;
    aux = malloc(sizeof(STUDIOS) * n);
    mergesort_recursivo_studio(a, aux, lo, hi);
//   free(aux);
}

void sort_studio(BUILDINGS *head) {
    BUILDINGS *buildings = head;
    while (buildings != NULL) {

        mergesort_run_studio(buildings->studios, buildings->num_studios, 0, buildings->num_studios - 1);
        buildings = buildings->next;
    }


}