//
// Created by Bruno Miguel on 18/12/2020.
//

#include "holidays.h"

int HOLIDAYSSIZE = INICIAL;
int POSICIONHOLIDAY = 0;


/**
 * cria um array para as epocas altas
 * @return array
 */
HOLIDAYS *createHolidaysArray() {
    HOLIDAYS *temp = (HOLIDAYS *) malloc(HOLIDAYSSIZE * sizeof(HOLIDAYS));
    ERRORMESSAGE(temp == NULL, "[MALL0C HOLIDAYS]");
    return temp;
}

/**
 * adiciona um feriado ao array
 * @param nome char *
 * @param date1 DATE data de inicio da epoca alta
 * @param date2 DATE data de fim da epoca alta
 */
void add_holiday( char *nome, DATE date1, DATE date2) {
    resize_holidays(&holidays);
    HOLIDAYS temp = create_holiday(nome, date1, date2);
    holidays[POSICIONHOLIDAY] = temp;
    POSICIONHOLIDAY++;
}

/**
 * cria a estrutura do feriado
 * @param nome nome do feriado
 * @param date1 DATE
 * @param date2 DATE
 * @return struct HOLIDAY
 */
HOLIDAYS create_holiday(char *nome, DATE date1, DATE date2) {
    HOLIDAYS temp;
    temp.nome = nome;
    temp.date = malloc(2 * sizeof(DATE));
    ERRORMESSAGE(temp.date == NULL, "[MALLOC DATE HOLIDAY]");
    temp.date[0] = date1;
    temp.date[1] = date2;

    return temp;
}

/**
 * aumenta o tamanho do array
 */
void resize_holidays() {
    if (HOLIDAYSSIZE * 0.6 <= POSICIONHOLIDAY) {
        HOLIDAYSSIZE *= 2;
        holidays = (HOLIDAYS *) realloc(holidays, HOLIDAYSSIZE * sizeof(HOLIDAYS));
        ERRORMESSAGE(holidays == NULL, "[REALLOC HOLIDAYS]");
    }
}

/**
 * imprime o array de feriados
 */
void print_holidays() {
    HOLIDAYS *current = holidays;
    printf("HOLIDAYS\n");
    for (int i = 0; i < POSICIONHOLIDAY; i++) {
        printf("NOME:%s\n", current[i].nome);
        printf("\t");
        print_date(current[i].date[0]);
        printf("\t");
        print_date(current[i].date[1]);
    }
}

/**
 * verifica se uma data colide com a epoca alta
 * @param date  data a testar colisao
 * @return true(1) false (0)
 */
int holiday_secion(DATE date){
    for (int i = 0; i <POSICIONHOLIDAY ; i++) {
            if(compare_date(holidays[i].date[0],date)==-1 && compare_date(holidays[i].date[1],date)==1)
                return 1;
    }
    return 0;
}
