//
// Created by W0L1D on 12/4/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.c"


void main() {
    TListe * tlist = NULL;

    tlist = init_TListe(tlist);


    //****************** 1 ****************
    inserer_queue_TListe(tlist, 9);
    inserer_queue_TListe(tlist, 4);
    inserer_queue_TListe(tlist, 18);
    inserer_queue_TListe(tlist, 5);
    inserer_queue_TListe(tlist, 12);
    inserer_queue_TListe(tlist, 6);
    inserer_queue_TListe(tlist, 10);
    inserer_queue_TListe(tlist, 7);
    inserer_queue_TListe(tlist, 14);
    inserer_queue_TListe(tlist, 8);
    inserer_queue_TListe(tlist, 11);
    inserer_queue_TListe(tlist, 0);
    inserer_queue_TListe(tlist, 15);
    inserer_queue_TListe(tlist, -1);
    inserer_queue_TListe(tlist, 22);
    inserer_queue_TListe(tlist, 3);
    inserer_queue_TListe(tlist, 19);
    inserer_queue_TListe(tlist, 1);
    inserer_queue_TListe(tlist, 23);
    inserer_queue_TListe(tlist, 2);
    inserer_queue_TListe(tlist, 17);
    inserer_queue_TListe(tlist, 20);
    inserer_queue_TListe(tlist, 21);


    printf("\naffichage 1: \n");
    affiche_liste(tlist);
    printf("\n\n");

    //****************** 2 ****************
    supprimer_position(tlist, 1);
    supprimer_position(tlist, tlist->nbr_elem/2);
    supprimer_position(tlist, tlist->nbr_elem);

    printf("\naffichage 2: \n");
    affiche_liste(tlist);
    printf("\n\n");

    //****************** 3 ****************

    inserer_tete_TListe(tlist, 10);
    inserer_queue_TListe(tlist, -3);

    printf("\naffichage 3: \n");
    affiche_liste(tlist);
    printf("\n\n");


    //****************** 4 ****************

    Cellule *plist = NULL;




    printf("\n\n");
}