
#include "structures.h"


int main(void) {

    BUILDINGS *buildings = NULL;
    HISTORY *history = create_hash_table();
    PEOPLE *people = NULL;
    printf("GESTOR ALOJAMENTOS\n\n");
    read_file_buildigns(&buildings);
    read_file_estudio(buildings);
    // read_file_studio_politics();
    //print_building_all(buildings);



    add_people(&people, "A", HOSPEDE);
    add_people(&people, "B", EMPREGADO);

    //print_all_people(people);


    DATE date1 = add_date(12, 12, 01, 03, 2020);
    DATE date2 = add_date(12, 12, 02, 04, 2020);
    DATE date3 = add_date(12, 12, 01, 03, 2021);
    DATE dateend = add_date(12, 12, 01, 03, 2022);


    add_branch_calendar(&buildings->studios[0], AisBnD, 2, "p1");
    add_branch_calendar(&buildings->studios[0], AirBnc, 3, "p2");
    BRANCH_CALENDAR *branchCalendar = buildings->studios[0].branch_calendar;
    add_config(&branchCalendar[0].configuration, "epoc", 1.2f);
    add_config(&branchCalendar[1].configuration, "epoc", 1.2f);
    add_config(&branchCalendar[0].configuration, "epoc", 1.2f);
    add_config(&branchCalendar[1].configuration, "epoc", 1.2f);

    add_branch_event(&buildings->studios[0].branch_calendar[0].branch_event, 1, date2, dateend, 1.2f, RESERVADO,
                     people);
    add_branch_event(&buildings->studios[0].branch_calendar[0].branch_event, 1, date3, dateend, 3.6f, RESERVADO,
                     people);

    add_branch_event(&buildings->studios[0].branch_calendar[1].branch_event, 2, date1, dateend, 1.2f, RESERVADO,
                     people);
    add_branch_event(&buildings->studios[0].branch_calendar[1].branch_event, 2, date3, dateend, 3.6f, RESERVADO,
                     people);

    //print_branch_events(buildings->studios[0].branch_calendar[0].branch_event);
    //print_branch_events(buildings->studios[0].branch_calendar[1].branch_event);

    //print_branch_calendar(&buildings->studios[0]);
   // refresh_master_event(buildings, history, people);

    printf("\n\n");
    //print_master_events(buildings->studios[0].masterEvents);

    //print_history(history);

    free(buildings);
    free(history);
    free(people);

    return EXIT_SUCCESS;

}




