//
// Created by Bruno Miguel on 20/11/2020.
//

#include "branch_calendar.h"

/**
 * adiciona um evento ao calendario branch
 * @param studios estrutura
 * @param platform  plataforma
 */
void add_branch_calendar(STUDIOS *studios, PLATFORM platform, unsigned priority, char *politics) {
    resize_branch_calendar(studios);
    BRANCH_CALENDAR temp = create_branch_calendar(platform, priority, politics);
    for (int i = 0; i < studios->sizeArrayBranch; i++) {
        if (i == studios->number_branch) {
            studios->branch_calendar[studios->number_branch] = temp;
            studios->number_branch++;
            return;
        }
        EXISTENTE(studios->branch_calendar[i].platform == platform, "[BRANCH CALENDAR EXISTENTE]");

        if (studios->branch_calendar[i].priority > temp.priority) {
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
BRANCH_CALENDAR *find_branch_calendar(STUDIOS *studios, int low, int high, PLATFORM platform) {
    if (low >= high || high <= low)
        return NULL;
    int mid = low + (high - low) / 2;
    if (studios->branch_calendar[mid].platform == platform)
        return &studios->branch_calendar[mid];
    if (studios->branch_calendar[low].platform == platform)
        return &studios->branch_calendar[low];
    if (studios->branch_calendar[high].platform == platform)
        return &studios->branch_calendar[high];
    if (studios->branch_calendar[mid].platform > platform)
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
        if (studios->branch_calendar[i].platform == platform) {
            shift_left_branchCalendar(studios->branch_calendar, i, studios->number_branch);
            studios->number_branch--;
            return;
        }
    }
    printf("[BRANCH CALENDAR NAO ENCONTRADO]\n");
}


/**
 * imprime todos os calendarios
 * @param studios estrutura onde estao guardados
 */
void print_branch_calendar(STUDIOS *studios) {
    printf("BRANCH CALENDAR\n");
    for (int i = 0; i < studios->number_branch; ++i) {
        BRANCH_CALENDAR *branchCalendar = &studios->branch_calendar[i];
        printf("PRIORIDADE: %u\n", branchCalendar->priority);
        printf("PLATAFORMA: %s\n", strPlatform(branchCalendar->platform));
        printf("POLITIC: %s\n", branchCalendar->politics);
        print_config(branchCalendar->configuration);
    }

}


void print_branch_calendar_unique(BRANCH_CALENDAR *branchCalendar) {
    printf("BRANCH CALENDAR\n");
    printf("PRIORIDADE: %u\n", branchCalendar->priority);
    printf("PLATAFORMA: %s\n", strPlatform(branchCalendar->platform));
    printf("POLITIC: %s\n", branchCalendar->politics);
    print_config(branchCalendar->configuration);


}

/**
 * cria um branch_calendar
 * @param politicsS struct politicas
 * @param platform plataforma
 * @param priority prioridade
 * @param politics nome da politica a implementar
 * @return branch_calendar criado
 */
BRANCH_CALENDAR create_branch_calendar(PLATFORM platform, unsigned priority, char *politics) {
    BRANCH_CALENDAR branchCalendar;
    branchCalendar.platform = platform;
    branchCalendar.priority = priority;
    branchCalendar.politics = malloc(4 * sizeof(char *));
    strcpy(branchCalendar.politics, politics);
    branchCalendar.branch_event = NULL;
    branchCalendar.configuration = NULL;
    combine_config(&branchCalendar);
    return branchCalendar;
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
        a[index].platform = -1;
        return;
    }
    a[index] = a[index + 1];
    shift_left_branchCalendar(a, index + 1, size);
}

/**
 * adiciona um configuracao á politica
 * @param pConfiguration  configuracao
 * @param name  nome
 * @param value valor
 */
void add_config(CONFIGURATION **pConfiguration, char *name, float value) {
    CONFIGURATION *temp = (CONFIGURATION *) malloc(sizeof(CONFIGURATION));
    temp->name = malloc(25 * sizeof(char *));
    strcpy(temp->name, name);
    temp->value = value;
    temp->next = *pConfiguration;
    *pConfiguration = temp;

}

/**
 * imprime as configuracoes
 * @param configuration  configuracao struct
 */
void print_config(CONFIGURATION *configuration) {
    CONFIGURATION *current = configuration;
    printf("CONFIGURATION\n");
    while (current != NULL) {
        printf("NAME:%s\n", current->name);
        printf("VALUE: %.2f \n", current->value);
        current = current->next;
    }

}

/**
 * combina as configuracoes
 * @param politics struct politicas
 * @param branchCalendar struct branch_calendar
 */
void combine_config(BRANCH_CALENDAR *branchCalendar) {
    POLITICS *current = politics;
    while (current != NULL) {
        if (strcmp(current->name, branchCalendar->politics) == 0 && current->platform == branchCalendar->platform) {
            CONFIGURATION *configPrinc = current->configuration;
            CONFIGURATION **configBranch = &branchCalendar->configuration;
            while (configPrinc != NULL) {
                add_config(configBranch, configPrinc->name, -1);
                configPrinc = configPrinc->next;
            }
        }
        current = current->next;
    }
}

/**
 * adicionar um valor á combifuracao previament combinada
 * @param pConfiguration  struct combinacao
 * @param value  valor a implementar
 */
void add_value_config(CONFIGURATION **pConfiguration, float value) {
    CONFIGURATION *current = *pConfiguration;
    ERRORMESSAGE(current == NULL, "[CONFIGURATION ADD VALUE: CONFIGURACAO VAIZA]");
    while (current != NULL) {
        if (current->value == -1) {
            current->value = value;
            return;
        }
        current = current->next;
    }
}


void add_specif_event(BUILDINGS *head, DATE begin, DATE end, int dias, char *buildingname, int n_pessoas) {
    BUILDINGS *buildings = find_building_by_name(head, buildingname);
    EXISTENTE(buildings == NULL, "[EDIFICIO NAO EXISTENTE]");
    EXISTENTE(getDifferenceDays(begin, end) < dias, "[INTERVALO DE TEMPO DEMASIADO CURTO]");
    PEOPLE_ALOCATED *peopleAlocated = NULL;
    if (check_people_can_have(begin, end, buildings, dias, n_pessoas, &peopleAlocated) == 0) {
        printf("NAO FOU POSSIVEL ENCONTRAR UMA VAGA\n");
        return;
    } else {
        print_people_alocated(peopleAlocated, n_pessoas);
    }
}

int
check_people_can_have(DATE begin, DATE end, BUILDINGS *head, int dias, int n_people, PEOPLE_ALOCATED **peopleAlocated) {

    BUILDINGS *buildings = head;
    DATE data_check_begin = begin;
    DATE data_check_end = addDays(data_check_begin, dias);
    int alocated = 0, temp;
    while (1) {
        for (int i = 0; i < buildings->num_studios; ++i) {
            STUDIOS studios = buildings->studios[i];
            temp = people_alocated(data_check_begin, data_check_end, studios.masterEvents, studios.typeStudio);
            if (temp >= n_people) {
                add_people_alocated(peopleAlocated, data_check_begin, data_check_end, temp, studios.index);
                return 1;
            }
            if (temp > 0) {
                add_people_alocated(peopleAlocated, data_check_begin, data_check_end, temp, studios.index);
                alocated += temp;
            }
            if (alocated >= n_people)
                return 1;
        }
        alocated = 0;
        data_check_begin = addDays(data_check_begin, 1);
        data_check_end = addDays(data_check_begin, dias);
        if (getDifferenceDays(data_check_begin, end) < dias)
            return 0;
    }


}

int people_alocated(DATE begin, DATE end, MASTER_EVENTS *masterEvents, TYPE_STUDIO typeStudio) {
    int alocated = 0;
    MASTER_EVENTS *temp = masterEvents;
    while (temp != NULL) {
        if (compare_date(begin, temp->date_begin) == 1 && compare_date(end, temp->date_end) == -1) {
            alocated = 1;
            break;
        }
        temp = temp->next;
    }
    if (alocated == 0)
        return getPeople_TypeStudio(typeStudio);
    return 0;
}


void add_people_alocated(PEOPLE_ALOCATED **peopleAlocated, DATE begin, DATE end, int n_people, int index) {
    PEOPLE_ALOCATED *temp = malloc(sizeof(PEOPLE_ALOCATED));
    temp->n_people = n_people;
    temp->index = index;
    temp->begin = begin;
    temp->end = end;
    temp->next = NULL;

    temp->next = (*peopleAlocated);
    (*peopleAlocated) = temp;
}

void print_people_alocated(PEOPLE_ALOCATED *peopleAlocated, int n_people) {
    printf("EXISTE VAGA NO PERIODO DE TEMPO\n");
    print_date(peopleAlocated->begin);
    print_date(peopleAlocated->end);
    printf("NOS SEGINTES ESTUDIOS:\n");
    PEOPLE_ALOCATED *temp = peopleAlocated;
    int aloced = 0;
    while (temp != NULL) {
        aloced = n_people - (n_people - temp->n_people);
        if (aloced > 0)
            printf("\tESTUDIO: %i PARA %i PESSOAS\n", temp->index, aloced);
        else
            printf("\tESTUDIO: %i PARA %i PESSOAS\n", temp->index, aloced);

        temp = temp->next;
    }
}


void add_branch_calendar_merge(STUDIOS *studios, PLATFORM platform, unsigned priority, char *politics) {
    resize_branch_calendar(studios);
    BRANCH_CALENDAR temp = create_branch_calendar(platform, priority, politics);
    studios->branch_calendar[studios->number_branch] = temp;
    studios->number_branch++;

}

void sort_branch_calendar(BUILDINGS *head) {
    BUILDINGS *buildings = head;
    while (buildings != NULL) {
        for (int i = 0; i < buildings->num_studios; ++i) {
            STUDIOS studios = buildings->studios[i];
            quicksort(studios.branch_calendar, 0, (int) studios.number_branch);
        }
        buildings = buildings->next;
    }


}


void quicksort(BRANCH_CALENDAR a[], int lo, int hi) {
    if (hi <= lo) return;
    int j;
    j = partitionQuicksort(a, lo, hi);

    quicksort(a, lo, j - 1);
    quicksort(a, j + 1, hi);
}

int partitionQuicksort(BRANCH_CALENDAR a[], int lo, int hi) {
    int i = lo, j = hi;
    BRANCH_CALENDAR aux;

    while (1) {
        while (a[++i].priority < a[lo].priority) {

            if (i == hi) break;
        }
        while (a[--j].priority > a[lo].priority) {

            if (j == lo) break;
        }
        if (i >= j) break; // check if pointers cross


        aux = a[i];
        a[i] = a[j];
        a[j] = aux; // swap
    }

    aux = a[lo];
    a[lo] = a[j];
    a[j] = aux;
    return j;
}