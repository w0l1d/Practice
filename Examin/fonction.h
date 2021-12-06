#include "fonction.c"

PPile *Empiler_PPile(PPile *Mapile, int Elem);
PPile *Depiler_PPile(PPile *Mapile);
PPile *Inserer_PPile_pos(PPile *Mapile, int Elem,int pos);
PPile *Supprimer_PPile_pos(PPile *Mapile,int pos);
PPile *Supprimer_PPile_val(PPile *Mapile, int val);
PPile *Supprimer_PPile_val_ord(PPile *Mapile, int val);
int Max_PPile(PPile *Mapile);
int Min_PPile(PPile *Mapile);
int Sommet_PPile(PPile Mapile);
void Affiche_PPile(PPile *Mapile);
int Acceder_Pile(PPile *Mapile);
void Affiche_Ppile(PPile *Mapile);
void Afficher_Ppile(PPile* Pile);
int Taile_PPile(PPile *Mapile);


int Init_PFile(PFile *Mapile);
PFile *cree_Pfile();
int Est_vide_PFile(PFile Mafile);
PFile *Enfiler_PFile(PFile *Mafile, int Elem);
int Defiler_PFile(PFile *Mafile);
void Afficher_PFile(PFile *Mafile);
PFile *Inserer_PFile_pos(PFile *Mafile, int Elem, int pos);
int Taile_PFile(PFile *Mafile);
PFile *Supprimer_PFile_pos(PFile *Mafile, int pos);
PFile *Supprimer_PFile_val(PFile *Mafile, int val);
PFile *Supprimer_PFile_val_ord(PFile *Mafile, int val);
int Max_PFile(PFile *Mafile);
int Min_PFile(PFile *Mafile);



Cellule *Cree_Cellule(int val);
int Taile_liste(Cellule *pliste);
Cellule *Inserer_pos_pliste(Cellule *pliste, int pos, int Elem);
Cellule *Supprimer_pos_pliste(Cellule *pliste, int pos);
Cellule *Supprimer_tete_pliste(Cellule *pliste);
Cellule *Supprimer_fin_pliste(Cellule *pliste);
Cellule* Supprimer_val_pliste(Cellule* Maliste,int val);
Cellule *Inserer_tete_pliste(Cellule *pliste, int val);
Cellule *Inserer_fin_pliste(Cellule *pliste, int val);
int rechrche_Elem_pliste(Cellule *pliste, int Elem);
int Nbr_Occurence_Elem_pliste(Cellule *pliste, int Elem);
void Afficher_pliste(Cellule *pliste);
Cellule *Inserer_Options_pliste(Cellule *pliste, int val, int pos, int choix);
Cellule *Suprimer_Options(Cellule *pliste, int choix, int pos,int val);




Maliste *Cree_Liste();

int Taille_liste(Maliste liste);

int Init_liste(Maliste liste);

int Insert_liste(Maliste *pliste, int Elem);

int Supprimer_pos_liste(Maliste *pliste, int pos);

int Supprimer_val_liste(Maliste *liste, int val);

int Insert_pos_liste(Maliste *pliste, int pos, int Elem);

int Suprimer_Options_liste(Maliste *liste, int choix, int pos,int val);

int Inserer_Options_liste(Maliste *liste, int val, int pos, int choix);

void Afficher_liste(Maliste *liste);

int Nbr_Occurence_Elem_liste(Maliste liste, int val);

int rechrche_Elem(Maliste liste, int val);

TPile *Cree_TPile();
int Init_TPile(TPile *Mapile);
int Taille_TPile(TPile *Mapile);
int Est_saturer_TPile(TPile Mapile);
int Inserer_TPile(TPile *Mapile, int Elem);
int Depiler_TPile(TPile *Mapile);
int Sommet_TPile(TPile Mapile);
void Affiche_TPile(TPile Mapile);
TFile *Cree_TFile();
int Init_TFile(TFile *Mafile);
int Enfiler_TFile(TFile *Mafile, int Elem);
int Defiler_TFile(TFile *Mafile);
int Taile_TFile(TFile Mafile);
int tasser_TFile(TFile *Mafile);

void Afficher_TFile(TFile Mafile);


Noeud *Cree_Noeud(int val);
void prefixe(Noeud *Arbre);
void infixe(Noeud *Arbre);
void postfixe(Noeud *Arbre);
Noeud *Insertion_Arbre_Horz(Noeud *Arbre, int val);
int taille_Arbre(Noeud *Arbre);
int Max_Element_Arbre(Noeud *Arbre);
int Min_Element_Arbre(Noeud *Arbre);
Noeud *remplacer_arbre(Noeud *org, Noeud *noeudr);
Noeud *supprimer_Arbre_Horz(Noeud *Arbre, int val);
void print2DUtil(Noeud *Arbre, int space);
void print2D(Noeud *Arbre);


void affiche_prefixeNO(Noeud *arbre);
void affiche_infixeNO(Noeud *arbre);
void affiche_postfixeNO(Noeud *arbre);
Noeud *recherche_elm(Noeud *arbre,int val);
Noeud* insertion_automatique(Noeud *arbre, int val);
Noeud *supp_arbre_no(Noeud *arbre, int val);
int size_arbreNO(Noeud* arbre);
int max_arbNO(Noeud *arbre);
void min_arbNO(Noeud *arbre, int *min);
void affiche_arbreNO_Real(Noeud *arbre);
int profondeur_arbreNO(Noeud *arbre);
void assign_val_to_MtxNO(Noeud *arbre, int *matrice, int cols, int line, int col, int ss);
Noeud *supp_def_arbre_no(Noeud *Arbre, int val);
Noeud* feuille_gch(Noeud *Arbre);
int fils_existe(Noeud *Arbre);
int fils_val_existe(Noeud *Arbre, int val);


PFile * trans_PPile_PFile(PPile* Mapile);
PPile * trans_PFile_PPile(PFile* Mafile);
Noeud * trans_PFile_ArbreBinOrd(PFile* Mafile);
Maliste *trans_PListe_TListe(Cellule *pliste);
Cellule *trans_TListe_PListe(Maliste *TabListe);
PPile *trans_PListe_PPile(Cellule *Maliste);



Maliste *Remplir_TListe_tableau(int Tab[], int Nbr);
Cellule *Remplir_PListe_tableau(int Tab[], int Nbr);
PPile *Remplir_PPile_tableau(int Tab[], int Nbr);
PFile * Remplir_PFile_tableau(int Tab[], int Nbr);
Noeud * Remplir_ArbreBinOrdHorz_tableau(int Tab[], int Nbr);