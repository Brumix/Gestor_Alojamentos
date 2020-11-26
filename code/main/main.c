#include "structures.h"


void add_array(int *a, int index, int val, int size) {
    if (index == size + 1) {
        a[index] = val;
        return;
    }
    int aux = a[index];
    a[index] = val;
    add_array(a, index + 1, aux, size);
}

void delete_array(int *a, int index, int size) {
    if (index == size - 1) {
        a[index] = -1;
        return;
    }
    a[index] = a[index + 1];
    delete_array(a, index + 1, size);
}

void print_array(int *a) {
    for (int i = 0; i < 10; ++i) {
        printf("%i ", a[i]);
    }
    printf("\n");
}


int main(void) {
    clock_t begin = clock();

    printf("GESTOR ALOJAMENTOS\n\n");

    BUILDINGS *buildings = NULL;
    LOCATION loc1 = add_location("Rua dos hereois", "34569N", "49657E");
    LOCATION loc2 = add_location("Rua dos animais", "3675455S", "93884O");

    add_building(&buildings, "B", loc1);
    add_building(&buildings, "D", loc2);
    add_building(&buildings, "A", loc2);
    add_building(&buildings, "C", loc1);
    // print_building_all(buildings);


    add_studio(buildings, (TYPE_STUDIO) T2, 12, 3, "nada");
    add_studio(buildings, (TYPE_STUDIO) T2, 12, 1, "nada");
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 4, "terraco");
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 2, "terraco");

    delete_studio(buildings, 1);
    delete_studio(buildings, 4);

    print_studio_all(buildings);

    DATE date1 = add_date(12, 23, 4, 12, 2002);

    add_branch_calendar(&buildings->studios[0], date1, AisBnE);
    // print_branch_calendar(&buildings->studios[0]);


    PEOPLE people = add_people(12, "Bruno Pereira", HOSPEDE);

    BRANCH_EVENTS *branchEvents = buildings->studios[0].branch_calendar[0].branch_event;
    add_branch_event(&branchEvents, people, 12, 10, RESERVADO);
    add_branch_event(&branchEvents, people, 123, 230, LIVRE);
    // print_branch_events(branchEvents);

    MASTER_EVENTS *masterEvents = buildings->studios[0].masterEvents;
    add_master_event(&masterEvents, AisBnE, people, 45, 23.56, LIMPEZA, date1);
    add_master_event(&masterEvents, AIRPlaces, people, 73, 786.95, MANUTENCAO, date1);
    // print_master_events(masterEvents);


    PRICE *price = createPriceArray();
    addprice(price, "zona", 1.20);
    addprice(price, "natal", 1.50);
    addprice(price, "pascoa", 1.50);
    addprice(price, "ano novo", 1.70);
    addprice(price, "familia", 0.10);

    //printprice(price);

    // printf("\n");


    //  printf("%.2f\n", calculate_price(price, masterEvents->price, 2, "zona", "natal"));
    //  printf("%.2f\n", calculate_price(price, masterEvents->price, 1, "natal"));
    //  printf("%.2f\n", calculate_price(price, branchEvents->price, 3, "zona", "natal", "familia"));
    //  printf("%.2f\n", calculate_price(price, branchEvents->price, 2, "zona", "nada"));


    clock_t end = clock();
    printf("Time elpased is %.4f seconds", (double) (end - begin) / CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}




