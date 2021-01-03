//
// Created by Bruno Miguel on 22/11/2020.
//

#include "master_events.h"


/**
 * adiciona um master event
 * @param head lista ligada dos eventos
 * @param platform plartaforma do evento
 * @param people pessoa  do evento
 * @param duration duracao do evento
 * @param price custo  do evento
 * @param master Event tipo do evento
 * @param date_begin data do evento
 */
void add_master_event(MASTER_EVENTS **head, PLATFORM platform, PEOPLE *people, DATE date_end, float price,
                      TYPE_MASTER_EVENT masterEvent, DATE date_begin) {

    MASTER_EVENTS *temp = create_master_event(platform, people, date_end, price, masterEvent, date_begin);
    ordena_master_event(head, temp);
}

/**
 * apaga um amster evento
 * @param head lista ligada dos master events
 * @param date data dop evento a apagar
 */
void delete_master_event(MASTER_EVENTS **head, DATE date,PLATFORM platform) {
    MASTER_EVENTS *current = *head;

    if (compare_date(current->date_begin, date) == 0 && current->platform==platform) {
        *head = current->next;
        return;
    }
    while (current != NULL) {
        if (compare_date(current->next->date_begin, date) == 0 && current->next->platform==platform) {
            current->next = current->next->next;
            return;
        }
        EXISTENTE(current->next->next == NULL, "[MASTER EVENT NAO ENCONTRADO]");

        current = current->next;
    }
}

/**
 * cria um master event
 * @param platform plataforma do evento
 * @param people pessoa do evento
 * @param duration duracao do evento
 * @param price custo do evento
 * @param masterEvent tipo do evento
 * @param date_begin data do evento
 * @return master_event
 */
MASTER_EVENTS *create_master_event(PLATFORM platform, PEOPLE *people, DATE date_end, float price,
                                   TYPE_MASTER_EVENT masterEvent, DATE date_begin) {
    MASTER_EVENTS *temp = (MASTER_EVENTS *) malloc(sizeof(MASTER_EVENTS));
    ERRORMESSAGE(temp == NULL, "[ADD MASTER EVENT]");

    temp->platform = platform;
    temp->people = people;
    temp->date_end = date_end;
    temp->price = price;
    temp->typeMasterEvent = masterEvent;
    temp->date_begin = date_begin;
    temp->next = NULL;
    return temp;
}


/**
 * imprime a lista dos eventos
 * @param masterEvents lista dos eventos
 */
void print_master_events(MASTER_EVENTS *masterEvents) {
    MASTER_EVENTS *curent = masterEvents;
    printf("MASTER EVENTS\n");
    while (curent != NULL) {
        printf("PLATAFORMA:%s\n", strPlatform(curent->platform));
        //print_people(curent->people);
        print_date(curent->date_begin);
        print_date(curent->date_end);
        printf("PRECO: %.2f\n", curent->price);
        printf("TIPO DO EVENTO: %s\n", strMasterEvent(curent->typeMasterEvent));
        curent = curent->next;
    }

}

/**
 * reorganiza os evetos
 * @param head cabeca da lista ligada
 * @param temp evento a adicionar
 */
void ordena_master_event(MASTER_EVENTS **head, MASTER_EVENTS *temp) {
    MASTER_EVENTS *current = *head;
    if (current == NULL) {
        *head = temp;
        return;
    }
    EXISTENTE(compare_date(current->date_begin, temp->date_begin) == 0, "[MASTER EVENT EXISTENTE]");

    if (compare_date(current->date_begin, temp->date_begin) == 1) {

        temp->next = *head;
        *head = temp;
        return;
    }
    while (current != NULL) {

        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        EXISTENTE(compare_date(current->next->date_begin, temp->date_begin) == 0, "[MASTER EVENT EXISTENTE]");

        if (compare_date(current->next->date_begin, temp->date_begin) == 1) {
            temp->next = current->next;
            current->next = temp;
            return;
        }

        current = current->next;
    }
}

/**
 * atualiza o master_events e o history
 * @param buildings  struct buildings
 * @param history  struct history
 * @param pPeople struct people
 */
void refresh_master_event(BUILDINGS *buildings, HISTORY *history, PEOPLE *pPeople) {
    BUILDINGS *building = buildings;
    while (building != NULL) {
        STUDIOS *studios = building->studios;
        for (int i = 0; i < building->num_studios; i++) {
            BRANCH_CALENDAR *branchCalendar = studios[i].branch_calendar;
            for (int j = 0; j < studios->number_branch; j++) {
                MASTER_EVENTS *masterEvents = studios[i].masterEvents;
                BRANCH_EVENTS *branchEvents = branchCalendar[j].branch_event;
                while (branchEvents != NULL) {
                    PEOPLE *people = find_people(pPeople, branchEvents->id);
                    ERRORMESSAGE(people == NULL, "[REFRESH MASTER EVENTS: PESSOA INEXISTENTE ]");
                    //little improvement
                    if (equal_master_event(masterEvents, branchCalendar->platform, branchEvents->date_begin)) {
                        branchEvents = branchEvents->next;
                        continue;
                    }
                    add_master_event(&studios[i].masterEvents, branchCalendar[j].platform,
                                     people, branchEvents->date_end, branchEvents->price, OCUPADO,
                                     branchEvents->date_begin);
                    add_history(history, branchCalendar[j].platform, people, branchEvents->date_end,
                                branchEvents->price,
                                branchEvents->date_begin, OCUPADO);
                    branchEvents = branchEvents->next;
                }
            }
            check_consistency_master(&studios[i].masterEvents,studios,buildings->num_studios);
        }
        building = building->next;
    }
}

/**
 * vesifica se ja existe o evento
 * @param masterEvents struct master_event
 * @param platform Platform plataforma
 * @param begin DATE data de inicio
 * @return true(1) or false(0)
 */
int equal_master_event(MASTER_EVENTS *masterEvents, PLATFORM platform, DATE begin) {
    MASTER_EVENTS *current = masterEvents;
    while (current != NULL) {
        if (current->platform == platform && compare_date(current->date_begin, begin) == 0)
            return 1;

        if (current->platform == platform && compare_date(current->date_begin, begin) == 1)
            return 0;
        current = current->next;
    }
    return 0;
}

/**
 * verifica colisoes no eventos
 * @param masterEvents struct master_event
 * @param studios struct studios
 * @param size tamanho do array studio
 */
void check_consistency_master(MASTER_EVENTS ** masterEvents,STUDIOS * studios,unsigned size){
   MASTER_EVENTS *temp=*masterEvents;
   STUDIOS *current=studios;
    while (temp!=NULL) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < current[i].number_branch; ++j) {
                BRANCH_CALENDAR currentBranch = current[i].branch_calendar[j];
                if (temp->platform != currentBranch.platform &&
                    compare_date(temp->date_begin, currentBranch.branch_event->date_begin) == 0) {
                    printf("colisao \t");
                    printf("%f\n", temp->price);
                }
                if (compare_date(temp->date_begin, currentBranch.branch_event->date_begin) == 1 &&
                    compare_date(temp->date_end, currentBranch.branch_event->date_end) == -1
                    ||
                        compare_date(temp->date_end, currentBranch.branch_event->date_begin) == 1 &&
                        compare_date(temp->date_end, currentBranch.branch_event->date_end) == -1)
                    printf("colisao2\n");
            }

        }
        temp = temp->next;
    }

}