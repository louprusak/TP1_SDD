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

void initDiary(char *fileName){
    char ligne[100];
    char year[5], week[3], hour[3], text[10];
    int day = 0;
    FILE* flot = fopen(fileName, "r");
    if(flot){
        while(fgets(ligne,100,flot)){

            

            strcpy(year,recupYear(ligne));
            strcpy(week,recupWeek(ligne));
            day = recupDay(ligne);
            strcpy(hour,recupHour(ligne));
            strcpy(text,recupText(ligne));
        }
    }
}




void readLine(FILE* flot){
    
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


