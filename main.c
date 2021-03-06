/*---------------------------------------------------------------*/
/* ***************** FICHIER PRINCIPAL (MAIN) ********************/
/* Fichier principal contenant la gestion du menu et des actions */
/* pour la gestion de l'Agenda et des actions.                   */
/*****************************************************************/
/*---------------------------------------------------------------*/

#include "diary.h"

//Programme principal
int main(int argc, char **argv){

    //Variables de menu
    int quit = 0;
    int answer = -1;
    
    //Listes nécessaires à l'éxecution du programe
    Diary d = initDiary();
    patternList_t *pl;

    //Elements constituant les éléments des listes
    char year[YEAR_SIZE]="";
    char name[ACTION_NAME_SIZE]="";
    char week[WEEK_SIZE]="";
    int day = 0;
    int hour = 0;

    //Elements à rentrer par l'utilisateur
    char pattern[11] = "";
    char filename[FILENAME_SIZE];

    //Message de bienvenue
    printf("\n#############################################################################\n"
            "# Bonjour et bienvenue sur votre système personnalisé de gestion d'Agenda ! #\n"
            "#############################################################################\n");

    //Gestion du menu
    while(!quit){

        printf("\nChoisissez ce que vous voulez faire :\n"
            "\n\t1) Initialiser l'Agenda à partir du fichier texte passé en argument.\n"
            "\t2) Ajouter une action dans l'Agenda.\n"
            "\t3) Supprimer une action de l'Agenda.\n"
            "\t4) Obtenir la liste des jours avec actions contenant motif.\n"
            "\t5) Sauvegarder l'Agenda en fichier texte.\n"
            "\t6) Afficher l'Agenda.\n"
            "\n\t0) Quitter.\n"
            "\nVeuillez indiquer votre choix en tapant le numéro associé sur votre clavier : "
            );

        //Lecture de la réponse de l'utilisateur
        scanf("%d%*c",&answer);

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
                    printf("--> Initialisation impossible car aucun fichier n'a été renseigné.\n\n");
                }
                break;
            case 2:
                //Ajout d'une action dans l'Agenda
                printf("_____________________________________________________________________________\n"
                        "2) Ajout d'une action dans l'Agenda. \n"
                );
                scanWeek(FALSE,year, week, &day, &hour, name);
                printf("\n");
                if (!addWeek(&d,year,week,day,hour,name)){
                    printf("--> Il y a déjà un élément à cette date.\n");
                }
                displayWeeksList(d);
                break;
            case 3:
                //Supression d'une action de l'Agenda
                printf("_____________________________________________________________________________\n"
                        "3) Suppression d'une action dans l'Agenda. \n"
                        "\nVeuillez entrer l'élément à supprimer : \n"
                );
                scanWeek(TRUE, year, week, &day, &hour, name);
                printf("\n");
                if (supprWeek(&d,year,week,day,hour)){
                    printf("--> L'élément a bien été supprimé.\n");
                }
                else {
                    printf("--> L'élément n'existe pas\n");
                }
                displayWeeksList(d);
                break;
            case 4:
                //Sous liste des jours avec actions contenant motifs
                printf("_____________________________________________________________________________\n"
                        "4) Rechercher un motif d'action dans l'agenda. \n"
                        "\nVeuillez entrer le motif à rechercher : "
                );
                pl = initPattern();
                fgets(pattern,11, stdin);
                removeBackSlashN(pattern);
                findPattern(d,pl,pattern);
                displayPattern(*pl);
                freePattern(pl);
                break;
            case 5:
                //Sauvegarde de l'Agenda
                printf("_____________________________________________________________________________\n"
                        "5) Sauvegarde de l'Agenda en fichier texte. \n"
                        "\nVeuillez enter le nom du fichier pour la sauvegarde : "
                );
                scanf("%s%*c",filename);
                if(saveDiary(d,filename)){
                    printf("--> Sauvegarde réussie.\n");
                }
                else{
                    printf("--> Erreur, impossible de sauvegarder.\n");
                }
                break;
            case 6:
                //Affichage de l'Agenda
                displayWeeksList(d);
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