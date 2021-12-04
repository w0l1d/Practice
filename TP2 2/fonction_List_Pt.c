
// declaration des Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "structures.h"







// la fct creer liste
Cellule * creer_PListe(int elem,int *etat)
{
// declarer une variable de type pt
    Cellule* NE;
// allocation de la memoire
    NE=(Cellule*)malloc(sizeof(Cellule));
//si il y a un probleme d'allocation
    if(!NE)
    {*etat=-1; // stocker dans une variable et l'utiliser dans la fct de gestion d'erreur
        return((Cellule*)NULL);//retourner null
    }
//si l'allocatin est bien passer
//initialisation
    NE->val=elem;
    NE->svt=NULL;
    *etat=1;
    //retourner l'element de type Cellule
    return((Cellule*)NE);
}//fin fct


// fct taille liste
int taille_pliste(Cellule *list)
{ // declaration d'un pt
    Cellule *pt;
    // initialiser la variable compt a zero
    int compt=0;
    //cas ou la iste n'existe pas
    if(!list)
    { printf("liste n'existe pas !! \n");
        return((int)-2);
    }
// si la liste existe
    pt=list;
//tant que pt est != de null
    while(pt)
    {
// incrementer le compteur
        compt++;
        pt=pt->svt;
    }
    return((int)compt);
}//fin fct


Cellule *inserer_queue_PList(Cellule *list, int val, int *etat) {
    Cellule *ne;
    ne = creer_PListe(val, etat);

    //cas ou la liste n'existe pas
    if(!list)
    {
        *etat=1;
        return((Cellule*) ne);
    }

    Cellule *pt = NULL;
    for(pt = list; pt->svt; pt = pt->svt);

    pt->svt = ne;
    return ((Cellule*) list);

}


Cellule *inserer_tete_PList(Cellule *list, int val, int *etat) {
    Cellule *ne;
    ne = creer_PListe(val, etat);

    ne->svt = list;

    return ((Cellule*) ne);

}


// fct inserer un elemet a une position p donnee
Cellule * inserer_pos_PList(Cellule* list,int pos, int elem,int *etat)
{
    Cellule *NE,*pt;
    int compt;
    //cas ou la liste n'existe pas
    if(!list)
    { *etat=-2;
        return((Cellule*)NULL);
    }
    // liste existe
    // si pos==1 (insertion en tete)
    if(pos==1)
    {
        // creer un NE et le donner comme suivant la liste
        NE=(Cellule*)creer_PListe(elem,etat) ;*etat=1	;
        NE->svt=list;
        //retourner l NE
        return((Cellule*)NE);
    }
    // si une position p est en dehors de la liste
    if ((pos<1 ) || ( taille_pliste(list)+1<pos))
    { *etat=-3;
        return((Cellule*)NULL);
    }
    // position est > a 1 et < nombre d'element
    compt=1;
    pt=list;
    while(compt< pos-1) //parcourir jusqu'a trouver la position avant
    { pt=pt->svt;
        compt++;
    }

    //creer l'element NE
    NE=(Cellule*)creer_PListe(elem,etat) ;
    NE->svt=pt->svt;
    pt->svt=NE;
    *etat=1;// pour l'utiliser a la fct gestion erreur
    return((Cellule*)list);
}//fin fct

// fct gestion des erreur ,pas de retour ,que des affichage des msg
void gestion_errp(int val)
{
    switch(val)
    {
        case -1 :
            printf("\n probleme d'allocation !! \n");
            break;
        case -2 :
            printf("\n liste n'existe pas !! \n");
            break;
        case -3 :
            printf("\n position non valide !! \n");
            break;
        case -4 :
            printf("\n on ne peux pas supprimer le 1er element !! \n");
            break;
        case 0 :
            printf("\n element n'existe pas !! \n");
            break;
        case  1 :
            printf("\n votre operation est bien effectuer   !! \n");
            break;

    }
}//fin fct

// fct qui supprime l'element qui se trouve a une position p donnee
int supprimer_pos_PtList(Cellule *list, int pos)
{   //list n'exist pas
    if (!list)
        return ((int)-1);
    //liste existe
    //on ne peut pas supprimer le premier element
    if (pos == 1)
        return ((int)-4);
    //else
    Cellule *curr = list,// utiliser un pt :" curr " pour parcourir la liste
    *tmp;// pour libérer l'espace occupee par l element qu'on veut supprimer
    int indice = 1; // pour trouver la position

    while (curr->svt)// tant que on a pas arriver a la fin du liste
    {
        if (pos == indice+1) //si on est en precedant de pos
            break;
        indice++;
        curr = curr->svt;
    }
    //element n'est pas trouver
    // position donnee est erronee
    if ((indice+1) != pos)
        return((int)-3) ;

    tmp = curr->svt; // tmp == element a supprimer
    curr->svt = tmp->svt;
    free(tmp);
    return((int)1) ;
}//fin fct

// Fct affiche tout les element de la liste
int afficher_plist(Cellule *list)
{
    // declaration des variable
    Cellule *pt;//pour parcourir la liste
    int compt;// donner les positions des elements
    //list n'exist pas
    if (!list)
        return -2 ;
    //Liste existe
    pt=list;
    compt=1;
    while(pt)//tant que ot n'est pas null
    {
        printf("%d\t", pt->val);
        compt++;
        pt=pt->svt;
    }
    return 1;// pour la gestion des erreurs
}//fin fct

// fonction affichel'element qui se trouve dans une position p
int affiche_pos(Cellule *list,int pos,int *etat)
{
    int indice;
    Cellule *pt;
    //liste n'exist pas
    if (!list) return((*etat)=-2);
    //liste existe
    indice=1;
    pt=list;
    // si une position p est en dehors de la liste
    if ((pos<1 ) || ( taille_pliste(list)<pos))	 return((*etat)=-3);
    //sinon
    while (indice!=pos)  // tant que on a pas arriver a la position
    {
        pt=pt->svt;
        indice++;
    }
    printf("\n l'element %d a la position %d",pt->val,pos);
    return((*etat)=2);

}//fin fct

//fonction qui recherche si un element existe dans la liste
int recherche_elem(Cellule *list,int elm )
{
    //liste n'exist pas
    if (!list)
    {
        printf("\n liste n'existe pas!");
        return((int)-2);
    }
    // liste existe
    Cellule *pt=list;// pour parcourir la liste
    int compt=0;//pour donner la position de l'element
    while(pt)//tant que ot n'est pas null
    {
        compt++;
        if((pt->val)==elm)return((int)compt);// element trouver
        pt=pt->svt;
    }
    // element n'existe pas dans laliste
    return((int)0);
}//fin fct

// fct compte le nombre d'occurence d'un element dans une lste
int nb_occ_elem(Cellule *list,int elm )
{
    Cellule *pt=list;
    int compt=0;
    //liste n'exist pas
    if (!list)
    {printf("\n liste n'existe pas!");
        return((int)-2);
    }
    // LISTE EXISTE
    while(pt)//tant que ot n'est pas null parcourir la liste
    { if((pt->val)==elm) compt++;	// si l'element existe incrementer le compteur
        pt=pt->svt;
    }
    return((int)compt);// returner le nombre ,zero si il n'existe pas
} //fin fct

//fct qui supprime la 1er occurence d'un element
void supp_first_occ(Cellule * list, int elm,int *etat)
{
    int pos;
    //liste n'exist pas
    if (!list) 	*etat=-2;

    pos=(int)recherche_elem(list,elm );// utiliser la fonction recherche_elem() qui retourne

    // la position de la 1er occurence
    if(!pos) *etat=0 ; // si pos==0 ,la fct gestion erreur va afficher ue l'elm n'existe pas
    else
        //sinon supprimer l'element avec la fct supprimer_pos_PtList()
        *etat=(int)(supprimer_pos_PtList(list, pos)) ;

}//fin fct

//fct qui supprime la 1er occurence d'un element
Cellule* supp_pos_PList(Cellule * list, int pos)
{
    //liste n'exist pas
    if (!list) 	return ((Cellule*) liste);




}//fin fct


// fct qui supprime tout les occurences d'un element
Cellule* supp_occ_elem_PList(Cellule *list,int val)
{
    Cellule *pt = list, *tmp;
    if (!list)
        return ((Cellule*) NULL);

    while (pt->val == val) {
        tmp = pt;
        pt = pt->svt;
        free(tmp);
    }

    list = pt;
    while(pt->svt) {
        if (pt->svt->val == val) {
            tmp = pt->svt;
            pt->svt = tmp->svt;
            tmp = NULL;
            free(tmp);
        }
        pt = pt->svt;
    }

    return ((Cellule*) list);

}//fin fct



// menu
int menu_Liste_pt()
{
    //declaration des variable
    int  etat,val,pos,result,choix = -1;
    Cellule* list = NULL;
    list = inserer_queue_PList(list, 0, &etat);
    list = inserer_queue_PList(list, 1, &etat);
    list = inserer_queue_PList(list, 5, &etat);
    list = inserer_queue_PList(list, 8, &etat);
    list = inserer_queue_PList(list, 9, &etat);
    list = inserer_queue_PList(list, 4, &etat);
    list = inserer_queue_PList(list, 6, &etat);
    list = inserer_queue_PList(list, 3, &etat);
    list = inserer_queue_PList(list, 12, &etat);
    list = inserer_queue_PList(list, 86, &etat);
    list = inserer_queue_PList(list, 14, &etat);

    do
    {

        //initialiser le choix
        choix = -1;
        printf("\n *****************************************************************************************************************\n "
               "\n 1  : creer votre liste \n"
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
               "\n >>>>>  ");

        scanf("%d", &choix); getchar();

        switch(choix)
        {
            case 1:// creer une liste
                printf (" \n entrer votre 1er element pour creer  la liste \n");
                scanf("%d",&val);
                list=creer_PListe(val,&etat);
                gestion_errp(etat);
                getch();
                break;

            case 2:// affichage de la taille
                printf("la taille de la liste est :%d", taille_pliste(list));
                getch();
                break;
            case 3:
                printf (" \n entrer l'element a inserer et sa position dans la liste \n");
                scanf("%d%d",&val,&pos);
                // inserer
                inserer_pos_PList(list,pos,val,&etat);
                //si il y a un erreur un msg va afficher
                gestion_errp(etat);
                getch();
                break;
            case 4:
                printf (" \n entrer l'element a inserer dans la liste \n");
                scanf("%d",&val);
                // inserer en queue
                inserer_pos_PList(list,((taille_pliste(list))+1),val,&etat);
                //si il y a un erreur un msg va afficher
                gestion_errp(etat);
                getch();

                break;
            case 5://afficher la liste
                afficher_plist(list);
                //si il y a un erreur un msg va afficher
                gestion_errp(etat);
                getch();
                break;
            case 6:
                printf (" \n entrer  l'element a chercher \n");
                scanf("%d",&val);
                //stocker le retour du fct recherche_elem
                result=(int)	recherche_elem(list,val);
                // afficher selon le resultat du retour
                (!result)?
                printf("element n''existe pas !")
                         :
                printf("element %d existe a la position %d :",val,result);
                getch();
                break;

            case 7:
                printf (" \n entrer la position de l'element que vous voulez afficher\n");
                scanf("%d",&pos);
                // afficher l'element qui se trouve a la position p
                affiche_pos(list,pos,&etat);
                //si il y a un erreur un msg va afficher
                gestion_errp(etat);
                getch();
                break;

            case 8:
                printf (" \n entrer  l'element a chercher \n");
                scanf("%d",&val);
                //stocker le retour du fct nb_occ_elem()
                result=(int)(nb_occ_elem(list,val ));
                //afficher selon le resultat du retour
                (!result)?
                printf("element n''existe pas !")
                         :
                printf("element %d existe %d fois ",val,result);
                break;

            case 9:
                printf (" \n entrer  l'element a supprimer \n");
                scanf("%d",&val);
                //supprimer 1er occurrence d'un element
                supp_first_occ(list, val,&etat);
                //si il y a un erreur un msg va afficher
                gestion_errp(etat);
                getch();
                break;

            case 10:
                printf("entrer la position \n");
                scanf("%d",&pos);
                //si il y a un erreur un msg va afficher sinon l'element egal a val va etre supprimer
                gestion_errp((int)supprimer_pos_PtList(list,pos));
                getch();
                break;

            case 11:
                printf (" \n entrer  l'element a supprimer \n");
                scanf("%d",&val);
                //si il y a un erreur un msg va afficher
                // sinon tout les element egal a val vont etre supprimer
                gestion_errp((supp_occ_elem_PList(list,val)));
                getch();
                break;
                // si le choix est <0 ou >11
            default :   printf("\n\nErreur : Choix Invalide\n\n");

                getch();
        }
    }while(choix);
}


/************************************************  END LISTE AVEC pt ******************************************/



