//
// Created by Bruno Miguel on 18/11/2020.
//

#include "location.h"

/**
 * cria umas coordenadas
 * @param lat  latitude
 * @param lon longuitude
 * @return gps
 */
GPS add_gps(char *lat, char *lon) {
    GPS temp;
    temp.longitude=malloc(25* sizeof(char *));
    temp.latitude=malloc(25* sizeof(char *));
    strcpy(temp.longitude, lon);
    strcpy(temp.latitude, lat);
    return temp;
}


/**
 * cria uma localizacao
 * @param city cidade
 * @param address morada
 * @param lat latirude
 * @param lon longuitude
 * @return localizacao
 */
LOCATION add_location(char *address, char *lat, char *lon) {
    LOCATION temp;
    temp.address=(char *)malloc(25* sizeof(char *));
    strcpy( temp.address, address);
    temp.gps = add_gps(lat, lon);
    return temp;
}

/**
 * imprime uma localizacao
 * @param loc localizacao
 */
void print_location(LOCATION loc) {
    printf("LOCALIZACAO:  ");
    printf("MORADA: %s  ", loc.address);
    printf("LATITUDE: %s  ", loc.gps.latitude);
    printf("LONGUITUDE: %s  ", loc.gps.longitude);
    printf("\n");
}