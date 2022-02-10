#include "diary.h"

//enlever le \n de la fin de la chaine de caractère
void removeBackSlashN(char *s){
    s[strlen(s) -1] = '\0';
}

//récupérer une partie de la chaine de carcatères depuis un début et jusqu'à une fin
void recupString(char *e, char *s, int debut,int fin){
    int j = 0;
    for (int i = debut; i < fin; i++)
    {
        if(e[i] != '\0'){
            s[j] = e[i];
            j++;
        }
        
    }
    //s[strlen(s)]='\0';
}