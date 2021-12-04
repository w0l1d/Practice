
    #include <stdio.h>
    #include <stdlib.h>
    #include "B_arbre_horiz_Pt.c"
    #include "B_arbre_horiz_tab.c"
    #include "arbre_non_ordonne.c"
    int main()
    {
        // Arbre Non Ordonee avec pointeur
        PNode *root_Ord = NULL;

        root_Ord = insert_Pt(root_Ord, 7);
        root_Ord = insert_Pt(root_Ord, 3);
        root_Ord = insert_Pt(root_Ord, 9);
        root_Ord = insert_Pt(root_Ord, 2);
        root_Ord = insert_Pt(root_Ord, 5);
        root_Ord = insert_Pt(root_Ord, 8);
        root_Ord = insert_Pt(root_Ord, 10);
        root_Ord = insert_Pt(root_Ord, 11);
        root_Ord = insert_Pt(root_Ord, 1);
        root_Ord = insert_Pt(root_Ord, 4);
        root_Ord = insert_Pt(root_Ord, 6);


        // Arbre Ordonee avec tableau
        Tree *arb = NULL;
        arb = init_Arbre_Tab();
        insert_Tab(arb, 7, 0);
        insert_Tab(arb, 3, 0);
        insert_Tab(arb, 9, 0);
        insert_Tab(arb, 2, 0);
        insert_Tab(arb, 5, 0);
        insert_Tab(arb, 8, 0);
        insert_Tab(arb, 10, 0);
        insert_Tab(arb, 11, 0);
        insert_Tab(arb, 1, 0);
        insert_Tab(arb, 4, 0);
        insert_Tab(arb, 6, 0);



        // Arbre Ordonee avec pointeur
        Noeud * root_NOrd = NULL;


        root_NOrd = insertion_automatique(root_NOrd, 7);
        root_NOrd = insertion_automatique(root_NOrd, 3);
        root_NOrd = insertion_automatique(root_NOrd, 9);
        root_NOrd = insertion_automatique(root_NOrd, 2);
        root_NOrd = insertion_automatique(root_NOrd, 8);
        root_NOrd = insertion_automatique(root_NOrd, 5);
        root_NOrd = insertion_automatique(root_NOrd, 10);
        root_NOrd = insertion_automatique(root_NOrd, 1);
//        root_NOrd = insertion_automatique(root_NOrd, 99);
//        root_NOrd = insertion_automatique(root_NOrd, 4);
//        root_NOrd = insertion_automatique(root_NOrd, 98);
//        root_NOrd = insertion_automatique(root_NOrd, 97);
//        root_NOrd = insertion_automatique(root_NOrd, 96);
//        root_NOrd = insertion_automatique(root_NOrd, 6);
//        root_NOrd = insertion_automatique(root_NOrd, 11);
//
//        root_NOrd = supp_arbre_no(root_NOrd, 99);
//        root_NOrd = supp_arbre_no(root_NOrd, 98);
//        root_NOrd = supp_arbre_no(root_NOrd, 97);
//        root_NOrd = supp_arbre_no(root_NOrd, 96);





        char choix;
        do
        {
            fflush(stdin);
            printf("\n******************* menu principal ***********************\n");
            printf("\n 1 : arbre Binaire Ordonne Horizontalement avec Pointeur \n");
            printf("\n 2 : arbre Binaire Ordonne Horizontalement avec Tableau \n");
            printf("\n 3 : arbre Binaire non ordonne \n");
            printf("\n 0 : Quitter \n");
            printf(">>>>>  ");
            scanf("%c",&choix);
            fflush(stdin);
            switch(choix)
            {
                case '1':
                    root_Ord = b_arbrePt_menu(root_Ord);
                    break;
                case '2':
                    arb = b_arbreTab_menu(arb);
                    break;
                case '3':
                    root_NOrd = menu_arb_non_ord(root_NOrd);
                    break;
                case '0':
                        exit(-1);

                default :
                    printf("\n choix non valide!!");
            }
        }while(choix);
     }
