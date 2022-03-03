#include "diary.h"

ActionsList initActions(void){
    return NULL;
}

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

// curr: pointeur de parcours de liste
// prec : pointeur de l'élément précédant celui en cours de lecture
Boolean addAction(ActionsList *plist, int day,int hour, char *name){
    Boolean code = TRUE; // indicateur d'erreur
    
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
                        code = FALSE;
                    } 
                    else {
                        // L'élément n'est pas le dernier de la liste ou alors il possède un jour plus grand que celui à placer
                        if (curr->next || curr->dayNumber>day){
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

void supprFirstAction(ActionsList* plist){
    Action_t* curr = *plist;
    *plist=curr->next;
    free(curr);
}

Boolean supprAction (ActionsList* plist, int day, int hour, char name[]){
    ActionsList prec = *plist;
    ActionsList curr=prec;
    Boolean code = TRUE;

    // La liste est vide
    if (!*plist){
        code = FALSE;
    }
    else {
        // On se déplace selon les jours
        while (curr!=NULL && curr->dayNumber < day){
            prec= curr;
            curr=curr->next;
        }
        // Égalité sur le jour
        if (curr->dayNumber==day){
            // Déplacement selon l'heure
            while (curr!=NULL && curr->dayNumber == day && curr->hour < hour){
                prec = curr;
                curr = curr->next;
            }
            // Vérification si il y a égalité de l'heure et du nom
            if (curr->hour==hour && strcmp(curr->actionName, name)==0){
                // Cas si l'élément à supprimer est le premier
                if (curr == *plist){
                    printf("Cas de l'élément en premier à supprimer\n");
                    supprFirstAction(plist);
                }
                // On élimine l'élément après prec
                else {
                    prec->next = curr->next;
                    free(curr);
                }
            // Dans tous les autres cas c'est que l'élément n'existe pas  donc on renvoit un code à FALSE
            }
            else {
                code = FALSE;
            }
        }
        else {
            code = FALSE;
        }
    }
    return code;
}

void displayActionsList(ActionsList list){
    while (list!= NULL)
    {
        printf("\t\t Jour %d à %02d h : %s\n",list->dayNumber, list->hour, list->actionName);
        list = list->next;
    }
}