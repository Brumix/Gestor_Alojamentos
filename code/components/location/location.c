//
// Created by Bruno Miguel on 18/11/2020.
//

#include "location.h"


GPS add_gps(char *lat, char *lon) {
    GPS temp ;
    temp.longitude=lon;
    temp.latitude=lat;
    return temp;
}

LOCATION add_location(char *address, char *lat, char *lon) {
    LOCATION temp ;
    temp.address = address;
    temp.gps = add_gps(lat, lon);
    return temp;
}

void print_location(LOCATION loc) {
    printf("LOCALIZACAO:  ");
    printf("MORADA: %s  ", loc.address);
    printf("LATITUDE: %s  ", loc.gps.latitude);
    printf("LONGUITUDE: %s  ", loc.gps.longitude);
    printf("\n");
}