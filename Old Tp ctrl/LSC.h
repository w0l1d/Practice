#ifndef LSC_H_INCLUDED
#define LSC_H_INCLUDED

//definition de la structure de la Cellule


//fonction d'allocation d'un noeud

Cellule* allouer (int valeur)
{
            Cellule *cellule;

        //allouer de l'espace memoire pour le noeud

        cellule=(Cellule*)malloc(sizeof(Cellule));

        //si l'allocation a echoue

        if(!cellule){

            printf("memoire insuffisante");
            exit(-1);

        }

        cellule->valeur=valeur;
        cellule->suivant=NULL;//l'valeurent suivant pointe sur le pointeur null

            return (Cellule*)cellule;//on retourne le noeud

}

Cellule *insererCel(Cellule *liste,Cellule *cel)
{
    if(!cel)    return (Cellule*)liste;

    cel->suivant=liste;
    return (Cellule*)cel;
}

//fonction qui retourne le dernier valeurent de la Cellule

Cellule* dernier(Cellule *liste)
{
            Cellule *courant;//declaration d'un courant de la Cellule

    for(courant=liste; courant->suivant; courant=courant->suivant);//Parcours de la Cellule jusqu'au dernier valeurent

            return (Cellule*)courant;//on retourne le dernier valeurent

}

//fonction de l'insertion d'un valeurent au debut de la Cellule

Cellule* inserer_Debut (Cellule *liste , int valeur){

                Cellule *nvvaleur;//declaration d'un nouveau valeurent

        nvvaleur=allouer(valeur);//allouer de l'espace memoire pour ce nouvel valeur

        //insertion du nouvel valeurent dans la Cellule

        nvvaleur->suivant=liste;

                return (Cellule*)nvvaleur;//retourner la Cellule

}

//fonction de l'insertion d'un valeurent � la fin de la Liste

Cellule* inserer_Queue (Cellule *liste,int valeur)
{
   //d�claration des pointeurs.
            Cellule *der,//le dernier valeurent de la liste.
                    *nvvaleur;//nouvel �l�ment � ajouter � la fin de la liste.

    nvvaleur=allouer(valeur);//cr�er le nouvel �l�ment.

    if(!liste)//si la liste est vide.
    {
        liste=nvvaleur;//la liste re�oit le nouvel �l�ment.
    }//fin de if(!liste)

    else//sinon.
    {
     //on va ajouter l'�l�ment � la fin.
        der=dernier(liste);//acc�der au dernier �l�ment.
        //le nouvel �l�ment devient le suivant du dernier �l�ment.
        der->suivant=nvvaleur;
    }//fin de else.
            return (Cellule*)liste;//On retourne la nouvel liste.

}//Fin de (Cellule *liste,int valeur)

//fct supprimer la fin de la liste.

Cellule* supp_Fin (Cellule *liste)
{

    Cellule *avDer,*tmp;

    if(liste)
    {

        avDer=liste;

        if(!liste->suivant){

            tmp=liste;
            liste=liste->suivant;
            free(tmp);

        }

        while (avDer->suivant->suivant)
        {

        avDer=avDer->suivant;

        }

        tmp=avDer->suivant;
        avDer->suivant=NULL;
        free(tmp);

    }

            return liste;

}

//fct de l'insertion dans une position donn�e

Cellule* inserer_Pos_Liste (Cellule *liste , int valeur , int position){

                        Cellule *courant,
                                *nvvaleur;

                        int cpt=1;


        if(position==1){

            liste=inserer_Debut(liste,valeur);

                return ((Cellule*)liste);

        }

        courant=liste;

        while (courant){

            if (cpt==position-1){

                nvvaleur=allouer(valeur);
                nvvaleur->valeur=valeur;
                nvvaleur->suivant=courant->suivant;
                courant->suivant=nvvaleur;

                        return ((Cellule*)liste);

            }

            courant=courant->suivant;
            cpt++;

        }

}

//fonction vide une Cellule

Cellule *vider_Liste (Cellule *liste){

            Cellule *courant=liste,//declaration d'un courant de la Cellule
                  *supp;//un pointeur qui contient l'valeurent a suprimer

        //vider la Cellule

        while(courant){

            supp=courant;
            courant=courant->suivant;
            free(supp);

        }

        return liste;

}

//fonction affiche tous les valeurents d'une Liste

void afficher_Liste (Cellule *liste){

                Cellule *courant=liste;//declaration et initialisation d'un courant de la Cellule

        printf("\n");

        //affiher les valeurents de la Cellule

        while(courant){

            printf("%+i\t",courant->valeur);
            courant=courant->suivant;

        }

        printf("\n");


}

//la fct de la supression du premier valeur

Cellule* supp_Deb (Cellule *liste){

        Cellule *supp;//declaretion de la case a suprimer

    //spression du premier valeurent

    supp=liste;
    liste=liste->suivant;
    free(supp);

        return (Cellule*)liste;//on retourne la liste
}

//fct de la suppression d'un valeurent dans une position

Cellule* supp_Liste_Pos (Cellule *liste , int position){

                    //declaration des pointeurs

                    Cellule *courant,//un pointeur courant
                            *supp;//case a suprimer

                    int     cpt=1;//un compteur

        //si la liste n'existe pas

        if(!liste){

            printf("\nliste inexistante\n");

                    return ((Cellule*)liste);

        }

        // si on veut supprimer le premier valeur

        if(position==1){

            liste=supp_Deb(liste);//on supprime le premier valeurent

                return ((Cellule*)liste);//on retourne la liste

        }

        //sinon on parcours la liste

        courant=liste;

        while(courant){

            if(cpt==position-1){

               //on suprime l'valeurent

                supp=courant->suivant;
                courant->suivant=courant->suivant->suivant;
                free(supp);

                        return ((Cellule*)liste);//on retourne la liste

            }

            courant=courant->suivant;
            cpt++;

        }

        //pour une position invalide

        printf("\nposition invalide\n");

                    return ((Cellule*)liste);//on retourne la liste


}

//liste du tri des valeurents

#endif // LSC_H_INCLUDED
