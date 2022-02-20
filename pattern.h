/*---------------------------------------------------------------*/
// **** FICHIER ENTETE LISTE DES JOURS AVEC MOTIF (PATTERN) ***** /
// Fichier contenant la structure de liste chainée nécessaire 
// pour la gestion de l'Agenda
/*---------------------------------------------------------------*/

#ifndef PATTERN_H
#define PATTERN_H

#include "actions.h"
#include "diary.h"

//---------------------------------------------------------------
//          Structure liste contigues des jours avec motifs
//
// Structure de type maillon de la liste des jours avec motifs
//
// -year : Numéro de l'année
// -weekNumber : Numéro de la semaine dans l'année
// -actionsList : Liste des actions à réaliser dans la semaine
// -next : Pointeur vers la semaine suivante
//---------------------------------------------------------------

typedef struct{
    int year;
    int weekNumber;
    int dayNumber;
    int hour;
    char actionName[11]; 
}pattern_t;

typedef struct{
    pattern_t *head;
    pattern_t *tail;
}patternList;



//---------------------------------------------------------------
// Fonctions
//---------------------------------------------------------------

void initPattern(patternList *ppl, int size);
void displayPattern(patternList pl, int size);
void freePattern(patternList *ppl);

#endif