#include <stdio.h>
#include "estruturas.h"


int main() {
    printf("GESTOR ALOJAMENTOS\n\n");

    EDIFICIOS *edificioHead = NULL;
    add_edificio(edificioHead, "1");
    add_edificio(edificioHead, "2");
    print_edificios(edificioHead);
    return 0;
}
