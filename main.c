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
    patternList p;

    char year[YEAR_SIZE]="";
    char name[ACTION_NAME_SIZE]="";
    int week =0;
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
                printf("____________________________________________________________________________\n"
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

                printf("Entrer l'année : ");
                scanf("%s",year);
                printf("\nEntrer la semaine :");
                scanf("%d", &week);
                printf("\nEntrer le jour : ");
                scanf("%d", &day);
                printf("\nEntrer l'heure : ");
                scanf("%d", &hour);
                printf("\nEnetrer le nom de l'action : ");
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
                printf("Entrer l'élément à supprimer: \n");
                printf("Entrer l'année : ");
                scanf("%s",year);
                printf("\nEntrer la semaine :");
                scanf("%d", &week);
                printf("\nEntrer le jour : ");
                scanf("%d", &day);
                printf("\nEntrer l'heure : ");
                scanf("%d", &hour);
                printf("\nEnetrer le nom de l'action: ");
                // ICI AUSSI
                //scanf("%s", name);
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
                printf("___________________________________________________________\n"
                        "4) Sauvegarde de l'Agenda en fichier texte. \n"
                        "\nVeuillez entrer une taille pour la liste : "
                );
                scanf("%d",&size);
                initPattern(&p,size);
                    printf("Initpattern ok\n");
                displayPattern(p,size);
                    printf("Display pattern ok \n");
                freePattern(&p);
                    printf("Free pattern ok\n");
                break;
            case 5:
                //Sauvegarde de l'Agenda
                printf("___________________________________________________________\n"
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
                
                displayWeeksList(d);
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