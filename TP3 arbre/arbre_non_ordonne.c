#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


// structure utilisee
typedef struct ND
{
    int info;//information du noeud
    int cpt;//nombre de repetition de cette info
    struct ND *gch;//pointeur sur le fils gauche
    struct ND *drt;//pointeur sur le fils droit
}Noeud;

//**********************************************************************************
/*******************************************************
 * Nom : Noeud* create_Noeud(int val)
 * role: cree et initialise un nouveau noeud
 * Entree : int val : la valeur du nouveau noeud
 * Sortie : Noeud* : pointeur sur le noeud cree
 */
Noeud* create_Noeud(int val)
{
    Noeud *ne = (Noeud*) malloc(sizeof(Noeud));
    if (!ne) {
        printf("\n\n Erreur d'allocation de memoire\n");
        exit(0);
    }

    ne->drt = ne->gch = NULL;
    ne->info = val;
    ne->cpt = 1;
    return ((Noeud*) ne);
}

//**********************************************************************************
/*******************************************************************
 * Nom : Noeud *recherche_elm(Noeud *root,int val)
 * role: s'avoir si un element est deja dans l'arbre
 * Entree : Noeud *root : l'arbre dans lequel on insert l'element
 *          int val : la valeur a inserer
 * Sortie : Noeud* : pointeur sur le noeud avec la valeur *val*
 *                   ou NULL s'il n'existe pas
 */
Noeud *recherche_elm(Noeud *root,int val)
{
    if (!root)
        return ((Noeud*) NULL);
    if(root->info == val)
        return((Noeud*)root);

    return recherche_elm(root->gch,val);
    return recherche_elm(root->drt,val);
}



//**********************************************************************************
/************************************************************************
 * Nom : int size_arbreNO(Noeud* root)
 *             calcule recursivement la taille d'un arbre donnee
 * Entree : Noeud *root: l'arbre sur lequel on applique le traitement
 *
 * Sortie : int : entier represente la taille de l'arbre
 */
int size_arbreNO(Noeud* root)
{
    if(!root) return ((int) 0);

    int gch=size_arbreNO(root->gch);
    int drt=size_arbreNO(root->drt);
    return	((int) drt + gch + (root->cpt));
}



//**********************************************************************************
/*************************************************************************
 * Nom : int fils_val_existe(Noeud *root, int val)
 *             cherche si une valeur donne existe dans l'arbre
 *               (utile pour la insertion)
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 *          int val
 * Sortie :int : 1 si exist, 0 sinon
 */
int fils_val_existe(Noeud *root, int val)
{
    if(!root) return((int)0);
    if (root->info == val)
        return ((int) 1);
    return fils_val_existe(root->gch, val)
           || fils_val_existe(root->drt, val);
}




//**********************************************************************************
/***********************************************************************************
 * Nom : Noeud* insertion_automatique(Noeud *root, int val)
 * role: Insert d'une maniere automatique un element dans l'arbre pour
 *       avoir un equilibre entre les elements droits et gauches de chaque noeud
 * Entree : Noeud *root : l'arbre dans lequel on insert l'element
 *          int val : la valeur a inserer
 * Sortie : Noeud* : pointeur sur la racine de l'arbre apres l'insertion
 */
Noeud* insertion_automatique(Noeud *root, int val)
{
    Noeud *tmp;
    int drt, gch;
// si l'arbre n'existe pas
    if (!root) {
        Noeud *ne = create_Noeud(val);
        return ((Noeud *) ne);
    }
// si l'arbre existe
// si la valeur existe (dans la racine)

    if (root->info == val) {
        root->cpt++;// incr le compteur
        return ((Noeud *) root);
    }
// si la valeur n'existe pas (dans la racine)
        //chercher si la valeur existe dans sous arbre de fils droit
    else if (fils_val_existe(root->drt, val))
    {
        root->drt = insertion_automatique(root->drt, val);
    }
        //chercher si la valeur existe dans sous arbre de fils gauche
    else if (fils_val_existe(root->gch, val)) {
        root->gch = insertion_automatique(root->gch, val);
    }
// si la valeur n'existe pas dans l'arbre
//ajouter dans le sous arbre a un nombre d'element inferieur
    else {
        drt = size_arbreNO(root->drt);
        gch = size_arbreNO(root->gch);
        if (gch <= drt)
            root->gch = insertion_automatique(root->gch, val);
        else
            root->drt = insertion_automatique(root->drt, val);
    }

    return ((Noeud *) root);
}



//**********************************************************************************
/***********************************************************************************
 * Nom : Noeud* insert_arb_no(Noeud *root, int val)
 * role: Insert d'une maniere manuellement un element dans l'arbre selon le
 *       choix de l'utilisateur a gauche /droite avec la possibilite d'inser auto
 * Entree : Noeud *root : l'arbre dans lequel on insert l'element
 *          int val : la valeur a inserer
 * Sortie : Noeud* : pointeur sur la racine de l'arbre apres l'insertion
 */
Noeud* insert_arb_no(Noeud *root, int val)
{ 	int gd;

// si l'arbre n'existe pas
    if (!root)
    {
        Noeud *ne = create_Noeud(val);
        return ((Noeud *) ne);
    }

    // si l'arbre existe
    // si la valeur existe (dans la racine)

    if (root->info == val) {
        root->cpt++;
        return ((Noeud *) root);
    }
    //chercher si la valeur existe dans sous arbre de fils droit
    else if (fils_val_existe(root->drt, val)) {
        root->drt = insert_arb_no(root->drt, val);
    }
    //chercher si la valeur existe dans sous arbre de fils gauche
    else if (fils_val_existe(root->gch, val)) {
        root->gch = insert_arb_no(root->gch, val);
    }
    // si la valeur n'existe pas dans l'arbre
    else
    {
        printf("vous voulez inserer a gauche (tapez : 1) ,a droit (tapez : 2) ou auto (tapez:3) (O :abort )");
        scanf("%d",&gd);getchar();

        switch(gd)
        {
            case 1 : 	root->gch =insert_arb_no(root->gch, val);
                break;

            case 2 :  	root->drt = insert_arb_no(root->drt, val);
                break;
            case 3 :  	insertion_automatique(root, val);
                break;

            case 0 : 	break;
        }
        return((Noeud*)root);

    }
}

//**********************************************************************************
/***********************************************************************
 * Nom : void affiche_prefixeNO(Noeud *root)
 *             Affichage Prefixe recurcive des elements de l'arbre
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_prefixeNO(Noeud *root)
{
    if (!root)
        return;

    printf("%d (%d)\t", root->info,root->cpt);

    affiche_prefixeNO(root->gch);
    affiche_prefixeNO(root->drt);
}


///**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_infixeNO(Noeud *root)
 *             Affichage infixe recurcive des elements de l'arbre
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_infixeNO(Noeud *root)
{
    if (!root)
        return;

    affiche_infixeNO(root->gch);
    printf("%d (%d)\t", root->info,root->cpt);
    affiche_infixeNO(root->drt);

}
///**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_postfixeNO(Noeud *root)
 *             Affichage infixe recurcive des elements de l'arbre
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_postfixeNO(Noeud *root)
{
    if (!root)
        return;

    affiche_postfixeNO(root->gch);
    affiche_postfixeNO(root->drt);
    printf("%d (%d)\t", root->info,root->cpt);
}



///**********************************************************************************
/************************************************************************************
 * Nom : Noeud* feuille_gch(Noeud *root)
 *             cherche le fils le plus a gauche du fils gauche
 *              (utile pour la suppression)
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 * Sortie :Noeud* poiteur sur le fils le plus a gauche du fils gauche
 */
Noeud* feuille_gch(Noeud *root)
{
    if(root->gch)
        root =feuille_gch(root->gch);
    return((Noeud*)root);
}


///**********************************************************************************
/***********************************************************************************
 * Nom : int fils_existe(Noeud *root)
 *             calcule le nombre des fils d'un racine
 *             (utile pour la suppression)
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 * Sortie :int nombre des fils
 */
int fils_existe(Noeud *root)
{
    if(!root->drt && !root->gch) return((int)0);//ni fils gauche ni droite

    else if (!root->gch) return((int)1);//fils droit existe
    else if (!root->drt)  return((int)2);//fils gauche existe
    else  return((int)3);//les deux fils existe

}




//**********************************************************************************
/***********************************************************************************
 * Nom : Noeud *supp_arbre_no(Noeud *root, int val)
 *             Cherche recursivement une valeur dans l'arbre et la supprime
 *             si compteur est >1 va decrementer le compteur
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 *          int val : La valeur a supprime
 * Sortie : Noeud* l'arbre apres la suppression
 */
Noeud *supp_arbre_no(Noeud *root, int val)
{
    int entier;
    //si la valeur n'est pas trouve
    if (!root)
    {
        return ((Noeud*) NULL);
    }
    //si le Noeud courant a info == val
    if(root->info== val)
    {
        if (root->cpt > 1)
        {
            (root->cpt)--; //supprimer une des repetition
            return ((Noeud*) root);
        }

        else {
            //chercher le nombre des fils
            Noeud *tmp = NULL;
            entier= fils_existe(root);
            switch(entier)
            {
                case 0 : free(root);
                    return ((Noeud*) tmp);
                case 1:  //On Remplace ce Noeud par son fils Droit
                    tmp = root->drt;
                    free(root);
                    return ((Noeud*) tmp);
                    //On Remplace ce Noeud par son fils gauche
                case 2 :tmp = root->gch;
                    free(root);
                    return ((Noeud*) tmp);
                    //On Remplace ce Noeud par son fils gauche
                    //le plus a gauche
                case 3 :tmp=feuille_gch(root);
                    root->info=tmp->info;
                    root->cpt=tmp->cpt;
                    root->gch=supp_arbre_no(root->gch,tmp->info);
                    return ((Noeud*)root);
            }
        }
    }
    else
        root->gch = supp_arbre_no(root->gch, val);

    root->drt = supp_arbre_no(root->drt, val);
}

//**********************************************************************************
/***********************************************************************************
 * Nom : Noeud *supp_def_arbre_no(Noeud *root, int val)
 *             Cherche recursivement une valeur dans l'arbre et la supprime
 *             meme si le compteur est >1
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 *          int val : La valeur a supprime
 * Sortie : Noeud* l'arbre apres la suppression
 */
Noeud *supp_def_arbre_no(Noeud *root, int val)
{
    int entier;
    //si la valeur n'est pas trouve
    if (!root)
        return ((Noeud*) root);

    //si le Noeud courant a info == val
    if(root->info== val)
    {
        Noeud *tmp = NULL;
        entier= fils_existe(root);
        switch(entier)
        {
            case 0 :free(root);
                return ((Noeud*) tmp);
            case 1:  //On Remplace ce Noeud par son fils Droit
                tmp = root->drt;
                free(root);
                return ((Noeud*) tmp);
                //On Remplace ce Noeud par son fils gauche
            case 2 :tmp = root->gch;
                free(root);
                return ((Noeud*) tmp);
                //On Remplace ce Noeud par son
                //fils gauche le plus a gauche
            case 3 :tmp=feuille_gch(root);
                root->info=tmp->info;
                root->cpt=tmp->cpt;
                root->gch=supp_arbre_no(root->gch,tmp->info);
                return ((Noeud*)root);
                break;
        }
    }
    else
    {
        root->gch = supp_arbre_no(root->gch, val);
        root->drt = supp_arbre_no(root->drt, val);
    }
}



//**********************************************************************************
/************************************************************************
 * Nom : int profondeur_arbreNO(Noeud *root)
 *             Calcule recursivement la profondeur de l'arbre
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 * Sortie : int la profondeur dans l'arbre
 */
int profondeur_arbreNO(Noeud *root)
{
    if (!root)
        return ((int)0);
    int drt = profondeur_arbreNO(root->drt) + 1;
    int gch = profondeur_arbreNO(root->gch) + 1;
    return (drt>gch)?drt:gch;
}




//**********************************************************************************
/***********************************************************************************
 * Nom : int max_arbNO(Noeud *root)
 *             Cherche recursivement la valeur maximal
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 * Sortie : int la valeur maximal dans l'arbre
 */
int max_arbNO(Noeud *root)
{
    int drt, gch;

    if (root->drt)
    {
        drt = max_arbNO(root->drt);
        if (root->gch) {
            gch = max_arbNO(root->gch);
            if ((drt > gch) && (drt > root->info))
                return drt;
            if (gch > root->info)
                return gch;
            return root->info;
        }
        if (drt > root->info)
            return drt;
        return root->info;
    }

    if (root->gch)
    {
        gch = max_arbNO(root->gch);
        return gch;
    }
    return root->info;

}




//**********************************************************************************
/**********************************************************************************
 * Nom : void min_arbNO(Noeud *root,int *min)
 *             Cherche recursivement la valeur maximal
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 *          int *min:la valeur min dans l'arbre
 * Sortie : rien
 */
void min_arbNO(Noeud *root, int *min)
{
    int drt = max_arbNO(root),
    gch = max_arbNO(root);
    if(root)
    {
        *min=root->info;
        min_arbNO(root->drt,&drt) ;
        min_arbNO(root->gch,&gch) ;
        if(*min>drt) *min=drt;
        if(*min>gch) *min=gch;
    }
}


//**********************************************************************************
/***********************************************************************************
 * Nom : int largeur_arbreNO(Noeud *root, const int *niveaux, int profondeur)
 *             cherche la largeur maximal d'arbre donnee
 *             largeur : le nombre de neoud maximal dans un niveau
 * Entree : const int *niveaux : la largeur d'arbre pur chaque niveau
 *          int profondeur : profondeur maximale de l'arbre
 * Sortie : entier represent la largeur de l'arbre
 */
int largeur_arbreNO(Noeud *root, const int *niveaux, int profondeur)
{
    if (!root)
        return ((int)0);
    int i,
            max = *niveaux;
    for (i = 0; i < profondeur; i++)
        if (max < *(niveaux+i))
            max = *(niveaux+i);
    return ((int) max);
}
//**********************************************************************************
/***********************************************************************************
 * Nom : largeur_max_arbreNO(Noeud *root)
 *             Cherche recursivement la largeur maximal de l'arbre
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 * Sortie : int la largeur maximal dans l'arbre
 */
int largeur_max_arbreNO(Noeud *root)
{
    if (!root)
        return ((int) 0);
    int prof = profondeur_arbreNO(root);
    return ((int) (pow(2, prof-1)));
}


//**********************************************************************************
/***********************************************************************************
 * Nom : void largeur_par_niveau_arbreNO(Noeud *root , int *niveaux, int ligne)
 *             calcule recursivement les largeurs d'arbre pour chaque niveau
 *             largeur : le nombre de neoud dans chaque niveau
 * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
 *          int *niveaux : largeur pour chaque niveau
 *                        initialise à {0,0,...}
 *                        eventielement contient les largeur de chaque
 *          int ligne : le niveau du noeud courant
 * Sortie : rien
 */
void largeur_par_niveau_arbreNO(Noeud *root , int *niveaux, int ligne)
{
    if (!root)
        return;

    (*(niveaux + ligne))++;
    largeur_par_niveau_arbreNO(root->gch, niveaux, ++ligne);
    largeur_par_niveau_arbreNO(root->drt, niveaux, ligne);
}



//**********************************************************************************
/***********************************************************************************
 * Nom : void assign_val_to_Mtx(PNode *root, int *matrice, int cols,
 *                              int line, int col, int ss)
 *             attribue les noeuds dans l'arbre
 *             au champs correspondent dans la matrice
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *          int *matrice : ou on attribue les valeur des noeuds
 *          int cols : nombre de colonnes de la matrice
 *          int line : ligne courant
 *          int col : colonne courant
 *          int ss : deplacement du colonne du fils par apport au parent
 * Sortie : rien
 */
void assign_val_to_MtxNO(Noeud *root, int *matrice, int cols, int line, int col, int ss) {
    if (!root)
        return;
    *((matrice+(line*cols))+col) = root->info;

    assign_val_to_MtxNO(root->drt, matrice, cols, line + 1, col + ss, ss/2);
    assign_val_to_MtxNO(root->gch, matrice, cols, line + 1, col - ss, ss/2);

}



//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_arbre_Real(PNode *root)
 *             afficher l'arbre comme arbre reel verticalement
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_arbreNO_Real(Noeud *root) {
    int prof = profondeur_arbreNO(root);
    int segma = 0;
    int tmp;
    for (int i = 0; i < prof; ++i) {
        tmp = (int)pow(2, i);
        segma+=tmp;
    }

    int matrice[prof][segma];
    int *pt = (int *) matrice;

    for (int i = 0; i < prof; ++i)
        for (int j = 0; j < segma; ++j)
            matrice[i][j] = -99;

    assign_val_to_MtxNO(root, pt, segma,  0, (segma/2), (segma/2+1)/2);

    printf("\n*******************************\n");
    for (int i = 0; i < prof; ++i) {
        for (int j = 0; j < segma; ++j) {
            if (matrice[i][j] == -99)
                printf("**");
            else
                printf("%02d", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n*******************************\n");
}




/***********************************************************************************
    * Nom : Noeud *menu_arb_non_ord(Noeud *root)
    *             afficher le menu des traitement
    *             possible a effectue sur un arbre
    * Entree : Noeud *root : l'arbre sur lequel on applique le traitement
    * Sortie : Noeud* : l'arbre apres les traitements
    */
Noeud *menu_arb_non_ord(Noeud *root)
{
    int choix, i,tmp, tmp2, *array = NULL;
    Noeud *ntmp = NULL;
    do {
        choix = -1;
        fflush(stdin);
        printf("********************************************************"

        "\n1  --> Affichage Prefixe"
               "\n2  --> Affichage Infixe"
               "\n3  --> Affichage Postfixe"
               "\n4  --> Inserer Element manuellement"
               "\n5  --> Inserer Element automatiquement"
               "\n6  --> Suppression un occurrence"
               "\n7  --> Suppression definitivement"
               "\n8  --> Profondeur de l'arbre"
               "\n9  --> Largeur de l'arbre"
               "\n10 --> Taille de l'arbre"
               "\n11 --> Maximum de l'arbre"
               "\n12 --> Minimum de l'arbre"
               "\n13 --> affichage arbre reel"
               "\n0  --> Retourne au menu principal"
        );
        printf("\n\n>>>>  ");
        scanf("%d", &choix);
        fflush(stdin);
        switch(choix) {
            case 0:
                break;

            case 1:
                if (!root)
                    printf("\n\nArbre est vide\n\n");
                else
                {
                    printf("\n\nAffichage Prefixe : \n");
                    affiche_prefixeNO(root);
                    printf("\n\n");
                }
                break;
            case 2:
                if (!root)
                    printf("\n\nArbre est vide\n\n");
                else {
                    printf("\n\nAffichage Infixe : \n");
                    affiche_infixeNO(root);
                    printf("\n\n");
                }

                break;
            case 3:
                if (!root)
                    printf("\n\nArbre est vide\n\n");
                else {
                    printf("\n\nAffichage Postfixe : \n");
                    affiche_postfixeNO(root);
                    printf("\n\n");
                }
                break;
            case 4:
                printf("\n\nEntrer la valeur a inseree: ");
                scanf("%d", &tmp);getchar();

                root=insert_arb_no(root, tmp);
                printf("\n\nInsertion bien effectuee\n\n\n");
                break;
            case 5:printf("\n\nEntrer la valeur a inseree: ");
                scanf("%d", &tmp);getchar();
                ntmp = recherche_elm(root, tmp);
                if (!ntmp)
                    root = insertion_automatique(root, tmp);
                else
                    ntmp->cpt++;
                printf("\n\nInsertion bien effectuee\n\n\n"); break;
            case 6:
            case 7:
                printf("Entrer la valeur a supprime : ");
                scanf("%d", &tmp);getchar();
                (choix == 6)? (root=supp_arbre_no(root, tmp)): (root=supp_def_arbre_no(root, tmp));
                printf("\nTraitement effectue\n");
                break;

            case 8:
                printf("\n\nProfondeur de l'arbre : %d\n\n", profondeur_arbreNO(root));
                break;
            case 9:
                tmp = profondeur_arbreNO(root);
                array = (int *) malloc(sizeof (int) * tmp);
                for (i = 0; i < tmp; ++i)
                    (*(array+i)) = 0;
                largeur_par_niveau_arbreNO(root, array, 0);
                tmp2 = largeur_arbreNO(root, array, tmp);
                free(array);
                array = NULL;
                printf("\n\nLargeur de l'arbre : %d\n\n", tmp2);
                break;

            case 10:
                tmp=size_arbreNO(root);
                printf("\n\nLa Taille de l'arbre : %d\n\n", tmp);
                break;
            case 11:
                if (!root)
                    printf("\n\nArbre est vide\n\n");
                else
                {
                    tmp=max_arbNO(root);
                    printf("\n\nLe Maximum de l'arbre : %d\n\n", tmp);
                }
                break;

            case 12:
                if (!root)
                    printf("\n\nArbre est vide\n\n");
                else
                {tmp=root->info;
                    min_arbNO(root,&tmp);
                    printf("\n\nLe Minimum de l'arbre : %d\n\n", tmp);
                }
                break;
            case 13:
                if (!root)
                    printf("\n\nArbre est vide\n\n");
                else
                    affiche_arbreNO_Real(root);
                break;
            default:
                printf("\n\nErreur: Choix Invalide!\n");
        }

        if (choix) getch();
    } while(choix != 0);
    return ((Noeud*) root);
}


