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
        case AisBnE:
            return "AisBnE";
        default:
            return "Nao existente";
    }
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
        default:
            return "Nao existente";
    }
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

