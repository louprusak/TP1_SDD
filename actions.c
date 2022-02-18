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
ActionsList createAction(int day, int hour, char *name){
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

//Savoir si une liste est vide
Boolean emptyActions(ActionsList l){
    if (l == NULL){
        return TRUE;
    }
    return FALSE;
}

//Connaitre la longueur de la liste
int lengthActions(ActionsList l){
    int i = 0;
    while(!emptyActions(l)){
        i++;
        l = l->next;
    }
    return i;
}

// // curr: pointeur de parcours de liste
// // prec : pointeur de l'élément précédant celui en cours de lecture

// int addAction (ActionsList *plist, int day,int hour, char *name){

//     ActionsList curr = list;
//     int code = 1; // indicateur d'erreur

//     if (list){ // La liste n'est pas vide

//         ActionsList prec = curr;

//         if (curr->dayNumber > day || (curr->dayNumber == day && curr->hour > hour)){ // l'élément va en tête de liste
//             ActionsList * plist = &list;
//             insertFirstAction(plist, day, hour, name); // NE FONCTIONNE PAS !!!!
//         } 
//         else {

//             ActionsList tmp = createAction (day, hour, name);

//             while (curr->next != NULL && curr->dayNumber < day){ // se déplacer jusqu'à obtenir un élément sup ou égal à day
//                 prec = curr;
//                 curr=curr->next;
//             }
//             if (day == curr->dayNumber){ // Cas d'un élément déjà présent pour ce jour-là
//                 if (curr->hour > hour){ // l'élément est rajouter avant se place avant curr
//                     prec->next = tmp;
//                     tmp->next = curr;
//                 } else {
//                     while (curr->next!= NULL && curr->dayNumber == day && curr->hour < hour){ // se déplacer jusqu'à elmt >= à hour
//                         prec = curr;
//                         curr = curr->next;
//                     }
//                     if (curr->hour == hour){
//                         code = 0; // Il y a une erreur car quelque chose est déjà enrgistré
//                     } else {
//                         if (curr->next){
//                             prec->next = tmp;
//                             tmp->next = curr;
//                         } else {
//                             // insertion en fin
//                             curr->next = tmp;
//                         }
//                     }
//                 }
//             } else {
//                 if (curr->next){
//                     prec->next = tmp;
//                     tmp->next = curr;
//                 } else {
//                     // insertion en fin
//                     curr->next = tmp;
//                 }
//             }
//         }

//     }else{ // Si la liste est vide
//         insertFirstAction(plist,day,hour,name); // NE FONCTIONNE PAS !!!
//     }
//     return code;
// }

int addAction(ActionsList *plist, int day,int hour, char *name){
    int code = 1; // indicateur d'erreur
    
    if(!*plist ){
        insertFirstAction(plist,day,hour,name);
    }
    else{

        ActionsList curr = *plist;
        ActionsList prec = curr;
        
        //Si le jour a ajouter est inférieur au premier de la liste
        //Ou qu'il est égal mais l'heure est plus petite que le premier
        //Alors l'élement va être en tête de liste 
        if (curr->dayNumber > day || (curr->dayNumber == day && curr->hour > hour)){
            insertFirstAction(plist, day, hour, name);
        } 
        else{
            ActionsList tmp = createAction (day, hour, name);

            //Tri en fonction du numéro du jour
            //On se déplace jusqu'à obtenir un élément sup ou égal à day
            while (curr->next != NULL && curr->dayNumber < day){
                prec = curr;
                curr=curr->next;
            }

            //Si le jour existe dans la liste
            if (day == curr->dayNumber){

                //Tri en fonction des heures

                //Toutes les heures sont sup alors on ajoute en tête du jour
                if (curr->hour > hour){
                    prec->next = tmp;
                    tmp->next = curr;
                }
                else{
                    //On se déplace jusqu'à obtenir une heure supérieure ou égale dans la liste sans changer de jours
                    while (curr->next!= NULL && curr->dayNumber == day && curr->hour < hour){
                        prec = curr;
                        curr = curr->next;
                    }

                    //Si on a extactement la même heure on ne peut pas avoir deux actions à la même heure donc on renvoie une erreur
                    if (curr->hour == hour){
                        code = 0;
                    } 
                    else {
                        if (curr->next){
                            prec->next = tmp;
                            tmp->next = curr;
                        } else {
                            // insertion en fin
                            curr->next = tmp;
                        }
                    }
                }
            }
            //Si il n'existe pas on le crée et on insère
            else{
                if (curr->next){
                    prec->next = tmp;
                    tmp->next = curr;
                } else {
                    // insertion en fin
                    curr->next = tmp;
                }
            }
        }
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
    //printf("je passe dans le displayactions\n");
    while (list!= NULL)
    {
        //printf("saucisse\n");
        printf("\t\t Jour %d à %02d h : %s\n",list->dayNumber, list->hour, list->actionName);
        list = list->next;
    }
    //printf("\n");
}