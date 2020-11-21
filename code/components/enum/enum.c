//
// Created by Bruno Miguel on 20/11/2020.
//

#include "enum.h"


char *strTypeStudio(TYPE_STUDIO ts) {
    switch (ts) {
        case T1:
            return "T1";
        case T2:
            return "T2";
        case T3D:
            return "T3D";
        case SUITE:
            return "SUITE";
        case SUITEPRESIDENCIAL:
            return "SUITEPRESIDENCIAL";
        default:
            return "Nao existente";
    }
}

char *strPlatform(PLATFORM platform) {
    switch (platform) {
        case AIRPlaces:
            return "AIRPlaces";
        case AirBnc:
            return "AirBnc";
        case AisBnD:
            return "AisBnD";
        case AisBnE:
            return "AisBnE";
        default:
            return "Nao existente";
    }
}

char *strTypePeople(TYPE_PEOPLE typePeople) {
    switch (typePeople) {
        case HOSPEDE:
            return "HOSPEDE";
        case EMPREGADO:
            return "EMPREGADO";
        default:
            return "Nao existente";
    }
}