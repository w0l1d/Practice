//
// Created by W0L1D on 11/9/2021.
//
#include <stdlib.h>
#include <stdio.h>

#define TailleMax 100


typedef struct tab
{ int T [TailleMax];
    int Nbelem;
}Maliste ;

//la fonction initialiser liste
int initialiser (Maliste *liste)
{
    liste->Nbelem=0 ;
    return ((int) liste->Nbelem);
}//fin de la fonction

// taille de la liste
int Taille_liste (Maliste liste)
{
    return ((int) liste.Nbelem) ;
}//fin de la fonction
//liste vide
int vide_liste (Maliste liste)
{ return ((int)( liste.Nbelem==0)) ;
}//fin de  la fonction
//liste pleine
int liste_saturee (Maliste liste)
{ return ((int)( liste.Nbelem==TailleMax)) ;
}//fin de la foncion
//inserer a une liste
int inserer_liste (Maliste *liste,int val,int pos)
{ int i ;
    if( !liste) //vérifier l’existence de la liste
    {printf ( "\n la liste n’existe pas") ;
        return ((int)-1) ;
    }
//vérification de la validité de la position
    if((pos<0)||(pos>liste->Nbelem))
        return ((int)0);
    if(liste_saturee(*liste)) //liste saturee
        return ((int)-2);
    for(i=liste->Nbelem-1; i >=pos; i--)
        liste->T[i+1]=liste->T[i];
    liste->T[pos]=val ;
//Mise à jour la taille de la liste
    liste->Nbelem++ ;
    return((int) 1) ;
} //fin de la fonction

void afficher_liste(Maliste liste)
{int i ; //variable courant
    for (i=0;i<= liste.Nbelem-1;i++)
        printf( "\n %d ",liste.T[i]) ;
}//fin de la fonction
int main ()
{
    Maliste L;
    L.Nbelem = 0;
//initialiser (L);
//Taille_liste (L);
    inserer_liste (&L,3,0);
    inserer_liste (&L,5,2);
    inserer_liste (&L,6,3);
    printf ("la taille est :%d",Taille_liste (L));
    afficher_liste(L);
}