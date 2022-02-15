/*---------------------------------------------------------------*/
// ***************** FICHIER ENTETE ACTIONS **********************
// Fichier contenant la structure de liste chainée nécessaire 
// pour la gestion des actions à réaliser par semaines
/*---------------------------------------------------------------*/

#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*---------------------------------------------------------------*/
// Constantes
/*---------------------------------------------------------------*/

#define ACTION_NAME_SIZE 10
#define DAY_SIZE 2
#define HOUR_SIZE 3

/*---------------------------------------------------------------*/
//                       Structure Action
//
// Structure de type maillon de la liste des actions
//
// -dayNumber : Numéro de jour (de 0 à 7)
// -hour : Heure de l'action (entre 00 et 24)
// -actionName : Nom de l'action à réaliser
// -next : Pointeur vers l'action suivante
/*---------------------------------------------------------------*/
typedef struct action{
    int dayNumber;           
    int hour;                
    char actionName[10];         
    struct action *next;        
}Action_t, *ActionsList;

/*---------------------------------------------------------------*/
// Fonctions
/*---------------------------------------------------------------*/

ActionsList initActions(void);
ActionsList createAction(int day, int hour, char * name);
void insertFirstAction(ActionsList *d, int day, int hour, char * name);
int addAction (ActionsList list, int day,int hour, char name[]);
int supprAction (ActionsList list, int day, int hour, char name[]);
void displayActionsList(ActionsList l);

#endif