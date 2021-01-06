//
// Created by Bruno Miguel on 02/01/2021.
//

#include "politics.h"

/**
 * adiciona um politica
 * @param name nome da politica
 * @param platform plataforma
 * @param size tamanho das configuracoes
 */
void add_politics(char *name, PLATFORM platform, int size) {
    POLITICS *temp = create_politics(name, platform, size);
    temp->next = politics;
    politics = temp;
}

/**
 * cria uma politica
 * @param name nome de politica
 * @param platform plataforma
 * @param size tamanho das configuracoes
 * @return
 */
POLITICS *create_politics(char *name, PLATFORM platform, int size) {
    POLITICS *temp = (POLITICS *) malloc(sizeof(POLITICS));
    ERRORMESSAGE(temp == NULL, "[POLITICS EDIFICIO]");
    temp->name = malloc(25 * sizeof(char));
    strcpy(temp->name, name);
    temp->platform = platform;
    temp->size = size;
    temp->configuration = NULL;
    return temp;
}
/**
 * imprime todas as politicas
 */
void print_politics() {
    POLITICS *current = politics;
    while (current != NULL) {
        printf("NAME: %s \n", current->name);
        printf("PLATAFORMA: %s \n", strPlatform(current->platform));
        current = current->next;
    }

}

/**
 * pesquisa por uma politica
 * @param politic struct politic
 * @return POLITICS *
 */
POLITICS *find_politics(char *politic) {
    POLITICS *current = politics;
    while (current != NULL) {
        if (strcmp(current->name, politic) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}