/*---------------------------------------------------------------*/
/* **** FICHIER ENTETE LISTE DES JOURS AVEC MOTIF (PATTERN) ******/
/* Fichier contenant la structure de liste chainée nécessaire    */
/* pour la gestion de l'Agenda                                   */
/*****************************************************************/
/*---------------------------------------------------------------*/

#ifndef PATTERN_H
#define PATTERN_H

#include "actions.h"

/*---------------------------------------------------------------*/
/* Constantes                                                    */
/*---------------------------------------------------------------*/
#define YEAR_SIZE 5
#define WEEK_SIZE 3
#define PATTERN_SIZE 50

/*---------------------------------------------------------------*/
//          Structure liste contigues des jours avec motifs
//
// Structure de type maillon de la liste des jours avec motifs
//
// -year : Numéro de l'année
// -weekNumber : Numéro de la semaine dans l'année
// -actionsList : Liste des actions à réaliser dans la semaine
// -next : Pointeur vers la semaine suivante
/*---------------------------------------------------------------*/

typedef struct pattern{
    char year[YEAR_SIZE];
    char weekNumber[WEEK_SIZE];
    int dayNumber;
    int hour;
    char actionName[ACTION_NAME_SIZE];
}pattern_t;

typedef struct{
    pattern_t list[PATTERN_SIZE];
    pattern_t *head;
    pattern_t *tail;
}patternList_t;



/*---------------------------------------------------------------*/
/* Fonctions                                                     */
/*---------------------------------------------------------------*/

patternList_t * initPattern();
void displayPattern(patternList_t pl);
void addDay(patternList_t *ppl, char * year, char * week, int day, int hour, char *actionName);
void freePattern(patternList_t *ppl);
void affichage_action_motif(patternList_t pl);

#endif