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

// Creation of a new action
ActionsList createAction(int day, int hour, char * name){
    ActionsList tmp = (ActionsList) malloc(sizeof(Action_t));
    if (tmp){
        tmp->dayNumber=day;
        tmp->hour = hour;
        strcpy(tmp->actionName,name);
        tmp->next = NULL;
    }
    return tmp;
}


// Insert en tête d'une action dans la liste des actions
void insertFirstAction(ActionsList *d, int day, int hour, char * name){
    Action_t *tmp = createAction(day, hour, name);
    if(tmp){
        if(!*d){
            tmp->next = NULL;
        }
        else{
            tmp->next = *d;
        }
        *d = tmp;
    }
}

// curr: pointeur de parcours de liste
// prec : pointeur de l'élément précédant celui en cours de lecture

int addAction (ActionsList list, int day,int hour, char name[]){

    ActionsList curr = list;
    int code = 1; // indicateur d'erreur

    if (list){ // La liste n'est pas vide

        ActionsList prec = curr;

        if (curr->dayNumber > day || (curr->dayNumber == day && curr->hour > hour)){ // l'élément va en tête de liste
            ActionsList * plist = &list;
            insertFirstAction(plist, day, hour, name); // NE FONCTIONNE PAS !!!!
        } else {

            ActionsList tmp = createAction (day, hour, name);

            while (curr->next != NULL && curr->dayNumber < day){ // se déplacer jusqu'à obtenir un élément sup ou égal à day
                prec = curr;
                curr=curr->next;
            }
            if (day == curr->dayNumber){ // Cas d'un élément déjà présent pour ce jour-là
                if (curr->hour > hour){ // l'élément est rajouter avant se place avant curr
                    prec->next = tmp;
                    tmp->next = curr;
                } else {
                    while (curr->next!= NULL && curr->dayNumber == day && curr->hour < hour){ // se déplacer jusqu'à elmt >= à hour
                        prec = curr;
                        curr = curr->next;
                    }
                    if (curr->hour == hour){
                        code = 0; // Il y a une erreur car quelque chose est déjà enrgistré
                    } else {
                        if (curr->next){
                            prec->next = tmp;
                            tmp->next = curr;
                        } else {
                            // insertion en fin
                            curr->next = tmp;
                        }
                    }
                }
            } else {
                if (curr->next){
                    prec->next = tmp;
                    tmp->next = curr;
                } else {
                    // insertion en fin
                    curr->next = tmp;
                }
            }
        }

    }else{ // Si la liste est vide
        ActionsList * plist = &list;
        *plist = createAction(day, hour, name); // NE FONCTIONNE PAS !!!
    }
    return code;
}


// //Renvoie vrai si la suppression est réussie
// int supprAction (ActionsList list, int day, int hour, char name[]){
//     ActionsList curr = list;
//     int code = 1;
//     if (list){
//         ActionsList prec;
//         while (curr!=NULL && curr->dayNumber < day){
//             prec = curr;
//             curr=curr->next;
//         }
//         if (curr->dayNumber == day){
//             while (curr!=NULL && curr->hour < hour){
//                 prec = curr;
//                 curr=curr->next;
//             }
//         } else {
//             code = 0;
//         }
//         if (curr->hour == hour && code){
//             while (!strcmp(curr->actionName, name)){
//                 prec = curr;
//                 curr=curr->next;
//             }
//         } else{
//             code = 0;
//         }
//         if (strcmp(curr->actionName, name) && code){
//             prec->next=curr->next;
//             free(curr);
//         }
//     }else {
//         code = 0;
//     }
//     return code;
// }

void displayActionsList(ActionsList list){
    while (list!= NULL)
    {
        printf("\t\t Jour %d à %d h : %s\n",list->dayNumber, list->hour, list->actionName);
        list = list->next;
    }
    printf("\n");
}