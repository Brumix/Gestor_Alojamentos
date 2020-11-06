
#include "estruturas.h"


int main() {
    printf("GESTOR ALOJAMENTOS\n\n");

    EDIFICIOS *edificioHead = NULL;

    LOCALIZACAO *loc1 = add_localizacao("Porto", "Avenida dos Aliados", 112);
    add_edificio(&edificioHead, "Hotel 1", loc1);
    LOCALIZACAO *loc2 = add_localizacao("Lisboa", "Marques do Pombal", 234);

    add_edificio(&edificioHead, "Hotel 2", loc2);
    add_edificio(&edificioHead,"Hotel 2",loc1);

    add_andar_hotel("Hotel 1",1,edificioHead);
    add_andar_hotel("Hotel 1",2,edificioHead);
    add_andar_hotel("Hotel 1",3,edificioHead);
    add_andar_hotel("Hotel 2",4,edificioHead);
    add_andar_hotel("Hotel 2",5,edificioHead);
    add_andar_hotel("Hotel 3",6,edificioHead);

    print_edificios(edificioHead);
    return 0;
}
