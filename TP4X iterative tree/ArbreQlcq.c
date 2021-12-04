//
// Created by W0L1D on 11/30/2021.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct NodeQcq {
    int info; //information du noeud
    int count; //compteur de repetition de l'info
    struct NodeQcq *brother; // pointeur vers le frere gauche
    struct NodeQcq *left; // pointeur veres le fils gauche
}NodeQcq;





NodeQcq* create_NodeQlq (int val) {
    NodeQcq *ne = malloc(sizeof (NodeQcq));
    if (!ne) {
        printf("\n\nErreur d'allocation de memoire\n");
        exit(0);
    }

    ne->brother = ne->left = NULL;
    ne->count = 1;
    ne->info = val;
}




NodeQcq *insert_NodeQlq(int val) {



}
