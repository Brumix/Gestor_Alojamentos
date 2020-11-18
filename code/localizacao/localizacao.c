//
// Created by Bruno Miguel on 18/11/2020.
//

#include "localizacao.h"


GPS *add_gps(char *lat, char *lon) {
    GPS *temp = (GPS *) malloc(sizeof(GPS));
    if (temp == NULL) {
        perror("[ADD GPS]");
        exit(-1);
    }
    temp->latitude = lat;
    temp->longuitude = lon;
    return temp;
}

LOCALIZACAO *add_localizacao(char *morada, char *lat, char *lon) {
    LOCALIZACAO *temp = (LOCALIZACAO *) malloc(sizeof(LOCALIZACAO));
    if (temp == NULL) {
        perror("[ADD LOCALIZACAO]");
        exit(-1);
    }
    temp->morada = morada;
    temp->gps = add_gps(lat, lon);
}

void print_localizacao(LOCALIZACAO *loc) {
    printf("LOCALIZACAO:  ");
    printf("MORADA: %s  ", loc->morada);
    printf("LATITUDE: %s  ", loc->gps->latitude);
    printf("LONGUITUDE: %s  ", loc->gps->longuitude);
    printf("\n");
}