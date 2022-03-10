---- TP1 SDD ----
Loup RUSAK
Mathilde WALCH
G2
-----------------

Explications :
--------------

- L'Agenda est géré par les fichiers diary.h et diary.c.
- L'Agenda délègue la gestion des listes d'actions par semaine aux fichiers actions.h et actions.c.
- La gestion de la liste contigue des jours avec motif est réalisée par les fichiers pattern.h et pattern.contigue.

- Le programme principal gère le menu utilisateur et les interactions avec les systèmes de gestion dans le fichier main.c

- Le fichier "diary.txt" est l'entrée de données pour le programme.


Fonctionnement :
----------------

Pour lancer le programme tapez "make" dans la ligne de commande.

Ce menu apparait :

                Choisissez ce que vous voulez faire :

                        1) Initialiser l'Agenda à partir du fichier texte passé en argument.
                        2) Ajouter une action dans l'Agenda.
                        3) Supprimer une action de l'Agenda.
                        4) Obtenir la liste des jours avec actions contenant motif.
                        5) Sauvegarder l'Agenda en fichier texte.
                        6) Afficher l'Agenda.

                        0) Quitter.

                Veuillez indiquer votre choix en tapant le numéro associé sur votre clavier : 

Indiquez donc votre choix dans la ligne de commande.

- L'option 1) utilise le fichier diary.txt et son contenu pour initialiser et remplir l'Agenda.
- L'option 2) ajoute une action dans l'Agenda en vous demandant sur la ligne de commande de rentrer les informations nécessaires.
- L'option 3) supprime une action dans l'Agenda en vous demandant sur la ligne de commande de rentrer les informations nécessaires.
- L'option 4) recherche un motif que vous rentrez dans la ligne de commande et fournie une liste contenant toutes les actions dont le nom contient ce motif.
- L'option 5) vous demande le nom d'un fichier de sortie et le programme sauvegardera l'Agenda courant sous le même format que le fichier d'entrée.
- L'option 6) Affiche l'Agenda courant sur la console sous cette forme :

                Agenda :
                    Année 2022 semaine 15 :
                        Jour 1 à 08h : TP de SDD
                        Jour 1 à 09h : TP de SVT



- Enfin, l'option 0) vous permet de quitter le programme proprement. (Attention la sauvegarde n'est cependant pas automatique)