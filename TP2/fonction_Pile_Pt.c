//
// Created by W0L1D on 11/7/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct PPile {
    int val;
    struct PPile *svt;
}PPile;


void affiche_PPile(PPile *pile, int *status);

PPile* init_PPile(int val)
{
    PPile *pile = (PPile*) malloc(sizeof(PPile));

    if (!pile)
    {
        printf("\n\nErreur d'allocation de la memoire\n\n");
        exit(0);
    }

    pile->val = val;
    pile->svt = NULL;
    return pile;
}


PPile* empiler_PPile(PPile *pile, int val)
{
    PPile *nouveau = init_PPile(val);

    nouveau->svt = pile;
    return ((PPile*) nouveau);
}

PPile* depiler_PPile(PPile *pile)
{
    if (!pile) // si la pile n'exist pas
        return ((PPile*) NULL);

    PPile *tmp;
    //sauvegarder la valeur a depile
    tmp = pile;
    //detacher la valeur depile de la pile
    pile = pile->svt;
    //liberer la mermoire alloue a la valeur depilee
    free(tmp);

    return ((PPile*) pile);
}



PPile* vider_PPile(PPile *pile)
{

    PPile *tmp;

    while(pile) {
        tmp = pile;
        pile = pile->svt;
        free(tmp);
    }

    return ((PPile*) NULL);
}



// taille pile avec pt
int taille_PPile(PPile *pile)
{
    int size = 0;

    while (pile) {
        pile = pile->svt;
        size++;
    }

    return ((int)size);
}


PPile* inverser_PPile(PPile *pile, int *status)
{
    PPile *tmp = NULL;

    while (pile)
    {
        tmp = empiler_PPile(tmp, pile->val);
        pile = depiler_PPile(pile);
    }
    *status = (tmp)? 1: 0;
    return tmp;
}


PPile* supprimer_pos_PPile(PPile *pile, int pos, int *status) {
    //pile n'exist pas
    if (!pile)
    {
        *status = -1;
        return ((PPile*) pile);
    }

    //supprimer le premier element
    if (pos == 1)
    {
        *status = 1;
        return ((PPile*) pile->svt);
    }

    int indice = 1;
    int *s;
    PPile *tmp = NULL;

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

    return ((PPile*) pile);
}
/*

PPile* supprimer_val_PPile(PPile *pile, int val, int *status) {

    PPile *tmp = NULL;
    int i = 1, val_depile;

    *status = 1;

    while (pile)
    {
        val_depile = pile->val;
        pile = depiler_PPile(pile);

        if (val_depile == val)
        {
            *status = 1;
            break;
        }
        tmp = empiler_PPile(tmp, val_depile);
    }

    while (tmp)
    {
        val_depile = tmp->val;
        tmp = depiler_PPile(tmp);
        pile = empiler_PPile(pile, val_depile);
    }


    return ((PPile*) pile);
}
*/





PPile* max_val_PPile(PPile *pile, int *max, int *status) {
    *status = 1;

    //pile n'exist pas
    if (!pile)
    {
        *status = -1;
        return ((PPile*) pile);
    }

    int max_val;
    PPile *tmp = NULL;
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
    return ((PPile*) pile);
}




PPile* min_val_PPile(PPile *pile, int *min, int *status) {
    *status = 1;

    //pile n'exist pas
    if (!pile)
    {
        *status = -1;
        return ((PPile*) pile);
    }

    int min_val;
    PPile *tmp = NULL;
    min_val = pile->val;

    while (pile)
    {
        if (min_val > pile->val)
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
    return ((PPile*) pile);
}






void affiche_PPile(PPile *pile, int *status)
{
    //si la pile vide
    if (!pile)
    {
        printf("\nla liste est vide\n");
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

        case -3:
            printf("\nLa position est incorrecte\n");
            break;

    }
    return 0;
}






int menu_TPile_Pt()
{
    PPile *pile = NULL;
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
//               "\n 10  : Supprimer un element par valeur \n "
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
                pile = depiler_PPile(pile);
                printf("\nDepilage bien effectee\n");
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

           /* case 10:
                printf("\nEntrer la valeur : \n");
                scanf("%d",&tmp); getchar();
                pile = supprimer_val_PPile(pile, tmp,&status);
                if (handle_errors_PPile(*status))
                    printf("\nl'element est supprime.\n");
                getch();
                break;*/

            default :   printf("\n\nErreur : Choix Invalide\n\n");
                getch();
        }

    }while(choix);
}


/************************************************  END PILE AVEC TABLEAU *********************************************************/








