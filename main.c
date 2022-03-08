/*---------------------------------------------------------------*/
/* ***************** FICHIER PRINCIPAL (MAIN) ********************/
/* Fichier principal contenant la gestion du menu et des actions */
/* pour la gestion de l'Agenda et des actions.                   */
/*****************************************************************/
/*---------------------------------------------------------------*/

#include "diary.h"

//Programme principal
int main(int argc, char **argv){



    int quit = 0;
    int answer = -1;
    int size = 0;
    char filename[FILENAME_SIZE];
    Diary d = initDiary();
    patternList_t pl;
    initPattern(&pl);

    char year[YEAR_SIZE]="";
    char name[ACTION_NAME_SIZE]="";
    char week[WEEK_SIZE]="";
    char pattern[11] = "";
    int day = 0;
    int hour = 0;

    // printf("Entrer le nom de l'action : ");
    // fgets(name,ACTION_NAME_SIZE,stdin);
    // printf("%s",name);

    printf("\n#############################################################################\n"
            "# Bonjour et bienvenue sur votre système personnalisé de gestion d'Agenda ! #\n"
            "#############################################################################\n");

    while(!quit){

        printf("\nChoisissez ce que vous voulez faire :\n"
            "\n\t1) Initialiser l'Agenda à partir du fichier texte passé en argument\n"
            "\t2) Ajouter une action dans l'Agenda\n"
            "\t3) Supprimer une action de l'Agenda\n"
            "\t4) Obtenir la liste des jours avec actions contenant motif (WIP)\n"
            "\t5) Sauvegarder l'Agenda en fichier texte\n"
            "\t6) Afficher l'Agenda\n"
            "\n\t0) Quitter\n"
            "\nVeuillez indiquer votre choix en tapant le numéro associé sur votre clavier : "
            );

        scanf("%d",&answer);

        switch (answer)
        {
            case 1:
                //Initialisation de l'Agenda à partir d'un fichier .txt
                printf("_____________________________________________________________________________\n"
                        "1) Initialisation de l'Agenda à partir du fichier texte passé en Argument. \n"
                );
                if(argc != 00 && argv[1] != NULL){
                    initDiaryWithFile(&d,argv[1]);
                    displayWeeksList(d);
                }
                else{
                    printf("Impossible car aucun fichier n'a été renseigné.\n\n");
                }
                break;
            case 2:
                //Ajout d'une action dans l'Agenda
                printf("_____________________________________________________________________________\n"
                        "2) Ajout d'une action dans l'Agenda. \n"
                );
                printf("Entrer l'année : ");
                scanf("%s",year);
                printf("\nEntrer la semaine :");
                scanf("%s", week);
                printf("\nEntrer le jour : ");
                scanf("%d", &day);
                printf("\nEntrer l'heure : ");
                scanf("%d%*c", &hour);
                printf("\nEntrer le nom de l'action : ");
                // Utilisation du fgets ??
                fgets(name,ACTION_NAME_SIZE,stdin);
                printf("\n");
                if (addWeek(&d,year,week,day,hour,name)){
                    displayWeeksList(d);
                }
                else {
                    printf("Il y a déjà un élément à cette date.\n");
                    displayWeeksList(d);
                }
                break;
            case 3:
                //Supression d'une action de l'Agenda
                printf("_____________________________________________________________________________\n"
                        "3) Suppression d'une action dans l'Agenda. \n"
                );
                printf("Entrer l'élément à supprimer: \n");
                printf("Entrer l'année : ");
                scanf("%s",year);
                printf("\nEntrer la semaine :");
                scanf("%s", week);
                printf("\nEntrer le jour : ");
                scanf("%d", &day);
                printf("\nEntrer l'heure : ");
                scanf("%d%*c", &hour);
                printf("\nEntrer le nom de l'action: ");
                fgets(name,ACTION_NAME_SIZE,stdin);
                printf("\n");

                if (supprWeek(&d,year,week,day,hour,name)){
                    printf("L'élément a bien été supprimé.\n");
                    displayWeeksList(d);
                }
                else {
                    printf("L'élément n'existe pas\n");
                    displayWeeksList(d);
                }
                break;
            case 4:
                //Sous liste des jours avec actions contenant motifs
                printf("_____________________________________________________________________________\n"
                        "4) Rechercher un motif d'action dans l'agenda. \n"
                        "\nVeuillez entrer le motif à rechercher : "
                );
                fflush(stdin);
                fgets(pattern,11, stdin);
                printf("%s\n",pattern);
                //removeBackSlashN(pattern);
                initPattern(&pl);
                    printf("Initpattern ok\n");

                findPattern(d,&pl,pattern);
                    printf("find patern OK\n");
                displayPattern(pl);
                    printf("Display pattern ok \n");
                freePattern(&pl);
                    printf("Free pattern ok\n");
                break;
            case 5:
                //Sauvegarde de l'Agenda
                printf("_____________________________________________________________________________\n"
                        "5) Sauvegarde de l'Agenda en fichier texte. \n"
                        "\nVeuillez enter le nom du fichier pour la sauvegarde : "
                );
                scanf("%s",filename);
                printf("%s",filename);

                
                // d = initDiary();

                // insertFirstWeek(&d,"2022",1);
                // addAction(&d->actionsList, 5, atoi("08"),"Espagnol");
                // addAction(&d->actionsList, 1, atoi("08"),"BDD");
                // addAction(&d->actionsList, 5, atoi("10"),"Anglais");
                // addAction(&d->actionsList, 6, atoi("12"),"Manger");

                // displayWeeksList(d);
                // printf("insertions OK\n");
                
                //displayWeeksList(d);
                // printf("Affichage OK\n");
                saveDiary(d,filename);

                break;
            case 6:
                //Affichage de l'Agenda
                if(d){
                    displayWeeksList(d);
                }
                else{
                    printf("--> L'agenda est vide.\n");
                }
                break;
            case 0:
                //Fermeture du programme
                printf("--> Fermeture du programme...\n");
                quit = 1;
                freeDiary(d);
                break;
            default:
                //Traitement d'un numéro incorrect
                printf("--> Numéro incorrect veuillez ressaisir.\n");
                fflush(stdin);
                break;
        }
    }

}