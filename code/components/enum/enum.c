//
// Created by Bruno Miguel on 20/11/2020.
//

#include "enum.h"

/**
 * print do enum STUDIO
 * @param ts emum studio
 * @return  string
 */
char *strTypeStudio(TYPE_STUDIO ts) {
    switch (ts) {
        case T0:
            return "T0";
        case T1:
            return "T1";
        case T2:
            return "T2";
        case T3:
            return "T3D";
        default:
            return "Nao existente";
    }
}


TYPE_STUDIO enumTypeStudio(char *ts) {

    if (strcmp(ts, "T0") == 0)
        return T0;
    if (strcmp(ts, "T1") == 0)
        return T1;
    if (strcmp(ts, "T2") == 0)
        return T2;
    if (strcmp(ts, "T3") == 0)
        return T3;
    else return NE;
}

/**
 * print do enum plataforma
 * @param platform  enum
 * @return  string
 */
char *strPlatform(PLATFORM platform) {
    switch (platform) {
        case AIRPlaces:
            return "AIRPlaces";
        case AirBnc:
            return "AirBnc";
        case AisBnD:
            return "AisBnD";
        case AirBnE:
            return "AirBnE";
        default:
            return "Nao existente";
    }
}

/**
 * transforma a string num enum
 * @param ts char*
 * @return enum
 */
PLATFORM enumTypePlataform(char *ts) {

    if (strcmp(ts, "airbnc") == 0 || strcmp(ts, "AirBnC") == 0)
        return AirBnc;
    if (strcmp(ts, "airbnd") == 0 || strcmp(ts, "AirBnD") == 0)
        return AisBnD;
    if (strcmp(ts, "AIRPlaces") == 0)
        return AIRPlaces;
    if (strcmp(ts, "airbne") == 0 || strcmp(ts, "AirBnE") == 0)
        return AirBnE;

    else return NP;
}

/**
 * print do enum people
 * @param typePeople  enum
 * @return string
 */
char *strTypePeople(TYPE_PEOPLE typePeople) {
    switch (typePeople) {
        case HOSPEDE:
            return "HOSPEDE";
        case EMPREGADO:
            return "EMPREGADO";
        case ORGANIZACAO:
            return "ORGANIZACAO";
        default:
            return "Nao existente";
    }
}

TYPE_PEOPLE enumTypePeople(char *ts) {


    if (strcmp(ts, "HOSPEDE") == 0)
        return HOSPEDE;
    if (strcmp(ts, "EMPREGADO") == 0)
        return EMPREGADO;
    if (strcmp(ts, "ORGANIZACAO") == 0)
        return ORGANIZACAO;

}


/**
 * print do enum branchevent
 * @param typeBranchEvent enum
 * @return string
 */
char *strTypeBranchEvent(TYPE_BRANCH_EVENT typeBranchEvent) {
    switch (typeBranchEvent) {
        case LIVRE:
            return "LIVRE";
        case RESERVADO:
            return "RESERVADO";
        default:
            return "Nao existente";
    }
}

/**
 * print do enum Masterevent
 * @param typeMasterEvent enum
 * @return string
 */
char *strMasterEvent(TYPE_MASTER_EVENT typeMasterEvent) {
    switch (typeMasterEvent) {
        case OCUPADO:
            return "OCUPADO";
        case LIMPEZA:
            return "LIMPEZA";
        case MANUTENCAO:
            return "MANUTENCAO";
        case FATURACAO:
            return "FATURACAO";
        case GREACAO_DE_RELATORIOS:
            return "GREACAO_DE_RELATORIOS";
        default:
            return "Nao existente";
    }
}

