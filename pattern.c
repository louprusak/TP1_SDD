#include "pattern.h"

void initPattern(patternList_t *ppl){
    ppl = (patternList_t*) malloc(sizeof(patternList_t));
    if(ppl){
        ppl->head = NULL;
        ppl->tail = NULL;
    }
}

void addDay(patternList_t *ppl, int *tabsize, char * year, char * week, int day, int hour, char *actionName){
    if(ppl && *tabsize < PATTERN_SIZE){

        pattern_t tmp;
        strcpy(tmp.year, year);
        strcpy(tmp.weekNumber, week);
        tmp.dayNumber = day;
        tmp.hour = hour;
        strcpy(tmp.actionName,actionName);

        if(!ppl->head){
            ppl->list[0] = tmp;
            ppl->head = &tmp;
        }
        else{
            *(ppl->tail+sizeof(pattern_t)) = tmp;
        }
        ppl->tail = &tmp;
    }
}

void displayPattern(patternList_t pl){
    if(pl.head){
        printf("Tête non nulle\n");
        pattern_t *list = pl.head;
        printf("list ok\n");
        while(list != pl.tail){
            printf("Je rentre dans le while\n");
            printf("%s %s %d %d %s",list->year,list->weekNumber,list->dayNumber,list->hour,list->actionName);
            list = list + sizeof(pattern_t);
        }
    }
    
}

void freePattern(patternList_t *ppl){
    //free(ppl->head);
    free(ppl);
}