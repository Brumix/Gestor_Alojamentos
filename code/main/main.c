
#include "structures.h"


int main(void) {
    clock_t time[2];
    time[0] = clock();

    printf("GESTOR ALOJAMENTOS\n\n");

    BUILDINGS *buildings = NULL;
    LOCATION loc1 = add_location("Rua dos herois", "Porto", "34569N", "49657E");
    LOCATION loc2 = add_location("Rua dos animais", "Lisboa", "3675455S", "93884O");

    add_building(&buildings, "B", loc2);
    add_building(&buildings, "A", loc2);
    add_building(&buildings, "D", loc1);
    add_building(&buildings, "C", loc1);

    //delete_building(&buildings, "D");
    // delete_building(&buildings, "A");

    //print_building_all(buildings);


    add_studio(buildings, (TYPE_STUDIO) T2, 12, 3, "nada");
    add_studio(buildings, (TYPE_STUDIO) T2, 12, 1, "nada");
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 4, "terraco");
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 2, "terraco");

    find_studio(buildings, 0, buildings->num_studios, 12);
    delete_studio(buildings, 1);
    delete_studio(buildings, 4);


    // print_studio_all(buildings);

    add_branch_calendar(&buildings->studios[0], AirBnc, 100);
    add_branch_calendar(&buildings->studios[0], AisBnE, 2);
    add_branch_calendar(&buildings->studios[0], AisBnD, 1);
    add_branch_calendar(&buildings->studios[0], AIRPlaces, 100);

    find_branch_calendar(&buildings->studios[0], 0, buildings->studios[0].number_branch, AisBnD);


    //delete_branchCalendar(&buildings->studios[0], AisBnE);

    //print_branch_calendar(&buildings->studios[0]);


    PEOPLE people = add_people("joao", HOSPEDE);
    PEOPLE people1 = add_people("bruna", EMPREGADO);


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

    PRICE *price = createPriceArray();
    add_price(price, "zona", 1.20);
    add_price(price, "natal", 1.50);
    add_price(price, "pascoa", 1.50);
    add_price(price, "ano novo", 1.70);
    add_price(price, "familia", 0.10);


    // printprice(price);
    //  printf("[DATE]:CALCULO AUTOMATICO COM A FUNCAO CALCULATE_PRICE\t\"ATOI PARA FLOAT\"\n");
    DATE natal[2];
    natal[0] = add_date(00, 00, 20, 12, now().Year);
    natal[1] = add_date(00, 00, 27, 12, now().Year);

    HOLIDAYS *holidays = createHolidaysArray();
    add_holiday(holidays, "NATAL",
                add_date(00, 00, 20, 12, now().Year),
                add_date(00, 00, 27, 12, now().Year));

    print_holidays(holidays);

    // printf("%.2f\n", calculate_price(price, masterEvents->price, 3, "zona", "natal", "2.3"));
    //printf("%.2f\n", calculate_price(price, masterEvents->price, 1, "natal"));
    //printf("%.2f\n", calculate_price(price, branchEvents->price, 3, "zona", "natal", "familia"));
    //printf("%.2f\n", calculate_price(price, branchEvents->price, 2, "zona", "nada"));


    HISTORY *history = create_hash_table();
    delete_history_event(history, "joao", date1);
    add_history(history, AisBnE, people, 1, 12.43, date3, LIMPEZA);
    add_history(history, AisBnE, people, 2, 12.43, date1, LIMPEZA);
    add_history(history, AisBnE, people1, 3, 12.43, date1, LIMPEZA);
    add_history(history, AisBnE, people, 4, 12.43, date2, LIMPEZA);
    add_history(history, AisBnE, people1, 5, 12.43, date2, LIMPEZA);
    add_history(history, AisBnE, people1, 3, 12.43, date1, LIMPEZA);
    //print_history(history);


    time[1] = clock();
    printf("O progama demorou %.4f seconds", (double) (time[1] - time[0]) / CLOCKS_PER_SEC);

    /**
     * Frees
     */
    free(buildings);
    free(history);
    free(branchEvents);
    free(masterEvents);
    free(price);


    return EXIT_SUCCESS;

    // esquema de epocas
    // geolocalizacao (9)
    // ficheiros de texto



}




