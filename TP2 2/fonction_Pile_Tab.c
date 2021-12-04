// declaration des Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "structures.h"




// la fct creer liste 
TSmtCel* createTPile()
{// declaration + allocation de la memoire
    TSmtCel *pile = (TSmtCel*) malloc(sizeof(TSmtCel));
    pile->sommet = -1;//
    if (!pile)//si liste existe
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }
    return((TSmtCel *)pile) ;
}//fin fct

// fct qui initialise la pile
TSmtCel* init_TPile(TSmtCel *pile)
{//si pile existe 
    if (pile)
        free(pile);
  //sinon creer une pile
    pile = createTPile();
    return ((TSmtCel*)pile);
}//fin fct

// taille pile  
int taille_TPile(TSmtCel pile)
  { return ((int)pile.sommet+1);
  }//fin fct

// fct qui vide la pile
int vider_pile(TSmtCel *pile, int *status)
{
    *status = 1;// valeur pour gerer les erreur
    if (!pile) // pile n'existe pas
    {
	   *status = -1;
        return((int)0) ;
    }
    pile->sommet = -1; //modifier la valeur 
}//fin fct

// fct verifier si la pile est vide retourne 1 si vide
// et 1 sinon
int est_TPile_vide(TSmtCel pile)
{
    return !(pile.sommet+1);
}//fin fct

//Fct empile une valeur dans la pile
int empiler_Tab(TSmtCel *pile, int val, int *status)
{
    *status = 1;// pour la gestion des erreurs
    if (!pile) // pile n'existe pas
    {
        *status = -1;
        return ((int)0);
    }
	//pile existe pas
    if ((pile->sommet+1) == MAX_ELEMS) //pile est saturee
    {
        *status = -2;
        return ((int)0);
    }

    // empilage et incrementation du sommet
    pile->tab[++(pile->sommet)] = val;

    return((int)1); // empilage est bien effectuÃ©e
}//fin fct


// fct depile la pile retourne nombre element si l'element est depiler sinon 0
int depiler_Tab(TSmtCel *pile, int *status)
{
    *status = 1;
    if (!pile) // pile n'existe pas
    {
        *status = -1;
        return ((int)0);
    }
    
    if ((!(pile->sommet+1))) //si le sommet == -1
    {
        *status = 0;
        return ((int)0); //pile est vide
    }

    // depilage et decrementation du sommet
    return pile->tab[pile->sommet--]; // retourne la valeur depiler

}//fin fct

//fct inverese l'ordre des elements de la pile et retourne la liste apres modification ,null sinon
TSmtCel* inverser_TPile(TSmtCel *pile, int *status)
{
    //pile n'exist pas
    if (!pile)
    {
        *status = -1;
        return((TSmtCel*) NULL);
    }
    // TPile est vide
    if (!(pile->sommet+1))
    {
        *status = 0;
        return ((TSmtCel*)pile);
    }
// utiliser une pile tmp pour empiler les elements depiler de liste
    TSmtCel *tmp = createTPile();
    int val_depile;

    while (!est_TPile_vide(*pile))//tant que pile n'est pas vide
    {
        val_depile = depiler_Tab(pile, status);
        empiler_Tab(tmp, val_depile, status);
    }

    return ((TSmtCel*)tmp);//retourne la pile tmp
}//fin fct

// fct qui trouve si un element se trouve dans une pile
//retourne sa position si existe, sinon retourne un zero
int trouver_val_TPile(TSmtCel *pile, int val, int *status)
{
    *status = 1;

    if (!pile) //pile n'exist pas
    {
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return ((int)0);
    }
    //pile existe
        if (est_TPile_vide(*pile))
    {
        *status = 0;
        return((int) 0); //pile est vide
    }

    TSmtCel *tmp;
    int indice = -1,//declaration des variables
        val_depiler;
    tmp = createTPile();

    while (!est_TPile_vide(*pile))
    {
        val_depiler = depiler_Tab(pile, status);
        empiler_Tab(tmp, val_depiler, status);
        //si indice != -1 et val donne == valeur depile
        if ((val_depiler == val) && !(indice+1))
            indice = pile->sommet +2; //le sommet point sur l'indice la valeur au desous du val
    }
    while (!est_TPile_vide(*tmp))
	   {
        val_depiler = depiler_Tab(tmp, status);
        empiler_Tab(pile, val_depiler, status);
    	}
    if (!(indice+1) )
    {
        *status = -3;
        return -1;
    }
    return indice;
}//fin fct

//fct qui donne l'element max dans la pile
int max_val_TPile(TSmtCel *pile, int *status)
{
    *status = 1;
    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return ((int)0);
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return ((int)0);
    }
// pile tmp pour empiler les element depiler par pile principale 
    TSmtCel *tmp;
    int val_depiler, max_elem;

    tmp = createTPile();

    max_elem = pile->tab[pile->sommet];

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = depiler_Tab(pile, status);
        empiler_Tab(tmp, val_depiler, status);
        //si indice != -1 et val donne == valeur depile
        if (max_elem < tmp->tab[tmp->sommet])
            max_elem = tmp->tab[tmp->sommet];// stocker le nouveau element max
    }

    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_Tab(tmp, status);//depiler la pile tmp 
        empiler_Tab(pile, val_depiler, status);//empiler la pile de nouveau avec le meme ordre
    }


    return max_elem;
}//fin fct



// fct qui retourne l'element min de la pile
int min_val_TPile(TSmtCel *pile, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return ((int)0);
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return ((int)0);
    }

    TSmtCel *tmp;
    int val_depiler, min_elem;

    tmp = createTPile();
// considerer le min = l'element qui se trouve au sommet
    min_elem = pile->tab[pile->sommet];

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = depiler_Tab(pile, status);
        empiler_Tab(tmp, val_depiler, status);
        //si indice != -1 et val donne == valeur depile
        if (min_elem > tmp->tab[tmp->sommet])
            min_elem = tmp->tab[tmp->sommet];
    }

    while (!est_TPile_vide(*tmp)) {
        val_depiler = depiler_Tab(tmp, status);
        empiler_Tab(pile, val_depiler, status);
    }


    return min_elem;
} //FIN de fonction max_val_TPile




// fct qui retourne le nombre d'occurence d'un element
int nbr_occur_TPile(TSmtCel *pile, int val, int *status)
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

    TSmtCel *tmp;
    int val_depiler, nbr_occur;

    tmp = createTPile();

    nbr_occur = 0;

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = depiler_Tab(pile, status);
        empiler_Tab(tmp, val_depiler, status);
        //si indice != -1 et val donne == valeur depile
        if (val == tmp->tab[tmp->sommet])
            nbr_occur++;
    }

    while (!est_TPile_vide(*tmp))  //tant que la pile tmp n'est pas vide
	{
        val_depiler = depiler_Tab(tmp, status);//depiler tmp
        empiler_Tab(pile, val_depiler, status);// empiler la pile
    }


    return nbr_occur;
} //FIN de fonction nbr_occur_TPile

//affcher l'element qui se trouve a la position p
int trouver_pos_TPile(TSmtCel *pile, int pos, int *status)
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

    TSmtCel *tmp;
    int val_depiler, val_pos;

    tmp = createTPile();

    val_pos = -1;

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = depiler_Tab(pile, status);
        empiler_Tab(tmp, val_depiler, status);
        //si sommet == position donnee
        if (pos == tmp->sommet)
        {
            val_pos = tmp->tab[tmp->sommet];// stocker l'element a la position p
            break;
        }
    }

    while (!est_TPile_vide(*tmp))  //tant que la pile tmp n'est pas vide
	{
        val_depiler = depiler_Tab(tmp, status);// depiler tmp
        empiler_Tab(pile, val_depiler, status);// empiler la pile
    }


    return val_pos;
} //FIN de fonction trouver_pos_TPile



//supprimer le premier occurence du val
void supprimer_val_TPILE(TSmtCel *pile, int val, int *status)
{
    *status = 1;

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

    TSmtCel *tmp;
    int val_depiler, val_pos;

    tmp = createTPile();

    val_pos = -1;

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = depiler_Tab(pile, status);

        if (val == pile->tab[pile->sommet])
            break;

        empiler_Tab(tmp, val_depiler, status);

    }

    while (!est_TPile_vide(*tmp))// tant que tmp n'est pas vide
	 {
        val_depiler = depiler_Tab(tmp, status);// depiler tmp
        empiler_Tab(pile, val_depiler, status);// empiler la pile
    }


} //FIN de fonction supprimer_val_TPILE





//supprimer toutes les occurences du val
void supprimer_all_occur_TPILE(TSmtCel *pile, int val, int *status)
{
    *status = 1;

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

    TSmtCel *tmp;
    int val_depiler, val_pos;

    tmp = createTPile();

    val_pos = -1;

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = depiler_Tab(pile, status);

        if (val == pile->tab[pile->sommet])
            continue;

        empiler_Tab(tmp, val_depiler, status);

    }

    while (!est_TPile_vide(*tmp)) {// tant que tmp n'est pas vide
        val_depiler = depiler_Tab(tmp, status);
        empiler_Tab(pile, val_depiler, status);
    }


} //FIN de fonction supprimer_all_occur_TPILE



//supprimer le premier occurence du val
void supprimer_pos_TPILE(TSmtCel *pile, int pos, int *status)
{
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

    TSmtCel *tmp;
    int val_depiler;

    tmp = createTPile();


    while (!est_TPile_vide(*pile))// tant que pile n'est pas vide
    {
        val_depiler = depiler_Tab(pile, status);

        if (pos-1 == pile->sommet)
        {
            *status = 1;
            break;
        }

        empiler_Tab(tmp, val_depiler, status);

    }

    while (!est_TPile_vide(*tmp))// tant que tmp n'est pas vide
	 {
        val_depiler = depiler_Tab(tmp, status);
        empiler_Tab(pile, val_depiler, status);
    }


} //FIN de fonction supprimer_pos_TPILE



// fct affiche tout les elements de la pile
void affiche_TPile(TSmtCel *pile, int *status)
{int i;
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

    for ( i = 0; i <= pile->sommet; ++i)
        printf("%d\t", pile->tab[i]);
}

// fonction de gestion d'erreurs
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
}// fin fct



// menu
int menu_TPile_Tab()
{
    TSmtCel *pile = createTPile();
    int choix; // choix de l'utilisateur

    int *status = (int*) malloc(sizeof(int)); // status de l'operation effectuee par la fonction
    int tmp, tmp2;// variables
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
                empiler_Tab(pile, tmp, status);
                if (handle_errors_TPile(*status))
                    printf("\nEmpilage bien effectee\n");
                getch();
                break;

            case 5:
                depiler_Tab(pile, status);
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
			// si le choix est <0 ou >14
            default :   printf("\n\nErreur : Choix Invalide\n\n");

                getch();
        }

    }while(choix);
}


/************************************************  END PILE AVEC TABLEAU *********************************************************/





