#include "structures.h"


int main(void) {
    printf("GESTOR ALOJAMENTOS\n\n");

    BUILDINGS *buildings = NULL;
    LOCATION loc1 = add_location("Rua dos hereois", "34569N", "49657E");
    LOCATION loc2 = add_location("Rua dos animais", "3675455S", "93884O");

    add_building(&buildings, "Edificio1", loc1);
    add_building(&buildings, "Edificio2", loc2);

    add_studio(buildings, (TYPE_STUDIO) T2, 12, 1);
    add_studio(buildings, (TYPE_STUDIO) SUITEPRESIDENCIAL, 12, 4);

    DATE date1 = add_date(12, 23, 4, 12, 2002);

    add_branch_calendar(&buildings->studios[0], date1, (PLATFORM) AisBnE);
    // print_branch_calendar(&buildings->studios[0]);

    add_master_calendar(&buildings->studios[0], date1);
    // print_master_calendar(&buildings->studios[0]);

    // print_building_all(buildings);

    PEOPLE people = add_people(12, "Bruno Pereira", HOSPEDE);

    BRANCH_EVENTS *branchEvents = buildings->studios[0].branch_calendar[0].branch_event;
    add_branch_event(&branchEvents, people, 12, 10, RESERVADO);
    add_branch_event(&branchEvents, people, 123, 230, LIVRE);
    print_branch_events(branchEvents);

    return 0;
}

