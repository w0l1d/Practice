//
// Created by W0L1D on 12/5/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"



TFile* createTFile()
{
    TFile *tFile = (TFile*) malloc(sizeof(TFile));

    if (!tFile)
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }

    tFile->tete = tFile->queue = 0;
    tFile->taille = 0;

    return tFile;
}


TFile* init_TFile(TFile *tFile) {
if (tFile) // si la file existe
        free(tFile);
    tFile = createTFile();
    return tFile;
}

int get_tete_TFile(TFile *tfile)
{
    return tfile->tab[tfile->tete];
}

// queuele tFile sans pt
int Taille_TFile(TFile tFile) {
    return ((int)tFile.taille);
}

int vider_TFile(TFile *tFile)
{
    if (!tFile) return -1; //tFile n'existe pas

    tFile->tete = tFile->queue = 0;
    tFile->taille = 0;
    return 1;
}


int est_saturee_TFile(TFile tab) {
    return ((int)(MAX_ELEMS == Taille_TFile(tab)));
}

int est_vide_TFile(TFile tab) {
    return !(tab.taille);
}

void tasser_TFile(TFile *pTab, int pos) {

    int i;

    for (i = pos; i < Taille_TFile(*pTab); ++i) {
        pTab->tab[i] = pTab->tab[i + pTab->tete];
    }
    pTab->queue = pTab->queue - pTab->tete;
    pTab->tete = pos;
}



int enfiler_TFile(TFile *tFile, int val)
{
    //tFile n'exist pas
    if (!tFile)
        return -1;

    //TFile est saturee
    if (est_saturee_TFile(*tFile))
        return -2;

    if ((tFile->queue + 1) == MAX_ELEMS)
        tasser_TFile(tFile, 0);

    if (tFile->taille == 0)
        tFile->tab[tFile->tete = tFile->queue = 0] = val;
    else
        tFile->tab[++tFile->queue] = val;
    tFile->taille++;
    return 1;
}


int defiler_TFile(TFile *tFile)
{
    //tFile n'exist pas
    if (!tFile)
        return -1;

    //TFile est vide
    if (est_vide_TFile(*tFile))
        return 0;

    //file contient un seul element
    if (Taille_TFile(*tFile) == 1)
        tFile->tete = tFile->queue = 0;
    else
        tFile->tete++;
    tFile->taille--;
    return 1;
}



int enfiler_pos_TFile(TFile *file, int pos, int val) {
    if (!file)
        return ((int) -1);
    if (!file->taille)
        return ((int) 0);
    int val_defile,
            size = file->taille,
            cpt = 0,
            status = -4;

    if (pos == (size + 1)) {
        enfiler_TFile(file, val);
        return ((int) 1);
    }


    while ((cpt++) < size) {
        val_defile = get_tete_TFile(file);
        defiler_TFile(file);
        if (cpt == pos) {
            status = 1;
            enfiler_TFile(file, val);
        }
        enfiler_TFile(file, val_defile);
    }
    return ((int) status);
}



int max_val_TFile(TFile *tFile, int *status)
{
    *status = 1;
    //File n'exist pas
    if (!tFile) {
        *status = -1;
        return -1;
    }
    //File est vide
    if (est_vide_TFile(*tFile)) {
        *status = 0;
        return 0;
    }

    int cpt = tFile->taille,
            max_file = get_tete_TFile(tFile),
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






int min_val_TFile(TFile *tFile, int *status)
{
    *status = 1;
    //File n'existe pas
    if (!tFile) {
        *status = -1;
        return -1;
    }

    //File est vide
    if (est_vide_TFile(*tFile)) {
        *status = 0;
        return 0;
    }

    int cpt = tFile->taille,
            min_file = get_tete_TFile(tFile),
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






//supprimer toutes les occurrences du val du file
int supp_val_occurs_TFile(TFile *file, int val) {
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
        val_defile = get_tete_TFile(file);
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
int supp_val_first_occur_TFile(TFile *file, int val) {
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
        val_defile = get_tete_TFile(file);
        defiler_TFile(file);
        if (val_defile != val)
            enfiler_TFile(file, val_defile);
        else {
            status = 1;
            break;
        }
    }
    while (cpt--) {
        val_defile = get_tete_TFile(file);
        defiler_TFile(file);
        enfiler_TFile(file, val_defile);
    }
    return ((int) status);
}



int supp_pos_TFile(TFile *file, int pos) {
    if (!file)
        return ((int) -1);
    if (!file->taille)
        return ((int) 0);

    int val_defile,
            size = file->taille,
            cpt = 0,
            status = -3; // valeur n'est pas trouve

    while ((cpt++) < size) {
        val_defile = get_tete_TFile(file);
        defiler_TFile(file);
        if (cpt != pos) {
            status = 1;
            enfiler_TFile(file, val_defile);
        }
    }
    return ((int) status);
}






void affiche_TFile(TFile *tFile)
{
    //file n'exist pas
    if (!tFile)
    {
        printf("\nFile n'est pas initialisee\n");
        return;
    }
    // file est vide
    if (est_vide_TFile(*tFile))
    {
        printf("\nla file est vide\n");
        return;
    }

    int cpt = tFile->taille,
            val_defile;

    printf("\nle elements de la File : \n");
    while (cpt--) {
        val_defile = get_tete_TFile(tFile);
        printf("%d\t", val_defile);
        defiler_TFile(tFile);
        enfiler_TFile(tFile, val_defile);
    }
    printf("\n");
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
