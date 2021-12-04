
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_ELEMS 30

typedef struct FileTab
{
    int tab[MAX_ELEMS]; // les elements de la file
    int tete; //indique la tete de la file
    int queue; //indique le queue de la file
    int taille; //indique la taille de la file

} FileTab;


void tasser_FileTab(FileTab *pTab, int pos);


FileTab* createTFile()
{
    FileTab *tFile = (FileTab*) malloc(sizeof(FileTab));

    if (!tFile)
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }

    tFile->tete = tFile->queue = 0;
    tFile->taille = 0;

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
int Taille_TFile(FileTab tFile) {
    return ((int)tFile.taille);
}

int vider_tFile(FileTab *tFile)
{
    if (!tFile) return -1; //tFile n'existe pas

    tFile->tete = tFile->queue = 0;
    tFile->taille = 0;
    return 1;
}


int est_saturee_FileTab(FileTab tab) {
    return ((int)(MAX_ELEMS == Taille_TFile(tab)));
}

int est_vide_FileTab(FileTab tab) {
    return !(tab.taille);
}

void tasser_FileTab(FileTab *pTab, int pos) {

    int i;

    for (i = pos; i < Taille_TFile(*pTab); ++i) {
        pTab->tab[i] = pTab->tab[i + pTab->tete];
    }
    pTab->queue = pTab->queue - pTab->tete;
    pTab->tete = pos;
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
        tasser_FileTab(tFile, 0);

    if (tFile->taille == 0)
        tFile->tab[tFile->tete = tFile->queue = 0] = val;
    else
        tFile->tab[++tFile->queue] = val;
    tFile->taille++;
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
    tFile->taille--;
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

    int cpt = tFile->taille,
        max_file = get_tete(tFile),
        val_defile;

    while (cpt--) {
        val_defile = tFile->tab[tFile->tete];
        if (max_file < val_defile)
            max_file = val_defile;
        defiler_TFile(tFile);
        enfiler_TFile(tFile, val_defile);
    }

    return ((int) max_file);
}






int min_val_TFile(FileTab *tFile, int *status)
{
    *status = 1;
    //File n'existe pas
    if (!tFile) {
        *status = -1;
        return -1;
    }

    //File est vide
    if (est_vide_FileTab(*tFile)) {
        *status = 0;
        return 0;
    }

    int cpt = tFile->taille,
        min_file = get_tete(tFile),
        val_defile;

    while (cpt--) {
        val_defile = tFile->tab[tFile->tete];
        if (min_file > val_defile)
            min_file = val_defile;
        defiler_TFile(tFile);
        enfiler_TFile(tFile, val_defile);
    }

    return ((int) min_file);

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
            printf("\n\nErreur %d :: \n\n", cd);
    }
    return 0;
}

//supprimer toutes les occurrences du val du file
int supp_TFile_val_occurs(FileTab *file, int val) {
    //File n'existe pas
    if (!file)
        return ((int) -1);
    //File est vide
    if (!file->taille)
        return ((int) 0);

    int status = -3,
            val_defile,
            cpt = file->taille;

    while (cpt--) {
        val_defile = get_tete(file);
        defiler_TFile(file);
        if (val_defile != val)
        {
            enfiler_TFile(file, val_defile);
            status = 1;
        }
    }
    return ((int) status);
}

//supprimer toutes les occurrences du val du file
int supp_TFile_val_first_occur(FileTab *file, int val) {
    //File n'existe pas
    if (!file)
        return ((int) -1);
    //File est vide
    if (!file->taille)
        return ((int) 0);

    int status = -3,
            val_defile,
            cpt = file->taille;

    while (cpt--) {
        val_defile = get_tete(file);
        defiler_TFile(file);
        if (val_defile != val)
            enfiler_TFile(file, val_defile);
        else {
            status = 1;
            break;
        }
    }
    while (cpt--) {
        val_defile = get_tete(file);
        defiler_TFile(file);
        enfiler_TFile(file, val_defile);
    }
    return ((int) status);
}


int inserer_TFile_pos(FileTab *file, int pos, int val) {
    if (!file)
        return ((int) -1);
    if (!file->taille)
        return ((int) 0);

    int val_defile,
            size = file->taille,
            cpt = 0,
            status = -4;

    while ((cpt++) <= size) {
        val_defile = get_tete(file);
        defiler_TFile(file);
        if (cpt == pos) {
            status = 1;
            enfiler_TFile(file, val);
        }
        enfiler_TFile(file, val_defile);
    }
    return ((int) status);
}



int supp_TFile_pos(FileTab *file, int pos) {
    if (!file)
        return ((int) -1);
    if (!file->taille)
        return ((int) 0);

    int val_defile,
            size = file->taille,
            cpt = 0,
            status = -3; // valeur n'est pas trouve

    while ((cpt++) <= size) {
        val_defile = get_tete(file);
        defiler_TFile(file);
        if (cpt != pos) {
            status = 1;
            enfiler_TFile(file, val_defile);
        }
    }
    return ((int) status);
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

    int cpt = tFile->taille,
        val_defile;

    printf("\nle elements de la File : \n");
    while (cpt--) {
        val_defile = get_tete(tFile);
        printf("%d\t", val_defile);
        defiler_TFile(tFile);
        enfiler_TFile(tFile, val_defile);
    }
    printf("\n");
}

int handle_errors(int cd) {
    switch(cd) {

        case 1:
            return 1;
        case 0:
            printf("\nFile est vide\n");
            break;
        case -1:
            printf("\nFile n'existe pas\n");
            break;
        case -2:
            printf("\nFile n'existe pas\n");
            break;
        case -3:
            printf("\nvaleur n'est pas trouve\n");
            break;
        case -4:
            printf("\nposition est incorrect.\n");
            break;
        default:
            printf("\nErreur!!!\n");
    }
    return ((int) 0);
}




int menu_TFile_Tab()
{
    FileTab *tFile = createTFile();
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
               "\n 12 : supprimer la 1ER occurrence d'une valeur \n "
               "\n 13 : supprimer l'element a une position \n "
               "\n 14 : supprimer tout les occurrences d'un element \n "
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
                affiche_tFile(tFile);
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

            case 12:
                printf("\n\nEntrer la valeur a supprimer : ");
                scanf("%d", &tmp);
                tmp2 = supp_TFile_val_first_occur(tFile, tmp);
                if (handle_errors_TFile(tmp2))
                    printf("\n\nLa suppression est bien effectuee\n\n");
                break;

            case 13:
                printf("\n\nEntrer la position du valeur : ");
                scanf("%d", &tmp);
                tmp2 = supp_TFile_pos(tFile, tmp);
                if (handle_errors_TFile(tmp2))
                    printf("\n\nLa suppression est bien effectuee\n\n");
                break;

            case 14:
                printf("\n\nEntrer la valeur a supprimer : ");
                scanf("%d", &tmp);
                tmp2 = supp_TFile_val_occurs(tFile, tmp);
                if (handle_errors_TFile(tmp2))
                    printf("\n\nLa suppression est bien effectuee\n\n");
                break;


            default :   printf("\n\nErreur : Choix Invalide\n\n");

        }
        getch();

    }while(choix);
}


/************************************************  END file AVEC TABLEAU *********************************************************/





