//
// Created by W0L1D on 11/23/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"
#include "fonctions_PPile_For_ARBRE.c"





//**********************************************************************************
/***********************************************************************************
 * Nom : PNode* create_PNode_Ord(int val)
 *             Insert recursivement un element dans
 *             l'arbre dans la position correcte
 * Entree : int val : la valeur du nouveau noeud
 * Sortie : PNode* : pointeur sur le noeud cree
 */
PNode* create_PNode_Ord(int val)
{
    PNode *ne = (PNode*) malloc(sizeof(PNode));
    if (!ne)
    {
        printf("\n\n Erreur d'allocation de memoire\n");
        exit(0);
    }

    ne->drt = ne->gch = NULL;
    ne->info = val;
    ne->cpt = 1;
    return ((PNode*) ne);
}


//**********************************************************************************
/***********************************************************************************
 * Nom : PNode* insert_PNode_Ord(PNode *root, int val)
 *             Insert recursivement un element dans
 *             l'arbre dans la position correcte
 * Entree : PNode *root : l'arbre dans lequel on insert l'element
 *          int val : la valeur a inserer
 * Sortie : PNode* : pointeur sur la racine de l'arbre apres l'insertion
 */
PNode* insert_PNode_Ord(PNode *root, int val)
{
    if (!root)
    {
        PNode *ne = create_PNode_Ord(val);
        return ((PNode*) ne);
    }
    if (root->info > val)
        root->gch = insert_PNode_Ord(root->gch, val);
    else if (root->info < val)
        root->drt = insert_PNode_Ord(root->drt, val);
    else
        root->cpt++;

    return ((PNode*)root);
}








///**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_prefixer_iter_PNode_Ord(PNode *root)
 *             Affichage Prefixer iterative des elements de l'arbre
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_prefixer_iter_PNode_Ord(PNode *root)
{
    if (!root)
        return;

    PAPile *pile = NULL;
    PNode *node = NULL;
    pile = empiler_PAPile(pile, root);

    while (pile) {
        node = pile->node;
        pile = depiler_PAPile(pile);
        printf("%d (%d)\t", node->info, node->cpt);
        if (node->drt)
            pile = empiler_PAPile(pile, node->drt);
        if (node->gch)
            pile = empiler_PAPile(pile, node->gch);
    }
}



///**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_prefixer_PNode_Ord(PNode *root)
 *             Affiche Prefixer récursivement les elements de l'arbre
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_prefixer_PNode_Ord(PNode *root)
{
    if (!root)
        return;

    printf("%d (%d)\t", root->info, root->cpt);
    affiche_prefixer_PNode_Ord(root->gch);
    affiche_prefixer_PNode_Ord(root->drt);

}




//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_postfixer_PNode_Ord(PNode *root)
 *             Affiche Postfixer récursivement les elements de l'arbre
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : rien
 */
void affiche_postfixer_PNode_Ord(PNode *root)
{
    if (!root)
        return;

    affiche_postfixer_PNode_Ord(root->gch);
    affiche_postfixer_PNode_Ord(root->drt);
    printf("%d\t", root->info);

}



//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_infixer_PNode_Ord(PNode *root)
 *             Affiche Infixer récursivement les elements de l'arbre
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : rien
 */
void affiche_infixer_PNode_Ord(PNode *root)
{
    if (!root)
        return;

    affiche_infixer_PNode_Ord(root->gch);
    printf("%d\t", root->info);
    affiche_infixer_PNode_Ord(root->drt);

}



//**********************************************************************************
/***********************************************************************************
 * Nom : int profondeur_PNode_Ord(PNode *root)
 *             calcule récursivement la profondeur de l'arbre
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : int la profondeur dans l'arbre
 */
int profondeur_PNode_Ord(PNode *root) {
    if (!root)
        return 0;
    int drt = profondeur_PNode_Ord(root->drt) + 1;
    int gch = profondeur_PNode_Ord(root->gch) + 1;
    return (drt>gch)? drt : gch;
}


//**********************************************************************************
/***********************************************************************************
 * Nom : void largeur_par_niveau_PNode_Ord(PNode *root , int *niveaux, int ligne)
 *             calcule récursivement les largeurs d'arbre pour chaque niveau
 *             largeur : le nombre de neoud dans chaque niveau
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *          int *niveaux : largeur pour chaque niveau
 *                        initialise à {0,0,...}
 *                        eventielement contient les largeur de chaque
 *          int ligne : le niveau du noeud courant
 * Sortie : rien
 */
void largeur_par_niveau_PNode_Ord(PNode *root , int *niveaux, int ligne) {
    if (!root)
        return;

    (*(niveaux + ligne))++;
    largeur_par_niveau_PNode_Ord(root->gch, niveaux, ++ligne);
    largeur_par_niveau_PNode_Ord(root->drt, niveaux, ligne);
}




//**********************************************************************************
/***********************************************************************************
 * Nom : int largeur_max_PNode_Ord(PNode *root)
 *             Cherche récursivement la largeur maximal de l'arbre
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : int la largeur maximal dans l'arbre
 */
int largeur_max_PNode_Ord(PNode *root) {
    if (!root)
        return ((int) 0);
    int prof = profondeur_PNode_Ord(root);
    return ((int) pow(2, prof-1));
}




//**********************************************************************************
/***********************************************************************************
 * Nom : int max_val_PNode_Ord(PNode *root)
 *             Cherche récursivement la valeur maximal
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 * Sortie : int la valeur maximal dans l'arbre
 */
int max_val_PNode_Ord(PNode *root) {
    if (!root->drt)
        return root->info;
    return max_val_PNode_Ord(root->drt);
}



//**********************************************************************************
/***********************************************************************************
 * Nom : PNode *max_noeud_PNode_Ord(PNode *root)
 *             Cherche récursivement le PNode avec la valeur maximal
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 * Sortie : PNode* pointeur sur le noeud maximal
 */
PNode *max_noeud_PNode_Ord(PNode *root) {
    if (!root)
        return ((PNode*) NULL);
    if (!root->drt)
        return root;
    return max_noeud_PNode_Ord(root->drt);
}


//**********************************************************************************
/***********************************************************************************
 * Nom : int min_val_PNode_Ord(PNode *root)
 *             Cherche récursivement la valeur minimal
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : int la valeur minimal dans l'arbre
 */
int min_val_PNode_Ord(PNode *root) {
    if (!root->gch)
        return root->info;
    return min_val_PNode_Ord(root->gch);
}




//**********************************************************************************
/***********************************************************************************
 * Nom : PNode *min_noeud_PNode_Ord(PNode *root)
 *             Cherche récursivement le PNode avec la valeur minimal
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : PNode* pointeur sur le noeud minimal
 */
PNode *min_noeud_PNode_Ord(PNode *root) {
    if (!root)
        return ((PNode*) NULL);
    if (!root->gch)
        return root;
    return min_noeud_PNode_Ord(root->gch);
}



PNode *parent_de_PNode_Ord(PNode *root, int val) {
    if (!root)
        return ((PNode*) NULL);
    if (root->drt)
        if (root->drt->info == val)
            return ((PNode*) root);
    if (root->gch)
        if (root->gch->info == val)
            return ((PNode*) root);

    if (root->info > val)
        return parent_de_PNode_Ord(root->gch, val);
    if (root->info < val)
        return parent_de_PNode_Ord(root->drt, val);

}




//**********************************************************************************
/***********************************************************************************
 * Nom : int largeur_PNode_Ord(PNode *root, const int *niveaux, int profondeur)
 *             cherche la largeur maximal d'arbre donnee
 *             largeur : le nombre de neoud maximal dans un niveau
 *
 * Entree : const int *niveaux : la largeur d'arbre pur chaque niveau
 *          int profondeur : profondeur maximale de l'arbre
 *
 * Sortie : entier represent la largeur de l'arbre
 */
int largeur_PNode_Ord(PNode *root, const int *niveaux, int profondeur) {
    if (!root)
        return 0;
    int i,
    max = *niveaux;
    for (i = 0; i < profondeur; i++)
        if (max < *(niveaux+i))
            max = *(niveaux+i);
    return ((int) max);
}


//**********************************************************************************
/***********************************************************************************
 * Nom : int size_PNode_Ord(PNode *root)
 *             calcule récursivement la taille d'un arbre donnee
 * Entree : PNode *root: l'arbre sur lequel on applique le traitement
 * Sortie : int : entier represente la taille de l'arbre
 */
int size_PNode_Ord(PNode *root)
{
    if (!root)
        return ((int) 0);

    int dt = size_PNode_Ord(root->gch),
    gch = size_PNode_Ord(root->drt);
    return ((int) dt + gch + (root->cpt));
}


//**********************************************************************************
/***********************************************************************************
 * Nom : PNode *supp_PNode_Ord(PNode *root,int val)
 *             Cherche récursivement une valeur dans l'arbre et la supprime
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *          int val : La valeur a supprime
 * Sortie : PNode* l'arbre apres la suppression
 */
PNode *supp_PNode_Ord(PNode *root, int val)
{
    //si la valeur n'est pas trouve
    if (!root)
    {
        printf("\nValeur n'est pas trouve\n");
        return ((PNode*) root);
    }

    if (val < root->info)
        //on cherche sur l'à gauche de l'arbre
        root->gch = supp_PNode_Ord(root->gch, val);

    else if (val > root->info)
        //on cherche sur l'à droite de l'arbre
        root->drt = supp_PNode_Ord(root->drt, val);

    else //si le PNode courant a info == val
    {
        //si la valeur est repetee : compteur > 1
        if (root->cpt > 1) {
            root->cpt--; //supprimer une des repetition
            return ((PNode*) root);
        }
        PNode *tmp = NULL;

        //PNode n'a pas de fils
        if (!root->drt && !root->gch)
        {
            free(root);
            return ((PNode*) tmp);
        }

            //PNode n'a pas de fils Droit
        else if (!root->drt)
        {
            //On Remplace ce PNode par son fils Gauche
            tmp = root->gch;
            free(root);
            return ((PNode*) tmp);
        }

            //PNode n'a pas de fils Gauche
        else if (!root->gch)
        {
            //On Remplace ce PNode par son fils Droit
            tmp = root->drt;
            free(root);
            return ((PNode*) tmp);
        }
            //Si le PNode a les fils droit et gauche
        else
        {
            //on cherche le minimun dans sous arbre du fils droit
            tmp = min_noeud_PNode_Ord(root->drt);
            //on replace le Nœud a supprimé par le minimum
            root->info = tmp->info;
            root->cpt = tmp->cpt;

            //pour eviter le decalage du compteur
            tmp->cpt = 1;
            //supprimer le minimum deja deplace
            root->drt = supp_PNode_Ord(root->drt, tmp->info);
        }
    }
    return ((PNode *) root);
}

//**********************************************************************************
/***********************************************************************************
 * Nom : PNode *supp_def_PNode_Ord(PNode *root, int val)
 *             Cherche récursivement une valeur dans l'arbre
 *             et la supprime definitivement
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *          int val : La valeur a supprime
 *
 * Sortie : PNode* l'arbre apres la suppression
 */
PNode *supp_def_PNode_Ord(PNode *root, int val)
{
    //si la valeur n'est pas trouve
    if (!root)
    {
        printf("\nValeur n'est pas trouve\n");
        return ((PNode*) root);
    }

    if (val < root->info)
        //on cherche sur l'à gauche de l'arbre
        root->gch = supp_PNode_Ord(root->gch, val);

    else if (val > root->info)
        //on cherche sur l'à droite de l'arbre
        root->drt = supp_PNode_Ord(root->drt, val);

    else //si le PNode courant a info == val
    {

        PNode *tmp = NULL;

        //PNode n'a pas de fils
        if (!root->drt && !root->gch)
        {
            free(root);
            return ((PNode*) tmp);
        }

            //PNode n'a pas de fils Droit
        else if (!root->drt)
        {
            //On Remplace ce PNode par son fils Gauche
            tmp = root->gch;
            free(root);
            return ((PNode*) tmp);
        }

            //PNode n'a pas de fils Gauche
        else if (!root->gch)
        {
            //On Remplace ce PNode par son fils Droit
            tmp = root->drt;
            free(root);
            return ((PNode*) tmp);
        }
            //Si le PNode a les fils droit et gauche
        else
        {
            //on cherche le minimun dans sous arbre du fils droit
            tmp = min_noeud_PNode_Ord(root->drt);


            //on replace le Nœud a supprimé par le minimum
            root->info = tmp->info;
            root->cpt = tmp->cpt;

            //supprimer le minimum deja deplace
            root->drt = supp_def_PNode_Ord(root->drt, tmp->info);
        }
    }
    return ((PNode *) root);
}





//**********************************************************************************
/***********************************************************************************
 * Nom : void assign_val_to_Mtx_PNode_Ord(PNode *root, int *matrice, int cols,
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
void assign_val_to_Mtx_PNode_Ord(PNode *root, int *matrice, int cols, int line, int col, int ss) {
    if (!root)
    return;
    *((matrice+(line*cols))+col) = root->info;

    assign_val_to_Mtx_PNode_Ord(root->drt, matrice, cols, line + 1, col + ss, ss/2);
    assign_val_to_Mtx_PNode_Ord(root->gch, matrice, cols, line + 1, col - ss, ss/2);

}



//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_arbre_Real_PNode_Ord(PNode *root)
 *             afficher l'arbre comme arbre reel verticalement
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_arbre_Real_PNode_Ord(PNode *root) {
    int prof = profondeur_PNode_Ord(root);
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

    assign_val_to_Mtx_PNode_Ord(root, pt, segma,  0, (segma/2), (segma/2+1)/2);

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



