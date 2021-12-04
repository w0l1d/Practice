//
// Created by W0L1D on 11/30/2021.
//

#include <stdio.h>
#include <stdlib.h>



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "fonction_Pile_Pt.c"

typedef struct Nd {
    int info; //information du noeud
    int cpt; //nombre de repetition de cette info
    struct Nd *gch; //pointeur sur le fils gauche
    struct Nd *drt; //pointeur sur le fils gauche
}PNode;




//**********************************************************************************
/***********************************************************************************
 * Nom : PNode* create_PNodePt(int val)
 *             Insert recursivement un element dans
 *             l'arbre dans la position correcte
 * Entree : int val : la valeur du nouveau noeud
 * Sortie : PNode* : pointeur sur le noeud cree
 */
PNode* create_PNodePt(int val)
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
 * Nom : PNode* insert_Pt(PNode *root, int val)
 *             Insert recursivement un element dans
 *             l'arbre dans la position correcte
 * Entree : PNode *root : l'arbre dans lequel on insert l'element
 *          int val : la valeur a inserer
 * Sortie : PNode* : pointeur sur la racine de l'arbre apres l'insertion
 */
PNode* insert_Pt(PNode *root, int val)
{
    if (!root)
    {
        PNode *ne = create_PNodePt(val);
        return ((PNode*) ne);
    }
    if (root->info > val)
        root->gch = insert_Pt(root->gch, val);
    else if (root->info < val)
        root->drt = insert_Pt(root->drt, val);
    else
        root->cpt++;

    return ((PNode*)root);
}





//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_infixer(PNode *root)
 *             Affiche Infixer récursivement les elements de l'arbre
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : rien
 */
void affiche_infixer(PNode *root)
{
    if (!root)
        return;

    affiche_infixer(root->gch);
    printf("%d (%d)\t", root->info, root->cpt);
    affiche_infixer(root->drt);

}

void aff_infixer_arbre_pt(PNode* root) {
    if (!root)
        return;
    PPile *pile = NULL;
    PNode *node = NULL;
    node = root;


    while(node || pile) {
        if (node) {
            pile = empiler(pile, node);
            node = node->gch;
        }
        if (!node && pile)
        {
            node = pile->node;
            pile = depiler(pile);
            printf("%d (%d)\t", node->info, node->cpt);
            node = node->drt;
        }

    }

}

void aff_postfixer_arbre_pt(PNode *root) {
    PPile *pile = NULL;
    PNode *node = root;

    if (!root)
        return;


    do {
        while(node) {
            if (node->drt)
               pile = empiler(pile, node->drt);
            pile = empiler(pile, node);
            node = node->gch;
        }
        node = pile->node;
        pile = depiler(pile);

        if (node->drt && pile) {
            if ((node->drt->info) == (pile->node->info)) {
                pile = depiler(pile);
                pile = empiler(pile, node);
                node = node->drt;
                continue;
            }
        }
        printf("%d (%d)\t", node->info, node->cpt);
        node = NULL;
    }while(pile);

}


void affiche_postfixer(PNode *root)
{
    if (!root)
        return;

    affiche_postfixer(root->gch);
    affiche_postfixer(root->drt);
    printf("%d\t", root->info);

}


void  affiche_postfixe_no_itir(PNode *root)
{
    PPile *pile;
    pile=NULL;
    PNode *tmp;
    tmp=root;
    pile=empiler(pile,tmp);
    while(pile)
    {

        tmp=tmp->gch;
        while(tmp)
        {
            pile=empiler(pile,tmp);
            tmp=tmp->gch;
        }
        //tmp null
        tmp=pile->node;
        pile=depiler(pile);
        printf("%d (%d) \t", tmp->info, tmp->cpt);

        if(tmp->drt){
            tmp=tmp->drt;
            pile=empiler(pile,tmp);}
    }
}




void main() {
    PNode *root = NULL;
    root = insert_Pt(root, 10);
    root = insert_Pt(root, 5);
    root = insert_Pt(root, 14);
    root = insert_Pt(root, 12);
    root = insert_Pt(root, 16);
    root = insert_Pt(root, 4);
    root = insert_Pt(root, 9);
    root = insert_Pt(root, 1);
    printf("\n\nArbre en infixer iterative : \n");
    aff_infixer_arbre_pt(root);
    printf("\n");

    printf("\n\nArbre en infixer recursive : \n");
    affiche_infixer(root);
    printf("\n");

    printf("\n\nArbre en postfixer iterative : \n");
    aff_postfixer_arbre_pt(root);
    printf("\n");


    printf("\n\nArbre en postfixer recursive : \n");
    affiche_postfixer(root);
    printf("\n");

    printf("\n\nArbre en postfixer iterative 2 : \n");
    affiche_postfixe_no_itir(root);
    printf("\n");
}


