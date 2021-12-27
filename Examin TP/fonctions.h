//
// Created by W0L1D on 12/6/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef PRACTICE_FONCTIONS_H
#define PRACTICE_FONCTIONS_H

#define MAX_ELEMS 30

typedef struct Table
{
    int tab[MAX_ELEMS];
    int nbr_elem;
} Table;


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

Table* create_Table();
Table* init_Table(Table *mtab);
int taille_Table(Table mtab);
int vider_Table(Table *mtab);
int inserer_queue_Table(Table *mtab, int val);
int inserer_tete_Table(Table *mtab, int val);
int inserer_position_Table(Table *mtab, int val, int pos);
int supprimer_position_Table(Table *mtab, int pos);
int supprimer_first_elem_Table(Table *mtab, int val);
int supprimer_elems_Table(Table *mtab, int val);
int affiche_Table(Table *mtab);


Cellule *trans_Table_PPile(Table mtab);

Cellule* init_PPile(int val);
Cellule* empiler_PPile(Cellule *pile, int val);
Cellule* depiler_PPile(Cellule *pile);
Cellule* inverser_PPile(Cellule *pile);
Cellule* affiche_PPile(Cellule *pile);
Cellule* supprimer_pos_PPile(Cellule *pile, int pos);
int taille_PPile(Cellule *pile);
Cellule* empiler_pos_PPile(Cellule *pile, int pos, int val);


PFile *trans_PPile_PFile(Cellule *pile);



PFile* createPFile();
PFile *initialiser_PFile();
int PFile_existe (PFile *f);
int PFile_vide (PFile *f);
int enfiler_PFile(PFile *f, int val);
int defiler_PFile(PFile *f);
int enfiler_pos_PFIle(PFile* file, int val, int pos);
void afficher_PFile(PFile *f);




PNode* create_PNode_Ord(int val);
PNode* insert_PNode_Ord(PNode *root, int val);

/******************************
 *
 *      Tableau
 *
 */


// la fct creer mtab
Table* create_Table()
{
    Table *mtab = (Table*) malloc(sizeof(Table)); // allocation de la memoire
    mtab->nbr_elem = 0;  // initialiser le nombre des element a 0
    if (!mtab)  //si mtab n'existe pas
    {
        printf("Erreur de location de la memoire");
        exit(-1);//sortir du prog
    }
    return (mtab);
}//fin fct createListe


// la fct initialiser mtab
Table* init_Table(Table *mtab)
{
    if (mtab) //si mtab existe
        free(mtab);
    mtab = create_Table(); //creer une autre mtab a l'aide de la fct createListe
    return mtab; //retourne la nouvelle mtab
}//fin fct init_Liste


// fct inserer un elemet en queue
int inserer_queue_Table(Table *mtab, int val)
{
    //mtab n'exist pas
    if (!mtab)
    {
        printf("mtab n'exist pas");
        return ((int)-1);
    }
    //Liste est saturee
    if (MAX_ELEMS == mtab->nbr_elem)
    {
        printf("Liste est saturee");
        return((int)-2);
    }
    // inserer dans la fin du tableau
    mtab->tab[mtab->nbr_elem++] = val;
    return((int) 1);
}//fin fct inserer_queue



/// fct inserer un elemet a une posotion donnee
int inserer_position_Table(Table *mtab, int val, int pos)
{ int i;
    //mtab n'exist pas
    if (!mtab)
    {
        printf("mtab n'exist pas");
        return ((int)-1);
    }
    //Liste est saturee
    if (MAX_ELEMS == mtab->nbr_elem)
    {
        printf("Liste est saturee");
        return((int)-2);
    }
    //position non valide
    if ((pos < 1) || (mtab->nbr_elem+1 < pos))
    {
        printf("position non valide");
        return((int)-3) ;
    }
    //sinon
    pos--;// pour trouver l'indice
    //faire une boucle pour decaler les elemet du tableau
    for( i = mtab->nbr_elem; i > pos; --i)
        mtab->tab[i] = mtab->tab[i-1];
    // inserer le nouveau element
    mtab->tab[pos] = val;
    //incrementer le nombre des elemet
    mtab->nbr_elem++;

    return ((int)1);
}//fin fct inserer_position



// fct qui supprime  l'element qui se trouve dans une position p donnee
int supprimer_position_Table(Table *mtab, int pos)
{ int i ;
    //mtab n'exist pas
    if (!mtab)
    {
        printf("mtab n'exist pas");
        return ((int)-1);
    }
    //position non valide
    if ((pos < 1) || ((mtab->nbr_elem)+ 1< pos))
    {
        printf("position non valide");
        return((int)-3) ;
    }
    //faire une boucle pour decaler les elemet du tableau
    for( i = pos-1; i < (mtab->nbr_elem ); i++)
        mtab->tab[i] = mtab->tab[i+1];
    // decrementer le nombre d'element
    mtab->nbr_elem--;
    return((int)1) ;//supprition effectuer
}// fin fct supprimer_position


int affiche_Table(Table *mtab)
{
    int i ;
    //mtab n'exist pas
    if (!mtab)
    {printf("la Table n'existe pas");
        return((int) -1);
    }
    // Liste est vide
    if (!mtab->nbr_elem)
    {printf("table est vide");
        return((int)0) ;
    }
    // boucle pour afficher elementpar element
    for (i = 0; i < mtab->nbr_elem; ++i)
    {
        printf("%d\t" ,  mtab->tab[i]);
    }
    return ((int) 1);
}



/******************************
 *
 *      Transfert tableau vers pile
 *
 */

Cellule *trans_Table_PPile(Table mtab) {
    if (!mtab.nbr_elem)
        return ((Cellule*) NULL);

    int i;
    Cellule *pile = NULL;

    for (i = 0; i < mtab.nbr_elem; ++i)
        pile = empiler_PPile(pile ,  mtab.tab[i]);

    pile = inverser_PPile(pile);

    return ((Cellule*) pile);
}



/******************************
 *
 *      Pile avec pointeur
 *
 */


Cellule* init_PPile(int val)
{
    Cellule *pile = (Cellule*) malloc(sizeof(Cellule));

    if (!pile)
    {
        printf("\n\nErreur d'allocation de la memoire\n\n");
        exit(0);
    }

    pile->val = val;
    pile->svt = NULL;
    return pile;
}



Cellule* empiler_PPile(Cellule *pile, int val)
{
    Cellule *nouveau = init_PPile(val);

    nouveau->svt = pile;
    return ((Cellule*) nouveau);
}



Cellule* depiler_PPile(Cellule *pile)
{
    if (!pile) // si la pile n'exist pas
        return ((Cellule*) NULL);

    Cellule *tmp;
    //sauvegarder la valeur a depile
    tmp = pile;
    //detacher la valeur depile de la pile
    pile = pile->svt;
    //liberer la mermoire alloue a la valeur depilee
    free(tmp);

    return ((Cellule*) pile);
}


Cellule* inverser_PPile(Cellule *pile) {
    Cellule *tmp = NULL;

    while (pile)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }
    return tmp;
}


Cellule* affiche_PPile(Cellule *pile)
{
    //si la pile vide
    if (!pile)
    {
        printf("\nla Pile est vide\n");
        return pile;
    }
    Cellule *tmp = NULL;

    printf("\nles elements de la pile : \n");
    while (pile)
    {
        printf("%d\t", pile->val);
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }

    printf("\n");
    return inverser_PPile(tmp);
}


Cellule* supprimer_pos_PPile(Cellule *pile, int pos)
{
    //pile n'exist pas
    if (!pile)
    {
        printf("\nPile n'existe pas\n");
        return ((Cellule*) pile);
    }

    //supprimer le premier element
    if (pos == 1)
        return ((Cellule*) pile->svt);


    int indice = 1, size;
    Cellule *tmp = NULL;

    size = taille_PPile(pile);
    if ((pos < 1) || (size < pos))
    {
        printf("\nPosition est incorrecte\n");
        return ((Cellule*)pile);
    }

    while (indice < pos)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        indice++;
    }


    pile = depiler_PPile(pile);


    while (tmp)
    {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    return ((Cellule*) pile);
}


int taille_PPile(Cellule *pile)
{
    int size = 0;

    while (pile) {
        pile = pile->svt;
        size++;
    }

    return ((int)size);
}



Cellule* empiler_pos_PPile(Cellule *pile, int pos, int val)
{
    //pile n'exist pas
    if (!pile) {
        printf("\nPile n'existe pas\n");
        return ((Cellule*) pile);
    }

    int indice = 1, size;
    Cellule *tmp = NULL;

    size = taille_PPile(pile);
    if ((pos < 1) || (size+1 < pos)) {
        printf("\nPosition est incorrecte\n");
        return ((Cellule*)pile);
    }

    while (indice < pos) {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        indice++;
    }

    pile = empiler_PPile(pile, val);

    while (tmp) {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    return ((Cellule*) pile);
}








/******************************
 *
 *      File avec pointeur
 *
 */


PFile* createPFile()
{
    PFile *pfile = (PFile*) malloc(sizeof(PFile));

    if (!pfile)
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }
    return pfile;
}



PFile *initialiser_PFile ()
{
    PFile *f = createPFile();
    f->tete=NULL; // on initialise la tete du PFile a NULL
    f->queue=NULL; // on initialise le queue du PFile a NULL
    f->taille=0; // on initialise la taille du PFile a 0
    return ((PFile*) f);
}

int PFile_existe (PFile *f)
{
    // 1 existe
    // 0 n'existe pas
    if (!f)
        return 0;
    return 1;
}

int PFile_vide (PFile *f)
{
    // 1 PFile vide
    // 0 PFile non vide
    if ((f->tete==NULL)&&(f->queue==NULL))
        return 1;
    return 0;
}

int enfiler_PFile(PFile *f, int val)
{
    Cellule *e=NULL; // declaration et initialiastion a NULL de l'Cellule a ajouter

    if (!PFile_existe(f)) // si la PFile n'existe pas
        return ((int) -1);

    if (PFile_vide(f)) // si la PFile vide
    {
        e=(Cellule *)malloc(sizeof(Cellule)); // l'allocation du memeoire

        e->val = val;
        f->tete=e; // definition du nouveau tete
        f->queue=e; // definition du nouveau queue
        f->taille++; // l'incrementation du taille du file
    }
    else // si la PFile non vide
    {
        e=(Cellule *)malloc (sizeof(Cellule)); // l'allocation du memeoire

        e->val = val;
        f->queue->svt=e; // definition du nouveau tete
        f->queue=e;
        f->taille++; // l'incrementation du taille du file
    }
    return ((int) 1);
}

int defiler_PFile(PFile *f)
{
    Cellule *tmp; // pointeur de type Cellule vers l'Cellule a supprimer
    if (!PFile_existe(f)) //file n'existe pas
        return((int) -1);
    if (PFile_vide(f)) //file est vide
        return((int) 0);

    // cas d'une seule Cellule
    if (f->taille == 1)
    {
        tmp = f->tete;
        f->tete= f->queue = NULL;
        f->taille--;
        free(tmp);
    }
        // cas de plusieurs Cellules
    else
    {
        tmp=f->tete; // on pointe sur le premier Cellule du file
        f->tete=f->tete->svt; // definition de la nouvelle tete du file
        free(tmp); // on supprimer le premier Cellule du file
        f->taille--; // decrimentation du taille du file
    }
    return ((int) 1);
}


int enfiler_pos_PFIle(PFile* file, int val, int pos)
{
    //File est vide
    if (!file)
        return ((int) -1);
    int cmp = 1,
            size = file->taille,
            val_defile,
            status = -4;

    if (pos == file->taille+1)
        return enfiler_PFile(file, val);

    while (cmp++ <= size)
    {
        val_defile = file->tete->val;
        if (pos == cmp-1)
        {
            status = 1;
            enfiler_PFile(file, val);
        }
        enfiler_PFile(file, val_defile);
        defiler_PFile(file);
    }
    return ((int) status);
}


void afficher_PFile (PFile *f)
{
    if (!PFile_existe(f))
        printf("PFile n'existe pas\n");
    if (PFile_vide(f))
        printf("PFile est vide\n");

    int cmp = f->taille;

    for(;cmp--;)
    {
        printf("%d\t" , f->tete->val);
        enfiler_PFile(f, f->tete->val);
        defiler_PFile(f);
    }
    printf ("\n");
}



/******************************
 *
 *      Transfert pile vers file
 *
 */

PFile *trans_PPile_PFile(Cellule *pile) {
    PFile *file = initialiser_PFile();

    int val_depile;
    while (pile) {
        val_depile = pile->val;
        pile = depiler_PPile(pile);
        enfiler_PFile(file, val_depile);
    }
    return ((PFile*) file);
}



/******************************
 *
 *      Transfert file vers arbre
 *
 */


PNode* trans_PFile_Arb(PFile *file) {
    PNode *arb = NULL;
    if (!file)
        return ((PNode*) arb);

    while (!PFile_vide(file)) {
        arb = insert_PNode_Ord(arb, file->tete->val);
        defiler_PFile(file);
    }
    return ((PNode*) arb);

}


PNode* create_PNode_Ord(int val)
{
    PNode *ne = (PNode*) malloc(sizeof(PNode));
    if (!ne)
    {
        printf("\n\n Erreur d'allocation de memoire\n");
        exit(0);
    }

    ne->drt = ne->gch = NULL;
    ne->info = val;
    ne->cpt = 1;
    return ((PNode*) ne);
}

PNode* insert_PNode_Ord(PNode *root, int val)
{
    if (!root)
    {
        PNode *ne = create_PNode_Ord(val);
        return ((PNode*) ne);
    }
    if (root->info > val)
        root->gch = insert_PNode_Ord(root->gch, val);
    else if (root->info < val)
        root->drt = insert_PNode_Ord(root->drt, val);
    else
        root->cpt++;

    return ((PNode*)root);
}




int profondeur_PNode_Ord(PNode *root) {
    if (!root)
        return 0;
    int drt = profondeur_PNode_Ord(root->drt) + 1;
    int gch = profondeur_PNode_Ord(root->gch) + 1;
    return (drt>gch)? drt : gch;
}




//**********************************************************************************
/***********************************************************************************
 * Nom : void assign_val_to_Mtx_PNode_Ord(PNode *root, int *matrice, int cols,
 *                              int line, int col, int ss)
 *             attribue les noeuds dans l'arbre
 *             au champs correspondent dans la matrice
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *          int *matrice : ou on attribue les valeur des noeuds
 *          int cols : nombre de colonnes de la matrice
 *          int line : ligne courant
 *          int col : colonne courant
 *          int ss : deplacement du colonne du fils par apport au parent
 * Sortie : rien
 */
void assign_val_to_Mtx_PNode_Ord(PNode *root, int *matrice, int cols, int line, int col, int ss) {
    if (!root)
        return;
    *((matrice+(line*cols))+col) = root->info;

    assign_val_to_Mtx_PNode_Ord(root->drt, matrice, cols, line + 1, col + ss, ss/2);
    assign_val_to_Mtx_PNode_Ord(root->gch, matrice, cols, line + 1, col - ss, ss/2);

}



//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_arbre_Real_PNode_Ord(PNode *root)
 *             afficher l'arbre comme arbre reel verticalement
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 * Sortie : rien
 */
void affiche_arbre_Real_PNode_Ord(PNode *root) {
    int prof = profondeur_PNode_Ord(root);
    int segma = 0;
    int tmp;
    for (int i = 0; i < prof; ++i) {
        tmp = (int)pow(2, i);
        segma+=tmp;
    }

    int matrice[prof][segma];
    int *pt = (int *) matrice;

    for (int i = 0; i < prof; ++i)
        for (int j = 0; j < segma; ++j)
            matrice[i][j] = -99;

    assign_val_to_Mtx_PNode_Ord(root, pt, segma,  0, (segma/2), (segma/2+1)/2);

    printf("\n*******************************\n");
    for (int i = 0; i < prof; ++i) {
        for (int j = 0; j < segma; ++j) {
            if (matrice[i][j] == -99)
                printf("**");
            else
                printf("%02d", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n*******************************\n");
}


void affiche_prefixer_PNode_Ord(PNode *root)
{
    if (!root)
        return;

    printf("%d\t", root->info, root->cpt);
    affiche_prefixer_PNode_Ord(root->gch);
    affiche_prefixer_PNode_Ord(root->drt);

}




//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_postfixer_PNode_Ord(PNode *root)
 *             Affiche Postfixer récursivement les elements de l'arbre
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : rien
 */
void affiche_postfixer_PNode_Ord(PNode *root)
{
    if (!root)
        return;

    affiche_postfixer_PNode_Ord(root->gch);
    affiche_postfixer_PNode_Ord(root->drt);
    printf("%d\t", root->info);

}



//**********************************************************************************
/***********************************************************************************
 * Nom : void affiche_infixer_PNode_Ord(PNode *root)
 *             Affiche Infixer récursivement les elements de l'arbre
 *
 * Entree : PNode *root : l'arbre sur lequel on applique le traitement
 *
 * Sortie : rien
 */
void affiche_infixer_PNode_Ord(PNode *root)
{
    if (!root)
        return;

    affiche_infixer_PNode_Ord(root->gch);
    printf("%d\t", root->info);
    affiche_infixer_PNode_Ord(root->drt);

}

PNode *min_noeud_PNode_Ord(PNode *root) {
    if (!root)
        return ((PNode*) NULL);
    if (!root->gch)
        return root;
    return min_noeud_PNode_Ord(root->gch);
}

PNode *supp_PNode_Ord(PNode *root, int val)
{
    //si la valeur n'est pas trouve
    if (!root)
    {
        printf("\nValeur n'est pas trouve\n");
        return ((PNode*) root);
    }

    if (val < root->info)
        //on cherche sur l'à gauche de l'arbre
        root->gch = supp_PNode_Ord(root->gch, val);

    else if (val > root->info)
        //on cherche sur l'à droite de l'arbre
        root->drt = supp_PNode_Ord(root->drt, val);

    else //si le PNode courant a info == val
    {
        //si la valeur est repetee : compteur > 1
        if (root->cpt > 1) {
            root->cpt--; //supprimer une des repetition
            return ((PNode*) root);
        }
        PNode *tmp = NULL;

        //PNode n'a pas de fils
        if (!root->drt && !root->gch)
        {
            free(root);
            return ((PNode*) tmp);
        }

            //PNode n'a pas de fils Droit
        else if (!root->drt)
        {
            //On Remplace ce PNode par son fils Gauche
            tmp = root->gch;
            free(root);
            return ((PNode*) tmp);
        }

            //PNode n'a pas de fils Gauche
        else if (!root->gch)
        {
            //On Remplace ce PNode par son fils Droit
            tmp = root->drt;
            free(root);
            return ((PNode*) tmp);
        }
            //Si le PNode a les fils droit et gauche
        else
        {
            //on cherche le minimun dans sous arbre du fils droit
            tmp = min_noeud_PNode_Ord(root->drt);
            //on replace le Nœud a supprimé par le minimum
            root->info = tmp->info;
            root->cpt = tmp->cpt;

            //pour eviter le decalage du compteur
            tmp->cpt = 1;
            //supprimer le minimum deja deplace
            root->drt = supp_PNode_Ord(root->drt, tmp->info);
        }
    }
    return ((PNode *) root);
}


//
//PNode* trans_Arb_PList(PNode *root, Cellule *list) {
//
//
//
//}




#endif //PRACTICE_FONCTIONS_H
