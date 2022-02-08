#include "diary.h"

void removeBackSlashN(char *s){
    s[strlen(s) -1] = '\0';
}

void recupString(char* e, char*s, int debut,int fin){
    int j = 0;
    for (int i = debut; i < fin; i++)
    {
        if(e[i] != '\0'){
            s[j] = e[i];
        }
        j++;
    }
}