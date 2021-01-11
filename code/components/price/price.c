//
// Created by Bruno Miguel on 23/11/2020.
//

#include "price.h"



float calculate_price(float price,float conf){
    if (price >= 1)
        return price*conf;

       return (price -(price * conf));

}


/**
 * calcula o preco do evvento
 * @param buildings struct edificios
 * @param id ip do evento a calcular
 * @return float
 */
float calculate_event_price(BUILDINGS *buildings, unsigned id) {
    BUILDINGS *building = buildings;
    float price = buildings->price_day;
    while (building != NULL) {
        STUDIOS *studios = building->studios;
        price *= (float) studios->area;
        for (int i = 0; i < building->num_studios; i++) {
            BRANCH_CALENDAR *branchCalendar = studios[i].branch_calendar;
            for (int j = 0; j < studios->number_branch; j++) {
                BRANCH_EVENTS *branchEvents = branchCalendar[j].branch_event;
                while (branchEvents != NULL) {

                    if (branchEvents->id == id) {
                        price *= (float) getDifferenceDays(branchEvents->date_begin, branchEvents->date_end);
                        return calculate_config_price(&branchCalendar[j], price);
                    }
                    branchEvents = branchEvents->next;
                }
            }
        }
        building = building->next;
    }
    return -1;
}

/**
 * calcula o preco com base nas comfiguracoes
 * @param branchCalendar struct branch_calendar
 * @param price float preco
 * @return float
 */
float calculate_config_price(BRANCH_CALENDAR *branchCalendar, float price) {
    CONFIGURATION *configuration = branchCalendar->configuration;
    BRANCH_EVENTS *branchEvents = branchCalendar->branch_event;
    while (configuration != NULL) {
        if (strcmp(configuration->name, "configuracao") == 0);

        else if
                (strcmp(configuration->name, "duracao") == 0){
            if (getDifferenceDays(branchEvents->date_begin, branchEvents->date_end) >= 5)
                price=calculate_price(price,configuration->value);
        }
        else  if (strcmp(configuration->name, "epoca") == 0)
            if (holiday_secion(branchEvents->date_begin) || holiday_secion(branchEvents->date_end))
                price=calculate_price(price,configuration->value);

            else if (strcmp(configuration->name, "ocupacao") == 0);


            else if (strcmp(configuration->name, "modalidade") == 0)
                if (branchEvents->people->typePeople == ORGANIZACAO)
                    price=calculate_price(price,configuration->value);


                else if (strcmp(configuration->name, "antecedencia") == 0)
                    if (getDifferenceDays(now(), branchEvents->date_begin) > 7)
                        price=calculate_price(price,configuration->value);



        configuration = configuration->next;
    }
    return price;
}