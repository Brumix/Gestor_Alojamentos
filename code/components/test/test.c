//
// Created by Bruno Miguel on 13/01/2021.
//

#include "test.h"


void main_test(BUILDINGS *buildings, HISTORY *history, PEOPLE *people) {
    //  criterio23(buildings, people, history);
    // criterio45(buildings, people, history);
    //criterio67(buildings, people, history);
    //criterio8(buildings,people,history);
   // criterio9(buildings,people,history);

}


void criterio23(BUILDINGS *buildings, PEOPLE *people, HISTORY *history) {
    read_politics();
    read_people(&people);
    read_file_buildigns(&buildings);
    read_file_estudio(buildings);
    read_file_studio_politics(buildings);
    read_events(buildings, people);

    // print_studio_all(buildings);
    // print_studio_all(buildings);
    // print_branch_calendar(&buildings->studios[0]);
    // print_branch_event(buildings->studios[0].branch_calendar[1].branch_event);

    refresh_master_event(buildings, history, people);

    // print_history(history);

    // print_building_all(buildings);
    //  delete_building(&buildings,"PF Boavista");
    //  update_building(buildings,"PF Boavista","A");
    //  print_building_all(buildings);
    // update_studio(buildings,1,56);
    //print_studio_all(buildings);
    // BRANCH_CALENDAR *branchCalendar = find_branch_calendar(&buildings->studios[0], 0,
    //                                                       buildings->studios[0].number_branch, AirBnc);
    // print_branch_calendar_unique(branchCalendar);
    //   DATE update = add_date(7, 10, 2020);
    //   print_branch_event(buildings->studios[0].branch_calendar[1].branch_event);
    //   update_branch_event(buildings->studios[0].branch_calendar[1].branch_event, update, 12.0f);
    //   print_branch_event(buildings->studios[0].branch_calendar[1].branch_event);
}


void criterio45(BUILDINGS *buildings, PEOPLE *people, HISTORY *history) {

    read_politics();
    read_people(&people);
    read_file_buildigns(&buildings);
    read_file_estudio(buildings);
    read_file_studio_politics(buildings);
    read_events(buildings, people);

    refresh_master_event(buildings, history, people);

    write_buildings(buildings);
    write_studio(buildings);
    write_history(history);
    write_events(buildings);
    read_building_bin();
    read_studio_bin();
    read_history_bin();
}


void criterio67(BUILDINGS *buildings, PEOPLE *people, HISTORY *history) {

    read_politics();
    read_people(&people);
    read_file_buildigns(&buildings);
    read_file_estudio(buildings);
    read_file_studio_politics(buildings);
    read_events(buildings, people);

    refresh_master_event(buildings, history, people);

    DATE date1 = add_date(12, 3, 2020);
    DATE date2 = add_date(12, 3, 2021);

    occupancy_rate(buildings, date1, date2);
    billing(buildings, date1, date2);

}


void criterio8(BUILDINGS *buildings, PEOPLE *people, HISTORY *history) {

    read_politics();
    read_people(&people);
    read_file_buildigns(&buildings);
    read_file_estudio(buildings);
    read_file_studio_politics(buildings);
    read_events(buildings, people);


    DATE past = add_date(1, 03, 2020);
    DATE past2 = add_date(5, 03, 2020);
    DATE past3 = add_date(30, 03, 2020);

    add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 1, past, past3, RESERVADO,
                     people);
    add_branch_event(buildings, &buildings->studios[0].branch_calendar[1].branch_event, 2, past2, past3, RESERVADO,
                     people);

    refresh_master_event(buildings, history, people);
}


void criterio9(BUILDINGS *buildings, PEOPLE *people, HISTORY *history){
    read_politics();
    read_people(&people);
    read_file_buildigns(&buildings);
    read_file_estudio(buildings);
    read_file_studio_politics(buildings);
    read_events(buildings, people);

    DATE date1 = add_date(1, 03, 2020);
    DATE date2 = add_date(15, 03, 2020);


    add_specif_event(buildings,date1,date2,7,"PF Boavista",13);

}