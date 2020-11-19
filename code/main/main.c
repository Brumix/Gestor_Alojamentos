
#include "structures.h"


int main() {
    printf("GESTOR ALOJAMENTOS\n\n");

    LOCATION *loc1 = add_location("Rua dos hereois", "34569N", "49657E");
    LOCATION *loc2 = add_location("Rua dos animais", "3675455S", "93884O");
    BUILDINGS *buildings = NULL;
    add_building(&buildings, "Edificio1", loc1);
    add_building(&buildings, "Edificio2", loc2);
    print_building_all(buildings);
    return 0;
}
