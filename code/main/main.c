
#include "structures.h"


int main(void) {

    BUILDINGS *buildings = NULL;
    HISTORY *history = create_hash_table();
    PEOPLE *people = NULL;
    politics = NULL;
    holidays = createHolidaysArray();



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
//add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 1, past, past3, RESERVADO,
//               people);
//add_branch_event(buildings, &buildings->studios[0].branch_calendar[1].branch_event, 2, past2, past3, RESERVADO,
//                 people);
//add_branch_event(buildings, &buildings->studios[0].branch_calendar[0].branch_event, 3, past2, future2, RESERVADO,
//              people);


    // print_branch_events(buildings->studios[0].branch_calendar[1].branch_event);
    refresh_master_event(buildings, history, people);
   delete_branch_event(&buildings->studios[0].masterEvents, &buildings->studios[0].branch_calendar[1].branch_event,
                      buildings->studios[0].branch_calendar[0].platform, past);

    delete_history_event(history, "C", past);

    //  print_history(history);



    // todo verificar veracidade das informacoes
    // todo ver evento com id 18,que quando descomento aparece uma colisao
    // todo terminar configuracoes

    free(buildings);
    free(history);
    free(people);
    free(politics);
    free(holidays);


    return EXIT_SUCCESS;

}



