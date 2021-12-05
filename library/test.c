//
// Created by W0L1D on 12/5/2021.
//
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "fonctions_TList.c"

// le menu
int menu_Liste_Tab()
{
    TListe *liste = create_TListe();
    int val,p,tmp,choix;
    do
    {
        //initialiser le choix
        choix = -1;
        //declaration du variable
        printf("\n *****************************************************************************************************************\n "
               " 1  : reinitialiser/vider votre liste \n"
               " 2  : taille de liste \n"
               " 3  : inserer un element a une position p\n"
               " 4  : inserer un element en queue de liste  \n"
               " 5  : affichage de la liste \n"
               " 6  : rechercher si un element existe dans la liste \n"
               " 7  : afficher l'element qui existe dans la position p \n "
               " 8  : afficher nombre occurence d'un element \n "
               " 9  : supprimer la 1ER occurence d'un element \n "
               " 10 : supprimer l'element a la position p \n "
               " 11 : supprimer tout les occurences d'un element \n "
               " 12 : afficher le max dans la liste \n "
               " 13 : afficher le min dans la liste \n "
               " 14 : afficher la position de la valeur max dans la liste \n "
               " 15 : afficher la position de la valeur min dans la liste \n "
               " 16 : inverser la  liste \n "
               " 0 : retour vers menu principal \n"
               "\n **********************************************************************************************************************\n "
               "\n >>>>>  ");

        scanf("%d%*c", &choix);

        switch(choix)
        {
            case 1:
                liste = init_TListe(liste);
                printf(" \n Liste bien Initialise \n");
                break;
            case 2:
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if( ! gestion_err_TListe(tmp = taille_TListe(*liste)))
                    //sinon afficher la taille
                    printf("La taille de la liste est %d.", tmp);
                break;
            case 3:
                printf (" \n entrer l'element a inserer et sa position dans la liste \n");
                scanf("%d%d",&val,&p);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err_TListe(inserer_position_TListe(liste,val,p) ))
                    //sinon inserer dans la liste et afficher que l'insetion est bien effectuer
                    printf(" \n insertion effectuer  \n");

                break;
            case 4:
                printf (" \n entrer l'element a inserer en queue de la liste \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err_TListe(inserer_queue_TListe(liste, val)))
                    //sinon inserer dans la liste et afficher  que l'insetion est bien effectuer
                    printf(" \n insertion effectuer  \n");
                break;
            case 5:
                // afficher la liste sinon si il y a un erreur va etre afficher
                if( gestion_err_TListe(affiche_TListe(liste))) break;

                break;
            case 6:
                printf (" \n entrer L'element a chercher  \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err_TListe(tmp = rechercher_elem_TListe(*liste,val)) )
                    //sinon afficher que l'element existe
                    printf("\n l element %d existe dans la liste", tmp);
                break;

            case 7:
                printf (" \n entrer une position  \n");
                scanf("%d",&p);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if( ! gestion_err_TListe(tmp = acceder_val_TListe(liste,p)))
                    //sinon afficher la valeur


                break;
            case 8:
                printf (" \n entrer l'element a chercher \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err_TListe(get_nbr_repetition_TListe(liste, val)))
                    //sinon afficher le nombre de repetition

                    break;
            case 9:	printf (" \n entrer l'element a supprimer \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err_TListe( supprimer_first_elem_TListe(liste,  val)))
                    //sinon supprimer la 1er occurence et afficher un msg
                    printf("\n element supprime");
                break;
            case 10:printf (" \n entrer la position  \n");
                scanf("%d",&p);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err_TListe(supprimer_position_TListe(liste,p)))
                    //sinon supprimer l'element  et afficher un msg
                    printf("\n element supprime");
                break;

            case 11:printf (" \n entrer l'element a supprimer \n");
                scanf("%d",&val);
                // si il y a un erreur la fct getion_err() va retourner 1,on aura un msg d'err et va sortir vers le menu_liste_tab
                if(! gestion_err_TListe(supprimer_elems_TListe(liste, val)))
                    //sinon supprimer tout les occurrences et afficher un msg
                    printf("\n element supprime");
                break;

            case 12: 	printf (" \n la valeur max dans la liste est %d " ,get_max_val_TListe(liste));
                break;
            case 13:	printf (" \n la valeur max dans la liste est %d " ,get_min_val_TListe(liste));
                break;

            case 14:    printf (" \n la position du valeur max dans la liste est %d " ,get_max_pos_TListe(liste));
                break;
            case 15:    printf (" \n la position du valeur min dans la liste est %d " ,get_min_pos_TListe(liste));
                break;

            case 16:
                if (gestion_err_TListe(inverser_TListe(liste))) break;
                // si il n'y a pas d'erreur  la liste va etre inverser
                printf (" \n la liste est inverser " );
                // afficher la liste  inversee
                if (gestion_err_TListe(affiche_TListe(liste)) )break;

                break;
                // si le choix est <0 ou >16
            default :   printf("\n\nErreur : Choix Invalide\n\n");


        }
        getch();
    }while(choix);
}




void main() {
   menu_Liste_Tab();
}
