
#include "structures.h"


int main(void) {

    BUILDINGS *buildings = NULL;
    HISTORY *history = create_hash_table();
    PEOPLE *people = NULL;
    printf("GESTOR ALOJAMENTOS\n\n");
    // read_file_buildigns(&buildings);
    // read_file_studio_politics();


    add_people(&people, "A", HOSPEDE);
    add_people(&people, "B", EMPREGADO);

    //print_all_people(people);

    LOCATION loc1 = add_location("a", "a", "a");
    add_building(&buildings, 1, "C", 1.2, loc1);
    add_building(&buildings, 1, "A", 1.2, loc1);
    add_building(&buildings, 1, "B", 1.2, loc1);

    add_studio(buildings, T2, 4, 20, 200);

    DATE date1 = add_date(12, 12, 01, 03, 2020);
    DATE date2 = add_date(12, 12, 02, 04, 2020);
    DATE date3 = add_date(12, 12, 01, 03, 2021);
    DATE dateend = add_date(12, 12, 01, 03, 2022);

    add_branch_calendar(&buildings->studios[0], AisBnD, 2);
    add_branch_calendar(&buildings->studios[0], AirBnc, 3);

    add_branch_event(&buildings->studios[0].branch_calendar[0].branch_event, 1, date2, dateend, 1.2, RESERVADO,people);
    add_branch_event(&buildings->studios[0].branch_calendar[0].branch_event, 1, date3, dateend, 3.6, RESERVADO,people);

    add_branch_event(&buildings->studios[0].branch_calendar[1].branch_event, 2, date1, dateend, 1.2, RESERVADO,people);
    add_branch_event(&buildings->studios[0].branch_calendar[1].branch_event, 2, date3, dateend, 3.6, RESERVADO,people);

    //print_branch_events(buildings->studios[0].branch_calendar[0].branch_event);
    //print_branch_events(buildings->studios[0].branch_calendar[1].branch_event);

    refresh_master_event(buildings, history,people);

    //print_master_events(buildings->studios[0].masterEvents);

    print_history(history);


    return EXIT_SUCCESS;


}




