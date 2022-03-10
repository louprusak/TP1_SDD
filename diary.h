/*---------------------------------------------------------------*/
/* ***************** FICHIER ENTETE AGENDA (DIARY) ***************/
/* Fichier contenant la structure de liste chainée nécessaire    */
/* pour la gestion de l'Agenda                                   */
/*****************************************************************/
/*---------------------------------------------------------------*/

#ifndef DIARY_H
#define DIARY_H

#include "actions.h"
#include "pattern.h"

/*---------------------------------------------------------------*/
/* Constantes                                                    */
/*---------------------------------------------------------------*/
#define FILENAME_SIZE 100
#define LINE_SIZE 21
#define YEAR_SIZE 5
#define WEEK_SIZE 3

/*---------------------------------------------------------------*/
/*                      Structure Semaines                       */
/*                                                               */
/* Structure de type maillon de la liste des semaines            */
/*                                                               */
/* -year : Numéro de l'année                                     */
/* -weekNumber : Numéro de la semaine dans l'année               */
/* -actionsList : Liste des actions à réaliser dans la semaine   */
/* -next : Pointeur vers la semaine suivante                     */
/*---------------------------------------------------------------*/
typedef struct week{
    char year[YEAR_SIZE];
    char weekNumber[WEEK_SIZE];
    ActionsList actionsList;
    struct week *next;
}week_t, *Diary;

/*---------------------------------------------------------------*/
/* Fonctions                                                     */
/*---------------------------------------------------------------*/
Diary initDiary(void);
void initDiaryWithFile(Diary *d, char *fileName);
Boolean saveDiary(Diary d, char *filename);
Diary initWeeks(void);
Boolean emptyDiary(Diary d);
int lengthDiary(Diary d);
Diary createWeekWithAction(char * year, char * weekNumber,int day, int hour, char * name);
void insertFirstWeekWithAction(Diary *d, char * year, char * weekNumber,int day, int hour, char* name);
void scanWeek(Boolean del,char *year, char *week, int *day, int *hour, char *name);
Boolean addWeek(Diary * pd,char * year, char * weekNumber,int dayNumber, int hour, char *name);
void findPattern(Diary d, patternList_t *ppl, char *pattern);
void supprFirstWeek(Diary* pd);
Boolean supprWeek(Diary * pd, char * year, char * week, int day, int hour);
void displayWeeksList(Diary d);
void freeDiary (Diary d);

//Fonctions du fichier stringUtils
void removeBackSlashN(char *s);
void recupString(char* e, char*s, int debut,int fin);

#endif