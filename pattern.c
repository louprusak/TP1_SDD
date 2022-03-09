#include "pattern.h"

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
            int taille = (ppl->tail) - (ppl->head) +1 ;
            //printf("ADDDAY : Taille %d\n",taille);
            (ppl->list)[taille] = tmp;
            (ppl->tail) = &((ppl->list)[taille]);
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