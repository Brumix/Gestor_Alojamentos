
#include "structures.h"


int main(void) {

    BUILDINGS *buildings = NULL;
    HISTORY *history = create_hash_table();
    PEOPLE *people = NULL;
    politics = NULL;
    holidays = createHolidaysArray();

    printf("GESTOR ALOJAMENTOS\n\n");
    read_politics(&politics);
     read_file_buildigns(&buildings);
    read_file_estudio(buildings);

    read_file_studio_politics(buildings);
     print_politics();

    exit(13);

    add_politics("p1", AirBnc, 3);
    add_config(&politics->configuration, "configuracao", 0.0f);
    add_config(&politics->configuration, "duracao", 0.0f);
    add_config(&politics->configuration, "epoca", 0.0f);

    DATE natal1 = add_date(20, 12, now().Year);
    DATE natal2 = add_date(27, 12, now().Year);
    add_holiday("Natal", natal1, natal2);


    LOCATION loc1 = add_location("rua A", "-12N", "8S");
    add_building(&buildings, 1, "EDIFICE B", 1.5f, loc1);

    add_studio(buildings, T2, 1, 12, 45);

    add_people(&people, "A", HOSPEDE);
    add_people(&people, "B", EMPREGADO);
    add_people(&people, "C", EMPREGADO);

    DATE past = add_date(01, 03, 2020);
    DATE past2 = add_date(20, 03, 2020);
    DATE past3 = add_date(30, 03, 2020);
    DATE future2 = add_date(01, 03, 2022);
    STUDIOS *studios1 = &buildings->studios[0];

    add_branch_calendar( studios1, AirBnc, 1, "p1");
    add_branch_calendar( studios1, AirBnE, 10, "p1");
    add_value_config(&buildings->studios[0].branch_calendar[0].configuration, 0.2f);
    add_value_config(&buildings->studios[0].branch_calendar[0].configuration, 0.5f);
    add_value_config(&buildings->studios[0].branch_calendar[0].configuration, 0.6f);


    add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 1, past, past3, RESERVADO,
                     people);
    add_branch_event(buildings, &buildings->studios[0].branch_calendar[1].branch_event, 2, past2, future2, RESERVADO,
                     people);
    add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 3, future2, future2, RESERVADO,
                     people);

    refresh_master_event(buildings, history, people);
    // delete_branch_event(&buildings->studios[0].masterEvents,&buildings->studios[0].branch_calendar[0].branch_event,buildings->studios[0].branch_calendar[0].platform,past);
    // refresh_master_event(buildings,history,people);
    // print_branch_events(buildings->studios[0].branch_calendar[0].branch_event);
    //print_branch_events(buildings->studios[0].branch_calendar[1].branch_event);

    // print_history(history);

    // todo resolver colisoes
    //todo ver remove history

    free(buildings);
    free(history);
    free(people);
    free(politics);
    free(holidays);


    return EXIT_SUCCESS;

}




