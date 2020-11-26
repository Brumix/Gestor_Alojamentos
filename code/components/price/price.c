//
// Created by Bruno Miguel on 23/11/2020.
//

#include "price.h"

int SIZEARRAY = INICIAL;
int POSICIONPRICE = 0;


PRICE *createPriceArray() {
    PRICE *price = malloc(INICIAL * sizeof(PRICE));
    return price;
}

void resizeArray(PRICE *price) {
    if (SIZEARRAY <= POSICIONPRICE * 0.8) {
        SIZEARRAY *= 2;
        price = (PRICE *) realloc(price, SIZEARRAY * sizeof(PRICE));
        if (price == NULL) {
            perror("[RESIZE PRICE]");
            exit(EXIT_FAILURE);
        }
    }
}

void addprice(PRICE *array, char *type, float valor) {

    array[POSICIONPRICE].price = valor;
    array[POSICIONPRICE].type = type;
    POSICIONPRICE++;
}

void printprice(PRICE *price) {

    for (int i = 0; i < POSICIONPRICE; i++) {
        printf("%s >>%.2f\n", price[i].type, price[i].price);
    }
}

float findprice(PRICE *price, char *type) {
    for (int i = 0; i < POSICIONPRICE; ++i) {
        if (strcmp(price[i].type, type) == 0)
            return price[i].price;
    }
    return 1;
}

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