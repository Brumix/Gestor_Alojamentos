#include <stdio.h>
#include "estruturas.h"


int main() {
    printf("GESTOR ALOJAMENTOS\n\n");

    EDIFICIOS *edificioHead = NULL;
    LOCALIZACAO *loc1 = addlocalizacao("Porto","Avenida dos Aliados",112);
    add_edificio(&edificioHead, "Hotel 1",loc1);
    LOCALIZACAO *loc2=addlocalizacao("Porto","Avenida dos Aliados",116);
    add_edificio(&edificioHead, "Hotel 2",loc2);

    print_edificios(&edificioHead);
    return 0;
}
