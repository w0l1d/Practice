//
// Created by W0L1D on 12/4/2021.
//

#ifndef PRACTICE_STRUCTURES_H
#define PRACTICE_STRUCTURES_H

#define MAX_ELEMS 30


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


typedef struct FileTab
{
    int tab[MAX_ELEMS]; // les elements de la file
    int tete; //indique la tete de la file
    int queue; //indique le queue de la file
    int taille; //indique la taille de la file

} FileTab;


typedef struct TPile
{
    int tab[MAX_ELEMS];
    int sommet; // indique l'index du dernier element
} TPile;


typedef struct TListe
{
    int tab[MAX_ELEMS];
    int nbr_elem;
} TListe;
#endif //PRACTICE_STRUCTURES_H
