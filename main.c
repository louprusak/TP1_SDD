#include "diary.h"

//Initialisation de l'Agenda
void initDiaryMain(Diary *pt_d){
    Diary d = *pt_d;
    d = initDiary();

    char filename[100] = "";

    printf("___________________________________________________________\n"
            "1) Initialisation de l'Agenda à partir d'un fichier texte. \n"
            "\nVeuillez enter le nom du fichier texte : "
            );

    scanf("%s",filename);
    removeBackSlashN(filename);

    //initDiaryWithFile(&d,filename);

    insertFirst(&d,"2022",1);
    addAction(&d->actionsList, 5, atoi("08"),"Espagnol");
    addAction(&d->actionsList, 1, atoi("08"),"BDD");
    addAction(&d->actionsList, 5, atoi("10"),"Anglais");
    addAction(&d->actionsList, 6, atoi("12"),"Manger");
    // insertFirst(&d,"2021",2);
    // insertFirst(&d,"2020",3);
    // insertFirst(&d,"2019",4);
    // insertFirst(&d,"2018",5);
    // insertFirst(&d,"2017",6);

    displayWeeksList(d);
}


//Programme principal
int main(void){

    int quit = 0;
    int answer = -1;
    Diary d;

    while(!quit){

        printf("#############################################################################\n"
            "# Bonjour et bienvenue sur votre système personnalisé de gestion d'Agenda ! #\n"
            "#############################################################################\n"
            "\nChoisissez ce que vous voulez faire :\n"
            "\n\t1) Initialiser l'Agenda à partir d'un fichier texte\n"
            "\t2) Ajouter une action dans l'Agenda (WORK IN PROGRESS)\n"
            "\t3) Supprimer une action de l'Agenda (WORK IN PROGRESS)\n"
            "\t4) Sauvegarder l'Agenda en fichier texte (WORK IN PROGRESS)\n"
            "\t5) Afficher l'Agenda\n"
            "\n\t0) Quitter\n"
            "\nVeuillez indiquer votre choix en tapant le numéro associé sur votre clavier : "
            );

        scanf("%d",&answer);

        switch (answer)
        {
            case 1:
                initDiaryMain(&d);
                break;
            case 2:
                //Ajout d'une action dans l'Agenda
                break;
            case 3:
                //Supression d'une action de l'Agenda
                break;
            case 4:
                //Sauvegarde de l'Agenda
                break;
            case 5:
                //Affichage de l'Agenda
                displayWeeksList(d);
                break;
            case 0:
                printf("Fermeture du programme...\n");
                quit = 1;
                break;
            default:
                printf("Numéro incorrect veuillez ressaisir : ");
                scanf("%d",&answer);
                break;
        }
    }
}