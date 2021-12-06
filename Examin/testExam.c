#include "fonction.h"

int main(int argc, char const *argv[])
{
    Maliste *liste = NULL;
    TPile *Mapile = NULL;
    PPile *MapileP = NULL;
    TFile *Mafile = NULL;
    PFile *MafileP = cree_Pfile();
    Cellule *Malistep = NULL;
    Noeud *Arbre = NULL,*nval=NULL;
    int res=0;
    int Tab[] = {9, 4, 18, 5, 12, 6, 10, 7, 14, 8, 11, 0, 15, -1, 22, 3, 19, 1, 23, 2, 17, 20, 21};

    printf("\n\n Affichage 1 \n");
    liste=Remplir_TListe_tableau(Tab,23);
   Afficher_liste(liste);


    printf("\n\n Affichage 2 \n");
   res=Supprimer_pos_liste(liste,0);
   res=Supprimer_val_liste(liste,11);
   res=Supprimer_pos_liste(liste,liste->nbElement-1);
   Afficher_liste(liste);


    printf("\n\n Affichage 3 \n");
   res=Insert_pos_liste(liste,0,10);
   res=Insert_pos_liste(liste,liste->nbElement,-3);
    Afficher_liste(liste);


    printf("\n\n Affichage 4 \n");
   Malistep = trans_TListe_PListe(liste);
    Afficher_pliste(Malistep);

    printf("\n\n Affichage 5 \n");
    Malistep = Inserer_tete_pliste(Malistep,15);
    Malistep = Inserer_fin_pliste(Malistep,-1);
    Afficher_pliste(Malistep);


    printf("\n\n Affichage 6.1\n");
    Malistep = Supprimer_val_pliste(Malistep,10);
    Afficher_pliste(Malistep);

    printf("\n\n Affichage 6.2 \n");
    Malistep = Supprimer_val_pliste(Malistep,-1);
    Malistep = Inserer_tete_pliste(Malistep,99);
    Afficher_pliste(Malistep);


     printf("\n\n Affichage 7 \n");
    Mapile = NULL;
    MapileP = trans_PListe_PPile(Malistep);
    Afficher_Ppile(MapileP);



    printf("\n\n Affichage 8.1 \n");
    //printf("\n %d ",Taile_PPile(MapileP));
    Afficher_Ppile(MapileP);


    printf("\n\n Affichage 8.2 \n");
    MapileP = Supprimer_PPile_pos(MapileP,1);
    //MapileP = Inserer_PPile_pos(MapileP,-1,2);
    MapileP = Inserer_PPile_pos(MapileP,-1,2);
    Afficher_Ppile(MapileP);

    printf("\n\n Affichage 9 \n");
    //MapileP = Supprimer_PPile_pos(MapileP,1);
    MapileP = Inserer_PPile_pos(MapileP,7,6);
    Afficher_Ppile(MapileP);
    


       return 0;
}
