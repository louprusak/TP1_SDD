/*---------------------------------------------------------------*/
/* ***************** FICHIER AGENDA (DIARY) ********************* /
/* Fichier contenant les fonctions nécessaires                   */
/* pour la gestion de l'Agenda.                                  */
/*****************************************************************/
/*---------------------------------------------------------------*/

#include "diary.h"

////////////// INUTILE /////////////////
// Diary initDiary(char *filename){
//     char year[4] = "";
//     int weekNumber = 0;
//     int dayNumber = 0;
//     int hour = 0;
//     char actionName[10] = "";

//     FILE * file = fopen(filename,"r");
//     if(file){
//         while(!feof(file)){
//             fread(file,4*sizeof(char),1,year);
//             fread(file,2*sizeof(int),1,weekNumber);
//             fread(file,sizeof(int),1,dayNumber);
//             fread(file,2*sizeof(int),1,hour);
//             fscanf(file,"%s",actionName);
//             addWeek();
//         }
//     }
// }

//Initialisation de la liste des semaines (Agenda)
Diary initDiary(void){
    return NULL;
}

// Lecture de l'agenda dans un fichier
void initDiaryWithFile(Diary *pd, char *fileName){

    char line[LINE_SIZE]="";
    char year[YEAR_SIZE]="", week[WEEK_SIZE]="", hour[HOUR_SIZE]="", name[ACTION_NAME_SIZE]="", day[DAY_SIZE]="";

    FILE* file = fopen(fileName, "r");
    if(file){
        while(fgets(line,LINE_SIZE,file)){

            //printf("Ligne: %s\n",line);

            recupString(line,year,0,3);
            recupString(line,week,4,5);
            recupString(line,day,6,6);
            recupString(line,hour,7,8);
            recupString(line,name,9,strlen(line)-3);

            //printf("Année : %s\n Semaine: %s\n Jour: %s\n Heure: %s\n Nom de l'action: %s\n",year, week, day, hour,name);

            ////// PROBLÈME AVEC LA FORME DE name QUI N'EST PAS ACCEPTÉ PAR LA FONCTION ///////////
            addWeek(pd,year,atoi(week),atoi(day),atoi(hour),name);
            

            ////////////// INUTILE /////////////////
            // insertFirstWeek(&d,"2022",1);
            // addAction(&d->actionsList, 5, atoi("08"),"Espagnol");
            // addAction(&d->actionsList, 1, atoi("08"),"BDD");
            // addAction(&d->actionsList, 5, atoi("10"),"Anglais");
            // addAction(&d->actionsList, 6, atoi("12"),"Manger");
            
        }
    }
    fclose(file);
}

//Création d'une semaine avec une action insérée
Diary createWeekWithAction(char * year, int weekNumber,int day, int hour, char * name){
    week_t* tmp = (week_t*) malloc(sizeof(week_t));
    if(tmp){
        //Allocation réussie
        strcpy(tmp->year,year);
        tmp->weekNumber = weekNumber;
        addAction(&(tmp->actionsList), day, hour, name);
        tmp->next = NULL;
    }
    return tmp;
}

////////////// INUTILE /////////////////
// //Création d'une semaine avec une liste d'actions vide (POUR LES TESTS A ENLEVER SI BESOIN)
// Diary createWeek(char *year, int weekNumber){
//      printf("Je passe dans le createWeek\n");
//      week_t* tmp = (week_t*) malloc(sizeof(week_t));
//      if(tmp){
//          strcpy(tmp->year,year);
//          tmp->weekNumber = weekNumber;
//          tmp->actionsList = initActions();
//          tmp->next = NULL;
//     }
//     return tmp;
// }

// Insert en tête une semaine dans la liste des semaines en insérant une action
void insertFirstWeekWithAction(Diary *d, char * year, int weekNumber,int day, int hour, char* name){
    week_t *tmp = createWeekWithAction(year, weekNumber, day, hour, name);
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

////////////// INUTILE /////////////////
// // Insert en tête une semaine dans la liste des semaines (POUR LES TESTS A ENLEVER SI BESOIN)
// void insertFirstWeek(Diary *d, char * year, int weekNumber){
//     week_t *tmp = createWeek(year, weekNumber);
//     if(tmp){
//         if(!*d){
//             tmp->next = NULL;
//         }
//         else{
//             tmp->next = *d;
//         }
//         *d = tmp;
//     }
// }

//Savoir si une liste est vide
Boolean emptyDiary(Diary d){
    if (d == NULL){
        return TRUE;
    }
    return FALSE;
}

//Connaitre la longueur de la liste
int lengthDiary(Diary d){
    int i = 0;
    while(!emptyDiary(d)){
        i++;
        d = d->next;
    }
    return i;
}

// Ajout d'une nouvelle action selon l'année, la semaine, le jour et l'heure
Boolean addWeek(Diary * pd,char * year, int weekNumber,int dayNumber, int hour, char name[]){
    Boolean code = TRUE; // indicateur d'erreur
    
    if(!*pd){
        insertFirstWeekWithAction(pd,year,weekNumber,dayNumber, hour, name);
    }
    else{

        Diary curr = *pd;
        Diary prec = curr;
        
        //Si l'année à ajouter est inférieure à la première de la liste
        //Ou qu'il est égal mais la semaine est plus petite que la première
        //Alors l'élement va être en tête de liste 
        if (strcmp(curr->year,year) > 0 || (strcmp(curr->year,year) == 0 && curr->weekNumber > weekNumber)){
            insertFirstWeekWithAction(pd, year, weekNumber,dayNumber, hour, name);
        } 
        else{
            Diary tmp = createWeekWithAction(year, weekNumber, dayNumber, hour, name);

            //Tri en fonction du numéro de l'année
            //On se déplace jusqu'à obtenir un élément sup ou égal à year
            while (curr->next != NULL && strcmp(curr->year,year)<0){
                prec = curr;
                curr=curr->next;
            }

            //Si l'année existe dans la liste
            if (strcmp(curr->year,year) == 0){

                //Tri en fonction des semaines

                //Toutes les semaines sont sup alors on ajoute en tête de l'année
                if (curr->weekNumber > weekNumber){
                    prec->next = tmp;
                    tmp->next = curr;
                }
                else{
                    //On se déplace jusqu'à obtenir une semaine supérieure ou égale dans la liste sans changer d'année
                    while (curr->next!= NULL && strcmp(curr->year,year)==0 && curr->weekNumber < weekNumber){
                        prec = curr;
                        curr = curr->next;
                    }

                    //Si on a extactement la même semaine on ajoute l'action à la liste des actions
                    if (curr->weekNumber == weekNumber){
                        code = addAction(&(curr->actionsList),dayNumber,hour,name);
                    } 
                    else {
                        // L'élément n'est pas le dernier de la liste ou alors il possède une année plus grande que celle à placer
                        if (curr->next || curr->year>year){
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


// Suppression du premier élément d'une liste de type Diary
void supprFirstWeek(Diary* pd){
    Diary curr=*pd;
    *pd=(curr)->next;
    free(curr);
}

// Suppression d'un élément de l'agenda
Boolean supprWeek(Diary * pd, char * year, int week, int day, int hour, char name[]){

    Boolean code = TRUE;

    // Dans le cas où l'agenda est vide
    if (!*pd){
        code = FALSE;
    }
    else {
        Diary curr = *pd;
        Diary prec = curr;
        // Déplacement selon l'année
        while (curr!=NULL && strcmp(curr->year,year)<0){
            prec= curr;
            curr=curr->next;
        }
        // Égalité sur l'année
        if (strcmp(curr->year,year)==0){
            // Déplacement selon la semaine
            while (curr!=NULL && strcmp(curr->year,year)==0 && curr->weekNumber < week ){
                prec = curr;
                curr = curr->next;
            }
            // Égalité de la semaine et l'action existe dans la liste des actions
            if (curr->weekNumber==week && supprAction(&(curr->actionsList),day,hour,name)){
                if (!curr->actionsList){
                    // La liste des actions est vide alors on supprime la case de l'année et de la semaine
                    if (curr==*pd){
                        supprFirstWeek(pd);
                    }
                    else {
                        prec->next = curr->next;
                        free(curr);
                    }
                }
            // Dans tous les autres cas l'élément n'existe pas
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



//Affiche la liste des semaines (Agenda)
void displayWeeksList(Diary d){
    printf("Agenda :\n");
    while (d != NULL)
    {
        printf("\tAnnée %s semaine %d :\n",d->year, d->weekNumber);
        displayActionsList(d->actionsList);
        d = d->next;
    }
    printf("\n");
}

//Sauvegarde de l'Agenda dans un fichier texte
void saveDiary(Diary d, char *filename){
    printf("Je passe dans le save\n");
    FILE *file = fopen(filename,"w");
    if(file){
        printf("%s %d\n",d->year,d->weekNumber);

        while(d != NULL){

            while(d->actionsList != NULL){
                fprintf(file,"%s%02d%d%02d%s\n",d->year,d->weekNumber,d->actionsList->dayNumber,d->actionsList->hour,d->actionsList->actionName);
                d->actionsList = d->actionsList->next;
            }
            
            d = d->next;
        }
    }
    fclose(file);
}

// Libération de la liste des semaines
void freeDiary (Diary d){
    Diary curr = d;
    Diary suiv = d;

    while (suiv!=NULL){
        suiv=suiv->next;
        freeActionsList(curr->actionsList);
        free(curr);
        curr=suiv;
    }
}