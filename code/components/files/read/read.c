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
         printf("%d// %s// %s// %s// %s// %s \n",index,nome,latitude,longitude,morada,tempPrice);
    }
    fclose(file_read);
}

void read_file_studio_politics() {

    FILE *file_read = fopen(FILESTUDIO_POLITICS, "r");
    ERRORMESSAGE(file_read == NULL, "[FILE STUDIO POLITICS]");
    int edificio = 0;
    char *politica = malloc(25 * sizeof(char *));
    float regras[3];

    fscanf(file_read, "%*s");
    while (!feof(file_read)) {
        fscanf(file_read, "%d", &edificio);
        fscanf(file_read, " %*s %[^,]s", politica);
        fscanf(file_read, " %*s ");
        fscanf(file_read, " %f %f %f ", &regras[0], &regras[1], &regras[2]);


        printf("%d  // %s // %f //%f// %f \n ", edificio, politica, regras[0], regras[1], regras[2]);
    }
    fclose(file_read);
}