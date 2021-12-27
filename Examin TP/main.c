//
// Created by W0L1D on 12/6/2021.
//


#include"fonctions.h"


void main() {
    Table *table = NULL;

    table = init_Table(table);



    inserer_queue_Table(table, 10);
    inserer_queue_Table(table, -1);
    inserer_queue_Table(table, 5);
    inserer_queue_Table(table, 10);
    inserer_queue_Table(table, 12);
    inserer_queue_Table(table, 4);
    inserer_queue_Table(table, 3);
    inserer_queue_Table(table, 6);
    inserer_queue_Table(table, 9);
    inserer_queue_Table(table, 15);
    inserer_queue_Table(table, 2);
    inserer_queue_Table(table, 0);

    /*
    *  QUESTION I-a
    *
    */
    printf("\n\naffichage I-a ::\n");
    affiche_Table(table);



    /*
     *  QUESTION I-b1
     *
     */
    supprimer_position_Table(table, 1);
    printf("\n\naffichage I-b1 ::\n");
    affiche_Table(table);


    /*
     *  QUESTION I-b2
     *
     */
    supprimer_position_Table(table, table->nbr_elem);
    printf("\n\naffichage I-b2 ::\n");
    affiche_Table(table);


    /*
     *  QUESTION I-b3
     *
     */
    supprimer_position_Table(table, 4);
    printf("\n\naffichage I-b3 ::\n");
    affiche_Table(table);


    /*
     *  QUESTION I-c1
     *
     */

    inserer_position_Table(table, 5, 1);
    printf("\n\naffichage I-c1 ::\n");
    affiche_Table(table);


    /*
     *  QUESTION I-c2
     *
     */

    inserer_position_Table(table, 15, table->nbr_elem);
    printf("\n\naffichage I-c2 ::\n");
    affiche_Table(table);



    /*
     *  QUESTION I-c3
     *
     */
    inserer_position_Table(table, -5, 7);
    printf("\n\naffichage I-c3 ::\n");
    affiche_Table(table);



    /*
     *  QUESTION II-a
     *
     */
    Cellule *pile = NULL;

    pile = trans_Table_PPile(*table);
    printf("\n\naffichage II-a ::\n");
    affiche_PPile(pile);



    /*
     *  QUESTION II-b1
     *
     */
    pile = supprimer_pos_PPile(pile, 1);
    printf("\n\naffichage II-b1 ::\n");
    affiche_PPile(pile);


    /*
     *  QUESTION II-b2
     *
     */
    pile = supprimer_pos_PPile(pile, taille_PPile(pile));
    printf("\n\naffichage II-b2 ::\n");
    affiche_PPile(pile);


    /*
     *  QUESTION II-b3
     *
     */
    pile = supprimer_pos_PPile(pile, 4);
    printf("\n\naffichage II-b3 ::\n");
    affiche_PPile(pile);




    /*
     *  QUESTION II-c1
     *
     */
    pile = empiler_pos_PPile(pile, 1, -2);
    printf("\n\naffichage II-c1 ::\n");
    affiche_PPile(pile);


    /*
     *  QUESTION II-c2
     *
     */
    pile = empiler_pos_PPile(pile, 5, 22);
    printf("\n\naffichage II-c2 ::\n");
    affiche_PPile(pile);


    /*
     *  QUESTION II-c3
     *
     */
    pile = empiler_pos_PPile(pile, taille_PPile(pile)+1, 33);
    printf("\n\naffichage II-c3 ::\n");
    affiche_PPile(pile);





    /*
     *  QUESTION III-a
     *
     */

    PFile *file = NULL;
    file = trans_PPile_PFile(pile);
    printf("\n\naffichage III-a ::\n");
    afficher_PFile(file);


    /*
     *  QUESTION III-b
     *
     */
    defiler_PFile(file);
    printf("\n\naffichage III-b ::\n");
    afficher_PFile(file);


    /*
     *  QUESTION III-c
     *
     */
    enfiler_PFile(file, -22);
    printf("\n\naffichage III-c ::\n");
    afficher_PFile(file);




    /*
     *  QUESTION IV-a
     *
     */
    PNode *arb = NULL;

    arb = trans_PFile_Arb(file);
    printf("\n\naffichage IV-a ::\n");
    affiche_arbre_Real_PNode_Ord(arb);






    /*
     *  QUESTION IV-b1
     *
     */

    printf("\n\naffichage IV-b1 ::\n");
    affiche_prefixer_PNode_Ord(arb);






    /*
     *  QUESTION IV-b2
     *
     */

    printf("\n\naffichage IV-b2 ::\n");
    affiche_infixer_PNode_Ord(arb);




    /*
     *  QUESTION IV-b3
     *
     */

    printf("\n\naffichage IV-b3 ::\n");
    affiche_postfixer_PNode_Ord(arb);


    /*
       *  QUESTION IV-c1
       *
       */


    arb = supp_PNode_Ord(arb, 9);
    printf("\n\naffichage IV-c1 ::\n");
    affiche_arbre_Real_PNode_Ord(arb);






    /*
       *  QUESTION IV-c2
       *
       */


    arb = supp_PNode_Ord(arb, 15);
    printf("\n\naffichage IV-c2 ::\n");
    affiche_arbre_Real_PNode_Ord(arb);




    /*
       *  QUESTION IV-d
       *
       */





}
