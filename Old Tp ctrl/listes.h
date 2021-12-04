#ifndef LISTES_H_INCLUDED
#define LISTES_H_INCLUDED
void init_Liste (MaListe *liste){

        if(!liste) printf("liste inexistante");

        else{

            liste->nbElem=0;

        }

}

int liste_Vide(MaListe liste){

        return (int)(liste.nbElem==0);

}

int liste_Pleine(MaListe liste){

        return (int)(liste.nbElem==NBMAX);

}

int inserer_Liste (MaListe *liste , int position , int elem){

                    int indice;

            if (!liste)      return ((int)-1);

            if ((position<=0)||(position>liste->nbElem+1))  return ((int)0);

            if (liste_Pleine(*liste))       return ((int)-2);

            for (indice=liste->nbElem-1; indice>=position-1; indice--)

                liste->tab[indice+1]=liste->tab[indice];

            liste->tab[position-1]=elem;
            liste->nbElem++;

                    return ((int)1);


}


int localiser_Liste(MaListe liste , int elem){

                int ind;

        for (ind=0; ind<liste.nbElem; ind++)

            if (liste.tab[ind]==elem)

                    return ((int)(ind+1));

                 return ((int)0);

}

void afficher_TListe(MaListe liste){

    int ind;

    printf("\nMa liste est:\n");

    for(ind=0; ind<liste.nbElem; ind++)
    {
        printf("%i\t",liste.tab[ind]);
    }
    printf("\n");
}

int acceder_liste (MaListe liste , int position){


    if ((position<=0)||(position>liste.nbElem)){
         printf("\nposition invalide\n");
         exit(0);
       }

       return liste.tab[position-1];


}


int supp_Liste (MaListe *liste , int position){

                    int indice;

        if(!liste)
        {
            printf("\nliste inexistante\n");
            return (int)-1;
        }

        if (liste_Vide(*liste))
        {
            printf("\nla liste est vide\n");
            return (int)0;
        }

        if ((position<=0)||(position>liste->nbElem))
        {
            printf("\nposition invalide\n");
            return (int)-2;
        }



        for (indice=position; indice<liste->nbElem; indice++)

            liste->tab[indice-1]=liste->tab[indice];

            liste->nbElem--;


}

int suivant_Liste (MaListe liste , int position){

       if (liste_Vide(liste)){

            printf("\nListe vide\n");
            exit(0);

       }

       if ((position<=0)||(position>liste.nbElem)){
         printf("\nposition invalide\n");
         exit(0);
       }

       if (position==liste.nbElem){

           printf("\ncet element n'apas de successeur\n");
           exit(0);

       }

                return (int)acceder_liste(liste,position+1);

}

int precedent_Liste (MaListe liste , int position){

       if (liste_Vide(liste)){

            printf("\nListe vide\n");
            exit(0);

       }

       if ((position<=0)||(position>liste.nbElem)){
         printf("\nposition invalide\n");
         exit(0);
       }

       if (position==liste.nbElem){

           printf("\ncet element n'a pas de precedeur\n");
           exit(0);

       }
    return (int)acceder_liste(liste,position-1);
}

#endif // LISTES_H_INCLUDED
