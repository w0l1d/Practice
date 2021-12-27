// declaration des Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "structures.h"


void affiche_PPile(Cellule *pile, int *status);

Cellule* init_PPile(int val)
{
    Cellule *pile = (Cellule*) malloc(sizeof(Cellule));

    if (!pile)
    {
        printf("\n\nErreur d'allocation de la memoire\n\n");
        exit(0);
    }

    pile->val = val;
    pile->svt = NULL;
    return pile;
}


Cellule* empiler_PPile(Cellule *pile, int val)
{
    Cellule *nouveau = init_PPile(val);

    nouveau->svt = pile;
    return ((Cellule*) nouveau);
}

Cellule* depiler_PPile(Cellule *pile)
{
    if (!pile) // si la pile n'exist pas
        return ((Cellule*) NULL);

    Cellule *tmp;
    //sauvegarder la valeur a depile
    tmp = pile;
    //detacher la valeur depile de la pile
    pile = pile->svt;
    //liberer la mermoire alloue a la valeur depilee
    free(tmp);

    return ((Cellule*) pile);
}



Cellule* vider_PPile(Cellule *pile)
{

    Cellule *tmp;

    while(pile) {
        tmp = pile;
        pile = pile->svt;
        free(tmp);
    }

    return ((Cellule*) NULL);
}



// taille pile avec pt
int taille_PPile(Cellule *pile)
{
    int size = 0;

    while (pile) {
        pile = pile->svt;
        size++;
    }

    return ((int)size);
}


Cellule* inverser_PPile(Cellule *pile, int *status)
{
    Cellule *tmp = NULL;

    while (pile)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }
    *status = (tmp)? 1: 0;
    return tmp;
}


Cellule* supprimer_pos_PPile(Cellule *pile, int pos, int *status) {
    //pile n'exist pas
    if (!pile)
    {
        *status = -1;
        return ((Cellule*) pile);
    }

    //supprimer le premier element
    if (pos == 1)
    {
        *status = 1;
        return ((Cellule*) pile->svt);
    }

    int indice = 1;
    int *s;
    Cellule *tmp = NULL;

    while (indice < pos)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        indice++;
    }

    //element n'est pas trouver
    // position donnee est erronee
    if (indice != pos)
        *status = -3;
    else
    {
        pile = depiler_PPile(pile);
        *status = 1;
    }

    int i = 0;
    while (tmp)
    {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    return ((Cellule*) pile);
}


Cellule* supprimer_val_PPile(Cellule *pile, int val, int *status)
{

    Cellule *tmp = NULL;
    int val_depile;

    *status = -2;

    while (pile)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        if (tmp->val == val)
        {
            tmp = depiler_PPile(tmp);
            *status = 1;
            break;
        }

    }

    while (tmp)
    {
        val_depile = tmp->val;
        tmp = depiler_PPile(tmp);
        pile = empiler_PPile(pile, val_depile);
    }


    return ((Cellule*) pile);
}






Cellule* supprimer_all_val_PPile(Cellule *pile, int val, int *status)
{

    Cellule *tmp = NULL;
    int val_depile;

    *status = -2;

    while (pile)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
        if (tmp->val == val)
        {
            tmp = depiler_PPile(tmp);
            *status = 1;
        }

    }

    while (tmp)
    {
        val_depile = tmp->val;
        tmp = depiler_PPile(tmp);
        pile = empiler_PPile(pile, val_depile);
    }


    return ((Cellule*) pile);
}




Cellule* max_val_PPile(Cellule *pile, int *max, int *status) {
    *status = 1;

    //pile n'exist pas
    if (!pile)
    {
        *status = -1;
        return ((Cellule*) pile);
    }

    int max_val;
    Cellule *tmp = NULL;
    max_val = pile->val;

    while (pile)
    {
        if (max_val < pile->val)
        {
            max_val = pile->val;
            *status = 1;
        }

        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }


    while (tmp)
    {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    *max = max_val;
    return ((Cellule*) pile);
}




Cellule* min_val_PPile(Cellule *pile, int *min, int *status) {
    *status = 1;

    //pile n'exist pas
    if (!pile)
    {
        *status = -1;
        return ((Cellule*) pile);
    }

    int min_val;
    Cellule *tmp = NULL;
    min_val = pile->val;

    while (pile)
    {
        if (min_val < pile->val)
        {
            min_val = pile->val;
            *status = 1;

        }

        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }

    while (tmp)
    {
        pile = empiler_PPile(pile, tmp->val);
        tmp = depiler_PPile(tmp);
    }

    *min = min_val;
    return ((Cellule*) pile);
}






void affiche_PPile(Cellule *pile, int *status)
{
    //si la pile vide
    if (!pile)
    {
        printf("\nla Pile est vide\n");
        *status = 0;
        return;
    }


    printf("\nle elements de la pile : \n");

    while (pile)
    {
        printf("%d\t", pile->val);
        pile = pile->svt;
    }
    printf("\n");
}





Cellule* affiche_PPile_principe(Cellule *pile, int *status)
{
    //si la pile vide
    if (!pile)
    {
        printf("\nla liste est vide\n");
        *status = 0;
        return pile;
    }


    Cellule *tmp;
    int val_depile;

    printf("\nle elements de la pile : \n");

    while (pile)
    {
        val_depile = pile->val;
        pile = depiler_PPile(pile);
        tmp = empiler_PPile(tmp, val_depile);
        printf("%d\t", val_depile);
    }
    printf("\n");


    while (tmp)
    {
        val_depile = tmp->val;
        tmp = depiler_PPile(tmp);
        pile = empiler_PPile(pile, val_depile);
    }

    *status = 1;
    return pile;
}


int handle_errors_PPile(int cd)
{
    switch (cd)
    {
        case 1:
            return 1;

        case 0:
            printf("\nLa pile est vide\n");
            break;

        case -1:
            printf("\nLa pile n'existe pas\n");
            break;

        case -2:
            printf("\nLa valeur n'est pas trouver\n");
            break;

        case -3:
            printf("\nLa position est incorrecte\n");
            break;

    }
    return 0;
}






int menu_TPile_Pt()
{
    Cellule *pile = NULL;
    int choix; // choix de l'utilisateur

    int *status = (int*) malloc(sizeof(int)); // status de l'operation effectuee par la fonction
    int tmp, tmp2;
    do
    {
        //initialiser le choix
        choix = -1;

        printf("\n *****************************************************************************************************************\n "
               "\n 1   : reinitialiser/vider votre pile \n"
               "\n 2   : taille de pile \n"
               "\n 3   : affichage de la pile \n"
               "\n 4   : Empiler \n"
               "\n 5   : Depiler \n "
               "\n 6   : Inverser la pile \n "
               "\n 7   : Maximum de la pile \n "
               "\n 8   : Minimum de la pile \n "
               "\n 9   : Supprimer un element par position \n "
               "\n 10  : Supprimer un element par valeur \n "
               "\n 11  : Supprimer les occurrences d'une valeur \n "
               "\n 12  : Afficher la pile en respectant le principe \n "
               "\n 0   : retour vers menu principal \n"
               "\n **********************************************************************************************************************\n "
               "\n >>>>>\t");

        scanf("%d", &choix); getchar();

        switch(choix)
        {
            case 0: break;

            case 1:
                pile = vider_PPile(pile);
                printf("la Pile bien Initialise");
                break;

            case 2:
                printf ("\nLa taille de la pile : %d\n", taille_PPile(pile));
                getch();
                break;

            case 3:
                affiche_PPile(pile, status);
                getch();
                break;

            case 4:
                printf("\nEntrer un entier : ");
                scanf("%d",&tmp); getchar();
                pile = empiler_PPile(pile, tmp);
                printf("\nEmpilage bien effectee\n");
                getch();
                break;

            case 5:
                if (!pile)
                    printf("\nLa pile est vide\n");
                else
                {
                    pile = depiler_PPile(pile);
                    printf("\nDepilage bien effectee\n");
                }
                getch();
                break;

            case 6:
                pile = inverser_PPile(pile, status);
                if (handle_errors_PPile(*status))
                    printf("\nPile est inverse\n");
                getch();
                break;

            case 7:
                max_val_PPile(pile, &tmp, status);

                if (handle_errors_PPile(*status))
                    printf("\nLe Maximum de la pile est %d.\n", tmp);
                getch();
                break;

            case 8:
                min_val_PPile(pile, &tmp, status);
                if (handle_errors_PPile(*status))
                    printf("\nLe Minimum de la pile est %d.\n", tmp);
                getch();
                break;

            case 9:
                printf("\nEntrer la position : \n");
                scanf("%d",&tmp); getchar();
                pile = supprimer_pos_PPile(pile, tmp, status);
                if (handle_errors_PPile(*status))
                    printf("\nl'element est supprime.\n");
                getch();
                break;

            case 10:
                printf("\nEntrer la valeur : \n");
                scanf("%d",&tmp); getchar();
                pile = supprimer_val_PPile(pile, tmp,status);
                if (handle_errors_PPile(*status))
                    printf("\nles occurrences sont supprimes.\n");
                getch();
                break;

            case 11:
                printf("\nEntrer la valeur : \n");
                scanf("%d",&tmp); getchar();
                pile = supprimer_all_val_PPile(pile, tmp,status);
                if (handle_errors_PPile(*status))
                    printf("\nl'element est supprime.\n");
                getch();
                break;

            case 12:
                pile = affiche_PPile_principe(pile, status);
                getch();
                break;

            default :   printf("\n\nErreur : Choix Invalide\n\n");

                getch();
        }

    }while(choix);
}


/************************************************  END PILE AVEC TABLEAU *********************************************************/








