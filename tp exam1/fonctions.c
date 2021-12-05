//
// Created by W0L1D on 12/4/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


/******************************
 *
 *      Liste avec tableau
 *
 */

// la fct creer liste
TListe* create_TListe()
{
    TListe *liste = (TListe*) malloc(sizeof(TListe)); // allocation de la memoire
    liste->nbr_elem = 0;  // initialiser le nombre des element a 0
    if (!liste)  //si liste n'existe pas
    {
        printf("Erreur de location de la memoire");
        exit(-1);//sortir du prog
    }
    return (liste);
}//fin fct createListe


// la fct initialiser liste
TListe* init_TListe(TListe *liste)
{
    if (liste) //si liste existe
        free(liste);
    liste = create_TListe(); //creer une autre liste a l'aide de la fct createListe
    return liste; //retourne la nouvelle liste
}//fin fct init_Liste


// fct inserer un elemet en queue
int inserer_queue_TListe(TListe *liste, int val)
{
    //liste n'exist pas
    if (!liste) return ((int)-1);
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem) return((int)-2);
    // inserer dans la fin du tableau
    liste->tab[liste->nbr_elem++] = val;
    return((int) 1);
}//fin fct inserer_queue


// fct qui supprime  l'element qui se trouve dans une position p donnee
int supprimer_position_TListe(TListe *liste, int pos)
{
    int i ;
    //liste n'exist pas
    if (!liste) return((int)-1) ;
    //position non valide
    if ((pos < 1) || ((liste->nbr_elem)+ 1< pos)) return((int)-3);
    //faire une boucle pour decaler les elemet du tableau
    for(i = pos-1; i < liste->nbr_elem; i++)
        liste->tab[i] = liste->tab[i+1];
    // decrementer le nombre d'element
    liste->nbr_elem--;
    return((int)1) ;//supprition effectuer
}// fin fct supprimer_position



// fct affiche le contenu de la liste
int affiche_tliste(TListe *liste)
{     int i ;
    //liste n'exist pas
    if (!liste) return((int) -1);
    // Liste est vide
    if (!liste->nbr_elem) return((int)0) ;
    // boucle pour afficher elementpar element
    for (i = 0; i < liste->nbr_elem; ++i)
    {
        printf("%d\t", liste->tab[i]);
    }
    return ((int) 1);
}


/// fct inserer un elemet a une posotion donnee
int inserer_position_TList(TListe *liste, int val, int pos)
{
    int i;
    //liste n'exist pas
    if (!liste) return ((int)-1);
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem) return((int) -2);
    //position non valide
    if ((pos < 1) || (liste->nbr_elem+1 < pos)) return((int)-3) ;
    //sinon
    pos--;// pour trouver l'indice
    //faire une boucle pour decaler les elemet du tableau
    for( i = liste->nbr_elem; i > pos; --i)
        liste->tab[i] = liste->tab[i-1];
    // inserer le nouveau element
    liste->tab[pos] = val;
    //incrementer le nombre des elemet
    liste->nbr_elem++;

    return ((int)1);
}//fin fct inserer_position_TList


// fct inserer un elemet en tete
int inserer_tete_TListe(TListe *liste, int val)
{
    //liste n'exist pas
    if (!liste) return ((int)-1);
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem) return((int)-2);

    int size = liste->nbr_elem;

    while(size--){
        liste->tab[size+1] = liste->tab[size];
    }

    // inserer au debut du tableau
    liste->tab[0] = val;
    liste->nbr_elem++;
    return((int) 1);
}//fin fct inserer_tete




/******************************
 *
 *      Liste avec pointeur
 *
 */
// la fct creer liste
Cellule * creer_Pliste(int elem)
{
// declarer une variable de type pt
    Cellule* NE;
// allocation de la memoire
    NE=(Cellule*)malloc(sizeof(Cellule));
//si il y a un probleme d'allocation
    if(!NE)
        return((Cellule*)NULL);//retourner null

//si l'allocatin est bien passer
//initialisation
    NE->val=elem;
    NE->svt=NULL;

    //retourner l'element de type Cellule
    return((Cellule*)NE);
}//fin fct

Cellule *inserer_queue_PList(Cellule *list, int val) {
    Cellule *ne;
    ne = creer_Pliste(val);

    //cas ou la liste n'existe pas
    if(!list)
    {
        return((Cellule*) ne);
    }

    Cellule *pt = NULL;
    for(pt = list; pt->svt; pt = pt->svt);

    pt->svt = ne;
    return ((Cellule*) list);

}


// fct inserer un elemet a une position p donnee
Cellule * inserer_pos_PList(Cellule* list,int pos, int elem)
{
    Cellule *NE,*pt;
    int compt;
    //cas ou la liste n'existe pas
    if(!list)
    {
        return((Cellule*)NULL);
    }
    // liste existe
    // si pos==1 (insertion en tete)
    if(pos==1)
    {
        // creer un NE et le donner comme suivant la liste
        NE=(Cellule*)creer_Pliste(elem);
        NE->svt=list;
        //retourner l NE
        return((Cellule*)NE);
    }
    // si une position p est en dehors de la liste
    if ((pos<1 ) || ( taille_pliste(list)+1<pos))
    {
        return((Cellule*)NULL);
    }
    // position est > a 1 et < nombre d'element
    compt=1;
    pt=list;
    while(compt< pos-1) //parcourir jusqu'a trouver la position avant
    { pt=pt->svt;
        compt++;
    }

    //creer l'element NE
    NE=(Cellule*)creer_Pliste(elem) ;
    NE->svt=pt->svt;
    pt->svt=NE;

    return((Cellule*)list);
}//fin fct




// fct taille liste
int taille_pliste(Cellule *list)
{
    // declaration d'un pt
    Cellule *pt;
    // initialiser la variable compt a zero
    int compt=0;
    //cas ou la iste n'existe pas
    if(!list)
    { printf("liste n'existe pas !! \n");
        return((int)-2);
    }
    // si la liste existe
    pt=list;
    //tant que pt est != de null
    while(pt)
    {
    // incrementer le compteur
        compt++;
        pt=pt->svt;
    }
    return((int)compt);
}//fin fct


// Fct affiche tout les element de la liste
int affiche_plist(Cellule *list)
{
    // declaration des variable
    Cellule *pt;//pour parcourir la liste
    int compt;// donner les positions des elements
    //list n'exist pas
    if (!list)
        return -2 ;
    //Liste existe
    pt=list;
    while(pt)//tant que ot n'est pas null
    {
        printf("%d\t", pt->val);

        pt=pt->svt;
    }
    return 1;// pour la gestion des erreurs
}//fin fct

Cellule *trans_Tliste_Pliste(TListe *tl, Cellule *pl) {
    if (!tl)
        return ((Cellule*) NULL);

    int size = tl->nbr_elem,
        status;

    while(size--) {
        pl = inserer_queue_PList(pl, tl->tab[0]);
        supprimer_position_TListe(tl,1);
    }
    return ((Cellule*) pl);
}



Cellule *inserer_tete_PList(Cellule *list, int val) {
    Cellule *ne;
    ne = creer_Pliste(val);

    ne->svt = list;

    return ((Cellule*) ne);

}

// fct qui supprime tout les occurences d'un element
Cellule* supp_occ_elem_PList(Cellule *list,int val)
{
    Cellule *pt = list, *tmp;
    if (!list)
        return ((Cellule*) NULL);

    while (pt->val == val) {
        tmp = pt;
        pt = pt->svt;
        free(tmp);
    }

    list = pt;
    while(pt->svt) {
        if (pt->svt->val == val) {
            tmp = pt->svt;
            pt->svt = tmp->svt;
            tmp = NULL;
            free(tmp);
        }
        pt = pt->svt;
    }

    return ((Cellule*) list);

}//fin fct


//// fct qui supprime tout les occurences d'un element
//Cellule* supp_occ_elem_PList(Cellule *list,int val, int *occ)
//{
//    Cellule *pt = list, tmp;
//    *occ = 0;
//
//    if (!list)
//        return ((Cellule*) NULL);
//
//    while(pt) {
//        if (pt->val == val)
//            (*occ)++;
//        pt = pt->svt;
//    }
//
//
//    return ((Cellule*) list);
//
//}//fin fct

//fct qui supprime la 1er occurence d'un element
Cellule* supp_pos_PList(Cellule * list, int pos)
{
    //liste n'exist pas
    if (!list) 	return ((Cellule*) list);

    int cpt = 1;

    Cellule *curr, *tmp;
    if (pos == 1)
    {
        tmp = list;
        list = list->svt;
        free(tmp);
        return ((Cellule*) list);
    }

    curr = list;


    while(curr)
    {
        cpt++;
        if (cpt == pos) {
            tmp = curr->svt;
            curr->svt = tmp->svt;
            free(tmp);
        }
        curr = curr->svt;

    }

    return ((Cellule*) list);
}//fin fct


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

Cellule* inverser_PPile(Cellule *pile)
{
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




Cellule *trans_Pliste_PPile(Cellule *list) {
    if (!list)
        return ((Cellule*) NULL);

    Cellule *curLst = list;
    Cellule *pile = NULL;

    while(curLst) {
        pile = empiler_PPile(pile, curLst->val);
        curLst = curLst->svt;
    }
    pile = inverser_PPile(pile);
    return ((Cellule*) pile);
}


Cellule* supprimer_pos_PPile(Cellule *pile, int pos) {
    //pile n'exist pas
    if (!pile)
        return ((Cellule*) pile);

    //supprimer le premier element
    if (pos == 1)
        return ((Cellule*) depiler_PPile(pile));


    int indice = 1;
    Cellule *tmp = NULL;

    while (indice < pos)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        indice++;
    }

    //l'element est trouve
    if (indice == pos)
        pile = depiler_PPile(pile);

    while (tmp)
    {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    return ((Cellule*) pile);
}


Cellule* supprimer_all_val_PPile(Cellule *pile, int val)
{
    Cellule *tmp = NULL;
    int val_depile;

    while (pile)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        if (tmp->val == val)
            tmp = depiler_PPile(tmp);

    }

    while (tmp)
    {
        val_depile = tmp->val;
        tmp = depiler_PPile(tmp);
        pile = empiler_PPile(pile, val_depile);
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

PFile *initialiser_PFile()
{
    PFile *f = createPFile();
    f->tete=NULL; // on initialise la tete du PFile a NULL
    f->queue=NULL; // on initialise le queue du PFile a NULL
    f->taille=0; // on initialise la taille du PFile a 0
    return ((PFile*) f);
}


int PFile_existe(PFile *f)
{
    // 1 existe
    // 0 n'existe pas
    if (!f)
        return 0;
    return 1;
}

int PFile_vide(PFile *f)
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

PFile *trans_PPile_PFile(Cellule* pile) {
    if (!pile)
        return ((PFile *) NULL);
    PFile *file = initialiser_PFile();
    while (pile) {
        enfiler_PFile(file, pile->val);
        pile = depiler_PPile(pile);
    }
    return ((PFile*) file);
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

int supprimer_val_occur_PFile(PFile *file, int val) {

    //File n'existe pas
    if (!file)
        return ((int) -1);
    //File est vide
    if (!file->taille)
        return ((int) 0);


    int val_defile,
        cmp = file->taille,
        status = -4;

    while (cmp--)
    {
        val_defile = file->tete->val;

        defiler_PFile(file);

        if (val_defile != val)
            enfiler_PFile(file, val_defile);
        else
            status = 1;
    }

    return ((int) status);
}


/******************************
 *
 *      Arbre binaire avec pointeur
 *
 */

PNode* create_PNodePt(int val)
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

PNode* insert_Pt(PNode *root, int val)
{
    if (!root)
    {
        PNode *ne = create_PNodePt(val);
        return ((PNode*) ne);
    }
    if (root->info > val)
        root->gch = insert_Pt(root->gch, val);
    else if (root->info < val)
        root->drt = insert_Pt(root->drt, val);
    else
        root->cpt++;

    return ((PNode*)root);
}



PNode* trans_PFile_Arb(PFile *file) {
    PNode *arb = NULL;
    if (!file)
        return ((PNode*) arb);

    while (!PFile_vide(file)) {
        arb = insert_Pt(arb, file->tete->val);
        defiler_PFile(file);

    }
    return ((PNode*) arb);

}

void affiche_prefixer(PNode *root)
{
    if (!root)
        return;

    printf("%d (%d)\t", root->info, root->cpt);
    affiche_prefixer(root->gch);
    affiche_prefixer(root->drt);
}

PNode *min_noeud_arbrePt(PNode *root) {
    if (!root)
        return ((PNode*) NULL);
    if (!root->gch)
        return root;
    return min_noeud_arbrePt(root->gch);
}

PNode *supp_arbrePt(PNode *root, int val)
{
    //si la valeur n'est pas trouve
    if (!root)
    {
        printf("\nValeur n'est pas trouve\n");
        return ((PNode*) root);
    }

    if (val < root->info)
        //on cherche sur l'à gauche de l'arbre
        root->gch = supp_arbrePt(root->gch, val);

    else if (val > root->info)
        //on cherche sur l'à droite de l'arbre
        root->drt = supp_arbrePt(root->drt, val);

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
            tmp = min_noeud_arbrePt(root->drt);
            //on replace le Nœud a supprimé par le minimum
            root->info = tmp->info;
            root->cpt = tmp->cpt;

            //pour eviter le decalage du compteur
            tmp->cpt = 1;
            //supprimer le minimum deja deplace
            root->drt = supp_arbrePt(root->drt, tmp->info);
        }
    }
    return ((PNode *) root);
}




PNode *supp_def_arbrePt(PNode *root, int val) {
    //si la valeur n'est pas trouve
    if (!root) {
        printf("\nValeur n'est pas trouve\n");
        return ((PNode *) root);
    }

    if (val < root->info)
        //on cherche sur l'à gauche de l'arbre
        root->gch = supp_arbrePt(root->gch, val);

    else if (val > root->info)
        //on cherche sur l'à droite de l'arbre
        root->drt = supp_arbrePt(root->drt, val);

    else //si le PNode courant a info == val
    {

        PNode *tmp = NULL;

        //PNode n'a pas de fils
        if (!root->drt && !root->gch) {
            free(root);
            return ((PNode *) tmp);
        }

            //PNode n'a pas de fils Droit
        else if (!root->drt) {
            //On Remplace ce PNode par son fils Gauche
            tmp = root->gch;
            free(root);
            return ((PNode *) tmp);
        }

            //PNode n'a pas de fils Gauche
        else if (!root->gch) {
            //On Remplace ce PNode par son fils Droit
            tmp = root->drt;
            free(root);
            return ((PNode *) tmp);
        }
            //Si le PNode a les fils droit et gauche
        else {
            //on cherche le minimun dans sous arbre du fils droit
            tmp = min_noeud_arbrePt(root->drt);


            //on replace le Nœud a supprimé par le minimum
            root->info = tmp->info;
            root->cpt = tmp->cpt;

            //supprimer le minimum deja deplace
            root->drt = supp_def_arbrePt(root->drt, tmp->info);
        }
    }
    return ((PNode *) root);
}