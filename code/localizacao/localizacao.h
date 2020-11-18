//
// Created by Bruno Miguel on 18/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_LOCALIZACAO_H
#define GESTOR_ALOJAMENTOS_LOCALIZACAO_H

#include "../main/estruturas.h"


GPS *add_gps(char *lat, char *lon);

LOCALIZACAO *add_localizacao(char *morada, char *lat, char *lon);

void print_localizacao(LOCALIZACAO *loc);

#endif //GESTOR_ALOJAMENTOS_LOCALIZACAO_H
