
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
        f->queue->suivant=e; // definition du nouveau tete
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
        f->tete=f->tete->suivant; // definition de la nouvelle tete du file
        free(tmp); // on supprimer le premier Cellule du file
        f->taille--; // decrimentation du taille du file
    }
    return ((int) 1);
}


int enfiler_pos_PFIle(PFile* file, int val, int pos)
{

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

    if (!file)
        return ((int) -1);
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


    if (!file)
        return ((int) -1);

    if (PFile_vide(file))
        return ((int) 0);

    int val_defile,
            cmp = file->taille;

    *max_val = file->tete->val;

    while (cmp)
    {
        val_defile = file->tete->val;
        defiler_PFile(file);
        enfiler_PFile(file, val_defile);

        if (*max_val < val_defile)
            *max_val = val_defile;
        cmp --;
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

    while (cmp)
    {
        val_defile = file->tete->val;
        enfiler_PFile(file, val_defile);
        defiler_PFile(file);

        if (*min_val > val_defile)
            *min_val = val_defile;
        cmp --;
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

    for(;cmp;)
    {
        printf("%d\t" , f->tete->val);
        enfiler_PFile(f, f->tete->val);
        defiler_PFile(f);
        cmp --;
    }
    printf ("\n");
}


/**************************  START fonction menu_PFile_Pt *********************************************************/

int menu_PFile_Pt()
{
    PFile *pfile = initialiser_PFile();
    int choix, tmp, tmp2, status;

    do
    {
        fflush(stdin);
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
        fflush(stdin);
        switch(choix)
        {
            case 0: break;

            case 1:
                pfile = initialiser_PFile();
                printf ("\nInitialisation bien faite.\n");
                getch();
                break;
            case 2:
                printf("La taille de la pfile : %d", pfile->taille);
                getch();
                break;

            case 3:
                printf ("\ndonner l'entier a ajouter : ");
                // lecture de l'Cellule a ajouter
                scanf ("%d",&tmp);getchar();
                enfiler_PFile(pfile, tmp);
                getch();
                break;

            case 4:
                defiler_PFile(pfile);
                getch();
                break;

            case 5:
                afficher_PFile(pfile);
                getch();
                break;

            case 6:
                printf ("\nEntrer la valeur a supprimer : ");
                scanf ("%d",&tmp); // lecture de l'Cellule a ajouter

                status = supprimer_val_occur_PFile(pfile, tmp);
                if (!(status-1)) // status == 1
                    printf("\nSuppression effectuer\n");
                else if(status == -4)
                    printf("\nValeur n'est pas trouve\n");
                else if(!status)
                    printf("\nfile est vide\n");
                getch();
                break;

            case 7:
                printf ("\nEntrer la valeur : ");
                scanf ("%d",&tmp); // lecture de l'Cellule a ajouter

                printf ("\nEntrer la position : ");
                scanf ("%d",&tmp2); // lecture de l'Cellule a ajouter
                status = enfiler_pos_PFIle(pfile, tmp, tmp2);
                if (!(status+4))
                    printf("\nPosition est incorrect");
                else if (status)
                    printf("\nEnfilement effectuer");
                else if (!(status))
                    printf("\nLa file est vide");
//                else if (*status)
//                    printf("\nEnfilement effectuer");
                getch();
                break;

            case 8:
                status = max_val_PFile(pfile, &tmp);
                if (status)
                    printf("\nle maximum de la file est %d ", tmp);
                else if (!(status))
                    printf("\nLa file est vide");
                getch();
                break;

            case 9:
                status = min_val_PFile(pfile, &tmp);
                if (status)
                    printf("\nle minimum de la file est %d ", tmp);
                else if (!(status))
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





