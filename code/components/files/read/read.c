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

    char *name = (char *) malloc(25 * sizeof(char *));
    char *plataform = (char *) malloc(25 * sizeof(char *));
    char *regras = (char *) malloc(25 * sizeof(char *));
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
    int j=2;
    fscanf(file_read, "%*s");
    while (!feof(file_read)) {
        fscanf(file_read, "%d", &estudio);
        fscanf(file_read, " %*s %[^,]s", politica);
        fscanf(file_read, " %*s ");
       STUDIOS *indexstudio= find_studio_everyhere(buildings,estudio);
        ERRORMESSAGE(indexstudio==NULL,"[READ FILE ESTUDIO:ESTUDIO INEXISTENTE]");


        printf(" %i estudio=%d index=%i  %s \n",indexstudio->index,estudio,indexstudio->index,politica);

        POLITICS *findPolitics= find_politics(politica);
        ERRORMESSAGE(findPolitics==NULL,"[READ FILE ESTUDIO:POLITICA INEXISTENTE]");

        add_branch_calendar(indexstudio,findPolitics->platform,1,findPolitics->name);

        CONFIGURATION * pConfiguration=indexstudio->branch_calendar[indexstudio->number_branch -1].configuration;


        printf(" Iteracao =%i\n",j);


        j++;
        for (int i = 0; i < findPolitics->size; i++) {
            fscanf(file_read, " %f ", &re);
            add_value_config(&pConfiguration,re);
        }
        printf("\n");
    }
    fclose(file_read);
}
