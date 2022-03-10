/*---------------------------------------------------------------*/
/* ***************** FICHIER AGENDA (DIARY) ******************** */
/* Fichier contenant les fonctions nécessaires                   */
/* pour la gestion de l'Agenda.                                  */
/*****************************************************************/
/*---------------------------------------------------------------*/

#include "diary.h"

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
/*                                                                      */
/* Variables locales: line : ligne en cours de lecture dans le fichier  */
/*            year: valeur de l'année de la ligne                       */
/*            week: valeur du numéro de la semaine de la ligne          */
/*            day: valeur de la journée de la ligne                     */
/*            hour: valeur de l'heure de la ligne                       */
/*            name: nom de l'action de la ligne                         */
/*            file: fichier en cours de lecture                         */
/* -------------------------------------------------------------------- */
void initDiaryWithFile(Diary *pd, char *fileName){

    char line[LINE_SIZE]="";
    char year[YEAR_SIZE]="", week[WEEK_SIZE]="", hour[HOUR_SIZE]="", name[ACTION_NAME_SIZE]="", day[DAY_SIZE]="";

    FILE* file = fopen(fileName, "r");

    if(file){

        while(fgets(line,LINE_SIZE,file))
        {
            recupString(line,year,0,3);
            recupString(line,week,4,5);
            recupString(line,day,6,6);
            recupString(line,hour,7,8);

            for (int i = 9; i < 19; i++)
            {
                if(line[i] == '\n')
                {
                    name[i-9] = '\0';
                }
                else
                {
                    name[i-9] = line[i];
                }
            }

            addWeek(pd,year,week,atoi(day),atoi(hour),name);
        }
    }
    fclose(file);
}

/* --------------------------------------------------------------------- */
/* scanWeek      Lecture d'une semaine avec action au clavier            */
/*                                                                       */
/* En entrée: del booléen permet de ne pas rentrer le nom si suppression */
/*            year la chaine de caractère donnant l'année                */
/*            weekNumber, day et hour les valeurs semaine, jour et heure */
/*           et name la chaîne de caractère contenant le nom de l'action */
/*                                                                       */
/* En sortie: void                                                       */
/* --------------------------------------------------------------------- */
void scanWeek(Boolean del, char *year, char *week, int *day, int *hour, char *name){
    printf("Entrez l'année : ");
    scanf("%s",year);
    printf("\nEntrez la semaine : ");
    scanf("%s", week);
    printf("\nEntrez le jour : ");
    scanf("%d", day);
    printf("\nEntrez l'heure : ");
    scanf("%d%*c", hour);
    if(!del){
        printf("\nEntrez le nom de l'action : ");
        fgets(name,ACTION_NAME_SIZE,stdin);
        removeBackSlashN(name);
    }
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
Diary createWeekWithAction(char * year, char *weekNumber,int day, int hour, char * name){
    week_t* tmp = (week_t*) malloc(sizeof(week_t));
    if(tmp){
        //Allocation réussie
        strcpy(tmp->year,year);
        strcpy(tmp->weekNumber,weekNumber);
        tmp->actionsList = NULL;
        tmp->next = NULL;
        addAction(&(tmp->actionsList), day, hour, name);
    }
    return tmp;
}


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
/*                                                                                     */
/* Variables locales: tmp : case créée à rajouter au début de la liste                 */
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
/*            year et week les chaines de caractères donnant l'année et la semaine     */
/*            day et hour les valeurs de la semaine, du jour et de l'heure             */
/*           et name la chaîne de caractère contenant le nom de l'action               */
/*                                                                                     */
/* En sortie: void                                                                     */
/*                                                                                     */
/* Variables locales: curr : pointeur de parcours de liste                             */
/*            prec: pointeur de l'élément précédent celui pointé par curr              */
/*            tmp: case à ajouter dans la liste                                        */
/*            code: boléeen qui vérifier si l'ajout est fait ou non                    */
/* ----------------------------------------------------------------------------------- */
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
                    while (curr->next!= NULL && strcmp(curr->year,year)==0 && strcmp(curr->weekNumber, weekNumber)<0 ){
                        prec = curr;
                        curr = curr->next;
                    }

                    //Si on a extactement la même semaine on ajoute l'action à la liste des actions
                    if (strcmp(curr->weekNumber, weekNumber) == 0){
                        code = addAction(&(curr->actionsList),dayNumber,hour,name);
                        freeActionsList(tmp->actionsList);
                        free(tmp);
                    } 
                    else {
                        // L'élément n'est pas le dernier de la liste ou alors il possède une année plus grande que celle à placer
                        if (curr->next || strcmp(curr->year,year) > 0){
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


/* --------------------------------------------------------------------------- */
/* findPattern      Rechercher un motif et créer une liste des jours qui l'ont */
/*                                                                             */
/* En entrée: d pointeur de tête de l'Agenda                                   */
/*            *ppl pointeur sur la liste des jours avec motifs                 */
/*            pattern chaine de caractères du motif à rechercher               */
/*                                                                             */
/* En sortie: void                                                             */
/* ----------------------------------------------------------------------------*/
void findPattern(Diary d, patternList_t *ppl, char *pattern){
    if(d){
        char *result = NULL;
        ActionsList al = NULL;
        while (d != NULL){
            al = d->actionsList;
            
            while(al != NULL){
                result = strstr(al->actionName,pattern);

                if(result){
                    addDay(ppl, d->year, d->weekNumber, al->dayNumber, al->hour, al->actionName);
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
/*                                                                      */
/* Variables locales: curr : l'élément à supprimer                      */
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
/*                                                                                     */
/* Variables locales: curr : pointeur de parcours de liste                             */
/*            prec: pointeur de l'élément précédent celui pointé par curr              */
/*            code: boléeen qui vérifier si la suppression est faite ou non            */
/* ----------------------------------------------------------------------------------- */
Boolean supprWeek(Diary * pd, char * year, char * week, int day, int hour){

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
        //printf("déplacement année : =%s= =%s=\n=%s= =%s=\n",curr->year,curr->weekNumber, year, week);
        // Égalité sur l'année
        if (strcmp(curr->year,year)==0){
            // Déplacement selon la semaine
            //printf("égalité dans l'année\n");
            while (curr!=NULL && strcmp(curr->year,year)==0 && strcmp(curr->weekNumber,week)<0 ){
                //printf("je passe dans le while\n");
                prec = curr;
                //printf("le prec ne merde pas\n");
                curr = curr->next;
            }
            //printf("fin while après égalité année\n");
            //int retour = strcmp(curr->weekNumber,week);
            //printf("%d\n",retour);
            //printf("%d %d %s\n",day,hour,name);
            // Égalité de la semaine et l'action existe dans la liste des actions
            if (strcmp(curr->weekNumber,week) == 0 && supprAction(&(curr->actionsList),day,hour)){
                //printf("égalité de la semaine\n");
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
                //printf("l'élément n'existe pas\n");
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
    if(d){
        printf("\nAgenda :\n");

        while (d != NULL){
            printf("\tAnnée %s semaine %s :\n",d->year, d->weekNumber);
            displayActionsList(d->actionsList);
            d = d->next;
        }
        printf("\n");
    }
    else{
        printf("--> L'agenda est vide.\n");
    }
}


/* -------------------------------------------------------------------- */
/* saveDiary      Sauvegarde de l'Agenda dans un fichier texte          */
/*                                                                      */
/* En entrée: pd le pointeur qui pointe sur la tête de la liste chainée */
/*            filename le nom du fichier à lire                         */
/*                                                                      */
/* En sortie: void                                                      */
/*                                                                      */
/* Variables locales: file : fichier en cours de lecture                */
/*            l: copie de la liste des actions                          */
/* -------------------------------------------------------------------- */
Boolean saveDiary(Diary d, char *filename){
    Boolean code = TRUE;

    if(d){
        FILE *file = fopen(filename,"w");
        if(file){

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
        code = FALSE;
        printf("Impossible l'agenda est vide.\n");
    }
    return code;
}


/* -------------------------------------------------------------------------- */
/* freeDiary    Libération de la liste des semaines                           */
/*                                                                            */
/* En entrée: d le pointeur qui pointe sur la tête de la liste de l'agenda    */
/*                                                                            */
/* En sortie: void                                                            */
/*                                                                            */
/* Variables locales: curr : pointeur de parcours de liste                    */
/*            suiv: pointeur de l'élément suivant celui pointé par curr       */
/* -------------------------------------------------------------------------- */
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