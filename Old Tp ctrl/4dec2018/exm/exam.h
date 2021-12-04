#ifndef EXAM_H_INCLUDED
#define EXAM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
///structure d'une cellule
typdef struct cel
{
    int val;
    struct cel *svt;
}cellule;
///structure de la file
typdef struct
{
    cellule *debut;
    cellule *fin;
}file;
cellule *allouer_noeud(int val);
cellule *empiler(cellule *pile ,int val);
cellule *depiler(cellule *pile);
void defiler(file *f);



#endif // EXAM_H_INCLUDED
