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

ActionsList initActions(void);
void displayActionsList(ActionsList l);

#endif