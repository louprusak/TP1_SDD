/*---------------------------------------------------------------*/
/* ***************** FICHIER AGENDA (DIARY) ******************** */
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

/* -------------------------------------------------------------------- */
/* initDiary        Initialisation de la liste des semaines (Agenda)    */
/*                                                                      */
/* En entrée: void                                                      */
/*                                                                      */
/* En sortie: NULL                                                      */
/* -------------------------------------------------------------------- */

Diary initDiary(void){
    return NULL;
}

/* -------------------------------------------------------------------- */
/* initDiaryWithFile      Lecture de l'agenda dans un fichier           */
/*                                                                      */
/* En entrée: pd le pointeur qui pointe sur la tête de la liste chainée */
/*            filename le nom du fichier à lire                         */
/*                                                                      */
/* En sortie: void                                                      */
/* -------------------------------------------------------------------- */

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
            recupString(line,name,9,18);
            //removeBackSlashN(name);

            //printf("Année : %s\n Semaine: %s\n Jour: %s\n Heure: %s\n Nom de l'action: %s\n",year, week, day, hour,name);

            ////// PROBLÈME AVEC LA FORME DE name QUI N'EST PAS ACCEPTÉ PAR LA FONCTION ///////////
            addWeek(pd,year,week,atoi(day),atoi(hour),name);
            

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
/* ----------------------------------------------------------------------------------- */
/* createWeekWithAction  Création d'une semaine avec une action insérée                */
/*                                                                                     */
/* En entrée: year la chaine de caractère donnant l'année                              */
/*            weekNumber, day et hour les valeurs de la semaine, du jour et de l'heure */
/*           et name la chaîne de caractère contenant le nom de l'action               */
/*                                                                                     */
/* En sortie: tmp une case semaine                                                     */
/* ----------------------------------------------------------------------------------- */

//Création d'une semaine avec une action insérée
Diary createWeekWithAction(char * year, char *weekNumber,int day, int hour, char * name){
    week_t* tmp = (week_t*) malloc(sizeof(week_t));
    if(tmp){
        //Allocation réussie
        strcpy(tmp->year,year);
        strcpy(tmp->weekNumber,weekNumber);
        //tmp->weekNumber = weekNumber;  on doit utliser des chaines de caractères
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


/* ----------------------------------------------------------------------------------- */
/* insertFirstWeekWithAction  Insert en tête une semaine dans la liste des semaines en */
/*                            insérant une action                                      */
/*                                                                                     */
/* En entrée: d le pointeur de tête de l'agenda                                        */
/*            year la chaine de caractère donnant l'année                              */
/*            weekNumber, day et hour les valeurs de la semaine, du jour et de l'heure */
/*           et name la chaîne de caractère contenant le nom de l'action               */
/*                                                                                     */
/* En sortie: void                                                                     */
/* ----------------------------------------------------------------------------------- */

void insertFirstWeekWithAction(Diary *d, char * year, char *weekNumber,int day, int hour, char* name){
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

/* -------------------------------------------------------------------- */
/* emptyDiary        Savoir si une liste est vide                       */
/*                                                                      */
/* En entrée: d le pointeur de tête de l'agenda                         */
/*                                                                      */
/* En sortie: TRUE si l'agenda est vide, FALSE sinon                    */
/* -------------------------------------------------------------------- */

Boolean emptyDiary(Diary d){
    Boolean code = FALSE;
    if (d == NULL){
        code = TRUE;
    }
    return code;
}

/* -------------------------------------------------------------------- */
/* lengthDiary        Connaitre la longueur de la liste                 */
/*                                                                      */
/* En entrée: d le pointeur de tête de l'agenda                         */
/*                                                                      */
/* En sortie: la longueur de l'agenda d                                 */
/* -------------------------------------------------------------------- */

int lengthDiary(Diary d){
    int i = 0;
    while(!emptyDiary(d)){
        i++;
        d = d->next;
    }
    return i;
}

/* ----------------------------------------------------------------------------------- */
/* addWeek  Ajout d'une nouvelle action selon l'année, la semaine, le jour et l'heure  */
/*                                                                                     */
/* En entrée: pd le pointeur qui pointe sur le pointeur tête de l'agenda               */
/*            year la chaine de caractère donnant l'année                              */
/*            weekNumber, day et hour les valeurs de la semaine, du jour et de l'heure */
/*           et name la chaîne de caractère contenant le nom de l'action               */
/*                                                                                     */
/* En sortie: void                                                                     */
/* ----------------------------------------------------------------------------------- */

// Ajout d'une nouvelle action selon l'année, la semaine, le jour et l'heure
Boolean addWeek(Diary * pd, char * year, char *weekNumber,int dayNumber, int hour, char name[]){
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
        if (strcmp(curr->year,year) > 0 || (strcmp(curr->year,year) == 0 && strcmp(curr->weekNumber,weekNumber) > 0)){
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
                if (strcmp(curr->weekNumber,weekNumber) > 0){
                    prec->next = tmp;
                    tmp->next = curr;
                }
                else{
                    //On se déplace jusqu'à obtenir une semaine supérieure ou égale dans la liste sans changer d'année
                    while (curr->next!= NULL && strcmp(curr->year,year)==0 && strcmp(curr->weekNumber, weekNumber)>0 ){
                        prec = curr;
                        curr = curr->next;
                    }

                    //Si on a extactement la même semaine on ajoute l'action à la liste des actions
                    if (strcmp(curr->weekNumber, weekNumber) == 0){
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

//Rechercher un motif et créer une liste des jours qui l'ont
void findPattern(Diary d, patternList_t *ppl, char *pattern){
    if(d){
        int tabsize = 0;
        char *result = NULL;
        ActionsList al = NULL;
        while (d != NULL)
        {
            al = d->actionsList;
            while(al != NULL)
            {
                result = strstr(d->actionsList->actionName,pattern);
                if(result){
                    addDay(ppl, &tabsize, d->year, d->weekNumber, al->dayNumber, al->hour, al->actionName);
                }
                al = al->next;
            }
            d = d->next;
        }
    }
    
} 

/* -------------------------------------------------------------------- */
/* supprFirstWeek  Suppression du premier élément d'une liste           */
/*                    de type Diary                                     */
/*                                                                      */
/* En entrée: pd le pointeur qui pointe sur la tête de la liste chainée */
/*                                                                      */
/* En sortie: void                                                      */
/* -------------------------------------------------------------------- */

void supprFirstWeek(Diary* pd){
    Diary curr=*pd;
    *pd=(curr)->next;
    free(curr);
}


/* ----------------------------------------------------------------------------------- */
/* supprWeek                   Suppression d'un élément de l'agenda                    */
/*                                                                                     */
/* En entrée: pd le pointeur qui pointe sur le pointeur tête de l'agenda               */
/*            year la chaine de caractère donnant l'année                              */
/*            weekNumber, day et hour les valeurs de la semaine, du jour et de l'heure */
/*           et name la chaîne de caractère contenant le nom de l'action               */
/*                                                                                     */
/* En sortie: TRUE si la suppression est faite, FALSE sinon                            */
/* ----------------------------------------------------------------------------------- */

Boolean supprWeek(Diary * pd, char * year, char * week, int day, int hour, char name[]){

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
        printf("déplacement année : =%s= =%s=\n=%s= =%s=\n",curr->year,curr->weekNumber, year, week);
        // Égalité sur l'année
        if (strcmp(curr->year,year)==0){
            // Déplacement selon la semaine
            printf("égalité dans l'année\n");
            while (curr!=NULL && strcmp(curr->year,year)==0 && strcmp(curr->weekNumber,week)<0 ){
                printf("je passe dans le while\n");
                prec = curr;
                printf("le prec ne merde pas\n");
                curr = curr->next;
            }
            printf("fin while après égalité année\n");
            int retour = strcmp(curr->weekNumber,week);
            printf("%d\n",retour);
            printf("%d %d %s\n",day,hour,name);
            // Égalité de la semaine et l'action existe dans la liste des actions
            if (strcmp(curr->weekNumber,week) == 0 && supprAction(&(curr->actionsList),day,hour,name)){
                printf("égalité de la semaine\n");
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
                printf("l'élément n'existe pas\n");
                code = FALSE;
            }
        }
        else {
            code = FALSE;
        }
    }
    return code;
}


/* -------------------------------------------------------------------- */
/* displayWeeksList        Affiche la liste des semaines (Agenda)       */
/*                                                                      */
/* En entrée: d le pointeur de tête de l'agenda                         */
/*                                                                      */
/* En sortie: void                                                      */
/* -------------------------------------------------------------------- */

void displayWeeksList(Diary d){
    printf("Agenda :\n");
    while (d != NULL)
    {
        printf("\tAnnée %s semaine %s :\n",d->year, d->weekNumber);
        displayActionsList(d->actionsList);
        d = d->next;
    }
    printf("\n");
}

/* -------------------------------------------------------------------- */
/* saveDiary      Sauvegarde de l'Agenda dans un fichier texte          */
/*                                                                      */
/* En entrée: pd le pointeur qui pointe sur la tête de la liste chainée */
/*            filename le nom du fichier à lire                         */
/*                                                                      */
/* En sortie: void                                                      */
/* -------------------------------------------------------------------- */

void saveDiary(Diary d, char *filename){
    //printf("Je passe dans le save\n");
    if(d){
        FILE *file = fopen(filename,"w");
        if(file){
            //printf("%s %s\n",d->year,d->weekNumber);

            while(d != NULL){
                
                ActionsList l = d->actionsList;
                while(l != NULL){
                    fprintf(file,"%s%s%d%02d%s\n",d->year,d->weekNumber,l->dayNumber,l->hour,l->actionName);
                    l = l->next;
                }
                
                d = d->next;
            }
        }
        fclose(file);
    }
    else{
        printf("Impossible l'agenda est vide.\n");
    }
    
}

/* -------------------------------------------------------------------------- */
/* freeDiary    Libération de la liste des semaines                           */
/*                                                                            */
/* En entrée: d le pointeur qui pointe sur la tête de la liste de l'agenda    */
/*                                                                            */
/* En sortie: void                                                            */
/* -------------------------------------------------------------------------- */

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