//
// Created by W0L1D on 12/5/2021.
//
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "fonctions_PPile.c"




void main() {

    Cellule *pile = NULL;
    pile = empiler_PPile(pile, 1);
    pile = empiler_PPile(pile, 2);
    pile = empiler_PPile(pile, 3);
    pile = empiler_PPile(pile, 4);
    pile = empiler_PPile(pile, 5);
    pile = empiler_PPile(pile, 6);
    pile = empiler_PPile(pile, 7);


    printf("\n\nAffichage 1.1 :: \n");
    pile = affiche_PPile(pile);


    printf("\n\nAffichage 1.2 :: \n");

    pile = empiler_bon_pos_Decr_PPile(pile, 5);
    pile = affiche_PPile(pile);

    printf("\n\nAffichage 1.2 :: \n");

    pile = empiler_bon_pos_Decr_PPile(pile, 8);
    pile = affiche_PPile(pile);
    printf("\n\nAffichage 1.2 :: \n");

    pile = empiler_bon_pos_Decr_PPile(pile,0 );
    pile = affiche_PPile(pile);



    printf("\n\nAffichage 2 :: \n");
    pile = empiler_pos_PPile(pile, 1, 11);
    pile = affiche_PPile(pile);


    printf("\n\nAffichage 3 :: \n");
    pile = empiler_pos_PPile(pile, 9, 99);
    pile = affiche_PPile(pile);


    printf("\n\nAffichage 4 :: \n");
    pile = empiler_pos_PPile(pile, 5, 55);
    pile = affiche_PPile(pile);




}
