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