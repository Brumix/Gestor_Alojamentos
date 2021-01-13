//
// Created by Bruno Miguel on 21/12/2020.
//

#include "read.h"


void read_file_buildigns(BUILDINGS **buildings) {
    FILE *file_read = fopen(FILEBUILDINGS, "r");
    ERRORMESSAGE(ferror(file_read), "[FILE BUILDINGS]");
    unsigned index;
    char *nome = (char *) malloc(25 * sizeof(char *));
    char *latitude = (char *) malloc(25 * sizeof(char *));
    char *longitude = (char *) malloc(25 * sizeof(char *));
    char *morada = (char *) malloc(25 * sizeof(char *));
    char *tempPrice = (char *) malloc(25 * sizeof(char *));
    float preco;
    fscanf(file_read, "%*s");
    while (!feof(file_read)) {
        fscanf(file_read, "%d", &index);
        fscanf(file_read, " %*s %[^,]s", nome);
        fscanf(file_read, " %*s %[^,]s", latitude);
        fscanf(file_read, " %*s %[^,]s", longitude);
        fscanf(file_read, " %*s %[^,]s", morada);
        fscanf(file_read, " %*s %[^\n]s ", tempPrice);
        preco = atof(tempPrice);
        LOCATION loc1 = add_location(morada, latitude, longitude);
        add_building(buildings, index, nome, preco, loc1);
    }
    fclose(file_read);
}

void read_file_estudio(BUILDINGS *buildings) {
    FILE *file_read = fopen(FILESTUDIOS, "r");
    ERRORMESSAGE(file_read == NULL, "[FILE STUDIO POLITICS]");
    int estudio = 0, numero = 0, edificio = 0, area = 0;
    char *configuracao = malloc(25 * sizeof(char *));
    fscanf(file_read, "%*s");
    while (!feof(file_read)) {
        fscanf(file_read, "%d", &estudio);
        fscanf(file_read, " %*s %d", &numero);
        fscanf(file_read, " %*s %d", &edificio);
        fscanf(file_read, " %*s %[^,]s", configuracao);
        fscanf(file_read, " %*s %d", &area);
        BUILDINGS *head = find_building(buildings, edificio);
        ERRORMESSAGE(head == NULL, "[READ STUDIOS: EDIFICIO NÂO ENCONTRADO]");
        ERRORMESSAGE(enumTypeStudio(configuracao) == NE, "[READ STUDIO: TIPO DE ESTUDIO INEXISTENTE]");
        add_studio(head, enumTypeStudio(configuracao), estudio, numero, area);
        // printf("%d  // %d // %d //%d// %d \n ", estudio, numero, edificio,enumTypeStudio(configuracao), area);
    }
    fclose(file_read);
}


void read_politics() {

    FILE *file_read = fopen(FILEPOLITICS, "r");
    ERRORMESSAGE(file_read == NULL, "[FILE POLITICS]");

    char *name = (char *) malloc(4 * sizeof(char *));
    char *plataform = (char *) malloc(10 * sizeof(char *));
    char *regras = (char *) malloc(12 * sizeof(char *));
    int sizerules[3] = {3, 3, 4}; // todo turn this dynamic
    int size = 0;

    fscanf(file_read, "%*s");
    while (!feof(file_read)) {
        fscanf(file_read, " %s  %*s", name);
        fscanf(file_read, " %s  %*s", plataform);
        add_politics(name, enumTypePlataform(plataform), sizerules[size]);
        for (int i = 0; i < sizerules[size]; i++) {
            fscanf(file_read, " %s  ", regras);
            add_config(&politics->configuration, regras, -1);
        }
        size++;
    }
    fclose(file_read);
}


void read_file_studio_politics(BUILDINGS *buildings) {
    FILE *file_read = fopen(FILESTUDIO_POLITICS, "r");
    ERRORMESSAGE(file_read == NULL, "[FILE STUDIO POLITICS]");

    unsigned estudio = 0;
    char *politica = malloc(25 * sizeof(char *));
    float re;
    int num;
    int priority[] = {1, 10, 100};
    fscanf(file_read, "%*s");
    while (!feof(file_read)) {
        fscanf(file_read, "%d", &estudio);
        fscanf(file_read, " %*s %[^,]s", politica);
        fscanf(file_read, " %*s  ");
        STUDIOS *studios = find_studio_everyhere(buildings, estudio);
        ERRORMESSAGE(studios == NULL, "[READ FILE ESTUDIO:ESTUDIO INEXISTENTE]");
        POLITICS *findPolitics = find_politics(politica);
        ERRORMESSAGE(findPolitics == NULL, "[READ FILE ESTUDIO:POLITICA INEXISTENTE]");
        num = (rand() % 3);
        add_branch_calendar(studios, findPolitics->platform, priority[num - 1], findPolitics->name);
        CONFIGURATION *pConfiguration = studios->branch_calendar[studios->number_branch - 1].configuration;

        for (int i = 0; i < findPolitics->size; i++) {
            fscanf(file_read, " %f ", &re);
            add_value_config(&pConfiguration, re);
        }
        // printf("Estudio:%u\n",studios->num_door);
        //  printf("ESTUDIO ID:%u \n",studios->index);
        // printf("NAME: %s\n",studios->branch_calendar[studios->number_branch - 1].politics);
        // print_config(pConfiguration);
        // printf("##############################\n\n");
    }
    fclose(file_read);
}


void read_events(BUILDINGS *buildings, PEOPLE *people) {
    FILE *file_read = fopen(FILEEVENTS, "r");
    ERRORMESSAGE(file_read == NULL, "[FILE EVENT]");
    int id = 0, num;
    char *name = (char *) malloc(25 * sizeof(char *));
    int day = 0, month = 0, year = 0;
    int hospede;
    int estudio;
    char *plataforma = (char *) malloc(25 * sizeof(char *));
    fscanf(file_read, "%*s");
    while (!feof(file_read)) {
        fscanf(file_read, "%d %*s", &id);
        fscanf(file_read, " %[^,]s", name);
        fscanf(file_read, " %*s %d", &year);
        fscanf(file_read, " %*s %d", &month);
        fscanf(file_read, " %*s %d", &day);
        DATE begin = add_date(day, month, year);
        fscanf(file_read, " %*s %d", &year);
        fscanf(file_read, " %*s %d", &month);
        fscanf(file_read, " %*s %d", &day);
        fscanf(file_read, " %*s %d", &hospede);
        fscanf(file_read, " %*s %d", &estudio);
        fscanf(file_read, " %*s %s ", plataforma);
        DATE end = add_date(day, month, year);
        PLATFORM platform = enumTypePlataform(plataforma);
        if (platform == NP) {
            STUDIOS *studios = find_studio_everyhere(buildings, estudio);
            PEOPLE *peoplefind = find_people(people, 4);
            ERRORMESSAGE(peoplefind == NULL, "[READ FILE ESTUDIO:PESSOA INEXISTENTE]");
            add_master_event(&studios->masterEvents, enumTypePlataform(plataforma), peoplefind, end, -50, MANUTENCAO,
                             begin);
        } else {
            STUDIOS *studios = find_studio_everyhere(buildings, estudio);
            num = (rand() % 3) + 1;
            PEOPLE *findPeople = find_people(people, num);
            ERRORMESSAGE(findPeople == NULL, "[READ FILE ESTUDIO:PESSOA INEXISTENTE]");
            BRANCH_CALENDAR *branchCalendar = find_branch_calendar(studios, 0, (int) studios->number_branch,
                                                                   platform);
            if (branchCalendar == NULL) {
                printf(" [READ FILE EVENTS:  BRANCH CALENDAR NAO EXISTENTE]\n");
                continue;
            }
            add_branch_event(buildings, &branchCalendar->branch_event, id, begin, end, RESERVADO, findPeople);
        }
    }
    fclose(file_read);
}

void read_people(PEOPLE **people) {
    FILE *file_read = fopen(FILEPEOPLE, "r");
    ERRORMESSAGE(file_read == NULL, "[FILE EVENT]");
    char *name = (char *) malloc(17 * sizeof(char *));
    char *apelido = (char *) malloc(7 * sizeof(char *));
    char *type = (char *) malloc(7 * sizeof(char *));
    while (!feof(file_read)) {
        fscanf(file_read, "%s %s %s", name, apelido, type);
        strcat(name, " ");
        strcat(name, apelido);
        add_people(people, name, enumTypePeople(type));
    }
    fclose(file_read);
}

void read_bin(char *file) {
    FILE *fp = fopen(file, "rb");
    char *bin = malloc(100 * sizeof(char));
    while (!feof(fp)) {
        fread(&bin, sizeof bin, 1, fp);
        printf("%s\n", bin);
    }
    fclose(fp);


}


void read_building_bin() {

    read_bin(FILEBUILDING_BIN);


}

void read_studio_bin() {
    read_bin(FILESTUDIO_BIN);
}

void read_history_bin() {
    read_bin(FILEHISTORY_BIN);
}