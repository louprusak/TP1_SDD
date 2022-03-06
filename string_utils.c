/*---------------------------------------------------------------*/
/* ******** FICHIER UTILITAIRE DE CHAINE DE CARACTERES ***********/
/* Fichier contenant des fonctions utiles                        */
/* pour la gestion des chaines de caractères                     */
/*****************************************************************/
/*---------------------------------------------------------------*/

#include "diary.h"

/*---------------------------------------------------------------*/
/*          Enlève le caractère de retour à la                   */
/*          fin d'une chaine de carcatères                       */
/*                                                               */
/* Entrée : s ; chaine de caractères                             */
/*---------------------------------------------------------------*/

void removeBackSlashN(char *s){
    s[strlen(s) -1] = '\0';
}

/*---------------------------------------------------------------*/
/*          Récupère une partie de la chaine de caractères       */
/*          depuis un début et jusqu'à une fin                   */
/*                                                               */
/* Entrée : input ; chaine de caractères fournie                 */
/*          output ; chaine de caractère renvoyée                */
/*          debut ; indice de début                              */
/*          fin ; indice de fin                                  */
/*---------------------------------------------------------------*/

void recupString(char *input, char *output, int debut,int fin){
    int j = 0;
    for (int i = debut; i <= fin; i++)
    {
        if(input[i] != '\0'){
            output[j] = input[i];
            j++;
        }
        
    }
    output[strlen(output)]='\0';
}