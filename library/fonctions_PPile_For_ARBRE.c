// declaration des Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"




PAPile* init_PAPile(struct Nd *node)
{
    PAPile *pile = (PAPile*) malloc(sizeof(PAPile));

    if (!pile)
    {
        printf("\n\nErreur d'allocation de la memoire\n\n");
        exit(0);
    }

    pile->node = node;
    pile->svt = NULL;
    return pile;
}


PAPile* empiler_PAPile(PAPile *pile, struct Nd *node)
{
    PAPile *nouveau = init_PAPile(node);

    nouveau->svt = pile;
    return ((PAPile*) nouveau);
}

PAPile* depiler_PAPile(PAPile *pile)
{
    if (!pile) // si la pile n'exist pas
        return ((PAPile*) NULL);

    PAPile *tmp;
    //sauvegarder la valeur a depile
    tmp = pile;
    //detacher la valeur depile de la pile
    pile = pile->svt;
    //liberer la mermoire alloue a la valeur depilee
    free(tmp);

    return ((PAPile*) pile);
}


