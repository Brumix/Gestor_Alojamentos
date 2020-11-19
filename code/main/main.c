
#include "structures.h"


int main(void) {
    printf("GESTOR ALOJAMENTOS\n\n");

    BUILDINGS *buildings = NULL;
    LOCATION loc1 = add_location("Rua dos hereois", "34569N", "49657E");
    LOCATION loc2 = add_location("Rua dos animais", "3675455S", "93884O");
    add_building(&buildings, "Edificio1", loc1);
    add_building(&buildings, "Edificio2", loc2);

   add_studio(buildings, (TYPE_STUDIO) T2, 12, 1);
    add_studio(buildings, (TYPE_STUDIO) T2, 12, 2);
    add_studio(buildings, (TYPE_STUDIO) T3D, 12, 3);
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 4);



    print_building_all(buildings);

    return 0;
}
