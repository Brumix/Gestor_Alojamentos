
#include "estruturas.h"


int main() {
    printf("GESTOR ALOJAMENTOS\n\n");

    EDIFICIOS *edificioHead = NULL;

    LOCALIZACAO *loc1 = add_localizacao("Porto", "Avenida dos Aliados", 112);
    add_edificio(&edificioHead, "Hotel 1", loc1);
    LOCALIZACAO *loc2 = add_localizacao("Lisboa", "Marques do Pombal", 234);


    add_andar_hotel("Hotel 1", 1, edificioHead);
    add_andar_hotel("Hotel 1", 2, edificioHead);
    add_estudio(&edificioHead->andar[0], 0);
    add_estudio(&edificioHead->andar[0], 1);
    add_estudio(&edificioHead->andar[1], 2);
    add_estudio(&edificioHead->andar[1], 3);


    add_edificio(&edificioHead, "Hotel 2", loc2);
    add_edificio(&edificioHead, "Hotel 2", loc1);
    add_andar_hotel("Hotel 3", 2, edificioHead);

    add_andar_hotel("Hotel 2", 1, edificioHead);

    add_estudio(&edificioHead->andar[0], 0);
    add_estudio(&edificioHead->andar[0], 1);
    print_edificios(edificioHead);
    return 0;
}
