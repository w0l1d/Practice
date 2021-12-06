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



typedef struct Nd {
    int info; //information du noeud
    int cpt; //nombre de repetition de cette info
    struct Nd *gch; //pointeur sur le fils gauche
    struct Nd *drt; //pointeur sur le fils gauche
}PNode;

typedef struct PAPile {
    struct Nd *node;
    struct PAPile *svt;
}PAPile;

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
Cellule* empiler_pos_PPile(Cellule *pile, int pos, int val);
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


TPile* create_TPile();
TPile* init_TPile(TPile *pile);
int taille_TPile(TPile pile);
int vider_TPile(TPile *pile);
int est_vide_TPile(TPile pile);
int empiler_TPile(TPile *pile, int val);
int depiler_TPile(TPile *pile);
int getSommet_TPile(TPile pile);
TPile* inverser_TPile(TPile *pile);
int trouver_val_TPile(TPile *pile, int val );
int max_val_TPile(TPile *pile );
int min_val_TPile(TPile *pile );
int nbr_occur_TPile(TPile *pile, int val );
int trouver_pos_TPile(TPile *pile, int pos );
void supprimer_val_TPILE(TPile *pile, int val );
void supprimer_all_occur_TPILE(TPile *pile, int val );
void supprimer_pos_TPILE(TPile *pile, int pos );
void affiche_TPile(TPile *pile );
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
int supp_pos_PFile(PFile *f, int pos);
int supp_elem_PFile(PFile *f, int val);

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
int taille_PListe(Cellule *list);
Cellule *inserer_queue_PList(Cellule *list, int val);
Cellule *inserer_tete_PList(Cellule *list, int val);
Cellule * inserer_pos_PList(Cellule* list,int pos, int elem,int *etat);
void gestion_errp_PListe(int val);
int afficher_PListe(Cellule *list);
int affiche_pos_PListe(Cellule *list,int pos,int *etat);
int recherche_elem_PListe(Cellule *list,int elm);
int nb_occ_elem_PListe(Cellule *list,int elm);
Cellule* supp_fst_occ_PList(Cellule *list,int val);
Cellule* supp_pos_PList(Cellule *list, int pos);
Cellule* supp_all_occ_PList(Cellule *list,int val);


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
TListe* create_TListe();
TListe* init_TListe(TListe *liste);
int taille_TListe(TListe liste);
int vider_TListe(TListe *liste);
int inserer_queue_TListe(TListe *liste, int val);
int inserer_tete_TListe(TListe *liste, int val);
int inserer_position_TListe(TListe *liste, int val, int pos);
int supprimer_position_TListe(TListe *liste, int pos);
int supprimer_first_elem_TListe(TListe *liste, int val);
int supprimer_elems_TListe(TListe *liste, int val);
int inverser_TListe(TListe *liste);
int get_max_val_TListe(TListe *liste);
int get_max_pos_TListe(TListe *liste);
int get_min_val_TListe(TListe *liste);
int get_min_pos_TListe(TListe *liste);
int get_nbr_repetition_TListe(TListe *liste, int val);
int acceder_val_TListe(TListe *liste, int pos);
int affiche_TListe(TListe *liste);
int gestion_err_TListe(int val);
int rechercher_elem_TListe(TListe liste,int elem);

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
PNode* create_PNode_Ord(int val);
PNode* insert_PNode_Ord(PNode *root, int val);

void affiche_prefixer_iter_PNode_Ord(PNode *root);
/**************************** START
 * PILE DES NODE FONCTIONS
 */
PAPile* init_PAPile(struct Nd *node);
PAPile* empiler_PAPile(PAPile *pile, struct Nd *node);
PAPile* depiler_PAPile(PAPile *pile);
/**************************** END
* PILE DES NODE FONCTIONS
*/

void affiche_prefixer_PNode_Ord(PNode *root);
void affiche_postfixer_PNode_Ord(PNode *root);
void affiche_infixer_PNode_Ord(PNode *root);
int profondeur_PNode_Ord(PNode *root);
void largeur_par_niveau_PNode_Ord(PNode *root , int *niveaux,
                                  int ligne);

int largeur_max_PNode_Ord(PNode *root);
int max_val_PNode_Ord(PNode *root);
int min_val_PNode_Ord(PNode *root);
PNode *min_noeud_PNode_Ord(PNode *root);
PNode *parent_de_PNode_Ord(PNode *root, int val);
int largeur_PNode_Ord(PNode *root, const int *niveaux,
                      int profondeur);

int size_PNode_Ord(PNode *root);
PNode *supp_PNode_Ord(PNode *root, int val);
PNode *supp_def_PNode_Ord(PNode *root, int val);
void assign_val_to_Mtx_PNode_Ord(PNode *root, int *matrice,
                                 int cols, int line,
                                 int col, int ss);

void affiche_arbre_Real_PNode_Ord(PNode *root);
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
