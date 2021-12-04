//
// Created by W0L1D on 12/4/2021.
//

#ifndef PRACTICE_STRUCTURES_H
#define PRACTICE_STRUCTURES_H

typedef struct Cellule
{
    int val;
    struct Cellule *svt;
}Cellule;

typedef struct PFile
{
    struct Cellule *tete;
    struct Cellule *queue;
    int taille;
}PFile;




#endif //PRACTICE_STRUCTURES_H
