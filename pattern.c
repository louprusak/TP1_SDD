#include "pattern.h"

/* -------------------------------------------------------------------- */
/* initPattern        Initialisation de la liste des motifs             */
/*                                                                      */
/* En entrée: void                                                      */
/*                                                                      */
/* En sortie: ppl: la liste de type patternList_t vide                  */
/* -------------------------------------------------------------------- */

//Init ok
patternList_t * initPattern(){
    patternList_t *ppl = (patternList_t*) malloc(sizeof(patternList_t));
    if(ppl){
        ppl->head = NULL;
        //printf("Tete nulle %d\n",ppl->head);
        ppl->tail = NULL;
        //printf("queue nulle %d\n",ppl->tail);
    }
    else{
        printf("Allocation mal passée\n");
    }
    return ppl;
}

/* ----------------------------------------------------------------------------------- */
/* addDay  Ajout d'une nouvelle occurrence du motif selon l'année, la semaine, le jour */
/*           l'heure et le nom de l'action                                             */
/*                                                                                     */
/* En entrée: ppl le pointeur sur la liste contiguë                                    */
/*            year et week les chaines de caractères donnant l'année et la semaine     */
/*            day et hour les valeurs de la semaine, du jour et de l'heure             */
/*           et name la chaîne de caractère contenant le nom de l'action               */
/*                                                                                     */
/* En sortie: void                                                                     */
/*                                                                                     */
/* Variables locales: tmp : l'élément à ajouter dans la liste                          */
/*            size: la taille de la liste non vide                                     */
/* ----------------------------------------------------------------------------------- */

void addDay(patternList_t *ppl, char * year, char * week, int day, int hour, char *actionName){
    if(ppl){
        //printf("ADDDAY : début du remplissage des valeurs\n");
        pattern_t tmp;
        strcpy(tmp.year, year);
        strcpy(tmp.weekNumber, week);
        tmp.dayNumber = day;
        tmp.hour = hour;
        strcpy(tmp.actionName,actionName);
        //printf("ADDDAY : fin du remplissage des valeurs\n");
        if(ppl->head)
        {
            //printf("ADDDAY : Tête pas vide: %d\n",ppl->head);
            int size = (ppl->tail) - (ppl->head) +1 ;
            //printf("ADDDAY : Taille %d\n",taille);
            (ppl->list)[size] = tmp;
            (ppl->tail) = &((ppl->list)[size]);
        }
        else{
            //printf("ADDDAY : Tête vide\n");
            (ppl->head) = &((ppl->list)[0]);//(ppl->list);
            (ppl->list)[0] = tmp;
            (ppl->tail) = &((ppl->list)[0]);
        }

        // if(!ppl->head){
        //     ppl->list[0] = tmp;
        //     ppl->head = &tmp;
        // }
        // else{
        //     *(ppl->tail+1) = tmp;
        // }
        // ppl->tail = &tmp;
    }
}

/* ----------------------------------------------------------------------------------- */
/* displayPattern         Affichage de la liste contiguë des occurences d'un motif     */
/*                                                                                     */
/* En entrée: pl: la liste contiguë                                                    */
/*            year et week les chaines de caractères donnant l'année et la semaine     */
/*                                                                                     */
/* En sortie: void                                                                     */
/*                                                                                     */
/* Variables locales: size : la taille de la liste non vide                            */
/*            elt: une case de la liste                                                */
/* ----------------------------------------------------------------------------------- */

void displayPattern(patternList_t pl){
    //printf("Tete et queu %d %d\n",pl.head,pl.tail);

    if (pl.head != NULL) 
    { 
        int size = (pl.tail - pl.head);// / sizeof(pattern_t); 
        printf("\nLe nombre de jours correspondant est: %d\n", size +1); 
        for (int i = 0; i <= size; i++) 
        {
            pattern_t elt = pl.list[i];
            printf("Année %s semaine %s jour %d à %02dh : %s\n", elt.year, elt.weekNumber, elt.dayNumber, elt.hour, elt.actionName); 
        } 
    } 
    else 
    { 
        printf("Aucun jour n'a été trouvé pour le motif rentré.\n"); 
    } 
    
}

// void affichage_action_motif(patternList_t pl) 
// { 
//     printf("Tete et queu %d %d\n",pl.head,pl.tail);

//     if (pl.tail != NULL) 
//     { 
//         int taille = (pl.tail - pl.head);// / sizeof(pattern_t); 
//         printf("NOMBRE DE JOURS CORRESPONDANTS: %d\n", taille + 1); 
//         for (int i = 0; i <= taille; i++) 
//         { 
//             printf("%d %s", pl.list[i].dayNumber, pl.list[i].actionName); 
//         } 
//     } else 
//     { 
//         printf("Aucun jour n'a été trouvé pour le motif\n" ); 
//     } 
// }

// void freePattern(patternList_t *ppl){
//     //free(ppl->head);
//     free(ppl);
// }