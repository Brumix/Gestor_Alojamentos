//
// Created by Bruno Miguel on 23/11/2020.
//

#include "price.h"

int SIZEARRAY = INICIAL;
int POSICIONPRICE = 0;

/**
 * cria um array de preco
 * @return array
 */
PRICE *createPriceArray() {
    PRICE *price = malloc(INICIAL * sizeof(PRICE));
    ERRORMESSAGE(price == NULL, "[MALLOC PRICE]");
    return price;
}

/**
 * reajustar o tamanho do array
 * @param price array dos precos
 */
void resizeArray(PRICE **price) {
    if (SIZEARRAY * 0.6 <= POSICIONPRICE) {
        SIZEARRAY *= 2;
        *price = (PRICE *) realloc(*price, SIZEARRAY * sizeof(PRICE));
        ERRORMESSAGE(price == NULL, "[RESIZE PRICE]");
    }
}

/**
 * adiciona um proprieadade de preco ao array
 * @param array  array dos precos
 * @param type tipo dos precos
 * @param valor percentual do preco
 */
void add_price(PRICE *array, char *type, float valor) {
    resizeArray(&array);
    array[POSICIONPRICE].price = valor;
    array[POSICIONPRICE].type = type;
    POSICIONPRICE++;
}

/**
 * imprime o array dos precos
 * @param price  array de precos
 */
void printprice(PRICE *price) {
    for (int i = 0; i < POSICIONPRICE; i++) {
        printf("%s >>%.2f\n", price[i].type, price[i].price);
    }
}

/**
 * retorna a posicao do argomento para saber a percentagem a aplicar
 * @param price array dos precos
 * @param type tipo de preco
 * @return float preco
 */
float findprice(PRICE *price, char *type) {
    for (int i = 0; i < POSICIONPRICE; ++i) {
        if (strcmp(price[i].type, type) == 0)
            return price[i].price;
    }
    printf("type:%s\n", type);
    float val = atoi(type);
    printf("%.2f\n", val);
    return val;
}

/**
 * calcula o custo de um evento comforme um evento
 * @param price array dos precos
 * @param baseprice preco base
 * @param argc argumentos para calcular o preco
 * @param ... lista dos argumentos
 * @return float preco final
 */
float calculate_price(PRICE *price, float baseprice, int argc, ...) {
    float finalprice = baseprice;
    float increase;
    va_list intArgumentPointer;
    va_start(intArgumentPointer, argc);
    for (int i = 0; i < argc; i++) {
        increase = findprice(price, va_arg(intArgumentPointer, char*));
        if (increase >= 1)
            finalprice *= increase;
        else
            finalprice -= finalprice * increase;
    }
    va_end(intArgumentPointer);
    return finalprice;
}