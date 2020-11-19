//
// Created by Bruno Miguel on 18/11/2020.
//

#include "location.h"


GPS *add_gps(char *lat, char *lon) {
    GPS *temp = (GPS *) malloc(sizeof(GPS));
    if (temp == NULL) {
        perror("[ADD GPS]");
        exit(-1);
    }
    temp->latitude = lat;
    temp->longitude = lon;
    return temp;
}

LOCATION *add_location(char *address, char *lat, char *lon) {
    LOCATION *temp = (LOCATION *) malloc(sizeof(LOCATION));
    if (temp == NULL) {
        perror("[ADD LOCALIZACAO]");
        exit(-1);
    }
    temp->address = address;
    temp->gps = add_gps(lat, lon);
}

void print_location(LOCATION *loc) {
    printf("LOCALIZACAO:  ");
    printf("MORADA: %s  ", loc->address);
    printf("LATITUDE: %s  ", loc->gps->latitude);
    printf("LONGUITUDE: %s  ", loc->gps->longitude);
    printf("\n");
}