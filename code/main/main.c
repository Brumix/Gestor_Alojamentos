#include "structures.h"



int main(void) {
    clock_t time[2];
    time[0] = clock();

    printf("GESTOR ALOJAMENTOS\n\n");

    BUILDINGS *buildings = NULL;
    LOCATION loc1 = add_location("Rua dos hereois", "34569N", "49657E");
    LOCATION loc2 = add_location("Rua dos animais", "3675455S", "93884O");

    add_building(&buildings, "B", loc2);
    add_building(&buildings, "A", loc2);
    add_building(&buildings, "D", loc1);
    add_building(&buildings, "C", loc1);

    //delete_building(&buildings, "D");
    // delete_building(&buildings, "A");

    // print_building_all(buildings);


    add_studio(buildings, (TYPE_STUDIO) T2, 12, 3, "nada");
    add_studio(buildings, (TYPE_STUDIO) T2, 12, 1, "nada");
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 4, "terraco");
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 2, "terraco");

    delete_studio(buildings, 1);
    delete_studio(buildings, 4);

    // print_studio_all(buildings);

    add_branch_calendar(&buildings->studios[0], AisBnE);
    add_branch_calendar(&buildings->studios[0], AisBnD);
    add_branch_calendar(&buildings->studios[0], AirBnc);

    delete_branchCalendar(&buildings->studios[0], AisBnE);

    // print_branch_calendar(&buildings->studios[0]);


    PEOPLE people = add_people(12, "joao", HOSPEDE);
    PEOPLE people1 = add_people(113, "bruna", EMPREGADO);


    DATE date1 = add_date(12, 23, 4, 12, 2002);
    DATE date2 = add_date(12, 24, 4, 12, 2002);
    DATE date3 = add_date(12, 24, 4, 6, 2002);


    BRANCH_EVENTS *branchEvents = buildings->studios[0].branch_calendar[0].branch_event;
    add_branch_event(&branchEvents, people, date1, 12, 10, RESERVADO);
    add_branch_event(&branchEvents, people, date3, 123, 230, LIVRE);
    add_branch_event(&branchEvents, people, date1, 123, 230, RESERVADO);
    add_branch_event(&branchEvents, people, date2, 123, 230, RESERVADO);

    delete_branch_event(&branchEvents, date1);

    //print_branch_events(branchEvents);

    MASTER_EVENTS *masterEvents = buildings->studios[0].masterEvents;

    add_master_event(&masterEvents, AisBnD, people, 73, 786.95, MANUTENCAO, date1);
    add_master_event(&masterEvents, AIRPlaces, people, 45, 23.56, LIMPEZA, date3);
    add_master_event(&masterEvents, AisBnD, people, 73, 786.95, MANUTENCAO, date1);
    add_master_event(&masterEvents, AisBnD, people, 73, 786.95, MANUTENCAO, date2);

    //delete_master_event(&masterEvents, date3);

    //print_master_events(masterEvents);


    // PRICE *price = createPriceArray();
    // addprice(price, "zona", 1.20);
    // addprice(price, "natal", 1.50);
    // addprice(price, "pascoa", 1.50);
    // addprice(price, "ano novo", 1.70);
    // addprice(price, "familia", 0.10);

    //printprice(price);


    //  printf("%.2f\n", calculate_price(price, masterEvents->price, 2, "zona", "natal"));
    //  printf("%.2f\n", calculate_price(price, masterEvents->price, 1, "natal"));
    //  printf("%.2f\n", calculate_price(price, branchEvents->price, 3, "zona", "natal", "familia"));
    //  printf("%.2f\n", calculate_price(price, branchEvents->price, 2, "zona", "nada"));




    HISTORY *history = create_hash_table();
    add_history(history, AisBnE, people, 67, 12.43, date3, LIMPEZA);
    add_history(history, AisBnE, people, 12, 12.43, date1, LIMPEZA);
    add_history(history, AisBnE, people1, 67, 12.43, date1, LIMPEZA);
    add_history(history, AisBnE, people, 12, 12.43, date1, LIMPEZA);
    add_history(history, AisBnE, people1, 67, 12.43, date2, LIMPEZA);
    print_history(history);
    printf("[PERGUINTAR AO STOR BUGG DO PRINTF_HISTORY]\n");

    time[1] = clock();
    printf("Time elpased is %.4f seconds", (double) (time[1] - time[0]) / CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}




