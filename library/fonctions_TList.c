//
// Created by W0L1D on 12/5/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"




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


// taille liste

int taille_TListe(TListe liste)
{
    return ((int)liste.nbr_elem);
}// fin fct taille_liste

// fct vider liste
int vider_TListe(TListe *liste)
{
    if (!liste) return ((int)-1); //liste n'existe pas
    //liste existe
    liste->nbr_elem = 0; //modifier nombre des element
}// fin fct vider_liste


// fct inserer un elemet en queue
int inserer_queue_TListe(TListe *liste, int val)
{
    //liste n'exist pas
    if (!liste)
    {
        printf("liste n'exist pas");
        return ((int)-1);
    }
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem)
    {
        printf("Liste est saturee");
        return((int)-2);
    }
    // inserer dans la fin du tableau
    liste->tab[liste->nbr_elem++] = val;
    return((int) 1);
}//fin fct inserer_queue

// fct inserer un elemet en tete
int inserer_tete_TListe(TListe *liste, int val)
{
    //liste n'exist pas
    if (!liste)
    {
        printf("liste n'exist pas");
        return ((int)-1);
    }
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem)
    {
        printf("Liste est saturee");
        return((int)-2);
    }

    int size = liste->nbr_elem;

    while(size--){
        liste->tab[size+1] = liste->tab[size];
    }

    // inserer au debut du tableau
    liste->tab[0] = val;
    liste->nbr_elem++;
    return((int) 1);
}//fin fct inserer_tete

/// fct inserer un elemet a une posotion donnee
int inserer_position_TListe(TListe *liste, int val, int pos)
{ int i;
    //liste n'exist pas
    if (!liste)
    {
        printf("liste n'exist pas");
        return ((int)-1);
    }
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem)
    {
        printf("Liste est saturee");
        return((int)-2);
    }
    //position non valide
    if ((pos < 1) || (liste->nbr_elem+1 < pos))
    {
        printf("position non valide");
        return((int)-3) ;
    }
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
}//fin fct inserer_position



// fct qui supprime  l'element qui se trouve dans une position p donnee
int supprimer_position_TListe(TListe *liste, int pos)
{ int i ;
    //liste n'exist pas
    if (!liste)
    {
        printf("liste n'exist pas");
        return ((int)-1);
    }
    //position non valide
    if ((pos < 1) || ((liste->nbr_elem)+ 1< pos))
    {
        printf("position non valide");
        return((int)-3) ;
    }
    //faire une boucle pour decaler les elemet du tableau
    for( i = pos-1; i < (liste->nbr_elem ); i++)
        liste->tab[i] = liste->tab[i+1];
    // decrementer le nombre d'element
    liste->nbr_elem--;
    return((int)1) ;//supprition effectuer
}// fin fct supprimer_position


/// fonction qui supprime le 1er element dans la liste egal a val
int supprimer_first_elem_TListe(TListe *liste, int val)
{ int i ;
    //liste n'exist pas
    if (!liste) return((int)-1) ;
    //liste existe
    //faire une boucle qui cherche le 1er element egale a val
    for(i = 0; i < liste->nbr_elem; i++)
        if (liste->tab[i] == val)
        {
            supprimer_position_TListe(liste, i+1);// utiliser la fct  supprimer_position pour supprimer l'element
            return ((int)1);
        }
    //element n'existe pas
    return ((int)-4);
} //fin fct supprimer_first_elem


/// fonction qui supprime tout les elements egal a val
int supprimer_elems_TListe(TListe *liste, int val)
{int i ;
    //liste n'exist pas
    if (!liste) return ((int)-1);
    //liste existe
    //faire une boucle pour trouver tout les element egal a val et les supprimer
    for( i = 0; i < liste->nbr_elem; i++)
    {
        supprimer_first_elem_TListe(liste,val);

    }
    return  ((int)1); // ELEMENT supprime

}// fin fct supprimer_elems

/*****************************************/

// fonction qui inverse l'ordre d'une liste
int inverser_TListe(TListe *liste)
{
    int i ;
    //liste n'exist pas
    if (!liste) return ((int)-1);
    // liste existe
    int tmp;
    //faire une boucle du 1er element du tableau jusqu'a nombre_element sur 2
    for (i = 0; i < liste->nbr_elem/2; ++i)
    { // utiliser une variable : tpm pour stocker la valeur a changer
        tmp = liste->tab[i];
        liste->tab[i] = liste->tab[liste->nbr_elem-i-1];
        liste->tab[liste->nbr_elem-i-1] = tmp;
    }

    return ((int)1);
}//fin fct inverser_liste


int get_max_val_TListe(TListe *liste) {
    int i ;
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int max = liste->tab[0];

    for (i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] > max)
            max = liste->tab[i];

    return max;
}
// fct retourne la position de l'element max
int get_max_pos_TListe(TListe *liste) {
    int i ;
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int max_pos = 0;
// boucle pour trouver si il y a un element plus grand que max
    for (i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] > liste->tab[max_pos])
            max_pos = i;
//retourner la position de max
    return max_pos;
}// fin fct

//fonction qui retourne l'element min dans le tableau
int get_min_val_TListe(TListe *liste) {
    int i ;
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int min = liste->tab[0];
// boucle pour trouver si il y a un element plus petit que min
    for (i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] < min)
            min = liste->tab[i];
// retourner l'element min
    return min;
}// fin fct

//// fct retourne la position de l'element min
int get_min_pos_TListe(TListe *liste) {
    int i ;
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int min_pos = 0;
// boucle pour trouver si il y a un element plus petit que min
    for ( i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] < liste->tab[min_pos])
            min_pos = i;
//retourner la position de min
    return min_pos;
}// fin fct


///fonction qui retourne le nombre d'occurence d'un element
int get_nbr_repetition_TListe(TListe *liste, int val)
{	//liste n'existe pas
    int i ;
    if (!liste) return((int) -1);
    //Liste est vide
    if (!liste->nbr_elem) return((int) 0);

    // compteur de repetition de la valeur donnee
    // intialiser a 0
    int compteur_rep = 0;
//boucle pour compter le nombre de fois
    for (i = 0; i < liste->nbr_elem; ++i)
        if (liste->tab[i] == val)
            compteur_rep++;
    //afficher
    printf("l'element %d existe %d fois dans la liste",val,compteur_rep);
    return  ((int)compteur_rep);
}// fin fct get_nbr_repetition

// fct retourne la valeur de la position p donnee
int acceder_val_TListe(TListe *liste, int pos)
{
    //Liste n'existe pas
    if (!liste) return((int)-1) ;
    //Liste est vide
    if (!liste->nbr_elem) return((int) 0);
    //position non valide
    if ((pos < 1) || (liste->nbr_elem < pos)) return((int) -3);
    // affichage de l'element
    printf ("l'element %d",liste->tab[pos-1]);
    return ((int)liste->tab[pos-1]);

}// fin fct


// fct affiche le contenu de la liste
int affiche_TListe(TListe *liste)
{
    int i ;
    //liste n'exist pas
    if (!liste)
    {printf("liste n'exist pas");
        return((int) -1);
    }
    // Liste est vide
    if (!liste->nbr_elem)
    {printf("Liste est vide");
        return((int)0) ;
    }
    // boucle pour afficher elementpar element
    for (i = 0; i < liste->nbr_elem; ++i)
    {
        printf("%d\t" ,  liste->tab[i]);
    }
    return ((int) 1);
}


// fct pour gerer les erreurs retourne 1 si il a un erreur et 0 sinon
int gestion_err_TListe(int val)
{ //si liste n'existe pas
    if(val==-1)
    {
        printf(" \n liste n'existe pas\n");
        return ((int)1);//  il  y a pas d'erreur
    }
    // si la liste est vide
    if(val==0)
    {
        printf(" \n liste vide \n");
        return ((int)1);//  il  y a pas d'erreur
    }
    // si la Liste est saturee
    if(val==-2)
    {
        printf(" \n Liste est saturee \n");
        return ((int)1);//  il  y a pas d'erreur
    }
    // si la entrer position non valide
    if(val==-3)
    {
        printf(" \n position non valide \n");
        return ((int)1); //  il  y a pas d'erreur
    }
    //si l'element n'esxiste pas dans la liste
    if(val==-4)
    {
        printf(" \n l element n'existe pas dans la liste" );
        return ((int)1); //  il  y a pas d'erreur
    }

    return ((int)0);  //   il n'y a pas d'erreur

}//fin fct


/// rechercher si un element existe dans la liste et donner sa position
int rechercher_elem_TListe(TListe liste,int elem)
{int i;
// verifier si la liste est vide
    if(liste.nbr_elem==0)
    { // printf("\n liste vide !!");
        return((int)0);
    }
    //boucle pour comparer chaque element de la liste avec la valeur entree
    for(i=0;i<liste.nbr_elem;i++)
    {   if (liste.tab[i]==elem)// trouver le 1er element = val
        {
            //afficher sa position
            return ((int)(i+1));
        }
    }//fin fct

//element n'esxiste pas dans la liste
    return ((int)-4);

}//fin fct

