
#include "estruturas.h"


int main() {
    printf("GESTOR ALOJAMENTOS\n\n");

    EDIFICIOS *edificioHead = NULL;
    LOCALIZACAO *loc1 = addlocalizacao("Porto","Avenida dos Aliados",112);
    add_edificio(&edificioHead, "Hotel 1",loc1);
    addandar(edificioHead,1,0);
    addandar(edificioHead,2,1);
    addandar(edificioHead,3,2);
    print_edificios(&edificioHead);
    printandar(edificioHead);
    return 0;
}
