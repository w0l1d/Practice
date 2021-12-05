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


typedef struct PFile
{
    struct Cellule *tete;
    struct Cellule *queue;
    int taille;
}PFile;



typedef struct Nd {
    int info; //information du noeud
    int cpt; //nombre de repetition de cette info
    struct Nd *gch; //pointeur sur le fils gauche
    struct Nd *drt; //pointeur sur le fils gauche
}PNode;


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
Cellule* supp_pos_PList(Cellule * list, int pos);


Cellule* init_PPile(int val);
Cellule* empiler_PPile(Cellule *pile, int val);
Cellule* depiler_PPile(Cellule *pile);
Cellule* inverser_PPile(Cellule *pile);
Cellule* affiche_PPile(Cellule *pile);
Cellule* supprimer_pos_PPile(Cellule *pile, int pos);
Cellule* supprimer_all_val_PPile(Cellule *pile, int val);
Cellule *trans_Pliste_PPile(Cellule *list);


PFile* createPFile();
PFile *initialiser_PFile();
int PFile_existe (PFile *f);
int PFile_vide (PFile *f);
int enfiler_PFile(PFile *f, int val);
int defiler_PFile(PFile *f);
PFile *trans_PPile_PFile(Cellule* pile);
void afficher_PFile (PFile *f);
int supprimer_val_occur_PFile(PFile *file, int val);


PNode* create_PNodePt(int val);
PNode* insert_Pt(PNode *root, int val);
PNode* trans_PFile_Arb(PFile *file);
void affiche_prefixer(PNode *root);
PNode *min_noeud_arbrePt(PNode *root);
PNode *supp_arbrePt(PNode *root, int val);
PNode *supp_def_arbrePt(PNode *root, int val);

#endif //PRACTICE_FONCTIONS_H
