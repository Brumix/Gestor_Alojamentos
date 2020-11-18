
#include "estruturas.h"


int main() {
    printf("GESTOR ALOJAMENTOS\n\n");

    LOCALIZACAO *loc1 = add_localizacao("Rua dos hereois", "34569N", "49657E");
    LOCALIZACAO *loc2 = add_localizacao("Rua dos animais", "3675455S", "93884O");
    EDIFICIOS *ediciohead = NULL;
    add_edificio(&ediciohead, "Edificio1", loc1);
    add_edificio(&ediciohead, "Edificio2", loc2);
    print_edificios_all(ediciohead);
    return 0;
}
