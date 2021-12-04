//
// Created by W0L1D on 11/4/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_ELEMS 30

typedef struct FileTab
{
    int tab[MAX_ELEMS]; // les elements de la file
    int tete; //indique la tete de la file
    int queue; //indique le queue de la file
    int tail; //indique la taille de la file

} FileTab;


void tasser_FileTab(FileTab *pTab);


FileTab* createTFile()
{
    FileTab *tFile = (FileTab*) malloc(sizeof(FileTab));

    if (!tFile)
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }

    tFile->tete = tFile->queue = 0;
    tFile->tail = 0;

    return tFile;
}

FileTab* init_TFile(FileTab *tFile)
{
    if (tFile) // si la file existe
        free(tFile);
    tFile = createTFile();
    return tFile;
}

int get_tete(FileTab *tfile)
{

    return tfile->tab[tfile->tete];
}

// queuele tFile sans pt
int Taille_TFile(FileTab tFile) { return ((int)tFile.tail); }

int vider_tFile(FileTab *tFile)
{
    if (!tFile) return -1; //tFile n'existe pas

    tFile->tete = tFile->queue = 0;
    tFile->tail = 0;
    return 1;
}


int est_saturee_FileTab(FileTab tab) {
    return ((int)(MAX_ELEMS == Taille_TFile(tab)));
}

int est_vide_FileTab(FileTab tab) {
    return !(tab.tail);
}

void tasser_FileTab(FileTab *pTab) {

    int i;

    for (i = 0; i < Taille_TFile(*pTab); ++i) {
        pTab->tab[i] = pTab->tab[i + pTab->tete];
    }
    pTab->queue = pTab->queue - pTab->tete;
    pTab->tete = 0;
}



int enfiler_TFile(FileTab *tFile, int val)
{
    //tFile n'exist pas
    if (!tFile)
        return -1;

    //TFile est saturee
    if (est_saturee_FileTab(*tFile))
        return -2;

    if ((tFile->queue + 1) == MAX_ELEMS)
        tasser_FileTab(tFile);

    if (tFile->tail == 0)
        tFile->tab[tFile->tete = tFile->queue = 0] = val;
    else
        tFile->tab[++tFile->queue] = val;
    tFile->tail++;
    return 1;
}


int defiler_TFile(FileTab *tFile)
{
    //tFile n'exist pas
    if (!tFile)
        return -1;

    //TFile est vide
    if (est_vide_FileTab(*tFile))
        return 0;

    //file contient un seul element
    if (Taille_TFile(*tFile) == 1)
        tFile->tete = tFile->queue = 0;
    else
        tFile->tete++;
    tFile->tail--;
    return 1;
}


int max_val_TFile(FileTab *tFile, int *status)
{
    *status = 1;
    //File n'exist pas
    if (!tFile) {
        *status = -1;
        return -1;
    }
    //File est vide
    if (est_vide_FileTab(*tFile)) {
        *status = 0;
        return 0;
    }

    int max_file = tFile->tab[tFile->tete];

    for (int i = tFile->tete; i < tFile->queue+1; ++i)
        if (max_file < tFile->tab[i])
        {
            *status = 1;
            max_file = tFile->tab[i];
        }

    return max_file;
}






int min_val_TFile(FileTab *tFile, int *status)
{
    *status = 1;
    //File n'exist pas
    if (!tFile) {
        *status = -1;
        return -1;
    }
    //File est vide
    if (est_vide_FileTab(*tFile)) {
        *status = 0;
        return 0;
    }

    int min_file = tFile->tab[tFile->tete];

    for (int i = tFile->tete; i < tFile->queue+1; ++i)
        if (min_file > tFile->tab[i])
        {
            *status = 1;
            min_file = tFile->tab[i];
        }

    return min_file;

}





int handle_errors_TFile(int cd)
{
    switch (cd) {

        case 1:
            return 1;
        case -1:
            printf("\nLa file n'existe pas\n");
            break;
        case -2:
            printf("\nLa file est saturee\n");
            break;

        case -3:
            printf("\nLa valeur n'est pas trouve\n");
            break;

        case -4:
            printf("\nLa position est incorrecte\n");
            break;

        case 0:
            printf("\nLa file est vide\n");
            break;

        default:
            printf("\n\nla valeur de status : %d \n\n", cd);
    }
    return 0;
}




void affiche_tFile(FileTab *tFile)
{
    //file n'exist pas
    if (!tFile)
    {
        printf("\nFile n'est pas initialisee\n");
        return;
    }
    // file est vide
    if (est_vide_FileTab(*tFile))
    {
        printf("\nla file est vide\n");
        return;
    }

    printf("\nle elements de la File : \n");
    for (int i = tFile->tete; i < tFile->queue+1; ++i)
        printf("%d\t", tFile->tab[i]);
    printf("\n");
}


int menu_TFile_Tab()
{
    FileTab *tFile = createTFile();
    int choix, *status, tmp;


    enfiler_TFile(tFile, 12);
    enfiler_TFile(tFile, 1);
    enfiler_TFile(tFile, 0);
    enfiler_TFile(tFile, 7);
    enfiler_TFile(tFile, 15);
    enfiler_TFile(tFile, 4);
    enfiler_TFile(tFile, 3);
    enfiler_TFile(tFile, 9);
    enfiler_TFile(tFile, 0);
    enfiler_TFile(tFile, 1);
    enfiler_TFile(tFile, 22);
    enfiler_TFile(tFile, 7);


    status = (int*) malloc(sizeof(int));
    do
    {
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
//               "\n 12 : supprimer la 1ER occurrence d'une valeur \n "
//               "\n 13 : supprimer l'element a une position \n "
//               "\n 14 : supprimer tout les occurrences d'un element \n "
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
                getch();
                break;
            case 2:
                printf("La taille de la tFile : %d", Taille_TFile(*tFile));
                getch();
                break;

            case 3:
                printf("\n\nEntrer la valeur : ");
                scanf("%d", &tmp);
                if (handle_errors_TFile(enfiler_TFile(tFile, tmp)))
                    printf("enfilage est effectué");
                getch();
                break;
            case 4:
                if (handle_errors_TFile(defiler_TFile(tFile)))
                    printf("defilage est effectué");
                getch();
                break;

            case 5:
                affiche_tFile(tFile);
                getch();
                break;

            case 6:

                tmp = max_val_TFile(tFile, status);
                if (handle_errors_TFile(*status))
                    printf("\nLe Maximum de la file est %d.\n", tmp);
                getch();
                break;
            case 7:

                tmp = min_val_TFile(tFile, status);
                if (handle_errors_TFile(*status))
                    printf("\nLe Minimum de la file est %d.\n", tmp);
                getch();
                break;


            default :   printf("\n\nErreur : Choix Invalide\n\n");

                getch();
        }

    }while(choix);
}


/************************************************  END LISTE AVEC TABLEAU *********************************************************/





