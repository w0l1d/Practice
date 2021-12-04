#ifndef PILESTAB_H_INCLUDED
#define PILESTAB_H_INCLUDED

//fct verifie si la pile est vide

int pile_Vide (TPile pile)
{

    /*on verifie si la pile est vide on retourne 1
    sinon on returne 0*/

            return (int)(pile.nbElem==0);

}

//fct verifie si la pile est satur�e

int pile_Sature (TPile pile)
{

    /*on verifie si la pile est satur�e on retourne 1
    sinon on returne 0*/

            return (int)(pile.nbElem==NBMAX);

}

//fct vide la pile

int raz_Pile (TPile *pile)
{
    //si la pile existe
        if (pile)
        {
            pile->nbElem=0;// le nombre d'elem re�oit 0
                return ((int)1);// et on retourne 1
        }
                return (int)0;//sinon on retourne 0
}

//fct � empiler un element

void empiler (TPile *pile , int elem){

    //si la pile est satur�e on affiche un message d'erreur

        if(pile_Sature(*pile))
        {

            printf("la pile est sature");

        }

        //sinon on empile

        else
        {

            pile->tab[pile->nbElem]=elem;
            pile->nbElem++;

        }

}

//fct � d�piler

void depiler(TPile *pile){

    //si lz pile est vide on affiche un msg d'err

        if(pile_Vide(*pile))
        {

            printf("la pile est vide");

        }

        //sinon on depile

        else
        {

            pile->nbElem--;//on d�cr�mente le nombre d'�lements

        }

}

// fct retourne le sommet de la pile

int sommet_Pile(TPile pile)
{

    //si la pile est vide on affiche un msg d'erreur
    //et on quite le programme

        if(pile_Vide(pile)){

            printf("la pile est vide");
            exit(-1);

        }

        //sinon on returne la tete de la pile

                return ((int)pile.tab[pile.nbElem-1]);

}

//fct affiche la pile

void afficher_Pile (TPile *pile)
{

                TPile tmp;
                int val;

            printf("\n");

            while(!pile_Vide(*pile))
            {

                val=sommet_Pile(*pile);
                printf("%i\t",val);
                depiler(pile);
                empiler(&tmp,val);

            }

            printf ("\n");

            while(!pile_Vide(tmp))
            {

                val=sommet_Pile(tmp);
                empiler(pile,val);
                depiler(&tmp);

            }
}


#endif // PILESTAB_H_INCLUDED
