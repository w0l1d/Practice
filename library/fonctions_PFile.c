//
// Created by W0L1D on 12/5/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"



PFile* createPFile()
{
    PFile *pfile = (PFile*) malloc(sizeof(PFile));

    if (!pfile)
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }
    return pfile;
}



PFile *initialiser_PFile ()
{
    PFile *f = createPFile();
    f->tete=NULL; // on initialise la tete du PFile a NULL
    f->queue=NULL; // on initialise le queue du PFile a NULL
    f->taille=0; // on initialise la taille du PFile a 0
    return ((PFile*) f);
}

int PFile_existe (PFile *f)
{
    // 1 existe
    // 0 n'existe pas
    if (!f)
        return 0;
    return 1;
}

int PFile_vide (PFile *f)
{
    // 1 PFile vide
    // 0 PFile non vide
    if ((f->tete==NULL)&&(f->queue==NULL))
        return 1;
    return 0;
}

int enfiler_PFile(PFile *f, int val)
{
    Cellule *e=NULL; // declaration et initialiastion a NULL de l'Cellule a ajouter

    if (!PFile_existe(f)) // si la PFile n'existe pas
        return ((int) -1);

    if (PFile_vide(f)) // si la PFile vide
    {
        e=(Cellule *)malloc(sizeof(Cellule)); // l'allocation du memeoire

        e->val = val;
        f->tete=e; // definition du nouveau tete
        f->queue=e; // definition du nouveau queue
        f->taille++; // l'incrementation du taille du file
    }
    else // si la PFile non vide
    {
        e=(Cellule *)malloc (sizeof(Cellule)); // l'allocation du memeoire

        e->val = val;
        f->queue->svt=e; // definition du nouveau tete
        f->queue=e;
        f->taille++; // l'incrementation du taille du file
    }
    return ((int) 1);
}

int defiler_PFile(PFile *f)
{
    Cellule *tmp; // pointeur de type Cellule vers l'Cellule a supprimer
    if (!PFile_existe(f)) //file n'existe pas
        return((int) -1);
    if (PFile_vide(f)) //file est vide
        return((int) 0);

    // cas d'une seule Cellule
    if (f->taille == 1)
    {
        tmp = f->tete;
        f->tete= f->queue = NULL;
        f->taille--;
        free(tmp);
    }
        // cas de plusieurs Cellules
    else
    {
        tmp=f->tete; // on pointe sur le premier Cellule du file
        f->tete=f->tete->svt; // definition de la nouvelle tete du file
        free(tmp); // on supprimer le premier Cellule du file
        f->taille--; // decrimentation du taille du file
    }
    return ((int) 1);
}


int enfiler_pos_PFIle(PFile* file, int val, int pos)
{
    //File est vide
    if (!file)
        return ((int) -1);
    int cmp = 1,
            size = file->taille,
            val_defile,
            status = -4;

    if (pos == file->taille+1)
        return enfiler_PFile(file, val);

    while (cmp++ <= size)
    {
        val_defile = file->tete->val;
        if (pos == cmp-1)
        {
            status = 1;
            enfiler_PFile(file, val);
        }
        enfiler_PFile(file, val_defile);
        defiler_PFile(file);
    }
    return ((int) status);
}




int supprimer_val_occur_PFile(PFile *file, int val) {

    //File n'existe pas
    if (!file)
        return ((int) -1);
    //File est vide
    if (!file->taille)
        return ((int) 0);


    int val_defile,
            cmp = file->taille,
            status = -4;

    while (cmp--)
    {

        val_defile = file->tete->val;

        defiler_PFile(file);

        if (val_defile != val)
            enfiler_PFile(file, val_defile);
        else
            status = 1;
    }

    return ((int) status);
}


int max_val_PFile(PFile *file, int *max_val) {
    //File n'existe pas
    if (!file)
        return ((int) -1);
    //File est vide
    if (PFile_vide(file))
        return ((int) 0);

    int val_defile,
            cmp = file->taille;

    *max_val = file->tete->val;

    while (cmp--)
    {
        val_defile = file->tete->val;
        defiler_PFile(file);
        enfiler_PFile(file, val_defile);

        if (*max_val < val_defile)
            *max_val = val_defile;
    }

    return ((int) 1);
}


int min_val_PFile(PFile *file, int *min_val) {


    if (!file)
        return ((int) -1);

    if (PFile_vide(file))
        return ((int) 0);

    int val_defile,
            cmp = file->taille;

    *min_val = file->tete->val;

    while (cmp--)
    {
        val_defile = file->tete->val;
        enfiler_PFile(file, val_defile);
        defiler_PFile(file);

        if (*min_val > val_defile)
            *min_val = val_defile;
    }

    return ((int) 1);
}



void afficher_PFile (PFile *f)
{
    if (!PFile_existe(f))
        printf("PFile n'existe pas\n");
    if (PFile_vide(f))
        printf("PFile est vide\n");

    int cmp = f->taille;

    for(;cmp--;)
    {
        printf("%d\t" , f->tete->val);
        enfiler_PFile(f, f->tete->val);
        defiler_PFile(f);
    }
    printf ("\n");
}


int supp_pos_PFile(PFile *f, int pos) {

    //File n'existe pas
    if (!f)
        return ((int) -1);
    //File est vide
    if (! f->taille)
        return ((int) 0);


    int val_defile,
            cmp1 = f->taille,
            cmp2=1;
    if(pos==1)
    { defiler_PFile( f);
        return ((int) 1);
    }
    if((pos<1)||(pos>f->taille))
    { printf("psition invalide");
        return ((int) -4);
    }
    else
    {
        while(cmp2<pos)
        { val_defile=f->tete->val;
            defiler_PFile( f);
            enfiler_PFile(f,val_defile);
            cmp2++;cmp1--;
        }
        defiler_PFile( f);
        cmp1--;
        while(cmp1)
        {val_defile=f->tete->val;
            defiler_PFile( f);
            enfiler_PFile(f,val_defile);
            cmp1--;
        }
        return ((int) 1);

    }
}

int supp_elem_PFile(PFile *f, int val)
{

    //File n'existe pas
    if (!f)
        return ((int) -1);
    //File est vide
    if (! f->taille)
        return ((int) 0);


    int val_defile,
            cmp1 = f->taille,
            cmp2=0;

    while(cmp1)
    {
        val_defile=f->tete->val;
        if(!cmp2)
            if(val_defile== val)
            {defiler_PFile( f);
                cmp2=1;cmp1--;
                val_defile=f->tete->val;
            }
        defiler_PFile( f);
        enfiler_PFile(f,val_defile);
        cmp1--;
    }
    if(!cmp2) return((int)-3);

    return ((int) 1);
}