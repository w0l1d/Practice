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
int supprimer_position_TListe(TListe *liste, int pos);
int affiche_tliste(TListe *liste);

int inserer_position_TList(TListe *liste, int val, int pos);
int inserer_tete_TListe(TListe *liste, int val);


Cellule * creer_Pliste(int elem);
Cellule *inserer_queue_PList(Cellule *list, int val);
Cellule * inserer_pos_PList(Cellule* list,int pos, int elem);
int taille_pliste(Cellule *list);
int affiche_plist(Cellule *list);
Cellule *trans_Tliste_Pliste(TListe *tl, Cellule *pl);
Cellule* supp_occ_elem_PList(Cellule *list,int val);


#endif //PRACTICE_FONCTIONS_H
