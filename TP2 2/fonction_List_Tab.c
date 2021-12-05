
// declaration des Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "structures.h"




// la fct creer liste
TListe* createListe()
{
    TListe *liste = (TListe*) malloc(sizeof(TListe)); // allocation de la memoire
    liste->nbr_elem = 0;  // initialiser le nombre des element a 0
    if (!liste)  //si liste n'existe pas
    {
        printf("Erreur de location de la memoire");
        exit(-1);//sortir du prog
    }
    return (liste);
}//fin fct createListe


// la fct initialiser liste
TListe* init_Liste(TListe *liste)
{
    if (liste) //si liste existe
        free(liste);
    liste = createListe(); //creer une autre liste a l'aide de la fct createListe
    return liste; //retourne la nouvelle liste
}//fin fct init_Liste


// taille liste

int taille_liste(TListe liste)
{ printf ("\n La taille de la liste : %d \n", liste.nbr_elem);
    return ((int)liste.nbr_elem);
}// fin fct taille_liste

// fct vider liste
int vider_liste(TListe *liste)
{
    if (!liste) return ((int)-1); //liste n'existe pas
    //liste existe
    liste->nbr_elem = 0; //modifier nombre des element
}// fin fct vider_liste


// fct inserer un elemet en queue
int inserer_queue(TListe *liste, int val)
{
    //liste n'exist pas
    if (!liste) return ((int)-1);
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem) return((int)-2);
    // inserer dans la fin du tableau
    liste->tab[liste->nbr_elem++] = val;
    return((int) 1);
}//fin fct inserer_queue

// fct inserer un elemet en tete
int inserer_tete(TListe *liste, int val)
{
    //liste n'exist pas
    if (!liste) return ((int)-1);
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem) return((int)-2);

    int size = liste->nbr_elem;

    while(size--){
        liste->tab[size+1] = liste->tab[size];
    }

    // inserer au debut du tableau
    liste->tab[0] = val;
    liste->nbr_elem++;
    return((int) 1);
}//fin fct inserer_tete

/// fct inserer un elemet a une posotion donnee
int inserer_position(TListe *liste, int val, int pos)
{ int i;
    //liste n'exist pas
    if (!liste) return ((int)-1);
    //Liste est saturee
    if (MAX_ELEMS == liste->nbr_elem) return((int) -2);
    //position non valide
    if ((pos < 1) || (liste->nbr_elem+1 < pos)) return((int)-3) ;
    //sinon
    pos--;// pour trouver l'indice
    //faire une boucle pour decaler les elemet du tableau
    for( i = liste->nbr_elem; i > pos; --i)
        liste->tab[i] = liste->tab[i-1];
    // inserer le nouveau element
    liste->tab[pos] = val;
    //incrementer le nombre des elemet
    liste->nbr_elem++;

    return ((int)1);
}//fin fct inserer_position



// fct qui supprime  l'element qui se trouve dans une position p donnee
int supprimer_position(TListe *liste, int pos)
{ int i ;
    //liste n'exist pas
    if (!liste) return((int)-1) ;
    //position non valide
    if ((pos < 1) || ((liste->nbr_elem)+ 1< pos)) return((int)-3) ;
    //faire une boucle pour decaler les elemet du tableau
    for( i = pos-1; i < liste->nbr_elem; i++)
        liste->tab[i] = liste->tab[i+1];
    // decrementer le nombre d'element
    liste->nbr_elem--;
    return((int)1) ;//supprition effectuer
}// fin fct supprimer_position


/// fonction qui supprime le 1er element dans la liste egal a val
int supprimer_first_elem(TListe *liste, int val)
{ int i ;
    //liste n'exist pas
    if (!liste) return((int)-1) ;
    //liste existe
    //faire une boucle qui cherche le 1er element egale a val
    for(i = 0; i < liste->nbr_elem; i++)
        if (liste->tab[i] == val)
        {
            supprimer_position(liste, i+1);// utiliser la fct  supprimer_position pour supprimer l'element
            return ((int)1);
        }
    //element n'existe pas
    return ((int)-4);
} //fin fct supprimer_first_elem


/// fonction qui supprime tout les elements egal a val
int supprimer_elems(TListe *liste, int val)
{int i ;
    //liste n'exist pas
    if (!liste) return ((int)-1);
    //liste existe
    //faire une boucle pour trouver tout les element egal a val et les supprimer
    for( i = 0; i < liste->nbr_elem; i++)
    {
        supprimer_first_elem(liste,val);

    }
    return  ((int)1); // ELEMENT supprime

}// fin fct supprimer_elems


// fonction qui inverse l'ordre d'une liste
int inverser_liste(TListe *liste)
{int i ;
    //liste n'exist pas
    if (!liste) return ((int)-1);
    // liste existe
    int tmp;
    //faire une boucle du 1er element du tableau jusqu'a nombre_element sur 2
    for (i = 0; i < liste->nbr_elem/2; ++i)
    { // utiliser une variable : tpm pour stocker la valeur a changer
        tmp = liste->tab[i];
        liste->tab[i] = liste->tab[liste->nbr_elem-i-1];
        liste->tab[liste->nbr_elem-i-1] = tmp;
    }

    return ((int)1);
}//fin fct inverser_liste


int get_max_val(TListe *liste) {
    int i ;
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int max = liste->tab[0];

    for (i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] > max)
            max = liste->tab[i];

    return max;
}
// fct retourne la position de l'element max
int get_max_pos(TListe *liste) {
    int i ;
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int max_pos = 0;
// boucle pour trouver si il y a un element plus grand que max
    for (i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] > liste->tab[max_pos])
            max_pos = i;
//retourner la position de max
    return max_pos;
}// fin fct

//fonction qui retourne l'element min dans le tableau
int get_min_val(TListe *liste) {
    int i ;
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int min = liste->tab[0];
// boucle pour trouver si il y a un element plus petit que min
    for (i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] < min)
            min = liste->tab[i];
// retourner l'element min
    return min;
}// fin fct

//// fct retourne la position de l'element min
int get_min_pos(TListe *liste) {
    int i ;
    //liste n'exist pas
    if (!liste) return -1;

    //Liste est vide
    if (!liste->nbr_elem) return 0;

    //initialiser la valeur du maximum
    int min_pos = 0;
// boucle pour trouver si il y a un element plus petit que min
    for ( i = 1; i < liste->nbr_elem; ++i)
        if(liste->tab[i] < liste->tab[min_pos])
            min_pos = i;
//retourner la position de min
    return min_pos;
}// fin fct


///fonction qui retourne le nombre d'occurence d'un element
int get_nbr_repetition(TListe *liste, int val)
{	//liste n'existe pas
    int i ;
    if (!liste) return((int) -1);
    //Liste est vide
    if (!liste->nbr_elem) return((int) 0);

    // compteur de repetition de la valeur donnee
    // intialiser a 0
    int compteur_rep = 0;
//boucle pour compter le nombre de fois
    for (i = 0; i < liste->nbr_elem; ++i)
        if (liste->tab[i] == val)
            compteur_rep++;
    //afficher
    printf("l'element %d existe %d fois dans la liste",val,compteur_rep);
    getch();//pour ne pas retourner le menu jusqu'a inserer un caractere
    return  ((int)compteur_rep);
}// fin fct get_nbr_repetition

// fct retourne la valeur de la position p donnee
int acceder_val(TListe *liste, int pos)
{
    //Liste n'existe pas
    if (!liste) return((int)-1) ;
    //Liste est vide
    if (!liste->nbr_elem) return((int) 0);
    //position non valide
    if ((pos < 1) || (liste->nbr_elem < pos)) return((int) -3);
    // affichage de l'element
    printf ("l'element %d",liste->tab[pos-1]);
    return ((int)liste->tab[pos-1]);

}// fin fct


// fct affiche le contenu de la liste
int affiche_liste(TListe *liste)
{
    int i ;
    //liste n'exist pas
    if (!liste) return((int) -1);
    // Liste est vide
    if (!liste->nbr_elem) return((int)0) ;
    // boucle pour afficher elementpar element
    for (i = 0; i < liste->nbr_elem; ++i)
    {
        printf(" l'element a la position  %d est: %d",i+1, liste->tab[i]);
        printf("\n");
    }
    return ((int) 1);
}


// fct pour gerer les erreurs retourne 1 si il a un erreur et 0 sinon
int gestion_err(int val)
{ //si liste n'existe pas
    if(val==-1)
    {
        printf(" \n liste n'existe pas\n");
        getch();
        return ((int)1);//  il  y a pas d'erreur
    }
    // si la liste est vide
    if(val==0)
    {
        printf(" \n liste vide \n");
        getch();
        return ((int)1);//  il  y a pas d'erreur
    }
    // si la Liste est saturee
    if(val==-2)
    {
        printf(" \n Liste est saturee \n");
        getch();
        return ((int)1);//  il  y a pas d'erreur
    }
    // si la entrer position non valide
    if(val==-3)
    {
        printf(" \n position non valide \n");
        getch();
        return ((int)1); //  il  y a pas d'erreur
    }
    //si l'element n'esxiste pas dans la liste
    if(val==-4)
    {
        printf(" \n l element n'esxiste pas dans la liste" );
        getch();
        return ((int)1); //  il  y a pas d'erreur
    }

    return ((int)0);  //   il n'y a pas d'erreur

}//fin fct


/// rechercher si un element existe dans la liste
int rechercher_elem(TListe liste,int elem)
{int i;
// verifier si la liste est vide
    if(liste.nbr_elem==0)
    { // printf("\n liste vide !!");
        return((int)0);
    }
    //boucle pour comparer chaque element de la liste avec la valeur entree
    for(i=0;i<liste.nbr_elem;i++)
    {   if (liste.tab[i]==elem)// trouver le 1er element = val
        {
            //afficher sa position
            return ((int)(i+1));
        }
    }//fin fct

//element n'esxiste pas dans la liste
    return ((int)-4);

}//fin fct


// le menu
int menu_Liste_Tab()
{
    TListe *liste = createListe();
    int val,p,choix;
    do
    {

        //initialiser le choix
        choix = -1;
        //declaration du variable
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
               "\n 12 : afficher le max dans la liste \n "
               "\n 13 : afficher le min dans la liste \n "
               "\n 14 : afficher la position de la valeur max dans la liste \n "
               "\n 15 : afficher la position de la valeur min dans la liste \n "
               "\n 16 : inverser la  liste \n "
               "\n 0 : retour vers menu principal \n"
               "\n **********************************************************************************************************************\n "
               "\n >>>>>  ");

        scanf("%d%*c", &choix);

        switch(choix)
        {
            case 1:
                liste = init_Liste(liste);
                printf(" \n Liste bien Initialise \n");
                getch();//pour que le resultat reste afficher jusqu'a entrer un caractere
                break;
            case 2:
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if( ! gestion_err(taille_liste(*liste)))
                    //sinon afficher la taille
                    getch();
                break;
            case 3:
                printf (" \n entrer l'element a inserer et sa position dans la liste \n");
                scanf("%d%d",&val,&p);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err(inserer_position(liste,val,p) ))
                    //sinon inserer dans la liste et afficher que l'insetion est bien effectuer
                    printf(" \n insertion effectuer  \n");
                getch();

                break;
            case 4:
                printf (" \n entrer l'element a inserer en queue de la liste \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err(inserer_queue(liste, val)))
                    //sinon inserer dans la liste et afficher  que l'insetion est bien effectuer
                    printf(" \n insertion effectuer  \n");
                getch();
                break;
            case 5:
                // afficher la liste sinon si il y a un erreur va etre afficher
                if( gestion_err(affiche_liste(liste))) break;

                break;
            case 6:
                printf (" \n entrer L'element a chercher  \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err(rechercher_elem(*liste,val)) )
                    //sinon afficher que l'element existe
                    printf("\n l element %d existe dans la liste");
                break;

            case 7:
                printf (" \n entrer une position  \n");
                scanf("%d",&p);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if( ! gestion_err(acceder_val(liste,p)))
                    //sinon afficher la valeur

                    getch();
                break;
            case 8:
                printf (" \n entrer l'element a chercher \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err(get_nbr_repetition(liste, val)))
                    //sinon afficher le nombre de repetition

                    break;
            case 9:	printf (" \n entrer l'element a supprimer \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err( supprimer_first_elem(liste,  val)))
                    //sinon supprimer la 1er occurence et afficher un msg
                    printf("\n element supprime");
                break;
            case 10:printf (" \n entrer la position  \n");
                scanf("%d",&p);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err(supprimer_position(liste,p)))
                    //sinon supprimer l'element  et afficher un msg
                    printf("\n element supprime");
                break;

            case 11:printf (" \n entrer l'element a supprimer \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err(supprimer_elems(liste, val)))
                    //sinon supprimer tout les occurrences et afficher un msg
                    printf("\n element supprime");
                break;

            case 12: 	printf (" \n la valeur max dans la liste est %d " ,get_max_val(liste));
                getch();
                break;
            case 13:	printf (" \n la valeur max dans la liste est %d " ,get_min_val(liste));
                getch();
                break;

            case 14:    printf (" \n la position du valeur max dans la liste est %d " ,get_max_pos(liste));
                getch();
                break;
            case 15:    printf (" \n la position du valeur min dans la liste est %d " ,get_min_pos(liste));
                getch();
                break;

            case 16:
                if (gestion_err(inverser_liste(liste))) break;
                // si il n'y a pas d'erreur  la liste va etre inverser
                printf (" \n la liste est inverser " );
                // afficher la liste  inversee
                if (gestion_err(affiche_liste(liste)) )break;
                getch();
                break;
                // si le choix est <0 ou >16
            default :   printf("\n\nErreur : Choix Invalide\n\n");

                getch();
        }

    }while(choix);
}


/************************************************  END LISTE AVEC TABLEAU *********************************************************/
