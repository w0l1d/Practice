//
// Created by W0L1D on 12/5/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


Cellule* init_PPile(int val) {
    Cellule *pile = (Cellule*) malloc(sizeof(Cellule));

    if (!pile) {
        printf("\n\nErreur d'allocation de la memoire\n\n");
        exit(0);
    }

    pile->val = val;
    pile->svt = NULL;
    return pile;
}


Cellule* empiler_PPile(Cellule *pile, int val)
{
    Cellule *nouveau = init_PPile(val);

    nouveau->svt = pile;
    return ((Cellule*) nouveau);
}

Cellule* depiler_PPile(Cellule *pile)
{
    if (!pile) // si la pile n'exist pas
        return ((Cellule*) NULL);

    Cellule *tmp;
    //sauvegarder la valeur a depile
    tmp = pile;
    //detacher la valeur depile de la pile
    pile = pile->svt;
    //liberer la mermoire alloue a la valeur depilee
    free(tmp);

    return ((Cellule*) pile);
}



Cellule* vider_PPile(Cellule *pile)
{

    Cellule *tmp;

    while(pile) {
        tmp = pile;
        pile = pile->svt;
        free(tmp);
    }

    return ((Cellule*) NULL);
}



// taille pile avec pt
int taille_PPile(Cellule *pile)
{
    int size = 0;

    while (pile) {
        pile = pile->svt;
        size++;
    }

    return ((int)size);
}


Cellule* inverser_PPile(Cellule *pile)
{
    Cellule *tmp = NULL;

    while (pile)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }
    return tmp;
}


Cellule* supprimer_pos_PPile(Cellule *pile, int pos)
{
    //pile n'exist pas
    if (!pile)
    {
        printf("\nPile n'existe pas\n");
        return ((Cellule*) pile);
    }

    //supprimer le premier element
    if (pos == 1)
        return ((Cellule*) pile->svt);


    int indice = 1, size;
    Cellule *tmp = NULL;

    size = taille_PPile(pile);
    if ((pos < 1) || (size < pos))
    {
        printf("\nPosition est incorrecte\n");
        return ((Cellule*)pile);
    }

    while (indice < pos)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        indice++;
    }


    pile = depiler_PPile(pile);


    while (tmp)
    {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    return ((Cellule*) pile);
}




Cellule* supprimer_val_PPile(Cellule *pile, int val)
{

    Cellule *tmp = NULL;
    int val_depile,
        status = 0;

    if (!pile) {
        printf("\nPile est vide\n");
        return ((Cellule*) NULL);
    }

    while (pile)
    {
        val_depile = pile->val;
        pile = depiler_PPile(pile);

        if (val_depile == val)
        {
            status = 1;
            break;
        }
        else
            tmp = empiler_PPile(tmp, val_depile);
    }

    if (!status)
        printf("\nValeur n'est pas trouve\n");

    while (tmp)
    {
        val_depile = tmp->val;
        tmp = depiler_PPile(tmp);
        pile = empiler_PPile(pile, val_depile);
    }

    return ((Cellule*) pile);
}






Cellule* supprimer_all_val_PPile(Cellule *pile, int val)
{

    Cellule *tmp = NULL;
    int val_depile,
            status = 0;

    if (!pile) {
        printf("\nPile est vide\n");
        return ((Cellule*) NULL);
    }

    while (pile)
    {
        val_depile = pile->val;
        pile = depiler_PPile(pile);

        if (val_depile == val)
            status = 1;
        else
            tmp = empiler_PPile(tmp, val_depile);
    }

    if (!status)
        printf("\nValeur n'est pas trouve\n");

    while (tmp)
    {
        val_depile = tmp->val;
        tmp = depiler_PPile(tmp);
        pile = empiler_PPile(pile, val_depile);
    }

    return ((Cellule*) pile);
}



Cellule* empiler_pos_PPile(Cellule *pile, int pos, int val)
{
    //pile n'exist pas
    if (!pile) {
        printf("\nPile n'existe pas\n");
        return ((Cellule*) pile);
    }

    int indice = 1, size;
    Cellule *tmp = NULL;

    size = taille_PPile(pile);
    if ((pos < 1) || (size+1 < pos)) {
        printf("\nPosition est incorrecte\n");
        return ((Cellule*)pile);
    }

    while (indice < pos) {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        indice++;
    }

    pile = empiler_PPile(pile, val);

    while (tmp) {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    return ((Cellule*) pile);
}



Cellule* empiler_bon_pos_Decr_PPile(Cellule *pile, int val) {
    //pile est vide
    if (!pile) {
        printf("\nPile est vide\n");
        return ((Cellule*) pile);
    }

    Cellule *tmp = NULL;

    if (val > pile->val) {
        pile = empiler_PPile(pile, val);
        return ((Cellule*)pile);
    }

    while (val < pile->val) {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        if (!pile)
            break;
    }

    pile = empiler_PPile(pile, val);

    while (tmp) {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    return ((Cellule*) pile);
}



Cellule* max_val_PPile(Cellule *pile, int *max)
{
    //pile n'exist pas
    if (!pile)
    {
        printf("\nPile est vide\n");
        return ((Cellule*) pile);
    }

    int max_val;
    Cellule *tmp = NULL;
    max_val = pile->val;

    while (pile)
    {
        if (max_val < pile->val)
            max_val = pile->val;

        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }


    while (tmp)
    {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    *max = max_val;
    return ((Cellule*) pile);
}




Cellule* min_val_PPile(Cellule *pile, int *min)
{
    //pile n'exist pas
    if (!pile)
    {
        printf("\nPile est vide\n");
        return ((Cellule*) pile);
    }

    int min_val;
    Cellule *tmp = NULL;
    min_val = pile->val;

    while (pile)
    {
        if (min_val > pile->val)
            min_val = pile->val;

        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }

    while (tmp)
    {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    *min = min_val;
    return ((Cellule*) pile);
}







Cellule* affiche_PPile(Cellule *pile)
{
    //si la pile vide
    if (!pile)
    {
        printf("\nla Pile est vide\n");
        return pile;
    }
    Cellule *tmp = NULL;

    printf("\nles elements de la pile : \n");
    while (pile)
    {
        printf("%d\t", pile->val);
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }

    printf("\n");
    return inverser_PPile(tmp);
}





Cellule* affiche_PPile_principe(Cellule *pile, int *status)
{
    //si la pile vide
    if (!pile)
    {
        printf("\nla pile est vide\n");
        *status = 0;
        return pile;
    }


    Cellule *tmp;
    int val_depile;

    printf("\nle elements de la pile : \n");

    while (pile)
    {
        val_depile = pile->val;
        pile = depiler_PPile(pile);
        tmp = empiler_PPile(tmp, val_depile);
        printf("%d\t", val_depile);
    }
    printf("\n");


    while (tmp)
    {
        val_depile = tmp->val;
        tmp = depiler_PPile(tmp);
        pile = empiler_PPile(pile, val_depile);
    }

    *status = 1;
    return pile;
}


int handle_errors_PPile(int cd)
{
    switch (cd)
    {
        case 1:
            return 1;

        case 0:
            printf("\nLa pile est vide\n");
            break;

        case -1:
            printf("\nLa pile n'existe pas\n");
            break;

        case -2:
            printf("\nLa valeur n'est pas trouver\n");
            break;

        case -3:
            printf("\nLa position est incorrecte\n");
            break;

    }
    return 0;
}
