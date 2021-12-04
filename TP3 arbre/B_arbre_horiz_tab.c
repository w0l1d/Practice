//
// Created by W0L1D on 11/23/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_ELEMS 50

typedef struct TNd {
    int info; //information du noeud
    int cpt; //nombre de repetition de cette info
    int gch; //indice du fils gauche
    int drt; //indice du fils gauche
}TNode;

typedef struct Tree {
    TNode nodes[MAX_ELEMS]; // tableau des Noeuds de l'arbre
    int root; // indice de la racine
    int nbElem; // nombre de Noeuds
}Tree;

//**********************************************************************************
/*************************************************************
 * Nom : Tree *init_Arbre_Tab()
 *             Initialisation de l'arbre
 * Entree : rien
 * Sortie : Arbre (Tree) Initialise
 */
Tree *init_Arbre_Tab() {
    Tree *tree = NULL;
    tree = (Tree*) malloc(sizeof (Tree));
    if (!tree)
    {
        printf("Erreur d'allocation de memoire");
        exit(-1);
    }
    tree->nbElem = 0;
    tree->root = -1;
    return ((Tree*) tree);
}




//**********************************************************************************
/***********************************************************************************
 * Nom : PNode* insert_Pt(PNode *root, int val)
 *             Insert recursivement un element dans l'arbre dans la position correcte
 * Entree : Tree *arb : l'arbre dans lequel on insert l'element
 *          int val : la valeur a inserer
 *          int pos : position courant
 * Sortie : -1 si l'arbre n'existe pas
 *           1 si l'insertion est effectuee
 */
int insert_Tab(Tree *arb, int val, int pos)
{
    //l'arbre n'existe pas
    if (!arb)
        return ((int) -1);
    TNode *tmp = NULL, *tmp_pos = NULL;

    //l'arbre est vide
    if (!arb->nbElem) {
        arb->root = 0;
        tmp = &(arb->nodes[0]);
        tmp->cpt = 1;
        tmp->info = val;
        tmp->gch = -1;
        tmp->drt = -1;
        arb->nbElem++;
        return ((int) 1);
    }

    tmp_pos = &(arb->nodes[pos]);

    //insertion a gauche
    if (tmp_pos->info > val) {

        //Noeud n'a pas de gauche
        if (tmp_pos->gch == -1)
        {
            int elem_indice = arb->nbElem++;
            tmp_pos->gch = elem_indice;
            tmp = &(arb->nodes[elem_indice]);
            tmp->cpt = 1;
            tmp->info = val;
            tmp->gch = -1;
            tmp->drt = -1;
            return ((int) 1);
        }
        return insert_Tab(arb, val, tmp_pos->gch);
    }

    //insertion a droit
    else if (tmp_pos->info < val) {

        //Noeud n'a pas de droit
        if (tmp_pos->drt == -1)
        {
            int elem_indice = arb->nbElem++;
            tmp_pos->drt = elem_indice;
            tmp = &(arb->nodes[elem_indice]);
            tmp->cpt = 1;
            tmp->info = val;
            tmp->gch = -1;
            tmp->drt = -1;
            return ((int) 1);
        }
        return insert_Tab(arb, val, tmp_pos->drt);
    } else {
        tmp_pos->cpt++;
        return ((int) 1);
    }
}



//**********************************************************************************
/*******************************************************************
 * Nom : void aff_prefixer_Tab(Tree *arb, int pos)
 *             Affiche prefixer recursivement les element de l'arbre
 * Entree : Tree *arb : l'arbre dans lequel on insert l'elementt
 *          int pos : position courant
 * Sortie : rien
 */
void aff_prefixer_Tab(Tree *arb, int pos)
{
    if (!arb) {
        printf("\n Arbre n'existe pas\n");
        return;
    }

    if (!arb->nbElem) {
        printf("\nArbre est vide\n");
        return;
    }
    if (pos == -1)
        return;

    TNode *tmp = NULL;
    tmp = &(arb->nodes[pos]);

    printf("%d (%d)\t", tmp->info, tmp->cpt);
    aff_prefixer_Tab(arb, tmp->gch);
    aff_prefixer_Tab(arb, tmp->drt);
}


//**********************************************************************************
/******************************************************************
 * Nom : void aff_infixer_Tab(Tree *arb, int pos)
 *             Affiche infixer recursivement les element de l'arbre
 * Entree : Tree *arb : l'arbre dans lequel on insert l'element
 *          int pos : position courant
 * Sortie : rien
 */
void aff_infixer_Tab(Tree *arb, int pos)
{
    if (!arb) {
        printf("\n Arbre n'existe pas\n");
        return;
    }

    if (!arb->nbElem) {
        printf("\nArbre est vide\n");
        return;
    }
    if (pos == -1)
        return;

    TNode *tmp = NULL;
    tmp = &(arb->nodes[pos]);

    aff_infixer_Tab(arb, tmp->gch);
    printf("%d (%d)\t", tmp->info, tmp->cpt);
    aff_infixer_Tab(arb, tmp->drt);
}


//**********************************************************************************
/*********************************************************************
 * Nom : void aff_postfixer_Tab(Tree *arb, int pos)
 *             Affiche postfixer recursivement les element de l'arbre
 * Entree : Tree *arb : l'arbre dans lequel on insert l'element
 *          int pos : position courant
 * Sortie : rien
 */
void aff_postfixer_Tab(Tree *arb, int pos)
{
    if (!arb) {
        printf("\n Arbre n'existe pas\n");
        return;
    }

    if (!arb->nbElem) {
        printf("\nArbre est vide\n");
        return;
    }
    if (pos == -1)
        return;

    TNode *tmp = NULL;
    tmp = &(arb->nodes[pos]);

    aff_postfixer_Tab(arb, tmp->gch);
    aff_postfixer_Tab(arb, tmp->drt);
    printf("%d (%d)\t", tmp->info, tmp->cpt);
}




//**********************************************************************************
/***********************************************************************************
 * Nom : int profondeur_arbreTab(Tree *arb, int pos)
 *             calcule récursivement la profondeur de l'arbre
 *
 * Entree : Tree *arb : l'arbre sur lequel on applique le traitement
 *          int pos : position de l'element courant dans le tableau
 *
 * Sortie : int la profondeur dans l'arbre
 */
int profondeur_arbreTab(Tree *arb, int pos) {

    TNode *tmp = NULL;
    tmp = &(arb->nodes[pos]);

    if (pos == -1)
        return ((int) 0);

    int drt = profondeur_arbreTab(arb, tmp->drt) + 1;
    int gch = profondeur_arbreTab(arb, tmp->gch) + 1;
    return (drt>gch)?drt:gch;
}



//**********************************************************************************
/***********************************************************************************
 * Nom : void assign_val_to_Mtx_tab(Tree *arb,int pos, int *matrice,
 *                                  int cols, int line, int col, int ss)
 *             attribue les noeuds dans l'arbre
 *             au champs correspondent dans la matrice
 * Entree : Tree *arb : l'arbre sur lequel on applique le traitement
 *          int pos : position de l'element courant dans le tableau
 *          int *matrice : ou on attribue les valeur des noeuds
 *          int cols : nombre de colonnes de la matrice
 *          int line : ligne courant
 *          int col : colonne courant
 *          int ss : deplacement du colonne du fils par apport au parent
 * Sortie : rien
 */
void assign_val_to_Mtx_tab(Tree *arb,int pos, int *matrice, int cols, int line, int col, int ss) {
    if (!(pos+1))
        return;

    TNode *tmp = NULL;
    tmp = &(arb->nodes[pos]);

    *((matrice+(line*cols))+col) = tmp->info;
    assign_val_to_Mtx_tab(arb, tmp->drt, matrice, cols, line + 1, col + ss, ss/2);
    assign_val_to_Mtx_tab(arb, tmp->gch, matrice, cols, line + 1, col - ss, ss/2);

}



//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_arbre_tab_Real(PNode *root)
 *             afficher l'arbre comme arbre reel verticalement
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_arbre_tab_Real(Tree *root) {
    int prof = profondeur_arbreTab(root, root->root);
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

    assign_val_to_Mtx_tab(root, root->root, pt, segma,  0, (segma/2), (segma/2+1)/2);

    printf("\n********************************\n\n");
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






Tree *b_arbreTab_menu(Tree *arb) {
        int choix, tmp, tmp2;
        if (!arb)
            arb = init_Arbre_Tab();
        do {
            choix = -1;
            fflush(stdin);
            printf("**************************************************************************"
                   "\n1  --> Affichage vertical d'arbre"
                   "\n2  --> Affichage Prefixer"
                   "\n3  --> Affichage Infixer"
                   "\n4  --> Affichage Postfixer"
                   "\n5  --> Inserer Element"
                   "\n6  --> Profondeur d'arbre"
                   "\n0  --> Retourner"
                   );
            printf("\n\n>>>>  ");
            scanf("%d", &choix);
            switch(choix) {
                case 0:
                    break;
                case 1:
                    affiche_arbre_tab_Real(arb);
                    break;
                case 2:
                    aff_prefixer_Tab(arb, arb->root);
                    break;
                case 3:
                    aff_infixer_Tab(arb, arb->root);
                    break;
                case 4:
                    aff_postfixer_Tab(arb, arb->root);
                    break;
                case 5: {
                    printf("\nEntrer l'element a inserer : ");
                    scanf("%d", &tmp);
                    tmp2 = insert_Tab(arb, tmp, arb->root);
                    if (tmp2 == -1) {
                        printf("\nErreur : Arbre n'est pas initialise\n");
                    }
                    if (tmp2 == 1) {
                        printf("\nInsertion effectuée\n");
                    }
                }
                    break;

                case 6:
                    tmp = profondeur_arbreTab(arb, arb->root);
                    printf("\nProfondeur de l'arbre : %d\n", tmp);
                    break;
                default:
                    printf("\n\nErreur: Choix Invalide!\n");
            }

            if (choix) getch();
            fflush(stdin);
        } while(choix != 0);
        return ((Tree*) arb);
    }

