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
        EXISTENTE(buildings->studios[i].num_door == door,"[ESTUDIO EXISTENTE]");
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
    temp.area=area;
    temp.sizeArrayBranch = INICIAL;
    temp.number_branch = 0;
    temp.branch_calendar = (BRANCH_CALENDAR *) malloc(INICIAL * sizeof(BRANCH_CALENDAR));
    clean_branch_event(temp.branch_calendar,INICIAL);
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
STUDIOS *find_studio_everyhere(BUILDINGS *building ,unsigned ind){
        BUILDINGS *current= building;
    while (current!=NULL){
           int index=find_studio(current, 0, current->num_studios, ind);
           if (index!= -1)
               return &current->studios[index];
        current=current->next;
    }
    return NULL;
}