#include "diary.h"


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

Diary initDiary(void){
    return NULL;
}

void initDiaryWithFile(Diary *d, char *fileName){

    char line[LINE_SIZE]="";
    char year[YEAR_SIZE]="", week[WEEK_SIZE]="", hour[HOUR_SIZE]="", text[ACTION_NAME_SIZE]="", day[DAY_SIZE]="";

    FILE* flot = fopen(fileName, "r");
    if(flot){
        while(fgets(line,LINE_SIZE,flot)){

            printf("Ligne: %s\n",line);

            recupString(line,year,0,3);
            recupString(line,week,4,5);
            recupString(line,day,6,6);
            recupString(line,hour,7,8);
            recupString(line,text,9,strlen(line));
            
            printf("Année : %s\n Semaine: %s\n Jour: %s\n Heure: %s\n Texte: %s\n",year, week, day, hour,text);

            // Chercher si la semaine est présente
                // Si oui on ajoute seulement l'action à la semaine
                // Sinon on crée une semaine et on ajoute l'action
        }
    }
}





//Initialisation de la liste des semaines (Agenda)
Diary initWeeks(void){
    return NULL;
}

//Savoir si une liste est vide
Boolean empty(Diary d){
    if (d == NULL){
        return TRUE;
    }
    return FALSE;
}

//Connaitre la longueur de la liste
int length(Diary d){
    int i = 0;
    while(!empty(d)){
        i++;
        d = d->next;
    }
    return i;
}

// void addWeek(Diary d, char *year, int weekNumber){
//     Diary curr = d;
//     while(curr->next != NULL){
//         while(curr->year < year){
//             curr = curr->next;
//         }
//         if(curr->year == year){
//             while(curr->weekNumber < weekNumber){
//                 curr = curr->next;
//             }
//             if(curr->weekNumber == weekNumber){
                
//             }
//         }
        
//     }
// }

Diary createWeek(char *year, int weekNumber){
    printf("Je passe dans le creatWeek\n");
    week_t* tmp = (week_t*) malloc(sizeof(week_t));
    if(tmp){
        printf("Allocation réussie\n");
        printf("%s -> %s\n",year,tmp->year);
        strcpy(tmp->year,year);
        printf("%s -> %s\n",year,tmp->year);
        tmp->weekNumber = weekNumber;
        tmp->actionsList = initActions();
        tmp->next = NULL;
    }
    return tmp;
}

// Renvoie la position du maillon avec l'année et le numéro de semaine ou 
// int exist(Diary d, char *year, int weekNumber){
//     int i = 0;
//     while (d->next)
//     {
//         if ((strcmp(year, d->year) == 0 && weekNumber == d->weekNumber) || )
//         {
//             break;
//         }

//         if(strcmp(year, d->year) > 0){

//         }
//         i++;
//     }
//     return i;
// }

// Insert en tête une semaine dans la liste des semaines
void insertFirst(Diary *d, char *year, int weekNumber){
    week_t *tmp = createWeek(year, weekNumber);
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

//Affiche la liste des semaines (Agenda)
void displayWeeksList(Diary d){
    printf("Agenda :\n");
    while (empty(d))
    {
        printf("\tAnnée %s semaine %d :\n",d->year, d->weekNumber);
        displayActionsList(d->actionsList);
        d = d->next;
    }
    printf("\n");
}


//Ajout dans les listes


