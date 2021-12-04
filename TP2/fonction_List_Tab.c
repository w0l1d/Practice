//
// Created by W0L1D on 11/2/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define MAX_ELEMS 30



typedef struct ListeTab
{
    int tab[MAX_ELEMS];
    int nbr_elem;
} ListeTab;


ListeTab* createListe()
{
    ListeTab *liste = (ListeTab*) malloc(sizeof(ListeTab));
    liste->nbr_elem = 0;
    if (!liste)
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }
    return liste;
}

ListeTab* init_Liste(ListeTab *liste)
{
    if (liste)
        free(liste);
    liste = createListe();
    return liste;
}

// taille liste sans pt

int taille_liste(ListeTab liste) { return ((int)liste.nbr_elem); }

int vider_liste(ListeTab *liste)
{
    if (!liste) return -1; //liste n'existe pas

    liste->nbr_elem = 0;
}

int inserer_queue(ListeTab *liste, int val)
{
    //liste n'exist pas
    if (!liste) return -1;
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem) return -2;

    liste->tab[liste->nbr_elem++] = val;
    return 1;
}

int inserer_position(ListeTab *liste, int val, int pos)
{
    //liste n'exist pas
    if (!liste) return -1;
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem) return -2;
    //position non valide
    if ((pos < 1) || (liste->nbr_elem+1 < pos)) return -3;
    pos--;

    for(int i = liste->nbr_elem; i > pos; --i)
        liste->tab[i] = liste->tab[i-1];

    liste->tab[pos] = val;
    liste->nbr_elem++;

    return 1;
}

int supprimer_position(ListeTab *liste, int pos)
{
    //liste n'exist pas
    if (!liste) return -1;
    //position non valide
    if ((pos < 1) || (liste->nbr_elem < pos)) return -3;

    for(int i = pos-1; i < liste->nbr_elem; ++i)
        liste->tab[i] = liste->tab[i+1];

    liste->nbr_elem--;

    return 1;
}

int supprimer_elems(ListeTab *liste, int val)
{
    //liste n'exist pas
    if (!liste) return -1;

    for(int i = 0; i < liste->nbr_elem; ++i)
        if (liste->tab[i] == val)
            supprimer_position(liste, i);

    return 1;
}

int supprimer_first_elem(ListeTab *liste, int val)
{
    //liste n'exist pas
    if (!liste) return -1;

    for(int i = 0; i < liste->nbr_elem; ++i)
        if (liste->tab[i] == val) {
            supprimer_position(liste, i);
            break;
        }
    return 1;
}

int inverser_liste(ListeTab *liste)
{
    //liste n'exist pas
    if (!liste) return -1;

    int tmp;
    for (int i = 0; i < liste->nbr_elem/2; ++i)
    {
        tmp = liste->tab[i];
        liste->tab[i] = liste->tab[liste->nbr_elem-i-1];
        liste->tab[liste->nbr_elem-i-1] = tmp;
    }
}

int get_max_val(ListeTab *liste) {
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int max = liste->tab[0];

    for (int i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] > max)
            max = liste->tab[i];

    return max;
}

int get_max_pos(ListeTab *liste) {
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int max_pos = 0;

    for (int i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] > liste->tab[max_pos])
            max_pos = i;

    return max_pos;
}

int get_min_val(ListeTab *liste) {
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int min = liste->tab[0];

    for (int i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] < min)
            min = liste->tab[i];

    return min;
}

int get_min_pos(ListeTab *liste) {
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int min_pos = 0;

    for (int i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] < liste->tab[min_pos])
            min_pos = i;

    return min_pos;
}

int get_nbr_repetition(ListeTab *liste, int val)
{
    if (!liste) return -1; //liste n'existe pas

    // compteur de repetition de la valeur donnee
    // intialiser a 0
    int compteur_rep = 0;

    for (int i = 0; i < liste->nbr_elem; ++i)
        if (liste->tab[i] == val)
            compteur_rep++;
    return compteur_rep;
}

int acceder_val(ListeTab *liste, int pos)
{
    //Liste n'existe pas
    if (!liste) return -1;
    //position non valide
    if ((pos < 1) || (liste->nbr_elem < pos)) return -3;

    return liste->tab[pos-1];

}

int affiche_liste(ListeTab *liste)
{
    //liste n'exist pas
    if (!liste) return -1;
    // Liste est vide
    if (!liste->nbr_elem) return 0;

    for (int i = 0; i < liste->nbr_elem; ++i)
        printf("%d\t", liste->tab[i]);
    printf("\n");
}





int menu_Liste_Tab()
{
    ListeTab *liste = createListe();
    int choix;
    do
    {
        //initialiser le choix
        choix = -1;
        printf("\n *****************************************************************************************************************\n "
               "\n 1  : reinitialiser/vider votre liste \n"
               "\n 2  : taille de liste \n"
               "\n 3  : inserer un element a une position p\n"
               "\n 4  : inserer un element en queue de liste  \n"
               "\n 5  : affichage de la liste \n"
               "\n 6  : rechercher si un element existe dans la liste \n"
               "\n 7  : afficher l'element qui existe dans la position p \n "
               "\n 8  : afficher nombre occurence d'un element \n "
               "\n 9  : supprimer la 1ER occurence d'un element \n "
               "\n 10 : supprimer l'element a la position p \n "
               "\n 11 : supprimer tout les occurences d'un element \n "
               "\n 0 : retour vers menu principal \n"
               "\n **********************************************************************************************************************\n "
               "\n >>>>>\t");

        scanf("%d", &choix); getchar();

        switch(choix)
        {
            case 1:
                liste = init_Liste(liste);
                printf("Liste bien Initialise");
                break;
            case 2:
                printf ("La taille de la liste : %d", taille_liste(*liste));
                getch();
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;

        }

    }while(choix);
}


/************************************************  END LISTE AVEC TABLEAU *********************************************************/
