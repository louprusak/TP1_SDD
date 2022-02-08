/*---------------------------------------------------------------*/
// ***************** FICHIER ENTETE AGENDA (DIARY) ************** /
// Fichier contenant la structure de liste chainée nécessaire 
// pour la gestion de l'Agenda
/*---------------------------------------------------------------*/

#ifndef DIARY_H
#define DIARY_H

#include "actions.h"

/*---------------------------------------------------------------*/
//                       Structure Semaines
//
// Structure de type maillon de la liste des semaines
//
// -year : Numéro de l'année
// -weekNumber : Numéro de la semaine dans l'année
// -actionsList : Liste des actions à réaliser dans la semaine
// -next : Pointeur vers la semaine suivante
/*---------------------------------------------------------------*/
typedef struct week{
    char year[5];
    int weekNumber;
    ActionsList actionsList;
    struct week *next;
}week_t, *Diary;

/*---------------------------------------------------------------*/
// Définition du type booléen personnalisé
/*---------------------------------------------------------------*/
typedef enum {TRUE, FALSE} Boolean;


Diary initWeeks(void);
Boolean empty(Diary d);
Diary createWeek(char *year, int weekNumber);
void insertFirst(Diary *d, char *year, int weekNumber);
void displayWeeksList(Diary d);


#endif