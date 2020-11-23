#include "structures.h"


int main(void) {
    printf("GESTOR ALOJAMENTOS\n\n");

    BUILDINGS *buildings = NULL;
    LOCATION loc1 = add_location("Rua dos hereois", "34569N", "49657E");
    LOCATION loc2 = add_location("Rua dos animais", "3675455S", "93884O");

    add_building(&buildings, "Edificio1", loc1);
    add_building(&buildings, "Edificio2", loc2);


    add_studio(buildings, (TYPE_STUDIO) T2, 12, 1, "nada");
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 4, "terraco");

    DATE date1 = add_date(12, 23, 4, 12, 2002);

    add_branch_calendar(&buildings->studios[0], date1, AisBnE);
    // print_branch_calendar(&buildings->studios[0]);


    add_master_calendar(&buildings->studios[0], date1);
    // print_master_calendar(&buildings->studios[0]);

    //print_building_all(buildings);

    PEOPLE people = add_people(12, "Bruno Pereira", HOSPEDE);

    BRANCH_EVENTS *branchEvents = buildings->studios[0].branch_calendar[0].branch_event;
    add_branch_event(&branchEvents, people, 12, 10, RESERVADO);
    add_branch_event(&branchEvents, people, 123, 230, LIVRE);
    // print_branch_events(branchEvents);

    MASTER_EVENTS *masterEvents = buildings->studios[0].master_calendar[0].master_event;
    add_master_event(&masterEvents, AisBnE, people, 45, 23.56, LIMPEZA);
    add_master_event(&masterEvents, AIRPlaces, people, 73, 786.95, MANUTENCAO);
    // print_master_events(masterEvents);


    PRICE *price = createPriceArray();
    addprice(price, "zona", 1.20);
    addprice(price, "natal", 1.50);
    addprice(price, "pascoa", 1.50);
    addprice(price, "ano novo", 1.70);
    addprice(price, "familia", 0.10);

    printprice(price);

    printf("\n");

    printf("%.2f\n", calculate_price(price, masterEvents->price, 2, "zona", "natal"));
    printf("%.2f\n", calculate_price(price, 10, 1, "natal"));
    printf("%.2f\n", calculate_price(price, 10, 3, "zona", "natal", "familia"));
    printf("%.2f\n", calculate_price(price, 10, 2, "zona", "nada"));

    return EXIT_SUCCESS;
}

