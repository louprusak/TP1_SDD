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

void initDiaryWithFile(Diary *pd, char *fileName){
    Diary d = *pd;
    d = initDiary();

    char line[LINE_SIZE]="";
    char year[YEAR_SIZE]="", week[WEEK_SIZE]="", hour[HOUR_SIZE]="", text[ACTION_NAME_SIZE]="", day[DAY_SIZE]="";

    FILE* file = fopen(fileName, "r");
    if(file){
        while(fgets(line,LINE_SIZE,file)){

            printf("Ligne: %s\n",line);

            recupString(line,year,0,3);
            recupString(line,week,4,5);
            recupString(line,day,6,6);
            recupString(line,hour,7,8);
            recupString(line,text,9,strlen(line));
            
            printf("Année : %s\n Semaine: %s\n Jour: %s\n Heure: %s\n Texte: %s\n",year, week, day, hour,text);

            insertFirst(&d,"2022",1);
            addAction(&d->actionsList, 5, atoi("08"),"Espagnol");
            addAction(&d->actionsList, 1, atoi("08"),"BDD");
            addAction(&d->actionsList, 5, atoi("10"),"Anglais");
            addAction(&d->actionsList, 6, atoi("12"),"Manger");
            


            //addWeek()


            // Chercher si la semaine est présente
                // Si oui on ajoute seulement l'action à la semaine
                // Sinon on crée une semaine et on ajoute l'action
        }
    }
    fclose(file);
}





//Initialisation de la liste des semaines (Agenda)
Diary initWeeks(void){
    return NULL;
}

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
    //printf("Je passe dans le creatWeek\n");
    week_t* tmp = (week_t*) malloc(sizeof(week_t));
    if(tmp){
        //printf("Allocation réussie\n");
        //printf("%s -> %s\n",year,tmp->year);
        strcpy(tmp->year,year);
        //printf("%s -> %s\n",year,tmp->year);
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


//Ajout dans les listes


