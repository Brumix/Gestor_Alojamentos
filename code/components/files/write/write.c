//
// Created by Bruno Miguel on 21/12/2020.
//

#include "write.h"


void write_file_append(char *filename, char *text) {
    FILE *file = fopen(filename, "a");
    ERRORMESSAGE(file == NULL, "[WRITE FILE APPEND: ERROR IN FILE]");
    fprintf(file, "%s", text);
    fclose(file);
}

void write_file_bin(char *filename, char *text) {
    remove(filename);
    FILE *file = fopen(filename, "ab+");
    ERRORMESSAGE(file == NULL, "[WRITE FILE APPEND: ERROR IN FILE]");
    fwrite(&text, sizeof text, 1, file);
    fclose(file);
}


void inicial_declaration(char *filename, DATE begin, DATE end) {

    char *text = malloc(100 * sizeof(char));
    sprintf(text, "####################### %i/%i/%i/t%i/%i/%i ##########################\n", begin.day,
            begin.month, begin.day, end.day, end.month, end.Year);
    write_file_append(filename, text);
}

void end_declaration(char *filanename) {
    char *inicial_declaration = malloc(100 * sizeof(char));
    sprintf(inicial_declaration, "#####################################################################\n");
    write_file_append(filanename, inicial_declaration);

}

void write_buildings(BUILDINGS *head) {
    BUILDINGS *buildings = head;
    remove(FILEBUILDING_WRITE);
    char *text = malloc(100 * sizeof(char));
    while (buildings != NULL) {
        sprintf(text, "ESTUDIO:%i %s %.2f\n\t LOCATION: %s %s %s\n", buildings->index, buildings->name,
                buildings->price_day, buildings->location.address, buildings->location.gps.latitude,
                buildings->location.gps.longitude);
        write_file_append(FILEBUILDING_WRITE, text);
        write_file_bin(FILEBUILDING_BIN, text);

        buildings = buildings->next;
    }
}

void write_studio(BUILDINGS *head) {
    BUILDINGS *buildings = head;
    char *text = malloc(100 * sizeof(char));
    remove(FILESTUDIO_WRITE);
    while (buildings != NULL) {

        for (int i = 0; i < buildings->num_studios; ++i) {
            STUDIOS studios = buildings->studios[i];
            sprintf(text, "ESTUDIO: %i %i %s %i\n", studios.index, studios.num_door, strTypeStudio(studios.typeStudio),
                    studios.area);
            write_file_append(FILESTUDIO_WRITE, text);
            write_file_bin(FILESTUDIO_BIN, text);
        }
        buildings = buildings->next;
    }

}

void write_history(HISTORY *head) {
    HISTORY *history = head;
    remove(FILEHISTORY_WRITE);
    char *text = malloc(100 * sizeof(char));
    for (int i = 0; i < HASHSIZE; ++i) {
        HYSTORY_EVENTS *pHitoryEvents = history[i].hystoryEvents;
        while (pHitoryEvents != NULL) {
            sprintf(text, "HISTORY\n\tPEOPLE:%s\t%s\n\tPRICE:%.2f TYPE %s\n", pHitoryEvents->people->name,
                    strTypePeople(pHitoryEvents->people->typePeople),
                    pHitoryEvents->events->price, strMasterEvent(pHitoryEvents->events->typeMasterEvent));
            write_file_append(FILEHISTORY_WRITE, text);
            write_file_bin(FILEHISTORY_BIN, text);
            pHitoryEvents = pHitoryEvents->next;
        }
    }

}

void write_events(BUILDINGS *head) {
    BUILDINGS *buildings = head;

    while (buildings != NULL) {
        for (int i = 0; i < buildings->num_studios; ++i) {
            STUDIOS studios = buildings->studios[i];
            for (int j = 0; j < studios.number_branch; ++j) {
                BRANCH_EVENTS *branchEvents = studios.branch_calendar[j].branch_event;
                char *filepath = malloc(100 * sizeof(char));
                char *filepathbin = malloc(100 * sizeof(char));
                sprintf(filepath, "%s%i%s.txt", BASEPATH, studios.index,
                        strPlatform(studios.branch_calendar->platform));
                sprintf(filepathbin, "%s%i%sbin.bin", BASEPATH, studios.index,
                        strPlatform(studios.branch_calendar->platform));
                while (branchEvents != NULL) {
                    remove(filepath);
                    char *text = malloc(120 * sizeof(char));
                    sprintf(text, "%i/%i/%i/t%i/%i/%i\nPEOPLE:%s\t%s\nPRICE %.2f", branchEvents->date_begin.day,
                            branchEvents->date_begin.month, branchEvents->date_begin.Year, branchEvents->date_end.day,
                            branchEvents->date_end.month, branchEvents->date_end.Year, branchEvents->people->name,
                            strTypePeople(branchEvents->people->typePeople), branchEvents->price);
                    write_file_append(filepath, text);
                    write_file_bin(filepathbin, text),

                            branchEvents = branchEvents->next;
                }
            }
        }
        buildings = buildings->next;
    }

}


