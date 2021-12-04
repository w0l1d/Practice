//
// Created by W0L1D on 11/4/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_ELEMS 30

typedef struct PileTab
{
    int tab[MAX_ELEMS];
    int sommet; // indique l'index du dernier element
} PileTab;


PileTab* createTPile()
{
    PileTab *pile = (PileTab*) malloc(sizeof(PileTab));
    pile->sommet = -1;
    if (!pile)
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }
    return pile;
}

PileTab* init_TPile(PileTab *pile)
{
    if (pile)
        free(pile);
    pile = createTPile();
    return pile;
}

// taille pile sans pt
int taille_TPile(PileTab pile) { return ((int)pile.sommet+1); }

int vider_pile(PileTab *pile, int *status)
{
    *status = 1;
    if (!pile) // pile n'existe pas
    {
        *status = -1;
        return 0;
    }

    pile->sommet = -1;
}


int est_TPile_vide(PileTab pile)
{
    return !(pile.sommet+1);
}

int empiler_TPile(PileTab *pile, int val, int *status)
{
    *status = 1;
    if (!pile) // pile n'existe pas
    {
        *status = -1;
        return 0;
    }
    if ((pile->sommet+1) == MAX_ELEMS) //pile est saturee
    {
        *status = -2;
        return 0;
    }

    // empilage et incrementation du sommet
    pile->tab[++(pile->sommet)] = val;

    return 1; // empilage est bien effectuée
}



int depiler_TPile(PileTab *pile, int *status)
{
    *status = 1;
    if (!pile) // pile n'existe pas
    {
        *status = -1;
        return 0;
    }
    if ((!(pile->sommet+1))) //si le sommet == -1
    {
        *status = 0;
        return 0; //pile est vide
    }

    // depilage et decrementation du sommet
    return pile->tab[pile->sommet--]; // retourne la valeur depiler

}


PileTab* inverser_TPile(PileTab *pile, int *status)
{
    //pile n'exist pas
    if (!pile)
    {
        *status = -1;
        return((PileTab*) NULL);
    }
    // TPile est vide
    if (!(pile->sommet+1))
    {
        *status = 0;
        return pile;
    }
    //initialisation de la pile temporaire
    PileTab *tmp = createTPile();
    int val_depile;

    while (!est_TPile_vide(*pile))
    {
        val_depile = depiler_TPile(pile, status);
        empiler_TPile(tmp, val_depile, status);
    }

    return ((PileTab*)tmp);
}

int trouver_val_TPile(PileTab *pile, int val, int *status)
{
    *status = 1;

    if (!pile) //pile n'exist pas
    {
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return 0;
    }
    if (est_TPile_vide(*pile))
    {
        *status = 0;
        return 0; //pile est vide
    }

    PileTab *tmp;
    int indice = -1,
            val_depiler;

    //initialisation de la pile temporaire
    tmp = createTPile();

    while (!est_TPile_vide(*pile))
    {
        val_depiler = depiler_TPile(pile, status);
        empiler_TPile(tmp, val_depiler, status);
        //si indice != -1 et val donne == valeur depile
        if ((val_depiler == val) && !(indice+1))
            indice = pile->sommet +2; //le sommet point sur l'indice la valeur au desous du val
    }

    //deplacer les elements vers la pile principale
    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_TPile(tmp, status);
        empiler_TPile(pile, val_depiler, status);
    }


    //La valeur n'est pas trouve dans la pile
    if (!(indice+1))
    {
        *status = -3;
        return -1;
    }

    return indice;
}

int max_val_TPile(PileTab *pile, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return 0;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return 0;
    }

    PileTab *tmp;
    int val_depiler, max_elem;

    //initialisation de la pile temporaire
    tmp = createTPile();

    max_elem = pile->tab[pile->sommet];

    while (!est_TPile_vide(*pile))
    {
        val_depiler = depiler_TPile(pile, status);
        empiler_TPile(tmp, val_depiler, status);
        //si indice != -1 et val donne == valeur depile
        if (max_elem < tmp->tab[tmp->sommet])
            max_elem = tmp->tab[tmp->sommet];
    }

    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_TPile(tmp, status);
        empiler_TPile(pile, val_depiler, status);
    }


    return max_elem;
}




int min_val_TPile(PileTab *pile, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return 0;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return 0;
    }

    PileTab *tmp;
    int val_depiler, min_elem;

    //initialisation de la pile temporaire
    tmp = createTPile();

    min_elem = pile->tab[pile->sommet];

    while (!est_TPile_vide(*pile))
    {
        val_depiler = depiler_TPile(pile, status);
        empiler_TPile(tmp, val_depiler, status);
        //si indice != -1 et val donne == valeur depile
        if (min_elem > tmp->tab[tmp->sommet])
            min_elem = tmp->tab[tmp->sommet];
    }


    //redeplace les elements vers la pile principale
    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_TPile(tmp, status);
        empiler_TPile(pile, val_depiler, status);
    }

    return min_elem;
} //FIN de fonction max_val_TPile





int nbr_occur_TPile(PileTab *pile, int val, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return 0;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return 0;
    }

    PileTab *tmp;
    int val_depiler, nbr_occur;

    tmp = createTPile();

    nbr_occur = 0;

    while (!est_TPile_vide(*pile))
    {
        val_depiler = depiler_TPile(pile, status);
        empiler_TPile(tmp, val_depiler, status);
        //si indice != -1 et val donne == valeur depile
        if (val == tmp->tab[tmp->sommet])
            nbr_occur++;
    }

    //redeplace les elements vers la pile principale
    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_TPile(tmp, status);
        empiler_TPile(pile, val_depiler, status);
    }


    return nbr_occur;
} //FIN de fonction nbr_occur_TPile






int trouver_pos_TPile(PileTab *pile, int pos, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return 0;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return 0;
    }

    PileTab *tmp;
    int val_depiler, val_pos;

    tmp = createTPile();

    val_pos = -1;

    while (!est_TPile_vide(*pile))
    {
        val_depiler = depiler_TPile(pile, status);
        empiler_TPile(tmp, val_depiler, status);
        //si sommet == position donnee
        if (pos == tmp->sommet) {
            val_pos = tmp->tab[tmp->sommet];
            break;
        }
            //empiler la valeur en pile temporiare
            empiler_TPile(tmp, val_depiler, status);

    }

    //redeplace les elements vers la pile principale
    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_TPile(tmp, status);
        empiler_TPile(pile, val_depiler, status);
    }


    return val_pos;
} //FIN de fonction trouver_pos_TPile



//supprimer le premier occurence du val
void supprimer_val_TPILE(PileTab *pile, int val, int *status)
{
    // si n'a pas changé de valeur
    // alors la position est erroné
    *status = -4;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return;
    }

    PileTab *tmp;
    int val_depiler;

    //initialisation de la pile
    tmp = createTPile();

    while (!est_TPile_vide(*pile))
    {
        val_depiler = depiler_TPile(pile, status);

        if (val == pile->tab[pile->sommet])
            break;

        //empiler la valeur en pile temporiare
        empiler_TPile(tmp, val_depiler, status);

    }

    //redeplace les elements vers la pile principale
    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_TPile(tmp, status);
        empiler_TPile(pile, val_depiler, status);
    }


} //FIN de fonction supprimer_val_TPILE





//supprimer toutes les occurences du val
void supprimer_all_occur_TPILE(PileTab *pile, int val, int *status)
{
    // si n'a pas changé de valeur
    // alors la position est erroné
    *status = -4;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return;
    }

    PileTab *tmp;
    int val_depiler;

    //initialisation de la pile
    tmp = createTPile();


    while (!est_TPile_vide(*pile))
    {
        val_depiler = depiler_TPile(pile, status);

        //sauter cette valeur si elle est == val
        if (val == pile->tab[pile->sommet])
            continue;

        //empiler la valeur en pile temporiare
        empiler_TPile(tmp, val_depiler, status);

    }

    //redeplace les elements vers la pile principale
    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_TPile(tmp, status);
        empiler_TPile(pile, val_depiler, status);
    }


} //FIN de fonction supprimer_all_occur_TPILE



//supprimer le premier occurrence du val
void supprimer_pos_TPILE(PileTab *pile, int pos, int *status)
{
    // si n'a pas changé de valeur
    // alors la position est erroné
    *status = -4;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return;
    }

    PileTab *tmp;
    int val_depiler;

    //initialisation de la pile
    tmp = createTPile();


    while (!est_TPile_vide(*pile))
    {
        //depiler de la file
        val_depiler = depiler_TPile(pile, status);

        if (pos-1 == pile->sommet) // la position à supprimer est trouvee
        {
            *status = 1;
            break;
        }

        //empiler la valeur en pile temporiare
        empiler_TPile(tmp, val_depiler, status);

    }

    //redeplace les elements vers la pile principale
    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_TPile(tmp, status);
        empiler_TPile(pile, val_depiler, status);
    }


} //FIN de fonction supprimer_pos_TPILE




void affiche_TPile(PileTab *pile, int *status)
{
    //pile n'exist pas
    if (!pile)
    {
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return;
    }
    // TPile est vide
    if (!(pile->sommet+1))
    {
        *status = 0;
        printf("\nla liste est vide\n");
        return;
    }

    printf("\nle elements de la pile : \n");

    for (int i = 0; i <= pile->sommet; ++i)
        printf("%d\t", pile->tab[i]);

}






int handle_errors_TPile(int cd)
{
    switch (cd) {

        case 1:
            return 1;
        case -1:
            printf("\nLa pile n'existe pas\n");
            break;
        case -2:
            printf("\nLa pile est saturee\n");
            break;

        case -3:
            printf("\nLa valeur n'est pas trouve\n");
            break;

        case -4:
            printf("\nLa position n'est pas correcte\n");
            break;

        case 0:
            printf("\nLa pile est vide\n");
            break;

    }
    return 0;
}




int menu_TPile_Tab()
{
    PileTab *pile = createTPile();
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
               "\n 7   : Trouver la position d'une valeur \n "
               "\n 8   : Trouver la valeur a une position \n "
               "\n 9   : Nombre d'occurence d'une valeur \n "
               "\n 10  : Supprimer par la position \n "
               "\n 11  : Supprimer la valeur \n "
               "\n 12  : Supprimer tous les occurances d'une valeur \n "
               "\n 13  : Trouver le maximum d'une pile \n "
               "\n 14  : Trouver le minimum d'une pile \n "
               "\n 0   : retour vers menu principal \n"
               "\n **********************************************************************************************************************\n "
               "\n >>>>>\t");

        scanf("%d", &choix); getchar();

        switch(choix)
        {
            case 0: break;

            case 1:
                pile = init_TPile(pile);
                printf("la Pile bien Initialise");
                break;

            case 2:
                printf ("\nLa taille de la pile : %d\n", taille_TPile(*pile));
                getch();
                break;

            case 3:
                affiche_TPile(pile, status);
                getch();
                break;

            case 4:
                printf("\nEntrer un entier : ");
                scanf("%d",&tmp);
                empiler_TPile(pile, tmp, status);
                if (handle_errors_TPile(*status))
                    printf("\nEmpilage bien effectee\n");
                getch();
                break;

            case 5:
                depiler_TPile(pile, status);
                if (handle_errors_TPile(*status))
                    printf("\nDepilage bien effectee\n");
                getch();
                break;

            case 6:
                pile = inverser_TPile(pile, status);
                if (handle_errors_TPile(*status))
                    printf("\nPile est inverse\n");
                getch();
                break;

            case 7:
                printf("\nEntrer la valeur a trouve : ");
                scanf("%d",&tmp);
                tmp2 = trouver_val_TPile(pile, tmp, status);
                if (handle_errors_TPile(*status))
                    printf("\nL'entier %d se trouve a la position %d.\n", tmp, tmp2);
                getch();
                break;


            case 8:
                printf("\nEntrer la position : ");
                scanf("%d",&tmp);
                tmp2 = trouver_pos_TPile(pile, tmp, status);
                if (handle_errors_TPile(*status))
                    printf("\nL'entier %d se trouve a la position %d.\n", tmp, tmp2);
                getch();
                break;




            case 9:

                printf("Entrer la valeur : ");
                scanf("%d", &tmp);
                tmp2 = nbr_occur_TPile(pile, tmp, status);

                if (handle_errors_TPile(*status))
                    printf("\nLe Nombre d'occurence de %d de la pile est %d.\n", tmp, tmp2);
                getch();
                break;

            case 10:

                printf("\nEntrer la position de la valeur a supprime : ");
                scanf("%d",&tmp);
                supprimer_pos_TPILE(pile, tmp, status);
                if (handle_errors_TPile(*status))
                    printf("\nl'element est supprimee.\n");

                getch();
                break;

            case 11:

                printf("\nEntrer la valeur a supprime : ");
                scanf("%d",&tmp);
                supprimer_val_TPILE(pile, tmp, status);
                if (handle_errors_TPile(*status))
                    printf("\nl'element est supprimee.\n");

                getch();
                break;

            case 12:
                printf("\nEntrer la valeur a supprime : ");
                scanf("%d",&tmp);
                supprimer_all_occur_TPILE(pile, tmp, status);
                if (handle_errors_TPile(*status))
                    printf("\nles occurences de l'element sont supprimes.\n");

                getch();
                break;

            case 13:

                tmp = max_val_TPile(pile, status);

                if (handle_errors_TPile(*status))
                    printf("\nLe Maximum de la pile est %d.\n", tmp);
                getch();
                break;

            case 14:

                tmp = min_val_TPile(pile, status);

                if (handle_errors_TPile(*status))
                    printf("\nLe Minimum de la pile est %d.\n", tmp);
                getch();
                break;

            default :   printf("\n\nErreur : Choix Invalide\n\n");

                getch();
        }

    }while(choix);
}


/************************************************  END PILE AVEC TABLEAU *********************************************************/





