// declaration des Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include "fonction_List_Tab.c"
#include "fonction_List_Pt.c"
#include "fonction_Pile_Tab.c"
#include "fonction_Pile_Pt.c"
#include "fonction_File_Tab.c"
#include "fonction_File_Pt2.c"

void menu() {
    char choix;// stocke le choix de l'utilisateur
    do {
      printf("\n *******************************************************************************************************\n "
               "\n Choisissez ce que vous voullez manipuler : \n"
               "\n 1 : Liste avec Tableau \n"
               "\n 2 : Liste avec Pointeurs \n"
               "\n 3 : Pile avec Tableau \n"
               "\n 4 : Pile avec Pointeurs \n"
               "\n 5 : File avec Tableau \n"
               "\n 6 : File avec Pointeurs \n"
               "\n 0 : QUITTER \n"
               "\n\n>>>>  ");
        scanf("%c", &choix);
        switch(choix)
        {
            case '0': break;
            case '1':     menu_Liste_Tab(); break;
            case '2':     menu_Liste_pt() ;break;
            case '3':  	  menu_TPile_Tab() ;break;
            case '4':     menu_TPile_Pt() ;break;
            case '5':     menu_TFile_Tab(); break;
            case '6':     menu_PFile_Pt();  break;
          default :   // si choix est != de ces caracteres 
			printf("\n\n Erreur : Choix Invalide\n\n");
            getch();
        }
    }while(choix);
}
void main()
{
    menu();
}
