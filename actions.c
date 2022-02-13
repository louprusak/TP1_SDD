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

void addAction (ActionsList list, int day,int hour, char name[ACTION_NAME_SIZE]){ // /!\ ne pas mettre de taille dans les prototypes
    ActionsList curr = list;

    ActionsList tmp;
    tmp = (ActionsList) malloc(sizeof(Action_t));
    tmp->dayNumber=day;
    tmp->hour = hour;
    strcpy(tmp->actionName,name);
    tmp->next = NULL;

    displayActionsList(tmp);

    tmp = (ActionsList) malloc (sizeof(Action_t));
    if (list){
        ActionsList prec;
        while (curr!=NULL && curr->dayNumber < day){
            prec = curr;
            curr=curr->next;
        }
        if (curr->dayNumber == day){
            while (curr!=NULL && curr->hour < hour){
                prec = curr;
                curr=curr->next;
            }
        }
        prec->next = tmp;
        tmp->next = curr;
    }else{
        list = tmp;

    }
}


void displayActionsList(ActionsList l){
    while (l != NULL)
    {
        printf("\t\t Jour %d à %d h : %s\n",l->dayNumber, l->hour, l->actionName);
        l = l->next;
    }
    printf("\n");
}

