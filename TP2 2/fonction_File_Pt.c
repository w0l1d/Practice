
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "structures.h"





void *initialiser_PFile (PFile *f)
{
    f->tete=NULL; // on initialise la tete du PFile a NULL
    f->queue=NULL; // on initialise le queue du PFile a NULL
    f->taille=0; // on initialise la taille du PFile a 0

}


PFile* createPFile()
{
    PFile *pfile = (PFile*) malloc(sizeof(PFile));

    if (!pfile)
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }

    pfile = initialiser_PFile(pfile);
    return pfile;
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
PFile *enfiler_PFile (PFile *f, int val)
{
    Cellule *e=NULL; // declaration et initialiastion a NULL de l'Cellule a ajouter

    if (!PFile_existe(f)) // si la PFile n'existe pas on le cree
        f=(PFile *)malloc (sizeof (PFile));

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
    return (PFile *)f;
}
int *enfiler_PFile2 (PFile *f, int val)
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

PFile *defiler_PFile (PFile *f)
{
    Cellule *tmp; // pointeur de type Cellule vers l'Cellule a supprimer
    if (!PFile_existe(f))
        printf("PFile n'existe pas\n");
    if (PFile_vide(f))
        printf("PFile deja vide\n");

    // cas d'une seule Cellule
    if (f->tete==f->queue)
    {
        f=initialiser_PFile(f);
        return ((PFile *) f);
    }
        // cas de plusieurs Cellules
    else
    {
        tmp=f->tete; // on pointe sur le premier Cellule du file
        f->tete=f->tete->svt; // definition de la nouvelle tete du file
        free(tmp); // on supprimer le premier Cellule du file
        f->taille--; // decrimentation du taille du file
        return ((PFile *)f);
    }
}

int *defiler_PFile2 (PFile *f)
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

PFile* enfiler_pos_PFIle(PFile* file, int val, int pos, int *status)
{
    PFile *tmp = createPFile();

    int cmp = 1, val_defile;
    *status = -4;

    if (pos == file->taille+1)
    {
        *status = 1;
        return enfiler_PFile(file, val);
    }

    while (!PFile_vide(file))
    {
        val_defile = file->tete->val;

        file = defiler_PFile(file);

        if (pos == cmp)
        {
            *status = 1;
            tmp = enfiler_PFile(tmp, val);
        }
        tmp = enfiler_PFile(tmp, val_defile);
        cmp++;
    }

    return ((PFile*) tmp);
}

int enfiler_pos_PFIle2(PFile* file, int val, int pos)
{

    if (!file)
        return ((int) -1);
    int cmp = file->taille,
    val_defile,
    status = -4;

    if (pos == file->taille+1)
        return enfiler_PFile2(file, val);

    while (cmp)
    {
        val_defile = file->tete->val;

        file = defiler_PFile(file);

        if (pos == cmp)
        {
            status = 1;
            file = enfiler_PFile(file, val);
        }
        file = enfiler_PFile(file, val_defile);
        cmp--;
    }

    return ((int) status);
}


PFile* supprimer_val_occur_PFile(PFile *file, int val, int *status) {

    PFile *tmp = createPFile();
    int val_defile;

    *status = -2;

    while (!PFile_vide(file))
    {
        val_defile = file->tete->val;

        file = defiler_PFile(file);

        if (val_defile == val)
        {
            *status = 1;
            continue;
        }

        tmp = enfiler_PFile(tmp, val_defile);
    }

    return ((PFile*) tmp);
}



int supprimer_val_occur_PFile2(PFile *file, int val) {

    int val_defile,
    status = -2,
    cmp = file->taille;

    while (cmp)
    {
        cmp --;
        val_defile = file->tete->val;

        file = defiler_PFile(file);

        if (val_defile == val){
            file->taille--;
            continue;
        }
        file = enfiler_PFile(file, val_defile);
    }

    return ((int) 1);
}


PFile* max_val_PFile(PFile *file, int *max_val, int *status) {

    PFile *tmp = createPFile();
    int val_defile;

    *status = -2;

    *max_val = file->tete->val;

    while (!PFile_vide(file))
    {
        val_defile = file->tete->val;
        file = defiler_PFile(file);
        tmp = enfiler_PFile(tmp, val_defile);

        if (*max_val < val_defile)
            *max_val = val_defile;
    }

    return ((PFile*) tmp);
}


PFile* max_val_PFile2(PFile *file, int *max_val, int *status) {

    PFile *tmp = createPFile();
    int val_defile;

    *status = -2;

    *max_val = file->tete->val;

    while (!PFile_vide(file))
    {
        val_defile = file->tete->val;
        file = defiler_PFile(file);
        tmp = enfiler_PFile(tmp, val_defile);

        if (*max_val < val_defile)
            *max_val = val_defile;
    }

    return ((PFile*) tmp);
}


PFile* min_val_PFile(PFile *file, int *min_val, int *status) {

    PFile *tmp = createPFile();
    int val_defile;

    *status = -2;

    *min_val = file->tete->val;

    while (!PFile_vide(file))
    {
        val_defile = file->tete->val;
        file = defiler_PFile(file);
        tmp = enfiler_PFile(tmp, val_defile);

        if (*min_val > val_defile)
            *min_val = val_defile;
    }

    return ((PFile*) tmp);
}

void afficher_PFile (PFile *f)
{
    int i;
    Cellule *crt; // declaration de pointeur pour parcourir la file
    if (PFile_existe(f)==0)
        printf("PFile n'existe pas\n");
    if (PFile_vide(f)==1)
        printf("PFile deja vide\n");
    crt=f->tete; // on commance par le premier Cellule
    for(i=0;i<f->taille;++i)
    {
        printf("%d\t" ,crt->val);
        crt = crt->svt;
    }
    printf ("\n");
}


/**************************  START fonction menu_PFile_Pt *********************************************************/

int menu_PFile_Pt()
{
    PFile *pfile = createPFile();
    int choix, tmp, tmp2, *status;

    status = (int*) malloc(sizeof(int));

    do
    {
        //initialiser le choix
        choix = -1;
        printf("\n *****************************************************************************************************************\n "
               "\n 1  : Reinitialise/Vider la File \n"
               "\n 2  : Taille de la File \n"
               "\n 3  : Enfiler \n"
               "\n 4  : Defiler \n"
               "\n 5  : Affichage de la File \n"
               "\n 6  : Supprimer par valeur \n"
               "\n 7  : enfiler a une position donner \n"
               "\n 8  : Maximum de la file \n"
               "\n 9  : Minimum de la file \n"
               "\n 0  : retour vers menu principal \n"
               "\n **********************************************************************************************************************\n "
               "\n >>>>>  ");

        scanf("%d", &choix); getchar();

        switch(choix)
        {
            case 0: break;

            case 1:
                pfile = initialiser_PFile(pfile);
                printf ("\nInitialisation bien faite.\n");
                getch();
                break;
            case 2:
                printf("La taille de la pfile : %d", pfile->taille);
                getch();
                break;

            case 3:
                printf ("\ndonner l'entier a ajouter : ");
                scanf ("%d",&tmp); // lecture de l'Cellule a ajouter
                pfile=enfiler_PFile(pfile, tmp);
                getch();
                break;

            case 4:
                pfile= defiler_PFile(pfile);
                getch();
                break;

            case 5:
                afficher_PFile(pfile);
                getch();
                break;

            case 6:
                printf ("\nEntrer la valeur a supprimer : ");
                scanf ("%d",&tmp); // lecture de l'Cellule a ajouter

                pfile = supprimer_val_occur_PFile(pfile, tmp, status);
                if (!(*status-1)) // status == 1
                    printf("Suppression effectuer");
                else
                    printf("Valeur n'est pas trouve");
                getch();
                break;

            case 7:
                printf ("\nEntrer la valeur : ");
                scanf ("%d",&tmp); // lecture de l'Cellule a ajouter

                printf ("\nEntrer la position : ");
                scanf ("%d",&tmp2); // lecture de l'Cellule a ajouter
                pfile = enfiler_pos_PFIle(pfile, tmp, tmp2, status);
                if (!(*status+4))
                    printf("\nPosition est incorrect");
                else if (*status)
                    printf("\nEnfilement effectuer");
                else if (!(*status))
                    printf("\nLa file est vide");
//                else if (*status)
//                    printf("\nEnfilement effectuer");
                getch();
                break;

            case 8:
                pfile = max_val_PFile(pfile, &tmp, status);
                if (*status)
                    printf("\nle maximum de la file est %d ", tmp);
                else if (!(*status))
                    printf("\nLa file est vide");
                getch();
                break;

            case 9:
                pfile = min_val_PFile(pfile, &tmp, status);
                if (*status)
                    printf("\nle minimum de la file est %d ", tmp);
                else if (!(*status))
                    printf("\nLa file est vide");
                getch();
                break;



                default :   printf("\n\nErreur : Choix Invalide\n\n");
                getch();
        }

    }while(choix);
}
/**************************  END fonction menu_PFile_Pt *********************************************************/



/************************************************  END file AVEC pt *********************************************************/





