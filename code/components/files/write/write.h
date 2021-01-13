//
// Created by Bruno Miguel on 21/12/2020.
//

#ifndef GESTOR_ALOJAMENTOS_WRITE_H
#define GESTOR_ALOJAMENTOS_WRITE_H

#include "../../../main/structures.h"

void write_file_append(char *filename, char *text);

void inicial_declaration(char *filename, DATE begin, DATE end);

void end_declaration(char *filename);

void write_buildings(BUILDINGS *head);

void write_studio(BUILDINGS *head);

void write_history(HISTORY *head);

void write_events(BUILDINGS *head);


void write_file_bin(char *filename, char *text);


#endif //GESTOR_ALOJAMENTOS_WRITE_H
