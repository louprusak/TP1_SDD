#include "pattern.h"

void initPattern(patternList *ppl, int size){
    ppl = (patternList*) malloc(sizeof(patternList));
    if(ppl){
        pattern_t *pp = ppl->head;
        pp = (pattern_t*) malloc(size*sizeof(pattern_t));
        if(pp){
            ppl->tail = (&pp[size-1]);
        }
    }
}

void displayPattern(patternList pl, int size){
    pattern_t *curr = pl.head;
    for (int i = 0; i < size; i++)
    {
        pattern_t elt = curr[i];
        printf("%d %d %d %d %s",elt.year,elt.weekNumber,elt.dayNumber,elt.hour,elt.actionName);
    }
}

void freePattern(patternList *ppl){
    free(ppl->head);
    free(ppl);
}