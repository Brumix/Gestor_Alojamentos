//
// Created by Bruno Miguel on 20/11/2020.
//

#include "branch_calendar.h"

/**
 * adiciona um evento ao calendario branch
 * @param studios estrutura
 * @param platform  plataforma
 */
void add_branch_calendar(STUDIOS *studios, PLATFORM platform, unsigned prioridade) {
    resize_branch_calendar(studios);
    BRANCH_CALENDAR temp = create_branch_calendar(platform, prioridade);
    for (int i = 0; i < studios->sizeArrayBranch; i++) {
        if (i == studios->number_branch) {
            studios->branch_calendar[studios->number_branch] = temp;
            studios->number_branch++;
            return;
        }
        EXISTENTE(studios->branch_calendar[i].plataforms.platform == platform, "[BRANCH CALENDAR EXISTENTE]");

        if (studios->branch_calendar[i].plataforms.priority > prioridade) {
            shift_right_branchCalendar(studios->branch_calendar, i, temp, studios->number_branch);
            studios->number_branch++;
            return;
        }
    }
}

/**
 * encontra uma posicao de um calendario de uma platafoprma
 * @param studios  estruturas onde estao guadados os calendarios da plataformas
 * @param low  possicao minima
 * @param high  possicao maxima
 * @param platform  plataforma que quero encontrar
 * @return posicao de uma possicao do array
 */
int find_branch_calendar(STUDIOS *studios, int low, int high, PLATFORM platform) {
    if (low >= high || high <= low)
        return -1;
    int mid = low + (high - low) / 2;
    if (studios->branch_calendar[mid].plataforms.platform == platform)
        return mid;
    if (studios->branch_calendar[low].plataforms.platform == platform)
        return low;
    if (studios->branch_calendar[high].plataforms.platform == platform)
        return high;
    if (studios->branch_calendar[mid].plataforms.platform > platform)
        return find_branch_calendar(studios, low, mid - 1, platform);

    return find_branch_calendar(studios, mid + 1, high, platform);
}

/**
 * apagua um evento do calendario
 * @param studios  estrutura onde estao guardados os calendarios
 * @param platform  plataforma que quero apaguar
 */
void delete_branchCalendar(STUDIOS *studios, PLATFORM platform) {
    for (int i = 0; i < studios->number_branch; i++) {
        if (studios->branch_calendar[i].plataforms.platform == platform) {
            shift_left_branchCalendar(studios->branch_calendar, i, studios->number_branch);
            studios->number_branch--;
            return;
        }
    }
    printf("[BRANCH CALENDAR NAO ENCONTRADO]\n");
}

/**
 * cria um calendario branch
 * @param platform  plataforma que quer cirar
 * @return  plataforma
 */
BRANCH_CALENDAR create_branch_calendar(PLATFORM platform, unsigned priority) {
    BRANCH_CALENDAR temp;
    temp.plataforms.platform = platform;
    temp.plataforms.priority = priority;
    temp.branch_event = NULL;
    return temp;
}

/**
 * imprime todos os calendarios
 * @param studios estrutura onde estao guardados
 */
void print_branch_calendar(STUDIOS *studios) {
    printf("BRANCH CALENDAR\n");
    for (int i = 0; i < studios->number_branch; ++i) {
        BRANCH_CALENDAR *branchCalendar = &studios->branch_calendar[i];
        printf("PRIORIDADE: %u\n", branchCalendar->plataforms.priority);
        printf("PLATAFORMA: %s\n", strPlatform(branchCalendar->plataforms.platform));
    }

}

/**
 * altera o tamanho do array
 * @param studios esterutura onde estao gaurdados os calendarios
 */
void resize_branch_calendar(STUDIOS *studios) {
    if (studios->sizeArrayBranch * 0.6 <= studios->number_branch) {
        studios->sizeArrayBranch *= 2;
        studios->branch_calendar = (BRANCH_CALENDAR *) realloc(studios->branch_calendar,
                                                               studios->sizeArrayBranch * sizeof(BRANCH_CALENDAR));
        ERRORMESSAGE(studios->branch_calendar == NULL, "[REALLOC BRANCH CALENDAR]");
    }
}

/**
 * reorganiza o array no caso de uma adicao
 * @param a   estreutura dos calendarios
 * @param index  posicao onde vai ser adicionado
 * @param val  branch calendar adicionado
 * @param size tamanho do array
 */
void shift_right_branchCalendar(BRANCH_CALENDAR *a, int index, BRANCH_CALENDAR val, unsigned size) {
    if (index == size) {
        a[index] = val;
        return;
    }
    BRANCH_CALENDAR aux = a[index];
    a[index] = val;
    shift_right_branchCalendar(a, index + 1, aux, size);
}

/**
 * reorganiza o array no casp de um delete
 * @param a  estreutura dos calendarios
 * @param index  posicao onde vai ser adicionado
 * @param size  tamanho do array
 */
void shift_left_branchCalendar(BRANCH_CALENDAR *a, int index, unsigned size) {
    if (index == size - 1) {
        a[index].plataforms.platform = -1;
        return;
    }
    a[index] = a[index + 1];
    shift_left_branchCalendar(a, index + 1, size);
}


