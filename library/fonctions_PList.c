//
// Created by W0L1D on 12/5/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


// la fct creer liste
Cellule * creer_PListe(int elem)
{
    Cellule* NE;

    NE=(Cellule*)malloc(sizeof(Cellule));

    //si il y a un probleme d'allocation
    if(!NE)
        return((Cellule*)NULL);//retourner null
    NE->val=elem;
    NE->svt=NULL;

    return((Cellule*)NE);
}


// fct taille liste
int taille_PListe(Cellule *list)
{ // declaration d'un pt
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
}


Cellule *inserer_queue_PList(Cellule *list, int val) {
    Cellule *ne;
    ne = creer_PListe(val);

    //cas ou la liste n'existe pas
    if(!list)
        return((Cellule*) ne);

    Cellule *pt = NULL;
    for(pt = list; pt->svt; pt = pt->svt);

    pt->svt = ne;
    return ((Cellule*) list);

}


Cellule *inserer_tete_PList(Cellule *list, int val) {
    Cellule *ne;
    ne = creer_PListe(val);
    ne->svt = list;
    return ((Cellule*) ne);
}


// fct inserer un elemet a une position p donnee
Cellule * inserer_pos_PList(Cellule* list,int pos, int elem,int *etat)
{
    Cellule *NE,*pt;
    int compt;
    //cas ou la liste n'existe pas
    if(!list)
    {
        *etat=-2;
        return((Cellule*)NULL);
    }


    // si une position p est en dehors de la liste
    if ((pos < 1) || (taille_PListe(list)+1 < pos)) {
        *etat=-3;
        return((Cellule*)NULL);
    }

    //creer l'element NE
    NE=(Cellule*)creer_PListe(elem);

    // si pos==1 (insertion en tete)
    if(pos==1)
    {
        NE->svt=list;
        return((Cellule*)NE);
    }

    // position est > a 1 et < nombre d'element
    compt=1;
    pt=list;
    //parcourir jusqu'à trouver la position avant pos
    while(compt< pos-1) {
        pt=pt->svt;
        compt++;
    }


    NE->svt=pt->svt;
    pt->svt=NE;
    *etat=1;// pour l'utiliser a la fct gestion erreur
    return((Cellule*)list);
}




// fct gestion des erreur ,pas de retour ,que des affichage des msg
void gestion_errp_PListe(int val)
{
    switch(val)
    {
        case -1 :
            printf("\n probleme d'allocation !! \n");
            break;
        case -2 :
            printf("\n liste n'existe pas !! \n");
            break;
        case -3 :
            printf("\n position non valide !! \n");
            break;
        case -4 :
            printf("\n on ne peux pas supprimer le 1er element !! \n");
            break;
        case 0 :
            printf("\n element n'existe pas !! \n");
            break;
        case  1 :
            printf("\n votre operation est bien effectuer   !! \n");
            break;

    }
}


/*// fct qui supprime l'element qui se trouve a une position p donnee
Cellule* supprimer_pos_PtList(Cellule *list, int pos)
{   //list n'exist pas
    if (!list)
        return ((Cellule*)NULL);


    Cellule *curr = list,// utiliser un pt :" curr " pour parcourir la liste
    *tmp;// pour libérer l'espace occupee par l element qu'on veut supprimer

    if (pos == 1) {
        tmp = list;
        list = list->svt;
        free(tmp);
        return ((Cellule *)list);
    }


    int indice = 1; // pour trouver la position

    while (curr->svt)// tant que on a pas arriver a la fin du liste
    {
        if (pos == indice+1) //si on est en precedant de pos
            break;
        indice++;
        curr = curr->svt;
    }
    //element n'est pas trouver
    // position donnee est erronee
    if ((indice+1) != pos) {
        printf("\nposition incorrecte\n");
        return((Cellule*)list);
    }

    tmp = curr->svt; // tmp == element a supprimer
    curr->svt = tmp->svt;
    free(tmp);
    return((Cellule*)list);
}*/

// Fct affiche tout les element de la liste
int afficher_PListe(Cellule *list)
{
    // declaration des variable
    Cellule *pt;//pour parcourir la liste
    //list n'existe pas
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
}

// fonction affichel'element qui se trouve dans une position p
int affiche_pos_PListe(Cellule *list,int pos,int *etat)
{
    int indice;
    Cellule *pt;
    //liste n'exist pas
    if (!list) return((*etat)=-2);
    //liste existe
    indice=1;
    pt=list;
    // si une position p est en dehors de la liste
    if ((pos<1 ) || ( taille_PListe(list)<pos))	 return((*etat)=-3);
    //sinon
    while (indice!=pos)  // tant que on a pas arriver a la position
    {
        pt=pt->svt;
        indice++;
    }
    printf("\n l'element %d a la position %d",pt->val,pos);
    return((*etat)=2);

}

//fonction qui recherche si un element existe dans la liste
int recherche_elem_PListe(Cellule *list,int elm)
{
    //liste n'exist pas
    if (!list)
    {
        printf("\n liste n'existe pas!");
        return((int)-2);
    }
    // liste existe
    Cellule *pt=list;// pour parcourir la liste
    int compt=0;//pour donner la position de l'element
    while(pt)//tant que ot n'est pas null
    {
        compt++;
        if((pt->val)==elm)return((int)compt);// element trouver
        pt=pt->svt;
    }
    // element n'existe pas dans laliste
    return((int)0);
}

// fct compte le nombre d'occurence d'un element dans une lste
int nb_occ_elem_PListe(Cellule *list,int elm)
{
    Cellule *pt=list;
    int compt=0;
    //liste n'exist pas
    if (!list)
    {printf("\n liste n'existe pas!");
        return((int)-2);
    }
    // LISTE EXISTE
    while(pt)//tant que ot n'est pas null parcourir la liste
    { if((pt->val)==elm) compt++;	// si l'element existe incrementer le compteur
        pt=pt->svt;
    }
    return((int)compt);// returner le nombre ,zero si il n'existe pas
}





// fct qui supprime tout les occurences d'un element
Cellule* supp_all_occ_PList(Cellule *list,int val)
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
            free(tmp);

        } else
            pt = pt->svt;
    }

    return ((Cellule*) list);

}



// fct qui supprime le premier occurrence d'un element
Cellule* supp_fst_occ_PList(Cellule *list,int val)
{
    Cellule *pt = list, *tmp;
    if (!list)
        return ((Cellule*) NULL);

    if (pt->val == val) {
        tmp = pt;
        pt = pt->svt;
        free(tmp);
        return ((Cellule*) pt);
    }


    while(pt->svt) {
        if (pt->svt->val == val) {
            tmp = pt->svt;
            pt->svt = tmp->svt;
            free(tmp);
            return ((Cellule*) list);
        }
        pt = pt->svt;
    }

    return ((Cellule*) list);

}


//fct qui supprime un element par position
Cellule* supp_pos_PList(Cellule * list, int pos)
{
    //liste n'exist pas
    if (!list) 	return ((Cellule*) list);

    if (pos < 1)
    {
        printf("\nPosition incorrecte\n");
        return ((Cellule *) list);
    }

    int cpt = 1;

    Cellule *curr, *tmp;
    if (pos == 1) {
        tmp = list;
        list = list->svt;
        free(tmp);
        return ((Cellule*) list);
    }

    curr = list;

    while(curr->svt)
    {
        cpt++;
        if (cpt == pos) {
            tmp = curr->svt;
            curr->svt = tmp->svt;
            free(tmp);
            return ((Cellule*) list);
        }
        curr = curr->svt;

    }
    printf("\nPosition incorrecte\n");

    return ((Cellule*) list);
}//fin fct