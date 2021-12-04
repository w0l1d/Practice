//
// Created by W0L1D on 12/4/2021.
//

#ifndef PRACTICE_FONCTIONS_H
#define PRACTICE_FONCTIONS_H

#define MAX_ELEMS 30

typedef struct TListe
{
    int tab[MAX_ELEMS];
    int nbr_elem;
} TListe;

typedef struct Cellule
{
    int val;
    struct Cellule *svt;
}Cellule;



TListe* create_TListe();
TListe* init_TListe(TListe *liste);
int inserer_queue_TListe(TListe *liste, int val);
int supprimer_position(TListe *liste, int pos);
int affiche_liste(TListe *liste);

int inserer_position(TListe *liste, int val, int pos);
int inserer_tete_TListe(TListe *liste, int val);


Cellule * creer_Pliste(int elem,int *etat);
Cellule *inserer_queue_PList(Cellule *list, int val, int *etat);
Cellule * inserer_pos_PList(Cellule* list,int pos, int elem,int *etat);
int taille_pliste(Cellule *list);



#endif //PRACTICE_FONCTIONS_H
