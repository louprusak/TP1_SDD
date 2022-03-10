/*---------------------------------------------------------------*/
/* ******** FICHIER UTILITAIRE DE CHAINE DE CARACTERES ***********/
/* Fichier contenant des fonctions utiles                        */
/* pour la gestion des chaines de caractères                     */
/*****************************************************************/
/*---------------------------------------------------------------*/

#include "diary.h"

/*---------------------------------------------------------------*/
/* removeBackSlashN    Enlève le caractère de retour à la        */
/*          fin d'une chaine de carcatères                       */
/*                                                               */
/* Entrée : s ; chaine de caractères                             */
/*---------------------------------------------------------------*/
void removeBackSlashN(char *s){
    s[strlen(s) -1] = '\0';
}

/*----------------------------------------------------------------- */
/* recupString       Récupère une partie de la chaine de caractères */
/*          depuis un début et jusqu'à une fin                      */
/*                                                                  */
/* Entrée : input ; chaine de caractères fournie                    */
/*          output ; chaine de caractère renvoyée                   */
/*          debut ; indice de début                                 */
/*          fin ; indice de fin                                     */
/*                                                                  */
/* Variables locales:                                               */
/*            i: indice du caractère en cours de lecture dans input */
/*            j : indice du prochain caractère libre dans output    */
/*----------------------------------------------------------------- */
void recupString(char *input, char *output, int begin,int end){
    int j = 0;
    for (int i = begin; i <= end; i++)
    {
        if(input[i] != '\0'){
            output[j] = input[i];
            j++;
        }
        
    }
    output[strlen(output)]='\0';
}