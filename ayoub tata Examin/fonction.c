
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100
typedef struct tab
{
    int Tab[MAX_ELEMENT]; //un tableau de taile MAxElement
    int nbElement;        //nombre des element
} Maliste;
typedef struct cel
{
    int Val;
    struct cel *suiv;
} Cellule, PPile;
typedef struct
{
    int Tab[MAX_ELEMENT];
    int debut; //indice de la tete
    int fin;   //indice de la fin de la file
} TFile;

typedef struct
{
    Cellule *tete;
    Cellule *Queue;
} PFile;
/**********************************************************************
 Le nom de la fonction :Cree_PPile;
 Entrees : int val:la valeur du nombre entier;
 Sorties:PPile *NElement: Renvoie  l'adresse memoire allouer de la cellule
  cree qui comprend une un nombre Entier comme valeur
 * ********************************************************************/
PPile *Cree_PPile(int val)
{
    PPile *NElement;
    NElement = (PPile *)malloc(sizeof(PPile));
    if (!NElement)
    {
        printf("Erreur");
        exit(0);
    }
    NElement->Val = val;
    NElement->suiv = NULL;
    //retourner l'adresse memoire allouer
    return ((PPile *)NElement);
}
/**********************************************************************
 Le nom de la fonction :Empiler_PPile ;
 Entrees : PPile *Mapile: adrese de la pile allouer
        int Elem:la valeur du nombre entier;
 Sorties: Renvoie  l'adresse memoire allouer de la pile avec linsertion de
  nouvelle element
 * ********************************************************************/
PPile *Empiler_PPile(PPile *Mapile, int Elem)
{
    PPile *NE=NULL;
    NE = (PPile *)Cree_PPile(Elem);
    if (!Mapile)
    {
        NE->suiv = NULL;
        return ((PPile *)NE);
    }
    NE->suiv = Mapile;
    return ((PPile *)NE);
}


/**********************************************************************
 Le nom de la fonction :Depiler_PPile ;
 Entrees : PPile *Mapile: adrese de la pile allouer
 Sorties: Renvoie  l'adresse memoire allouer de la pile avec la supression en tete 
 * ********************************************************************/


PPile* Depiler_PPile(PPile *pile)
{
    if (!pile) // si la pile n'exist pas
        return ((PPile*) NULL);

    PPile *tmp;
    //sauvegarder la valeur a depile
    tmp = pile;
    //detacher la valeur depile de la pile
    pile = pile->suiv;
    //liberer la mermoire alloue a la valeur depilee
    free(tmp);

    return ((PPile*) pile);
}



PPile *Inserer_PPile_pos(PPile *Mapile, int Elem, int pos)
{
    PPile *tmp = NULL;
    int indice = 1;

    //cas la liste n'existe pas
    if (!Mapile)
    {
        printf("\n la pile est null");
        //cas impossible
        return ((PPile *)NULL);
    }
    //cas en dehor de la liste
    if ((pos < 1) || (pos > (Taile_PPile(Mapile) + 1)))
        return ((PPile *)Mapile);

    while (indice < pos)
    {
        tmp = Empiler_PPile(tmp, Mapile->Val);
        
        Mapile = Depiler_PPile(Mapile);
       
        indice++;
    }
    tmp = Empiler_PPile(tmp, Elem);
    //reordonner la pile initial
    while (tmp)
    {
        Mapile = Empiler_PPile(Mapile, tmp->Val);
        tmp = Depiler_PPile(tmp);
    }

    return ((PPile *)Mapile);
}
PPile *Supprimer_PPile_pos(PPile *Mapile, int pos)
{
    PPile *tmp = NULL;
    int indice = 1;

    //cas la liste n'existe pas
    if (!Mapile)
    {
        //cas impossible
        return ((PPile *)NULL);
    }
    //cas en dehor de la liste
    if ((pos < 1) || (pos > (Taile_PPile(Mapile) + 1)))
        return ((PPile *)Mapile);

    while (indice < pos)
    {
        tmp = Empiler_PPile(tmp, Mapile->Val);
        Mapile = Depiler_PPile(Mapile);
        indice++;
    }
    Mapile = Depiler_PPile(Mapile);

    //reordonner la pile initial
    while (tmp)
    {
        Mapile = Empiler_PPile(Mapile, tmp->Val);
        tmp = Depiler_PPile(tmp);
    }

    return ((PPile *)Mapile);
}

PPile *Supprimer_PPile_val(PPile *Mapile, int val)
{
    PPile *tmp = NULL;

    //cas la liste n'existe pas
    if (!Mapile)
    {
        //cas impossible
        return ((PPile *)NULL);
    }

    while (Mapile)
    {
        if (Mapile->Val != val)
            tmp = Empiler_PPile(tmp, Mapile->Val);
        Mapile = Depiler_PPile(Mapile);
    }

    //reordonner la pile initial
    while (tmp)
    {
        Mapile = Empiler_PPile(Mapile, tmp->Val);
        tmp = Depiler_PPile(tmp);
    }

    return ((PPile *)Mapile);
}
PPile *Supprimer_PPile_val_ord(PPile *Mapile, int val)
{
    PPile *tmp = NULL;

    //cas la liste n'existe pas
    if (!Mapile)
    {
        //cas impossible
        return ((PPile *)NULL);
    }

    while (Mapile)
    {
        if (Mapile->Val < val)
        {
            tmp = Empiler_PPile(tmp, Mapile->Val);
            Mapile = Depiler_PPile(Mapile);
        }
        else if (Mapile->Val == val)
            Mapile = Depiler_PPile(Mapile);
        else
            break;
    }

    //reordonner la pile initial
    while (tmp)
    {
        Mapile = Empiler_PPile(Mapile, tmp->Val);
        tmp = Depiler_PPile(tmp);
    }

    return ((PPile *)Mapile);
}

int Max_PPile(PPile *Mapile)
{
    int Max = 0;
    PPile *tmp = NULL;
    if (!Mapile)
        return ((int)-1);
    Max = Mapile->Val;
    while (Mapile)
    {
        if (Max < Mapile->Val)
            Max = Mapile->Val;
        tmp = Empiler_PPile(tmp, Mapile->Val);
        Mapile = Depiler_PPile(Mapile);
    }

    //reordonner la pile initial
    while (tmp)
    {
        Mapile = Empiler_PPile(Mapile, tmp->Val);
        tmp = Depiler_PPile(tmp);
    }
    return ((int)Max);
}

int Min_PPile(PPile *Mapile)
{
    int Min = 0;
    PPile *tmp = NULL;
    if (!Mapile)
        return ((int)-1);
    Min = Mapile->Val;
    while (Mapile)
    {
        if (Min > Mapile->Val)
            Min = Mapile->Val;
        tmp = Empiler_PPile(tmp, Mapile->Val);
        Mapile = Depiler_PPile(Mapile);
    }

    //reordonner la pile initial
    while (tmp)
    {
        Mapile = Empiler_PPile(Mapile, tmp->Val);
        tmp = Depiler_PPile(tmp);
    }
    return ((int)Min);
}
// int Taile_PPile(PPile *Mapile)
// {
//     PPile *tmp=NULL;
//     int cmp=0;
//     if(!Mapile) return ((int) -1);
//     while (Mapile)
//     {
//         cmp++;
//         tmp = Empiler_PPile(tmp,Mapile->Val);
//         Mapile=Depiler_PPile(Mapile);

//     }
//     while (tmp)
//     {
//       Mapile = Empiler_PPile(Mapile,tmp->Val);
//       tmp=Depiler_PPile(tmp);
//     }

//     return((int )cmp);

//  }
int Taile_PPile(PPile *Pile)
{
    PPile *tmp;     // pile temporaire
    int indice = 0; // initialiser indice par 0
    if (!Pile)
        return ((int)0);         // 0 si la pile n'existe pas
    tmp = Cree_PPile(Pile->Val); // creation de la pile temporaire
    Pile = Depiler_PPile(Pile);  // depiler pile
    indice = 1;
    while (Pile) // tant qu'il existe des elements dans a pile
    {
        tmp = Empiler_PPile(tmp, Pile->Val); // empiler dans tmp
        Pile = Depiler_PPile(Pile);          // depiler
        indice++;                            // incrementer indice
    }
    while (tmp) // tant qu'il y a des elements dans tmp
    {
        Pile = Empiler_PPile(Pile, tmp->Val); // empiler dans pile
        tmp = Depiler_PPile(tmp);             // depiler tmp
    }
    return ((int)indice); // retourner la taille
}
/**********************************************************************
 Le nom de la fonction :Sommet_PPile ;
 Entrees : PPile Mapile: Contenue de la pile
 Sorties: Renvoie la valeur du sommet de la pile
 * ********************************************************************/
int Sommet_PPile(PPile Mapile)
{
    return ((int)Mapile.Val);
}
/**********************************************************************
 Le nom de la fonction :Affiche_PPile ;
 Entrees : PPile *Mapile: Contenu de la pile
 Sorties:void : affichage des element de la pile
 * ********************************************************************/
// void Affiche_PPile(PPile *Mapile)
// {
//     PPile *ptr;
//     ptr=NULL;
//     //affichage des elements de la pile
//     ptr=Mapile;
//     while (ptr != NULL)
//     {
//         printf("\n\t%d", ptr->Val);
//         ptr = ptr->suiv;
//     }
// }

/**********************************************************************
 Le nom de la fonction :Acceder_Pile ;
 Entrees : PPile *Mapile: adrese de la pile allouer
 Sorties:int : la valeur du sommet de la pile
 * ********************************************************************/
int Acceder_Pile(PPile *Mapile)
{
    return ((int)Mapile->Val);
}
/**********************************************************************
 Le nom de la fonction :Affiche_PPile ;
 Entrees : PPile *Mapile: adrese de la pile allouer
 Sorties:void : affichage des element de la pile
//  * ********************************************************************/
// void Afficher_Ppile(PPile *Mapile)
// {
//     printf("\n  ************ Affichage de la pile  ************ \n");
//     PPile *tmp;
//     tmp = NULL;
//     if (!Mapile)
//     {
//         printf("\nPile n'esxiste pas !");
//         exit(0);
//     }
//     printf("\n");
//     while (Mapile)
//     {

//         printf(" %d  ",
//                Acceder_Pile(Mapile));
//         tmp = Empiler_PPile(tmp, Mapile->Val);
//         Mapile = Depiler_PPile(Mapile);
//     }
//     while (tmp)
//     {
//         Mapile = Empiler_PPile(Mapile, tmp->Val);
//         tmp = Depiler_PPile(tmp);
//     }
//     printf("\n");
// }
// void Afficher_Ppile(PPile* Pile)
// { 
//          printf("\n  ************ Affichage de la pile  ************ \n");
//     PPile* tmp; // pile tmp
//     if(!Pile) // si la pile n'existe pas, message d'erreur et quitter
//     { 
//         printf("Pile n'esxiste pas !"); 
//         exit(0);
//     }
//     tmp = Cree_PPile(Pile->Val); // creation de tmp
//     printf(" %d ",Pile->Val);// affichage du premier elem 
//     Pile = Depiler_PPile(Pile); // depiler 
//     while (Pile) // tant qu'il existe des elements dans pile
//     {
//         printf(" %d  ",Pile->Val); // affichage 
//         tmp = Empiler_PPile(tmp,Pile->Val); // empilement dans tmp 
//         Pile = Depiler_PPile(Pile); // depilement 
//     }
//     // retourner les valeurs dans pile
//     while (tmp)
//     {
//         Pile = Empiler_PPile(Pile,tmp->Val);
//         tmp = Depiler_PPile(tmp);
//     }
//     printf("\n Fin d'affichage."); // fin d'affichage 
// }
void Afficher_Ppile(PPile *pile)
{
    //si la pile vide
    if (!pile)
    {
        printf("\nla liste est vide\n");
        
    }


    printf("\n ********** Affichage de la pile ************* \n");

    while (pile)
    {
        printf(" %d  ", pile->Val);
        pile = pile->suiv;
    }
    printf("\n");
}
// void Afficher_Ppile(PPile* Pile)
// {
//     PPile* tmp; // pile tmp
//     if(!Pile) // si la pile n'existe pas, message d'erreur et quitter
//     {
//         printf("Pile n'esxiste pas !");
//         exit(0);
//     }
//     tmp = Cree_PPile(Pile->Val); // creation de tmp
//     printf("\n %d \n",Pile->Val);// affichage du premier elem
//     Pile = Depiler_PPile(Pile); // depiler
//     while (Pile) // tant qu'il existe des elements dans pile
//     {
//         printf("\n %d \n",Pile->Val); // affichage
//         tmp = Empiler_PPile(tmp,Pile->Val); // empilement dans tmp
//         Pile = Depiler_PPile(Pile); // depilement
//     }
//     // retourner les valeurs dans pile
//     while (tmp)
//     {
//         Pile = Empiler_PPile(Pile,tmp->Val);
//         tmp = Depiler_PPile(tmp);
//     }
//     printf("\n Fin d'affichage."); // fin d'affichage
// }

/**********************************************************************
 Le nom de la fonction :Init_PFile;
 Entrees : PFile *Mafile:l'adresse de la file passer en parametre;
 Sorties: int status:Renvoie 0 en cas de mafile est ne contient pas d'adresse
         rencoie 1 en cas l intialisation de la tete et la queue et bien passer;
 * ********************************************************************/
int Init_PFile(PFile *Mafile)
{
    if (!Mafile)
        return ((int)0);
    Mafile->tete = Mafile->Queue = NULL;
    return ((int)1);
}
/**********************************************************************
 Le nom de la fonction :cree_Pfile;
 Sorties: PFile *Mafile:Adresse de la file alloué
  * ********************************************************************/
PFile *cree_Pfile()
{
    PFile *Mafile;
    Mafile = (PFile *)malloc(sizeof(PFile));
    if (!Mafile)
    {
        printf("\n Erreur de l allocation");
        exit(0);
    }
    Mafile->tete = Mafile->Queue = NULL;
    return ((PFile *)Mafile);
}
//Cree une nouvelle cellule

/**********************************************************************
 Le nom de la fonction :Cree_Cellule;
 Entrees : int val:la valeur du nombre entier;
 Sorties: Renvoie  l'adresse memoire allouer de la cellule cree qui comprend 
 une un nombre Entier comme valeur
 * ********************************************************************/
Cellule *Cree_Cellule(int val)
{
    Cellule *NElement;
    NElement = (Cellule *)malloc(sizeof(Cellule));
    if (!NElement)
    {
        printf("Erreur");
        exit(0);
    }
    NElement->Val = val;
    NElement->suiv = NULL;
    //retourner l'adresse memoire allouer
    return ((Cellule *)NElement);
}
/**********************************************************************
 Le nom de la fonction :Est_vide_PFile;
 Entrees : PFile Mafile:Contenue de la file;
 Sorties: Renvoie 1 si la file et vide en verifiant si la tete et la queue sont null 
            sinon renvoie 0;
  * ********************************************************************/
int Est_vide_PFile(PFile Mafile)
{
    if (Mafile.Queue == NULL && Mafile.tete == NULL)
        return ((int)1);
    return ((int)0);
}
/**********************************************************************
 Le nom de la fonction :Enfiler_PFile;
 Entrees : PFile *Mafile:l'adresse de la file passer en parametre;
          int val:la valeur du nombre entier;
 Sorties: Renvoie renvoyer l'adresse alloué de la file 
            on insérant le nouveau element dans la queue;
  * ********************************************************************/
PFile *Enfiler_PFile(PFile *Mafile, int Elem)
{
    Cellule *NE;
    if (!Mafile)
        return ((PFile *)NULL);
    //creer une nouvelle cellule
    NE = (Cellule *)Cree_Cellule(Elem);
    //si la file est vide
    if (Est_vide_PFile(*Mafile))
    {

        Mafile->tete = Mafile->Queue = NE;
        return ((PFile *)Mafile);
    }

    Mafile->Queue->suiv = NE;
    Mafile->Queue = NE;
    return ((PFile *)Mafile); //prev return ((int)1);
}
/**********************************************************************
 Le nom de la fonction :Defiler_PFile;
 Entrees : PFile *Mafile:l'adresse de la file passer en parametre;
 Sorties: int:Renvoie -1 si la n'existe pas
        renvoie 0 si la file vide
        renvoie 1 si le defilement est bien passer       
* ********************************************************************/
int Defiler_PFile(PFile *Mafile)
{
    Cellule *NE;
    if (!Mafile)
        return ((int)-1);

    //si la file est vide
    if (Est_vide_PFile(*Mafile))
        return ((int)0);
    if (Mafile->tete == Mafile->Queue)
    {
        free(Mafile->tete);
        Mafile->tete = Mafile->Queue = NULL;
    }
    else
    {
        NE = Mafile->tete;
        Mafile->tete = Mafile->tete->suiv;
        free(NE);
    }
    return ((int)1);
}
/**********************************************************************
 Le nom de la fonction :Afficher_PFile;
 Entrees : PFile *Mafile:l'adresse de la file passer en parametre;
 Sorties: void :Affficher les element de la tete de la file
 * ********************************************************************/
void Afficher_PFile(PFile *Mafile)
{

    PFile *tmp = cree_Pfile();
    int res = 0;
    if (!Mafile)
    {
        printf("\n La file n existe pas");
        exit(-1);
    }
    while (Mafile->tete)
    {
        printf("\n\t %d", Mafile->tete->Val);
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
    }
    //recuperer la file intial
    Mafile->tete = tmp->tete;
    Mafile->Queue = tmp->Queue;
}
int Taile_PFile(PFile *Mafile)
{
    int cmp = 0, res = 0;
    PFile *tmp = cree_Pfile();
    if (!Mafile)
        return ((int)-1);
    while (Mafile->tete)
    {
        cmp++;
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
    }

    //recuperer la file intial
    Mafile->tete = tmp->tete;
    Mafile->Queue = tmp->Queue;
    return ((int)cmp);
}
PFile *Inserer_PFile_pos(PFile *Mafile, int Elem, int pos)
{
    PFile *tmp = cree_Pfile();
    int indice = 1, res = 0;

    if (!Mafile)
        return ((PFile *)NULL);
    if (pos < 1 || (pos > (Taile_PFile(Mafile) + 1)))
        return ((PFile *)Mafile);
    while (indice < pos)
    {
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
        indice++;
    }
    tmp = Enfiler_PFile(tmp, Elem);

    //recuperer la liste initial
    while (Mafile->tete)
    {
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
    }

    return ((PFile *)tmp);
}
PFile *Supprimer_PFile_pos(PFile *Mafile, int pos)
{
    PFile *tmp = cree_Pfile();
    int indice = 1, res = 0;

    if (!Mafile)
        return ((PFile *)NULL);
    if (pos < 1 || (pos > (Taile_PFile(Mafile) + 1)))
        return ((PFile *)Mafile);
    while (indice < pos)
    {
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
        indice++;
    }
    res = Defiler_PFile(Mafile);

    //recuperer la liste initial
    while (Mafile->tete)
    {
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
    }

    return ((PFile *)tmp);
}
PFile *Supprimer_PFile_val(PFile *Mafile, int val)
{
    PFile *tmp = cree_Pfile();
    int res = 0;
    if (!Mafile)
        return ((PFile *)NULL);

    while (Mafile->tete)
    {
        if (Mafile->tete->Val != val)
        {
            tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
            res = Defiler_PFile(Mafile);
        }
        else
            res = Defiler_PFile(Mafile);
    }
    //recuperer la file intial
    Mafile->tete = tmp->tete;
    Mafile->Queue = tmp->Queue;
    return ((PFile *)Mafile);
}

PFile *Supprimer_PFile_val_ord(PFile *Mafile, int val)
{
    PFile *tmp = cree_Pfile();
    int indice = 1, res = 0;

    if (!Mafile)
        return ((PFile *)NULL);

    while (Mafile->tete)
    {
        if (Mafile->tete->Val < val)
        {
            tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
            res = Defiler_PFile(Mafile);
        }
        else if (Mafile->tete->Val == val)
            res = Defiler_PFile(Mafile);
        else
            break;
    }
    while (Mafile->tete)
    {
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
    }

    return ((PFile *)tmp);
}

int Max_PFile(PFile *Mafile)
{
    PFile *tmp = cree_Pfile();
    int Max = 0, res = 0;

    if (!Mafile)
        return ((int)Max);

    Max = Mafile->tete->Val;
    while (Mafile->tete)
    {
        if (Mafile->tete->Val > Max)
            Max = Mafile->tete->Val;
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
    }
    //recuperer la file intial
    Mafile->tete = tmp->tete;
    Mafile->Queue = tmp->Queue;

    return ((int *)Max);
}
int Min_PFile(PFile *Mafile)
{
    PFile *tmp = cree_Pfile();
    int Min = 0, res = 0;

    if (!Mafile)
        return ((int)Min);

    Min = Mafile->tete->Val;
    while (Mafile->tete)
    {
        if (Mafile->tete->Val < Min)
            Min = Mafile->tete->Val;
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
        res = Defiler_PFile(Mafile);
    }
    //recuperer la file intial
    Mafile->tete = tmp->tete;
    Mafile->Queue = tmp->Queue;

    return ((int)Min);
}
//taile de la liste
/**********************************************************************
 Le nom de la fonction :Taile_liste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier;
 Sorties: int ind:Renvoie la taile de la liste Renvoie 
 * ********************************************************************/
int Taile_liste(Cellule *pliste)
{
    int ind = 0;
    Cellule *ptmp;

    if (!pliste)
        return ((int)-1);
    ptmp = pliste;
    while ((ptmp))
    {
        ind++;
        ptmp = ptmp->suiv;
    }
    return ((int)ind);
}
/**********************************************************************
 Le nom de la fonction :Inserer_pos_pliste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier;
            int pos:la position d'ou l'insertion du nouvelle element
            int Elem:la valeur de l'element a inserer
 Sorties: Cellule *pliste:Renvoie la nouvelle liste avec l'insertion d'une nouvelle cellule
                        a la position donnée
 * ********************************************************************/
Cellule *Inserer_pos_pliste(Cellule *pliste, int pos, int Elem)
{
    Cellule *ptr, *NE;
    int cmp = 0;
    NE = (Cellule *)Cree_Cellule(Elem);
    if (pos == 1) //insertion a la tete de la liste
    {
        //cree cellule
        NE->suiv = pliste;
        return ((Cellule *)NE);
    }
    //cas la liste n'existe pas
    if (!pliste)
    {
        //cas impossible
        return ((Cellule *)NULL);
    }
    //cas en dehor de la liste

    if ((pos < 1) || (pos > (Taile_liste(pliste) + 1)))
        return ((Cellule *)pliste);
    cmp = 1;
    ptr = pliste;
    while (cmp < pos)
    {
        ptr = ptr->suiv;
        cmp++;
    }

    NE->suiv = ptr->suiv;
    ptr->suiv = NE;
    return ((Cellule *)pliste);
}
/**********************************************************************
 Le nom de la fonction :Supprimer_pos_pliste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier;
            int pos:la position de l'element a suprimmer

 Sorties: Cellule *pliste:Renvoie la nouvelle liste avec une suppression d'une cellule
                        a la position donnée
 * ********************************************************************/
Cellule *Supprimer_pos_pliste(Cellule *pliste, int pos)
{
    int cmp = 1;
    Cellule *ptr, *ptmp, *NE;
    //cas la liste n'existe pas
    if (!pliste)
    {
        //cas impossible
        return ((Cellule *)NULL);
    }
    //cas en dehor de la liste
    if ((pos < 1) || (pos > (Taile_liste(pliste) + 1)))
        return ((Cellule *)pliste);
    ptmp = pliste;
    if (pos == 1)
    {
        return ((Cellule *)pliste->suiv);
    }

    while (cmp < pos)
    {
        ptr = ptmp;
        ptmp = ptmp->suiv;
        cmp++;
    }
    NE = ptmp->suiv;
    ptr->suiv = NE;
    free(ptmp);
    return ((Cellule *)pliste);
}
/**********************************************************************
 Le nom de la fonction :Supprimer_tete_pliste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier;
 Sorties: Cellule *pliste:Renvoie la nouvelle liste avec une suppression d'une cellule
                        a la tete de la liste
 * ********************************************************************/
Cellule *Supprimer_tete_pliste(Cellule *pliste)
{
    Cellule *ptr;
    if (!pliste)
        return ((Cellule *)NULL);
    ptr = pliste;
    ptr = ptr->suiv;
    return ptr;
}
/**********************************************************************
 Le nom de la fonction :Supprimer_fin_pliste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier; 
 Sorties: Cellule *pliste:Renvoie la nouvelle liste avec une suppression d'une cellule
                        a la fin de la liste
 * ********************************************************************/
Cellule *Supprimer_fin_pliste(Cellule *pliste)
{
    Cellule *ptr, *ptmp;
    if (!pliste)
        return ((Cellule *)NULL);
    ptr = pliste;
    while (ptr->suiv != NULL)
    {
        ptmp = ptr;
        ptr = ptr->suiv;
    }
    ptmp->suiv = NULL;
    free(ptr);
    return pliste;
}
/**********************************************************************
 Le nom de la fonction :Inserer_tete_pliste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier;
            int Elem:la valeur de l'element a inserer
 Sorties: Cellule *pliste:Renvoie la nouvelle liste avec une insertion du nouvel element 
                        la tete de la liste
 * ********************************************************************/
Cellule *Inserer_tete_pliste(Cellule *pliste, int val)
{
    Cellule *ptr, *NE;

    if (!pliste)
        return ((Cellule *)NULL);
    ptr = pliste;
    NE = (Cellule *)Cree_Cellule(val);
    NE->suiv = ptr;
    return ((Cellule *)NE);
}
/**********************************************************************
 Le nom de la fonction :Inserer_fin_pliste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier;
            int val:la valeur de l'element a inserer
 Sorties: Cellule *pliste:Renvoie la nouvelle liste avec une insertion du nouvel element 
                        la fin de la liste
 * ********************************************************************/
Cellule *Inserer_fin_pliste(Cellule *pliste, int val)
{
    Cellule *ptr, *NE;

    NE = (Cellule *)Cree_Cellule(val);
    if (!pliste)
        return ((Cellule *)NE);
    ptr = pliste;
    while (ptr->suiv != NULL)
        ptr = ptr->suiv;
    ptr->suiv = NE;
    return ((Cellule *)pliste);
}
/**********************************************************************
 Le nom de la fonction :tasser_TFile;
 Entrees :TFile *Mafile:l'adresse de la file passer en parametre;
 Sorties: int :Renvoie 0  si la file n'existe pas 
                Renvoie 1 si le decalage des element est reussi
 * ********************************************************************/
int tasser_TFile(TFile *Mafile)
{
    int indice = 0;
    if (!Mafile)
        return ((int)0);

    for (indice = Mafile->debut; indice <= Mafile->fin; indice++)
        Mafile->Tab[indice - Mafile->debut] = Mafile->Tab[indice];
    Mafile->debut = 0;
    return ((int)1);
}
/**********************************************************************
 Le nom de la fonction :rechrche_Elem_pliste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier;
            int Elem:la valeur de l'element a rechercher
 Sorties: int indice:Renvoie la position de l'element a recherecher
 * ********************************************************************/
int rechrche_Elem_pliste(Cellule *pliste, int Elem)
{
    int indice = 1;
    Cellule *ptr;
    if (!pliste)
        //cas impossible
        return ((int)-1);
    ptr = pliste;
    while ((ptr->suiv != NULL) && (ptr->Val != Elem))
    {
        indice++;
        ptr = ptr->suiv;
    }
    if (ptr->Val == Elem)
        return ((int)indice);
    return ((int)-1);
}
/**********************************************************************
 Le nom de la fonction :Nbr_Occurence_Elem_pliste;
 Entrees : Cellule *pliste:liste des cellule qui comprend des nombre entier;
            int Elem:la valeur de l'element a rechercher
 Sorties: int cmp:Renvoie nombre des occurence de la valeur de l'element rechercher
 * ********************************************************************/
int Nbr_Occurence_Elem_pliste(Cellule *pliste, int Elem)
{
    int cmp = 0;
    Cellule *ptr;
    if (!pliste)
        //cas impossible
        return ((int)-1);
    ptr = pliste;
    while (ptr->suiv != NULL)
    {
        if (ptr->Val == Elem)
            cmp++;
        ptr = ptr->suiv;
    }
    if (ptr->Val == Elem)
        cmp++;
    return ((int)cmp);
}
/**********************************************************************
 Le nom de la fonction :Afficher_pliste;
 Entrees : Cellule *pliste:liste des element entier;
 Sorties: void :Affficher les element de la liste
 * ********************************************************************/
void Afficher_pliste(Cellule *pliste)
{
    printf("\n ************ Affichage une liste chainé  ************ \n");
    printf("\n");
    Cellule *ptr;
    if (!pliste)
    {
        printf("\n liste est vide");
        exit(-1);
    }
    ptr = pliste;
    while (ptr != NULL)
    {
        printf(" %d  ", ptr->Val);
        ptr = ptr->suiv;
    }
    printf("\n");
}
/**********************************************************************
 Le nom de la fonction :Inserer_Options_pliste;
 Entrees : Cellule *pliste:liste des element entier;
            int val:la valeur de nouvel element a inserer
            int pos:position de l'insertion
            int choix:choix d insertion a effectuer 1-en tete 2-en fin 3- a une position donner
 Sorties: Cellule *pliste:Renvoie une nouvelle liste avec un nouvaux element inserer
 * ********************************************************************/
Cellule *Inserer_Options_pliste(Cellule *pliste, int val, int pos, int choix)
{
    switch (choix)
    {
    case 1:
        pliste = Inserer_tete_pliste(pliste, val);
        break;
    case 2:
        pliste = Inserer_fin_pliste(pliste, val);
        break;
    case 3:
        pliste = Inserer_pos_pliste(pliste, pos, val);
        break;

    default:
        break;
    }
    return ((Cellule *)pliste);
}
Cellule *Supprimer_val_pliste(Cellule *Maliste, int val)
{
    int res = 0;
    int indice = 1;
    if (!Maliste)
        return ((Cellule *)NULL);

    Cellule *tmp = Maliste;
    while (tmp)
    {
        if (val == tmp->Val)
        {

            Maliste = Supprimer_pos_pliste(Maliste, indice);

            break;
        }
        indice++;
        tmp = tmp->suiv;
    }

    return ((Cellule *)Maliste);
}
/**********************************************************************
 Le nom de la fonction :Suprimer_Options;
 Entrees : Cellule *pliste:liste des element entier;
            int pos:position de l'insertion
            int choix:choix de suprission a effectuer 1-en tete 2-en fin 3- a une position donner
 Sorties: Cellule *pliste: Renvoie la nouvelle liste avec une suppression
             de l'un des elements de la liste
 * ********************************************************************/
Cellule *Suprimer_Options(Cellule *pliste, int choix, int pos, int val)
{
    switch (choix)
    {
    case 1:
        pliste = Supprimer_tete_pliste(pliste);
        break;
    case 2:
        pliste = Supprimer_fin_pliste(pliste);
        break;
    case 3:
        pliste = Supprimer_pos_pliste(pliste, pos);
        break;
    case 4:
        pliste = Supprimer_val_pliste(pliste, val);
        break;

    default:
        break;
    }
    return ((Cellule *)pliste);
}

//declaration de la structure

//Creation de la liste
/**********************************************************************
 Le nom de la fonction :Cree_Liste;
 Sorties: Renvoie l'adresse memoire allouer de la liste crée 
          on intialisant le nombre des element a 0
 * ********************************************************************/
Maliste *Cree_Liste()
{
    Maliste *pt;
    pt = (Maliste *)malloc(sizeof(Maliste));
    if (!pt)
    {
        printf("Erreur");
        exit(0);
    }
    pt->nbElement = 0;
    return ((Maliste *)pt);
}

//taile d'une liste
/**********************************************************************
 Le nom de la fonction :Taile_liste;
 Entrees : Maliste liste:le contenu de la liste des elements
 Sorties: int liste.nbElement:Renvoie le nombre des elements dans la liste
 * ********************************************************************/
int Taille_liste(Maliste liste)
{
    return ((int)liste.nbElement);
}

//taile d'une liste version pointeur

// int Taille_liste(Maliste *pliste)
// {
//     if(pliste) return ((int)pliste->nbElement);
//     return((int)-1);//si liste n'existe pas

// }
//initialiser liste
/**********************************************************************
 Le nom de la fonction :Init_liste;
 Entrees : Maliste liste:le contenu de la liste des elements
 Sorties: int liste.nbElement:initialiser le nombre des element a zero
 * ********************************************************************/
int Init_liste(Maliste liste)
{
    liste.nbElement = 0;
    return ((int)liste.nbElement);
}
//insertion
/**********************************************************************
 Le nom de la fonction :Insert_liste;
 Entrees : Maliste *pliste:liste des cellule qui comprend des nombre entier;
            int Elem:la valeur de l'element a inserer
 Sorties: int :Renvoie l etat de l'insertion si tout bien passer 
        en effectuant une insertion a la fin de la liste  du nouvel element 
                        la fin de la liste
 * ********************************************************************/
int Insert_liste(Maliste *pliste, int Elem)
{
    //tester si la liste existe
    if (!pliste)
        return ((int)-1);
    //liste sature
    if (pliste->nbElement == MAX_ELEMENT)
        return ((int)0);
    //inserer l'element
    pliste->Tab[pliste->nbElement] = Elem;
    //mise a jour des nombre des elements
    pliste->nbElement++;
    return ((int)1);
}

//supprission a la position donné l'indice du tableau
/**********************************************************************
 Le nom de la fonction :Supprimer_pos_liste;
 Entrees : Maliste *pliste:liste des elements avec un nombre des entier dans la liste ;
            int pos:la position de l'element a suprimmer
 Sorties: Cellule *pliste:Renvoie la nouvelle liste avec une suppression d'une cellule
                        a la position donnée
 * ********************************************************************/
int Supprimer_pos_liste(Maliste *pliste, int pos)
{
    int ind;
    //est ce que la liste existe
    if (!pliste)
        return ((int)-1);
    //position non valide
    if ((pos < 0) || (pos > pliste->nbElement - 1))
        return ((int)0);
    //Decalage des elements
    for (ind = pos; ind < pliste->nbElement - 1; ind++)
        pliste->Tab[ind] = pliste->Tab[ind + 1];

    pliste->nbElement--;

    return ((int)1);
}
/*
    alternative de decalage
    for(ind=pos;;ind<pliste->nbElement-1;pliste->Tab[ind++]=pliste->Tab[ind+1]);
    */
//mise a jour des nombre elements apres le decalage
/**********************************************************************
 Le nom de la fonction :Insert_pos_liste;
 Entrees : Cellule *pliste:liste des ele qui comprend des nombre entier;
            int pos:la position d'ou l'insertion du nouvelle element
            int Elem:la valeur de l'element a inserer
 Sorties: Cellule *pliste:Renvoie la nouvelle liste avec l'insertion d'une nouvelle cellule
                        a la position donnée
 * ********************************************************************/
int Insert_pos_liste(Maliste *pliste, int pos, int Elem)
{
    int ind;
    //est ce que la liste existe
    if (!pliste)
        return ((int)-1);
    //position non valide
    if ((pos < 0) || (pos > pliste->nbElement))
        return ((int)0);
    // cas de table sature
    if (MAX_ELEMENT == pliste->nbElement)
        return ((int)-2);
    //decalage des element pour l'insertion
    for (ind = (pliste->nbElement - 1); ind >= pos; ind--)
        pliste->Tab[ind + 1] = pliste->Tab[ind];
    //insertion dans la position
    pliste->Tab[pos] = Elem;
    //mise a jour de la taile de tableau
    pliste->nbElement++;
    return ((int)1);
}
int Supprimer_val_liste(Maliste *liste, int val)
{
    int res = 0;
    if (!liste)
        return ((int)0);

    for (int i = 0; i < liste->nbElement; i++)
    {
        if (val == liste->Tab[i])
        {
            res = Supprimer_pos_liste(liste, i);

            return ((int)1);
        }
    }
    return ((int)-1);
}
/**********************************************************************
 Le nom de la fonction :Suprimer_Options_liste;
 Entrees : Cellule *pliste:liste des element entier;
            int pos:position de l'insertion
            int choix:choix de suprission a effectuer 1-en tete 2-en fin 3- a une position donner
 Sorties: Cellule *pliste: Renvoie la nouvelle liste avec une suppression
             de l'un des elements de la liste
 * ********************************************************************/

int Suprimer_Options_liste(Maliste *liste, int choix, int pos, int val)
{
    int resultat = 0;
    switch (choix)
    {
    case 1:
        resultat = Supprimer_pos_liste(liste, 0);
        break;
    case 2:
        resultat = Supprimer_pos_liste(liste, liste->nbElement - 1);
        break;
    case 3:
        resultat = Supprimer_pos_liste(liste, pos);
        break;
    case 4:
        resultat = Supprimer_val_liste(liste, val);
        break;
    default:
        break;
    }
    return ((int)resultat);
}
/**********************************************************************
 Le nom de la fonction :Inserer_Options_liste;
 Entrees : Cellule *pliste:liste des element entier;
            int val:la valeur de nouvel element a inserer
            int pos:position de l'insertion
            int choix:choix d insertion a effectuer 1-en tete 2-en fin 3- a une position donner
 Sorties: Cellule *pliste:Renvoie une nouvelle liste avec un nouvaux element inserer
 * ********************************************************************/

int Inserer_Options_liste(Maliste *liste, int val, int pos, int choix)
{
    int resultat = 0;
    switch (choix)
    {
    case 1:
        resultat = Insert_pos_liste(liste, 0, val);
        break;
    case 2:
        resultat = Insert_liste(liste, val);
        break;
    case 3:
        resultat = Insert_pos_liste(liste, pos, val);
        break;

    default:
        break;
    }
    return ((int)resultat);
}

/**********************************************************************
 Le nom de la fonction :Afficher_liste;
 Entrees : Maliste *liste:un pointeur sur la structure Maliste
 Sorties: void :Affficher les element de la liste
 * ********************************************************************/

void Afficher_liste(Maliste *liste)
{
    int indice;
    printf("\n ******** Affichage des element de la liste ******** \n");
    printf("\n");
    for (indice = 0; indice < liste->nbElement; indice++)
        printf(" %d  ", liste->Tab[indice]);

    printf("\n");
}
/**********************************************************************
 Le nom de la fonction :Nbr_Occurence_Elem_liste;
Entrees : Maliste *liste:un pointeur sur la structure Maliste
            int val:la valeur de l'element a rechercher
 Sorties: int cmp:Renvoie nombre des occurence de la valeur de l'element rechercher
 * ********************************************************************/
int Nbr_Occurence_Elem_liste(Maliste liste, int val)
{
    int cmp = 0, indice = 0;
    for (indice = 0; indice < liste.nbElement; indice++)
    {
        if (val == liste.Tab[indice])
            cmp++;
    }
    return cmp;
}
/**********************************************************************
 Le nom de la fonction :Nbr_Occurence_Elem_liste;
Entrees : Maliste *liste:un pointeur sur la structure Maliste
            int val:la valeur de l'element a rechercher
 Sorties: int ind:Renvoie l 'indice de l'element presenter dans la liste
 * ********************************************************************/
int rechrche_Elem(Maliste liste, int val)
{
    int ind = 0, indice = 0;
    for (indice = 0; indice < liste.nbElement; indice++)
    {
        if (val == liste.Tab[indice])
            ind = ++indice;
    }
    return ind;
}

/**********************************************************************
 Le nom de la fonction :Cree_TFile;
 Sorties: TFile *Mafile:Adresse de la file alloué
  * ********************************************************************/
TFile *Cree_TFile()
{
    TFile *Mafile;
    Mafile = (TFile *)malloc(sizeof(TFile));

    if (!Mafile)
        return ((TFile *)NULL);
    return ((TFile *)Mafile);
}
/**********************************************************************
 Le nom de la fonction :Init_PFile;
 Entrees : TFile *Mafile:l'adresse de la file passer en parametre;
 Sorties: int status:Renvoie 0 en cas de mafile est ne contient pas d'adresse
                    rencoie 1 en cas l intialisation de la tete 
                    et la queue avec la valeur -1 est bien passer;
 * ********************************************************************/
int Init_TFile(TFile *Mafile)
{
    if (!Mafile)
        return ((int)0);
    Mafile->debut = Mafile->fin = -1;
    return ((int)1);
}
/**********************************************************************
 Le nom de la fonction :Enfiler_TFile;
 Entrees : TFile *Mafile:l'adresse de la file passer en parametre;
          int Elem:la valeur du nombre entier a enfiler;
 Sorties: Renvoie -1 si Mafile n'existe pas 
        Renvoie 0 et 1 si l'insertion de l'element est bien fait;
  * ********************************************************************/
int Enfiler_TFile(TFile *Mafile, int Elem)
{
    if (!Mafile)
        return ((int)-1);
    if ((Mafile->debut == -1) && (Mafile->fin == -1))
    {
        Mafile->debut++;
        Mafile->fin = Mafile->debut;
        Mafile->Tab[Mafile->fin++] = Elem;
        return ((int)0);
    }
    if (MAX_ELEMENT == Mafile->fin)
    {
        //decalage des elements
        if (tasser_TFile(Mafile) == 1)
        {
            Mafile->Tab[Mafile->fin++] = Elem;
            return ((int)1);
        }
    }
    Mafile->Tab[Mafile->fin++] = Elem;
    return ((int)1);
};

/**********************************************************************
 Le nom de la fonction :Defiler_TFile;
 Entrees : TFile *Mafile:l'adresse de la file passer en parametre;
 Sorties: int:Renvoie -1 en cas d'erreur
        renvoie 0 si la file n'existe pas
        renvoie 1 si le defilement est bien passer       
* ********************************************************************/
int Defiler_TFile(TFile *Mafile)
{
    if (!Mafile)
        return ((int)0);
    if (Mafile->fin >= Mafile->debut)
    {
        Mafile->debut++;
        return ((int)1);
    }
    else
        return ((int)-1);
}
/**********************************************************************
 Le nom de la fonction :Taile_TFile;
 Entrees : TFile Mafile:Contenu de l'adresse de la file;
 Sorties: int :Renvoie la taile de la file Renvoie 
 * ********************************************************************/
int Taile_TFile(TFile Mafile)
{
    if (Mafile.debut == -1 && Mafile.fin == -1)
        return ((int)0);
    return ((int)Mafile.fin - Mafile.debut + 1);
}
/**********************************************************************
 Le nom de la fonction :Est_saturer_TFile;
 Entrees : TFile Mafile:Contenu de l'adresse de la file;
 Sorties: int :Renvoie vrai si la taille de file egal a MAx element
 * ********************************************************************/
int Est_saturer_TFile(TFile Mafile)
{
    return ((int)Taile_TFile(Mafile) == MAX_ELEMENT);
}

/**********************************************************************
 Le nom de la fonction :Afficher_TFile;
Entrees : TFile Mafile:Contenu de l'adresse de la file;
 Sorties: void :Affficher les element du tableau de la file
 * ********************************************************************/
void Afficher_TFile(TFile Mafile)
{
    int indice;
    for (indice = Mafile.debut; indice < Mafile.fin; indice++)
        printf("\n\t%d", Mafile.Tab[indice]);
}

typedef struct
{
    int Tab[MAX_ELEMENT];
    int sommet; //sommet de la pile
} TPile;

/**********************************************************************
 Le nom de la fonction :Cree_TPile;
 Sorties: TPile *Mapile:Adresse de la pile alloué
  * ********************************************************************/
TPile *Cree_TPile()
{
    TPile *Mapile;
    Mapile = (TPile *)malloc(sizeof(TPile));
    if (!Mapile)
        return ((TPile *)NULL);
    return ((TPile *)Mapile);
}
/**********************************************************************
 Le nom de la fonction :Init_PFile;
 Entrees : TPile *Mapile:l'adresse de la file passer en parametre;
 Sorties: int status:Renvoie 0 en cas de pile est ne contient pas d'adresse
                    rencoie 1 en cas l intialisation de la pile est reussi
 * ********************************************************************/
int Init_TPile(TPile *Mapile)
{
    if (!Mapile)
        return ((int)-1);
    Mapile->sommet = 0; //nombre des element dans la pile
    return ((int)1);
}

/**********************************************************************
 Le nom de la fonction :Taille_TPile;
 Entrees : TPile *Mapile:l'adresse de la file passer en parametre;
 Sorties: int :Renvoie la taile de la pile est par defaut la valeur de sommet
 * ********************************************************************/
int Taille_TPile(TPile *Mapile)
{
    return ((int)Mapile->sommet);
}
/**********************************************************************
 Le nom de la fonction :Est_saturer_TPile;
 Entrees : TPile Mapile:Contenu de la pile;
 Sorties: int :Renvoie vrai si la taille de pile egal a MAx element
 * ********************************************************************/

int Est_saturer_TPile(TPile Mapile)
{
    return ((int)MAX_ELEMENT == Mapile.sommet);
}
/**********************************************************************
 Le nom de la fonction :Inserer_TPile;
 Entrees : TPile *Mapile:l'adresse de la pile passer en parametre;
          int Elem:la valeur du nombre entier;
 Sorties: Renvoie 1 en cas de l insertion est reussi;
            Renvoie 0 si la pile est saturer 
            renvoie -1 si la pile n'existe pas
  * ********************************************************************/
int Inserer_TPile(TPile *Mapile, int Elem)
{
    if (!Mapile)
        return ((int)-1); //la pile n'existe pas
    if (Est_saturer_TPile(*Mapile))
        return ((int)0);
    Mapile->Tab[Mapile->sommet++] = Elem;
    return ((int)1);
}
/**********************************************************************
 Le nom de la fonction :Depiler_TPile;
 Entrees : TPile *Mapile:l'adresse de la pile passer en parametre;
 Sorties: Renvoie 1 en cas de la supprission est reussi ;
            Renvoie 0 si la pile est vide
            renvoie -1 si la pile n'existe pas
  * ********************************************************************/
int Depiler_TPile(TPile *Mapile)
{
    if (!Mapile)
        return ((int)-1);
    if (Mapile->sommet == 0)
        return ((int)0);
    Mapile->sommet--;
    return ((int)1);
}
/**********************************************************************
 Le nom de la fonction :Sommet_TPile ;
 Entrees : PPile Mapile: Contenue de la pile
 Sorties: Renvoie la valeur du sommet de la pile
 * ********************************************************************/

int Sommet_TPile(TPile Mapile)
{
    return ((int)Mapile.Tab[Mapile.sommet - 1]);
}
/**********************************************************************
 Le nom de la fonction :Affiche_TPile ;
 Entrees : PPile Mapile: Contenu de la pile
 Sorties:void : affichage des element de la pile
 * ********************************************************************/
void Affiche_TPile(TPile Mapile)
{
    int indice;
    //affichage des elements de la pile
    printf("affichage des elements de la pile");
    for (indice = Mapile.sommet - 1; indice >= 0; indice--)
        printf("\n\t%d", Mapile.Tab[indice]);
}

#include <stdbool.h>

/*********************************  Fonction des Arbre  ************************************/
#define COUNT 10
typedef struct Nd
{
    int info;            //la valeur du noeud
    struct Nd *fils_gch; //un pointeur sur le fils gauche  du noeud
    struct Nd *fils_dt;  //un pointeur sur le fils droit du noeud
    int cmp;             //nombre des occurence du valeur du noeud
} Noeud;

//fonction de creation de nouveau noeud
/**********************************************************************
 Le nom de la fonction :Cree_Noeud;
 Entrees : int val: la valeur d'entier a inserer 
 Sorties: Noeud Nd:l'adresse du noeud creer
 * ********************************************************************/
Noeud *Cree_Noeud(int val)
{
    Noeud *Nd;
    Nd = (Noeud *)malloc(sizeof(Noeud));
    if (!Nd) //tester l'allocation
    {
        printf("\n Erreur d allocation ");
        exit(-1);
    }
    //initialisation du noeud
    Nd->cmp = 1;
    Nd->info = val;
    Nd->fils_gch = Nd->fils_dt = NULL;
    return ((Noeud *)Nd);
}
// affichage prefixer
/**********************************************************************
 Le nom de la fonction :Prefixxe;
 Entrees : Noeud *Arbre: un pointeur de premier Noeud dans l'arbre
 sortie :void :permet d'affichage prefixe
 
 * ********************************************************************/
void prefixe(Noeud *Arbre)
{
    int ind;
    if (Arbre) //si l'arbre existe
    {
        //affichage de la valeur du noeud avec ses occurence
        for (ind = 0; ind < Arbre->cmp; ind++)
        {
            printf("\n%d", Arbre->info);
        }
        prefixe(Arbre->fils_gch);
        prefixe(Arbre->fils_dt);
    }
}
// affichage infixe
/**********************************************************************
 Le nom de la fonction :infixe;
 Entrees : Noeud *Arbre: un pointeur de premier Noeud dans l'arbre
 sortie :void :permet d'affichage infixe 
 
 * ********************************************************************/
void infixe(Noeud *Arbre)
{
    int ind;
    if (Arbre) //si l'arbre existe
    {
        infixe(Arbre->fils_gch);
        //affichage de la valeur du noeud avec ses occurence
        for (ind = 0; ind < Arbre->cmp; ind++)
        {
            printf("\n%d", Arbre->info);
        }

        infixe(Arbre->fils_dt);
    }
}
// affichage postfixe
/**********************************************************************
 Le nom de la fonction :postfixe;
 Entrees : Noeud *Arbre: un pointeur de premier Noeud dans l'arbre
 sortie :void :permet d'affichage postfixe

 * ********************************************************************/
void postfixe(Noeud *Arbre)
{
    int ind;
    if (Arbre) //si l'arbre existe
    {
        postfixe(Arbre->fils_gch);
        postfixe(Arbre->fils_dt);
        //affichage de la valeur du noeud avec ses occurence
        for (ind = 0; ind < Arbre->cmp; ind++)
        {
            printf("\n%d", Arbre->info);
        }
    }
}
/**********************************************************************
 Le nom de la fonction :Insertion_Arbre_Horz;
 Entrees : Noeud *Arbre: un pointeur de premier Noeud dans l'arbre
            int val:la valeur de l'element a inserer
 sortie :Noeud *Arbre :revoie le pointeur de l'adresse de premier Noeud 
                        apres l insertion de l'element

 * ********************************************************************/
Noeud *Insertion_Arbre_Horz(Noeud *Arbre, int val)
{
    Noeud *Nd;

    if (!Arbre) //si l'arbre n'existe pas
    {
        Nd = Cree_Noeud(val); //creation de nouveaux noeud
        return ((Noeud *)Nd); //retourner un pointeur du noeud creé
    }
    if (val < Arbre->info)                                            //si la valeur inferieur au racine
        Arbre->fils_gch = Insertion_Arbre_Horz(Arbre->fils_gch, val); //effectuez l insertion dans le sous arbre gauche
    else if (val > Arbre->info)                                       //si la valeur supérieur au racine
        Arbre->fils_dt = Insertion_Arbre_Horz(Arbre->fils_dt, val);   //effectuez l insertion dans le sous arbre droit
    else
        Arbre->cmp++; //l'element déja inserer incrementer son compteur

    return ((Noeud *)Arbre); //retourner le pointeur de la racine
}
/**********************************************************************
 Le nom de la fonction :taille_Arbre;
 Entrees : Noeud *Arbre: un pointeur du racine de l'arbre

 sortie :int  :revoie le nombre des noeud de l'arbre passé au paramétre

 * ********************************************************************/
int taille_Arbre(Noeud *Arbre)
{

    if (Arbre) //si l'arbre existe
        return 1 + taille_Arbre(Arbre->fils_gch) + taille_Arbre(Arbre->fils_dt);
    return 0;
}
/**********************************************************************
 Le nom de la fonction :Max_Element_Arbre;
 Entrees : Noeud *Arbre: un pointeur du racine de l'arbre
 sortie :int  :revoie le Max des noeud dans l'arbre

 * ********************************************************************/
int Max_Element_Arbre(Noeud *Arbre)
{

    if (Arbre->fils_dt == NULL) //si le fils droit du racine est vide
    {
        return Arbre->info; //renvoyer la valeur du racine
    }
    return Max_Element_Arbre(Arbre->fils_dt); //sinon chercher le max dans le sous arbre droit
}
/**********************************************************************
 Le nom de la fonction :Min_Element_Arbre;
 Entrees : Noeud *Arbre: un pointeur du racine de l'arbre
 sortie :int  :revoie le Min des noeud dans l'arbre

 * ********************************************************************/
int Min_Element_Arbre(Noeud *Arbre)
{

    if (Arbre->fils_gch == NULL) //si le fils droit du racine est vide
    {
        return Arbre->info; //renvoyer la valeur du racine
    }
    return Min_Element_Arbre(Arbre->fils_gch); //sinon chercher le min dans le sous arbre gauche
}

/**********************************************************************
 Le nom de la fonction :remplacer_arbre;
 Entrees : Noeud *org: un pointeur du racine de l'arbre a modifier 
           Noeud *noeudr: un pointeur sur le sous arbre a modifier
 sortie :Noeud * noeudr :revoie le pointeur du racine de l'arbre 
                apres le remplacement par le fils le plus gauche 
                sous arbre droite

 * ********************************************************************/
Noeud *remplacer_arbre(Noeud *org, Noeud *noeudr)
{
    if (noeudr->fils_gch)                                          //si fils gauche existe
        noeudr->fils_gch = remplacer_arbre(org, noeudr->fils_gch); //remplacement de noeud
    else
    {
        org->info = noeudr->info; //la racine a comme valeur la valeur du noeud le plus gauche
        noeudr = noeudr->fils_dt; //le noeud le plus gauche recoit le vide
    }
    return ((Noeud *)noeudr); //retourner l'arbre aprés le remplacement
}
/**********************************************************************
 Le nom de la fonction :supprimer_Arbre_Horz;
 Entrees : Noeud *Arbre: un pointeur du racine de l'arbre 
           int val: la valeur a suprimmer
 sortie :Noeud * Arbre :revoie le pointeur du racine de l'arbre 
                apres supprission de l'element

 * ********************************************************************/
Noeud *supprimer_Arbre_Horz(Noeud *Arbre, int val)
{
    if (!Arbre)
        return (Arbre);
    // si l'elemnt a supprimer se trouve au  sous-arbre gauche//
    if (val < Arbre->info)
        Arbre->fils_gch = supprimer_Arbre_Horz(Arbre->fils_gch, val);
    // si l'elemnt a supprimer se trouve au sous-arbre droit//
    else if (val > Arbre->info)
        Arbre->fils_dt = supprimer_Arbre_Horz(Arbre->fils_dt, val);
    else
    {
        if (Arbre->cmp > 1)
            Arbre->cmp--;
        else
        {
            if (!Arbre->fils_dt)
                Arbre = Arbre->fils_gch; // si l'arbre n'a pas un fils droit
            else if (!Arbre->fils_gch)
                Arbre = Arbre->fils_dt; // si l'rbre n'a pas un fils gauche
            else
                Arbre->fils_dt = remplacer_arbre(Arbre, Arbre->fils_dt); //le remplacement par le fils le plus gauche
                                                                         //sous arbre droite
        }
    }
    return ((Noeud *)Arbre);
}
void print2DUtil(Noeud *Arbre, int space)
{
    if (Arbre == NULL)
        return;
    space += COUNT;
    print2DUtil(Arbre->fils_dt, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d (%d)\n", Arbre->info, Arbre->cmp);
    print2DUtil(Arbre->fils_gch, space);
}
void print2D(Noeud *Arbre)
{
    print2DUtil(Arbre, 0);
}

/*******************************   Arbre binaire non ordonner   ****************************/
/***********************************************************************
 * Nom : void affiche_prefixeNO(Noeud *arbre)
 *             Affichage Prefixe recurcive des elements de l'arbre
 * Entree : Noeud *arbre : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_prefixeNO(Noeud *arbre)
{
    if (!arbre)
        return;

    printf("%d (%d)\t", arbre->info, arbre->cmp);

    affiche_prefixeNO(arbre->fils_gch);
    affiche_prefixeNO(arbre->fils_dt);
}

///**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_infixeNO(Noeud *arbre)
 *             Affichage infixe recurcive des elements de l'arbre
 * Entree : Noeud *arbre : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_infixeNO(Noeud *arbre)
{
    if (!arbre)
        return;

    affiche_infixeNO(arbre->fils_gch);
    printf("%d (%d)\t", arbre->info, arbre->cmp);
    affiche_infixeNO(arbre->fils_dt);
}
///**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_postfixeNO(Noeud *arbre)
 *             Affichage infixe recurcive des elements de l'arbre
 * Entree : Noeud *arbre : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_postfixeNO(Noeud *arbre)
{
    if (!arbre)
        return;

    affiche_postfixeNO(arbre->fils_gch);
    affiche_postfixeNO(arbre->fils_dt);
    printf("%d (%d)\t", arbre->info, arbre->cmp);
}
Noeud *recherche_elm(Noeud *arbre, int val)
{
    if (!arbre)
        return ((Noeud *)NULL);
    if (arbre->info == val)
        return ((Noeud *)arbre);

    return recherche_elm(arbre->fils_gch, val);
    return recherche_elm(arbre->fils_dt, val);
}

/***********************************************************************************
 * Nom : Noeud* insertion_automatique(Noeud *arbre, int val)
 * role: Insert d'une maniere automatique un element dans l'arbre pour
 *       avoir un equilibre entre les elements droits et gauches de chaque noeud
 * Entree : Noeud *arbre : l'arbre dans lequel on insert l'element
 *          int val : la valeur a inserer
 * Sortie : Noeud* : pointeur sur la racine de l'arbre apres l'insertion
 */
Noeud *insertion_automatique(Noeud *arbre, int val)
{
    Noeud *tmp;
    int fils_dt, fils_gch;
    // si l'arbre n'existe pas
    if (!arbre)
    {
        Noeud *ne = Cree_Noeud(val);
        return ((Noeud *)ne);
    }
    // si l'arbre existe
    // si la valeur existe (dans la racine)

    if (arbre->info == val)
    {
        arbre->cmp++; // incr le compteur
        return ((Noeud *)arbre);
    }
    // si la valeur n'existe pas (dans la racine)
    //chercher si la valeur existe dans sous arbre de fils droit
    else if (fils_val_existe(arbre->fils_dt, val))
    {
        arbre->fils_dt = insertion_automatique(arbre->fils_dt, val);
    }
    //chercher si la valeur existe dans sous arbre de fils gauche
    else if (fils_val_existe(arbre->fils_gch, val))
    {
        arbre->fils_gch = insertion_automatique(arbre->fils_gch, val);
    }
    // si la valeur n'existe pas dans l'arbre
    //ajouter dans le sous arbre a un nombre d'element inferieur
    else
    {
        fils_dt = size_arbreNO(arbre->fils_dt);
        fils_gch = size_arbreNO(arbre->fils_gch);
        if (fils_gch <= fils_dt)
            arbre->fils_gch = insertion_automatique(arbre->fils_gch, val);
        else
            arbre->fils_dt = insertion_automatique(arbre->fils_dt, val);
    }

    return ((Noeud *)arbre);
}
/************************************************************************************
 * Nom : Noeud* feuille_gch(Noeud *Arbre)
 *             cherche le fils le plus a gauche du fils gauche
 *              (utile pour la suppression)
 * Entree : Noeud *Arbre : l'arbre sur lequel on applique le traitement
 * Sortie :Noeud* poiteur sur le fils le plus a gauche du fils gauche
 */
Noeud *feuille_gch(Noeud *Arbre)
{
    if (Arbre->fils_gch)
        Arbre = feuille_gch(Arbre->fils_gch);
    return ((Noeud *)Arbre);
}
/***********************************************************************************
 * Nom : Noeud *supp_arbre_no(Noeud *arbre, int val)
 *             Cherche recursivement une valeur dans l'arbre et la supprime
 *             si compteur est >1 va decrementer le compteur
 * Entree : Noeud *arbre : l'arbre sur lequel on applique le traitement
 *          int val : La valeur a supprime
 * Sortie : Noeud* l'arbre apres la suppression
 */
Noeud *supp_arbre_no(Noeud *arbre, int val)
{
    int entier;
    //si la valeur n'est pas trouve
    if (!arbre)
    {
        return ((Noeud *)NULL);
    }
    //si le Noeud courant a info == val
    if (arbre->info == val)
    {
        if (arbre->cmp > 1)
        {
            (arbre->cmp)--; //supprimer une des repetition
            return ((Noeud *)arbre);
        }

        else
        {
            //chercher le nombre des fils
            Noeud *tmp = NULL;
            entier = fils_existe(arbre);
            switch (entier)
            {
            case 0:
                free(arbre);
                return ((Noeud *)tmp);
            case 1: //On Remplace ce Noeud par son fils Droit
                tmp = arbre->fils_dt;
                free(arbre);
                return ((Noeud *)tmp);
                //On Remplace ce Noeud par son fils gauche
            case 2:
                tmp = arbre->fils_gch;
                free(arbre);
                return ((Noeud *)tmp);
                //On Remplace ce Noeud par son fils gauche
                //le plus a gauche
            case 3:
                tmp = feuille_gch(arbre);
                arbre->info = tmp->info;
                arbre->cmp = tmp->cmp;
                arbre->fils_gch = supp_arbre_no(arbre->fils_gch, tmp->info);
                return ((Noeud *)arbre);
            }
        }
    }
    else
        arbre->fils_gch = supp_arbre_no(arbre->fils_gch, val);

    arbre->fils_dt = supp_arbre_no(arbre->fils_dt, val);
}
/************************************************************************
 * Nom : int size_arbreNO(Noeud* arbre)
 *             calcule recursivement la taille d'un arbre donnee
 * Entree : Noeud *arbre: l'arbre sur lequel on applique le traitement
 *
 * Sortie : int : entier represente la taille de l'arbre
 */
int size_arbreNO(Noeud *arbre)
{
    if (!arbre)
        return ((int)0);

    int fils_gch = size_arbreNO(arbre->fils_gch);
    int fils_dt = size_arbreNO(arbre->fils_dt);
    return ((int)fils_dt + fils_gch + (arbre->cmp));
}
/***********************************************************************************
 * Nom : int max_arbNO(Noeud *arbre)
 *             Cherche recursivement la valeur maximal
 * Entree : Noeud *arbre : l'arbre sur lequel on applique le traitement
 * Sortie : int la valeur maximal dans l'arbre
 */
int max_arbNO(Noeud *arbre)
{
    int fils_dt, fils_gch;

    if (arbre->fils_dt)
    {
        fils_dt = max_arbNO(arbre->fils_dt);
        if (arbre->fils_gch)
        {
            fils_gch = max_arbNO(arbre->fils_gch);
            if ((fils_dt > fils_gch) && (fils_dt > arbre->info))
                return fils_dt;
            if (fils_gch > arbre->info)
                return fils_gch;
            return arbre->info;
        }
        if (fils_dt > arbre->info)
            return fils_dt;
        return arbre->info;
    }

    if (arbre->fils_gch)
    {
        fils_gch = max_arbNO(arbre->fils_gch);
        return fils_gch;
    }
    return arbre->info;
}
/**********************************************************************************
 * Nom : void min_arbNO(Noeud *arbre,int *min)
 *             Cherche recursivement la valeur maximal
 * Entree : Noeud *arbre : l'arbre sur lequel on applique le traitement
 *          int *min:la valeur min dans l'arbre
 * Sortie : rien
 */
void min_arbNO(Noeud *arbre, int *min)
{
    int fils_dt = max_arbNO(arbre),
        fils_gch = max_arbNO(arbre);
    if (arbre)
    {
        *min = arbre->info;
        min_arbNO(arbre->fils_dt, &fils_dt);
        min_arbNO(arbre->fils_gch, &fils_gch);
        if (*min > fils_dt)
            *min = fils_dt;
        if (*min > fils_gch)
            *min = fils_gch;
    }
}
/***********************************************************************************
 * Nom : void affiche_arbre_Real(PNode *arbre)
 *             afficher l'arbre comme arbre reel verticalement
 * Entree : PNode *arbre : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_arbreNO_Real(Noeud *arbre)
{
    int prof = profondeur_arbreNO(arbre);
    int segma = 0;
    int tmp;
    for (int i = 0; i < prof; ++i)
    {
        tmp = (int)pow(2, i);
        segma += tmp;
    }

    int matrice[prof][segma];
    int *pt = (int *)matrice;

    for (int i = 0; i < prof; ++i)
        for (int j = 0; j < segma; ++j)
            matrice[i][j] = -99;

    assign_val_to_MtxNO(arbre, pt, segma, 0, (segma / 2), (segma / 2 + 1) / 2);

    printf("\n*******************************\n");
    for (int i = 0; i < prof; ++i)
    {
        for (int j = 0; j < segma; ++j)
        {
            if (matrice[i][j] == -99)
                printf("**");
            else
                printf("%02d", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n*******************************\n");
}
/************************************************************************
 * Nom : int profondeur_arbreNO(Noeud *arbre)
 *             Calcule recursivement la profondeur de l'arbre
 * Entree : Noeud *arbre : l'arbre sur lequel on applique le traitement
 * Sortie : int la profondeur dans l'arbre
 */
int profondeur_arbreNO(Noeud *arbre)
{
    if (!arbre)
        return ((int)0);
    int fils_dt = profondeur_arbreNO(arbre->fils_dt) + 1;
    int fils_gch = profondeur_arbreNO(arbre->fils_gch) + 1;
    return (fils_dt > fils_gch) ? fils_dt : fils_gch;
}
/***********************************************************************************
 * Nom : void assign_val_to_Mtx(PNode *arbre, int *matrice, int cols,
 *                              int line, int col, int ss)
 *             attribue les noeuds dans l'arbre
 *             au champs correspondent dans la matrice
 * Entree : PNode *arbre : l'arbre sur lequel on applique le traitement
 *          int *matrice : ou on attribue les valeur des noeuds
 *          int cols : nombre de colonnes de la matrice
 *          int line : ligne courant
 *          int col : colonne courant
 *          int ss : deplacement du colonne du fils par apport au parent
 * Sortie : rien
 */
void assign_val_to_MtxNO(Noeud *arbre, int *matrice, int cols, int line, int col, int ss)
{
    if (!arbre)
        return;
    *((matrice + (line * cols)) + col) = arbre->info;

    assign_val_to_MtxNO(arbre->fils_dt, matrice, cols, line + 1, col + ss, ss / 2);
    assign_val_to_MtxNO(arbre->fils_gch, matrice, cols, line + 1, col - ss, ss / 2);
}
/***********************************************************************************
 * Nom : Noeud *supp_def_arbre_no(Noeud *Arbre, int val)
 *             Cherche recursivement une valeur dans l'arbre et la supprime
 *             meme si le compteur est >1
 * Entree : Noeud *Arbre : l'arbre sur lequel on applique le traitement
 *          int val : La valeur a supprime
 * Sortie : Noeud* l'arbre apres la suppression
 */
Noeud *supp_def_arbre_no(Noeud *Arbre, int val)
{
    int entier;
    //si la valeur n'est pas trouve
    if (!Arbre)
        return ((Noeud *)Arbre);

    //si le Noeud courant a info == val
    if (Arbre->info == val)
    {
        Noeud *tmp = NULL;
        entier = fils_existe(Arbre);
        switch (entier)
        {
        case 0:
            free(Arbre);
            return ((Noeud *)tmp);
        case 1: //On Remplace ce Noeud par son fils Droit
            tmp = Arbre->fils_dt;
            free(Arbre);
            return ((Noeud *)tmp);
            //On Remplace ce Noeud par son fils gauche
        case 2:
            tmp = Arbre->fils_gch;
            free(Arbre);
            return ((Noeud *)tmp);
            //On Remplace ce Noeud par son
            //fils gauche le plus a gauche
        case 3:
            tmp = feuille_gch(Arbre);
            Arbre->info = tmp->info;
            Arbre->cmp = tmp->cmp;
            Arbre->fils_gch = supp_arbre_no(Arbre->fils_gch, tmp->info);
            return ((Noeud *)Arbre);
            break;
        }
    }
    else
    {
        Arbre->fils_gch = supp_arbre_no(Arbre->fils_gch, val);
        Arbre->fils_dt = supp_arbre_no(Arbre->fils_dt, val);
    }
}
///**********************************************************************************

///**********************************************************************************
/***********************************************************************************
 * Nom : int fils_existe(Noeud *Arbre)
 *             calcule le nombre des fils d'un racine
 *             (utile pour la suppression)
 * Entree : Noeud *Arbre : l'arbre sur lequel on applique le traitement
 * Sortie :int nombre des fils
 */
int fils_existe(Noeud *Arbre)
{
    if (!Arbre->fils_dt && !Arbre->fils_gch)
        return ((int)0); //ni fils gauche ni droite

    else if (!Arbre->fils_gch)
        return ((int)1); //fils droit existe
    else if (!Arbre->fils_dt)
        return ((int)2); //fils gauche existe
    else
        return ((int)3); //les deux fils existe
}
/*************************************************************************
 * Nom : int fils_val_existe(Noeud *Arbre, int val)
 *             cherche si une valeur donne existe dans l'arbre
 *               (utile pour la insertion)
 * Entree : Noeud *Arbre : l'arbre sur lequel on applique le traitement
 *          int val
 * Sortie :int : 1 si exist, 0 sinon
 */
int fils_val_existe(Noeud *Arbre, int val)
{
    if (!Arbre)
        return ((int)0);
    if (Arbre->info == val)
        return ((int)1);
    return fils_val_existe(Arbre->fils_gch, val) || fils_val_existe(Arbre->fils_dt, val);
}

/********************** les fonctions de transfer et de remplissage********************************/

// transfere les element de la pile vers une file
PFile *trans_PPile_PFile(PPile *Mapile)
{
    PFile *Mafile = cree_Pfile();
    if (!Mapile)
        return ((PFile *)NULL);
    PPile *tmp = NULL;
    while (Mapile)
    {
        Mafile = Enfiler_PFile(Mafile, Mapile->Val);
        tmp = Empiler_PPile(tmp, Mapile->Val);
        Mapile = Depiler_PPile(Mapile);
    }
    while (tmp)
    {

        Mapile = Empiler_PPile(Mapile, tmp->Val);
        tmp = Depiler_PPile(tmp);
    }
    Afficher_PFile(Mafile);
    return ((PFile *)Mafile);
}
//transfere les element de la file vers une pile
PPile *trans_PFile_PPile(PFile *Mafile)
{
    PPile *Mapile = NULL;
    PFile *tmp = cree_Pfile();
    if (!Mafile)
        return ((PPile *)NULL);

    while (Mafile->tete)
    {
        Mapile = Empiler_PPile(Mapile, Mafile->tete->Val);
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
    }
    Mafile->tete = tmp->tete;
    Mafile->Queue = tmp->Queue;
    Afficher_Ppile(Mapile);
    return ((PPile *)Mapile);
}
// transfere les element de file vers une arbre

Noeud *trans_PFile_ArbreBinOrd(PFile *Mafile)
{
    Noeud *Arbre = NULL;
    PFile *tmp = cree_Pfile();
    if (!Mafile)
        return ((Noeud *)NULL);

    while (Mafile->tete)
    {
        Arbre = Insertion_Arbre_Horz(Arbre, Mafile->tete->Val);
        tmp = Enfiler_PFile(tmp, Mafile->tete->Val);
    }
    Mafile->tete = tmp->tete;
    Mafile->Queue = tmp->Queue;
    print2D(Arbre);
    return ((Noeud *)Arbre);
}
//transferer une liste chainé au liste tableau
Maliste *trans_PListe_TListe(Cellule *pliste)
{
    Maliste *liste = NULL;
    liste = Cree_Liste();
    int res = 0;
    while (pliste)
    {
        res = Insert_liste(liste, pliste->Val);
        pliste = pliste->suiv;
    }

    return ((Maliste *)liste);
}
//transfere une liste chainé a une pile
PPile *trans_PListe_PPile(Cellule *Maliste)
{
    PPile *Mapile = NULL ;
    Cellule *tmp = Maliste;
    int val=0;
    while (Maliste)
    {
        val = Maliste->Val;
        Mapile = Empiler_PPile(Mapile, val);
        Maliste = Maliste->suiv;
    }
    return ((PPile *)Mapile);
}
//transferer une liste tableau au liste chainé

Cellule *trans_TListe_PListe(Maliste *TabListe)
{
    Cellule *pliste = NULL;

    int indice;
    for (indice = 0; indice < TabListe->nbElement; indice++)
        pliste = Inserer_fin_pliste(pliste, TabListe->Tab[indice]);

    return ((Cellule *)pliste);
}

//Remplire Tliste with tableau
Maliste *Remplir_TListe_tableau(int Tab[], int Nbr)
{
    int indice, res = 0;
    Maliste *liste = Cree_Liste();
    for (indice = 0; indice < Nbr; indice++)
    {
        res = Insert_liste(liste, Tab[indice]);
    }
    return ((Maliste *)liste);
}
//Remplire liste chainé with tableau
Cellule *Remplir_PListe_tableau(int Tab[], int Nbr)
{
    int indice, res = 0;
    Cellule *liste = NULL;
    for (indice = 0; indice < Nbr; indice++)
    {
        liste = Inserer_fin_pliste(liste, Tab[indice]);
    }
    printf("\n ******** Remplir avec tableau a ete effectuer ******** ");

    return ((Cellule *)liste);
}
//Remplire une pile avec un tableau
//ne fonction pas <Makhdamach>
PPile *Remplir_PPile_tableau(int Tab[], int Nbr)
{
    PPile *Mapile = NULL;
    int indice, res = 0;
    int val = 0;
    for (indice = 0; indice < Nbr; indice++)
    {
        val = Tab[indice];
        Mapile = Empiler_PPile(Mapile, val);
    }
    return ((PPile *)Mapile);
}
//Remplire une file avec un tableau
PFile *Remplir_PFile_tableau(int Tab[], int Nbr)
{
    PFile *Mafile = cree_Pfile();
    int indice, res = 0;
    int val = 0;
    for (indice = 0; indice < Nbr; indice++)
    {
        val = Tab[indice];
        Mafile = Enfiler_PFile(Mafile, val);
    }
    return ((PFile *)Mafile);
}
//Remplire une arbre binaire horizontal avec un tableau
Noeud *Remplir_ArbreBinOrdHorz_tableau(int Tab[], int Nbr)
{
    Noeud *Arbre = NULL;
    int indice, res = 0;
    int val = 0;
    for (indice = 0; indice < Nbr; indice++)
    {
        val = Tab[indice];
        Arbre = Insertion_Arbre_Horz(Arbre, val);
    }
    return ((Noeud *)Arbre);
}