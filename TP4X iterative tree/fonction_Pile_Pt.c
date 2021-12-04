// declaration des Bibliothèques
#include <stdio.h>
#include <stdlib.h>





struct Nd* create_PNodePt(int val);



typedef struct PPile {
    struct Nd *node;
    struct PPile *svt;
}PPile;



PPile* init_PPile(struct Nd *node)
{
    PPile *pile = (PPile*) malloc(sizeof(PPile));

    if (!pile)
    {
        printf("\n\nErreur d'allocation de la memoire\n\n");
        exit(0);
    }

    pile->node = node;
    pile->svt = NULL;
    return pile;
}


PPile* empiler(PPile *pile, struct Nd *node)
{
    PPile *nouveau = init_PPile(node);

    nouveau->svt = pile;
    return ((PPile*) nouveau);
}

PPile* depiler(PPile *pile)
{
    if (!pile) // si la pile n'exist pas
        return ((PPile*) NULL);

    PPile *tmp;
    //sauvegarder la valeur a depile
    tmp = pile;
    //detacher la valeur depile de la pile
    pile = pile->svt;
    //liberer la mermoire alloue a la valeur depilee
    free(tmp);

    return ((PPile*) pile);
}


