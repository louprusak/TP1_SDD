#include "diary.h"

ActionsList initActions(void){
    return NULL;
}

// ActionsList initWeeksByFile(char *fileName){
//     FILE *file = fopen(fileName,"r");
//     if(file){
//         while(!feof(file)){
        
//         }
//     }
// }

void displayActionsList(ActionsList l){
    while (l != NULL)
    {
        printf("\t\t Jour %d à %d : %s\n",l->dayNumber, l->hour, l->actionName);
        l = l->next;
    }
    printf("\n");
}