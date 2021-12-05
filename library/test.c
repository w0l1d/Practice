//
// Created by W0L1D on 12/5/2021.
//
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "fonctions_TFile.c"


int menu_TFile_Tab()
{
    TFile *tFile = createTFile();
    int choix, *status, tmp, tmp2;

    status = (int*) malloc(sizeof(int));

    enfiler_TFile(tFile, 2);
    enfiler_TFile(tFile, 5);
    enfiler_TFile(tFile, 7);
    enfiler_TFile(tFile, 2);
    enfiler_TFile(tFile, 21);
    enfiler_TFile(tFile, 0);
    enfiler_TFile(tFile, 3);
    enfiler_TFile(tFile, 8);
    enfiler_TFile(tFile, 10);
    enfiler_TFile(tFile, 11);
    enfiler_TFile(tFile, 13);
    enfiler_TFile(tFile, 4);
    enfiler_TFile(tFile, 9);
    enfiler_TFile(tFile, 99);

    do {
        //initialiser le choix
        choix = -1;
        printf("\n *****************************************************************************************************************\n "
               "\n 1  : Reinitialiser/Vider la File \n"
               "\n 2  : Taille de la File \n"
               "\n 3  : Enfiler \n"
               "\n 4  : Defiler \n"
               "\n 5  : Affichage de la File \n"
               "\n 6  : Maximum de la file \n "
               "\n 7  : Minimum de la file \n "
               //               "\n 8  : Inverser la file \n "
               //               "\n 9  : Trouver la position d'element par valeur \n"
               //               "\n 10 : Trouver la valeur d'une position \n "
               //               "\n 11 : Nombre d'occurrence d'un element \n "
               "\n 11 : Enfiler position \n "
               "\n 12 : supprimer la 1ER occurrence d'une valeur \n "
               "\n 13 : supprimer l'element a une position \n "
               "\n 14 : supprimer tout les occurrences d'un element \n "
               "\n 15 : supprimer par position \n "
               "\n 0  : retour vers menu principal \n"
               "\n **********************************************************************************************************************\n "
               "\n >>>>>  ");

        scanf("%d", &choix); getchar();

        switch(choix)
        {
            case 0: break;

            case 1:
                tFile = init_TFile(tFile);
                printf("TFile bien Initialise");
                break;
            case 2:
                printf("La taille de la tFile : %d", Taille_TFile(*tFile));
                break;

            case 3:
                printf("\n\nEntrer la valeur : ");
                scanf("%d", &tmp);
                if (handle_errors_TFile(enfiler_TFile(tFile, tmp)))
                    printf("enfilage est effectué");
                break;
            case 4:
                if (handle_errors_TFile(defiler_TFile(tFile)))
                    printf("defilage est effectué");
                break;

            case 5:
                affiche_TFile(tFile);
                break;

            case 6:
                tmp = max_val_TFile(tFile, status);
                if (handle_errors_TFile(*status))
                    printf("\nLe Maximum de la file est %d.\n", tmp);
                break;
            case 7:

                tmp = min_val_TFile(tFile, status);
                if (handle_errors_TFile(*status))
                    printf("\nLe Minimum de la file est %d.\n", tmp);
                break;

            case 11:
                printf("\n\nEntrer la valeur a enfiler : ");
                scanf("%d", &tmp);
                printf("\n\nEntrer la position : ");
                scanf("%d", &tmp2);
                tmp2 = enfiler_pos_TFile(tFile, tmp2, tmp);
                if (handle_errors_TFile(tmp2))
                    printf("\n\nL'enfilement est bien effectuee\n\n");
                break;

            case 12:
                printf("\n\nEntrer la valeur a supprimer : ");
                scanf("%d", &tmp);
                tmp2 = supp_val_first_occur_TFile(tFile, tmp);
                if (handle_errors_TFile(tmp2))
                    printf("\n\nLa suppression est bien effectuee\n\n");
                break;

            case 13:
                printf("\n\nEntrer la position du valeur : ");
                scanf("%d", &tmp);
                tmp2 = supp_pos_TFile(tFile, tmp);
                if (handle_errors_TFile(tmp2))
                    printf("\n\nLa suppression est bien effectuee\n\n");
                break;

            case 14:
                printf("\n\nEntrer la valeur a supprimer : ");
                scanf("%d", &tmp);
                tmp2 = supp_val_occurs_TFile(tFile, tmp);
                if (handle_errors_TFile(tmp2))
                    printf("\n\nLa suppression est bien effectuee\n\n");
                break;

            case 15:
                printf("\n\nEntrer la position : ");
                scanf("%d", &tmp2);
                tmp2 = supp_pos_TFile(tFile, tmp2);
                if (handle_errors_TFile(tmp2))
                    printf("\n\nLa suppression est bien effectuee\n\n");
                break;

            default :   printf("\n\nErreur : Choix Invalide\n\n");

        }
        getch();

    }while(choix);
}


void main() {
   menu_TFile_Tab();
}
