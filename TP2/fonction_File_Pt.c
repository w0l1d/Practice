//
// Created by W0L1D on 11/4/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct Cellule
{
    int val;
    struct Cellule *suivant;
}Cellule;

typedef struct PFile
{
    struct Cellule *tete;
    struct Cellule *queue;
    int taille;
}PFile;


PFile *initialiser_PFile (PFile *f)
{
    f->tete=NULL; // on initialise la tete du PFile a NULL
    f->queue=NULL; // on initialise le queue du PFile a NULL
    f->taille=0; // on initialise la taille du PFile a 0
    return (PFile *)f;
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
PFile *enfiler_PFIle (PFile *f)
{
    Cellule *e=NULL; // declaration et initialiastion a NULL de l'Cellule a ajouter
    if (PFile_existe(f)==0) // si la PFile n'existe pas on le cree
        f=(PFile *)malloc (sizeof (PFile));
    if (PFile_vide(f)==1) // si la PFile vide
    {
        e=(Cellule *)malloc (sizeof(Cellule)); // l'allocation du memeoire
        printf ("donner l'entier a ajouter : ");
        scanf ("%d",&e->val); // lecture de l'Cellule a ajouter
        f->tete=e; // definition du nouveau tete
        f->queue=e; // definition du nouveau queue
        f->taille++; // l'incrementation du taille du file
        return (PFile *)f;
    }
    else // si la PFile non vide
    {
        e=(Cellule *)malloc (sizeof(Cellule)); // l'allocation du memeoire
        printf ("donner l'entier a ajouter : ");
        scanf ("%d",&e->val); // lecture de l'Cellule a ajouter
        f->queue->suivant=e; // definition du nouveau tete
        f->queue=e;
        f->taille++; // l'incrementation du taille du file
        return (PFile *)f;
    }
}

PFile *defiler_PFIle (PFile *f)
{
    Cellule *tmp; // pointeur de type Cellule vers l'Cellule a supprimer
    if (PFile_existe(f)==0)
        printf("PFile n'existe pas\n");
    if (PFile_vide(f)==1)
        printf("PFile deja vide\n");

    // cas d'un seul Cellule
    if (f->tete==f->queue)
    {
        f=initialiser_PFile(f);
        return (PFile *)f;
    }
        // cas de plusieurs Cellules
    else
    {
        tmp=f->tete; // on pointe sur le premier Cellule du file
        f->tete=f->tete->suivant; // definition de la nouvelle tete du file
        free(tmp); // on supprimer le premier Cellule du file
        f->taille--; // decrimentation du taille du file
        return (PFile *)f;
    }
}


void afficher_PFile (PFile *f)
{
    Cellule *crt; // declaration de pointeur pour parcourir la file
    if (PFile_existe(f)==0)
        printf("PFile n'existe pas\n");
    if (PFile_vide(f)==1)
        printf("PFile deja vide\n");
    crt=f->tete; // on commance par le premier Cellule
    for(int i=0;i<f->taille;++i)
    {
        printf("%d\t" ,crt->val);
        crt = crt->suivant;
    }
    printf ("\n");
}


int menu_PFile_Pt()
{
    PFile *pfile = createPFile();
    int choix;
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

                pfile=enfiler_PFIle(pfile);
                getch();
                break;

            case 4:
                pfile= defiler_PFIle(pfile);
                getch();
                break;

            case 5:
                afficher_PFile(pfile);
                getch();
                break;



            default :   printf("\n\nErreur : Choix Invalide\n\n");

                getch();
        }

    }while(choix);
}


/************************************************  END LISTE AVEC TABLEAU *********************************************************/





