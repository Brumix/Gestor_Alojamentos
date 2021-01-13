
#include "structures.h"


int main(void) {

    BUILDINGS *buildings = NULL;
    HISTORY *history = create_hash_table();
    PEOPLE *people = NULL;
    politics = NULL;
    holidays = createHolidaysArray();

    //goto REAL;

    read_politics();

    LOCATION loc1 = add_location("Rua dos hereois", "34569N", "49657E");
    LOCATION loc2 = add_location("Rua dos animais", "3675455S", "93884O");

    add_building(&buildings, 2, "A", 1.6f, loc2);
    add_building(&buildings, 1, "B", 1.3f, loc2);

    add_studio(buildings, (TYPE_STUDIO) T2, 12, 3, 12);
    add_studio(buildings, (TYPE_STUDIO) T2, 15, 1, 3);

    DATE date1 = add_date(01, 01, 2020);
    DATE date2 = add_date(10, 01, 2020);
    DATE date3 = add_date(12, 01, 2020);
    DATE dateend = add_date(20, 01, 2020);
    add_people(&people, "A", HOSPEDE);
    add_people(&people, "B", EMPREGADO);

    add_branch_calendar(&buildings->studios[0], AisBnD, 2, "p1");
    add_branch_calendar(&buildings->studios[0], AirBnc, 3, "p2");

    BRANCH_CALENDAR *branchCalendar = buildings->studios[0].branch_calendar;
    add_config(&branchCalendar[0].configuration, "epoc", 1.2f);
    add_config(&branchCalendar[1].configuration, "epoc", 1.2f);
    add_config(&branchCalendar[0].configuration, "epoc", 1.2f);
    add_config(&branchCalendar[1].configuration, "epoc", 1.2f);

    add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 1, date2, date3, RESERVADO,
                     people);

    add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 2, date2, date3, RESERVADO,
                     people);
    people = people->next;
    add_branch_event(buildings, &buildings->studios[1].branch_calendar[1].branch_event, 2, date2, date3, RESERVADO,
                     people);
    add_branch_event(buildings, &buildings->studios[1].branch_calendar[1].branch_event, 2, date3, dateend, RESERVADO,
                     people);

    refresh_master_event(buildings, history, people);
    // print_master_events(buildings->studios[0].masterEvents);


    //occupancy_rate(buildings,date1,dateend);

    // billing(buildings,date1,dateend);

    write_buildings(buildings);
    write_studio(buildings);
    write_history(history);
    write_events(buildings);
    read_building_bin();
    read_studio_bin();
    read_history_bin();


    _exit(12);


    REAL:

    printf("GESTOR ALOJAMENTOS\n\n");

    read_politics();
    read_people(&people);
    read_file_buildigns(&buildings);
    read_file_estudio(buildings);
    read_file_studio_politics(buildings);
    read_events(buildings, people);

    DATE natal1 = add_date(20, 12, now().Year);
    DATE natal2 = add_date(27, 12, now().Year);
    add_holiday("Natal", natal1, natal2);

    DATE past = add_date(01, 03, 2020);
    DATE past2 = add_date(20, 03, 2020);
    DATE past3 = add_date(30, 03, 2020);
    DATE future2 = add_date(01, 03, 2022);


    //  add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 1, past, past3, RESERVADO,
    //                   people);
    //  add_branch_event(buildings, &buildings->studios[0].branch_calendar[1].branch_event, 2, past2, past3, RESERVADO,
    //                   people);
    // add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 3, past2, future2, RESERVADO,
    //                  people);


    // print_branch_events(buildings->studios[0].branch_calendar[1].branch_event);
    refresh_master_event(buildings, history, people);
    delete_branch_event(&buildings->studios[0].masterEvents, &buildings->studios[0].branch_calendar[1].branch_event,
                        buildings->studios[0].branch_calendar[0].platform, past);

    delete_history_event(history, "C", past);

    occupancy_rate(buildings, past, future2);

    billing(buildings, past, future2);

    //  print_history(history);

    write_buildings(buildings);
    write_studio(buildings);
    write_history(history);
    write_events(buildings);
    read_building_bin();
    read_studio_bin();
    read_history_bin();


    // todo verificar veracidade das informacoes
    // todo terminar configuracoes
    // todo 9

    free(buildings);
    free(history);
    free(people);
    free(politics);
    free(holidays);


    return EXIT_SUCCESS;

}



