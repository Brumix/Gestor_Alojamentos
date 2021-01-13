//
// Created by Bruno Miguel on 20/11/2020.
//

#ifndef GESTOR_ALOJAMENTOS_ENUM_H
#define GESTOR_ALOJAMENTOS_ENUM_H

#include "../../main/structures.h"


char *strTypeStudio(TYPE_STUDIO ts);

TYPE_STUDIO enumTypeStudio(char *ts);

int getPeople_TypeStudio(TYPE_STUDIO ts);

char *strPlatform(PLATFORM platform);

PLATFORM enumTypePlataform(char *ts);

char *strTypePeople(TYPE_PEOPLE typePeople);

TYPE_PEOPLE enumTypePeople(char * s);

char *strTypeBranchEvent(TYPE_BRANCH_EVENT typeBranchEvent);

char *strMasterEvent(TYPE_MASTER_EVENT typeMasterEvent);

#endif //GESTOR_ALOJAMENTOS_ENUM_H
