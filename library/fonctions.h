//
// Created by W0L1D on 12/5/2021.
//

#ifndef PRACTICE_FONCTIONS_H
#define PRACTICE_FONCTIONS_H


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


typedef struct TFile
{
    int tab[MAX_ELEMS]; // les elements de la file
    int tete; //indique la tete de la file
    int queue; //indique le queue de la file
    int taille; //indique la taille de la file

} TFile;


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


/******************************     START
 *  PILE avec POINTEURs
 *  ***************************
 */
Cellule* init_PPile(int val);
Cellule* empiler_PPile(Cellule *pile, int val);
Cellule* depiler_PPile(Cellule *pile);
Cellule* vider_PPile(Cellule *pile);
int taille_PPile(Cellule *pile);
Cellule* inverser_PPile(Cellule *pile);
Cellule* supprimer_pos_PPile(Cellule *pile, int pos);
Cellule* supprimer_val_PPile(Cellule *pile, int val);
Cellule* supprimer_all_val_PPile(Cellule *pile, int val);
Cellule* max_val_PPile(Cellule *pile, int *max);
Cellule* min_val_PPile(Cellule *pile, int *min);
Cellule* affiche_PPile(Cellule *pile);
int handle_errors_PPile(int cd);

/******************************     END
 *  PILE avec POINTEURs
 *  ***************************
 */

//************************************************************************************
//************************************************************************************

/******************************     START
 *  PILE avec TABLEAUx
 *  ***************************
 */

TPile* createTPile();
TPile* init_TPile(TPile *pile);
int taille_TPile(TPile pile);
int vider_pile(TPile *pile);
int est_TPile_vide(TPile pile);
int empiler_Tab(TPile *pile, int val);
int depiler_Tab(TPile *pile);
int getSommet_TPile(TPile pile);
TPile* inverser_TPile(TPile *pile);
int trouver_val_TPile(TPile *pile, int val, int *status);
int max_val_TPile(TPile *pile, int *status);
int min_val_TPile(TPile *pile, int *status);
int nbr_occur_TPile(TPile *pile, int val, int *status);
int trouver_pos_TPile(TPile *pile, int pos, int *status);
void supprimer_val_TPILE(TPile *pile, int val, int *status);
void supprimer_all_occur_TPILE(TPile *pile, int val, int *status);
void supprimer_pos_TPILE(TPile *pile, int pos, int *status);
void affiche_TPile(TPile *pile, int *status);
int handle_errors_TPile(int cd);

/******************************     END
 *  PILE avec TABLEAUx
 *  ***************************
 */

//************************************************************************************
//************************************************************************************

/******************************     START
 *  FILE avec POINTEURS
 *  ***************************
 */
PFile* createPFile();
PFile *initialiser_PFile();
int PFile_existe (PFile *f);
int PFile_vide (PFile *f);
int enfiler_PFile(PFile *f, int val);
int defiler_PFile(PFile *f);
int enfiler_pos_PFIle(PFile* file, int val, int pos);
int supprimer_val_occur_PFile(PFile *file, int val);
int max_val_PFile(PFile *file, int *max_val);
int min_val_PFile(PFile *file, int *min_val);
void afficher_PFile (PFile *f);

/******************************     END
 *  FILE avec POINTEURS
 *  ***************************
 */

//************************************************************************************
//************************************************************************************

/******************************     START
 *  FILE avec TABLEAUx
 *  ***************************
 */
TFile* createTFile();
TFile* init_TFile(TFile *tFile);
int get_tete_TFile(TFile *tfile);
int Taille_TFile(TFile tFile);
int vider_TFile(TFile *tFile);
int est_saturee_TFile(TFile tab);
int est_vide_TFile(TFile tab);
void tasser_TFile(TFile *pTab, int pos);
int enfiler_TFile(TFile *tFile, int val);
int defiler_TFile(TFile *tFile);
//int enfiler_pos_TFile(TFile *tFile, int val, int *status, int pos);
int enfiler_pos_TFile(TFile *file, int pos, int val);
int max_val_TFile(TFile *tFile, int *status);
int min_val_TFile(TFile *tFile, int *status);
int supp_val_occurs_TFile(TFile *file, int val);
int supp_val_first_occur_TFile(TFile *file, int val);
int supp_pos_TFile(TFile *file, int pos);
void affiche_TFile(TFile *tFile);
int handle_errors_TFile(int cd);

/******************************     END
 *  FILE avec TABLEAUx
 *  ***************************
 */

//************************************************************************************
//************************************************************************************

/******************************     START
 *  LIST avec POINTEURS
 *  ***************************
 */
Cellule * creer_PListe(int elem);
int taille_pliste(Cellule *list);
Cellule *inserer_queue_PList(Cellule *list, int val);
Cellule *inserer_tete_PList(Cellule *list, int val);
Cellule * inserer_pos_PList(Cellule* list,int pos, int elem,int *etat);
void gestion_errp(int val);
int supprimer_pos_PtList(Cellule *list, int pos);
int afficher_plist(Cellule *list);
int affiche_pos(Cellule *list,int pos,int *etat);
int recherche_elem(Cellule *list,int elm);
int nb_occ_elem(Cellule *list,int elm);
void supp_first_occ(Cellule * list, int elm,int *etat);
Cellule* supp_pos_PList(Cellule *list, int pos);
Cellule* supp_occ_elem_PList(Cellule *list,int val);


/******************************     END
 *  LIST avec POINTEURS
 *  ***************************
 */

//************************************************************************************
//************************************************************************************

/******************************     START
 *  LIST avec TABLEAUx
 *  ***************************
 */



/******************************     END
 *  LIST avec TABLEAUx
 *  ***************************
 */

//************************************************************************************
//************************************************************************************

/******************************     START
 *  ARBRE BINAIRE avec POINTEURS
 *  ***************************
 */



/******************************     END
 *  ARBRE BINAIRE avec POINTEURS
 *  ***************************
 */

//************************************************************************************
//************************************************************************************

/******************************     START
 *  ARBRE BINAIRE avec TABLEAUx
 *  ***************************
 */



/******************************     END
 *  ARBRE BINAIRE avec TABLEAUx
 *  ***************************
 */

//************************************************************************************
//************************************************************************************







#endif //PRACTICE_FONCTIONS_H
