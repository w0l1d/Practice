#ifndef PILESPOINT_H_INCLUDED
#define PILESPOINT_H_INCLUDED



/*
//definir la structure de la pile.
typedef struct Cellule
{

    int valeur;//le champ de l'element.
    struct Cellule *suivant;//la case suivante.

}Cellule;
/*

/*la fct de l'allocation de l'espace memoire
d'une cellule.
Entr�e:un entier.
Sortie:la cellule.
*/
/*
Cellule* creer_Cellule (int valeur)
{

            Cellule *cel;

    //alouer de l'espace memoire de la cellule.
    cel=(Cellule*)malloc(sizeof(Cellule));

    //si l'allocation a �chou�.
    if(!cel)
    {

        printf("\nprobleme de la memoire.\n");
        exit(-1);

    }

    //insertion de l'element dans la cellule.
    cel->valeur=valeur;
    cel->suivant=NULL;
    //on retourne la cellule qu'on a cre�e.
            return ((Cellule*)cel);

}

/*fct initiallise la pile.
Nom:init_PPile.
Input: le pointeur t�te de la pile.
Output:le pinteur de la t�tede la pile.
*/


Cellule* init_PPile (Cellule *pile)
{
    /*la t�te de la pile re�oit un
    pointeur null*/
    pile=NULL;
    /*on retourne la t�te de la pile*/
            return ((Cellule*)pile);

}//fin de init_PPile (Cellule *pile).

/*
fct � vider la pile
Input: le pointeur de la t�te de la pile.
Output: le pointeur de la pile vid�e.
*/

Cellule* vider_PPile (Cellule *pile)
{
   //d�claration d'un pointeur temporaire.
            Cellule *tmp;
    //tant que la t�te n'est pas nulle
    while(pile)
    {

      tmp=pile;//le temporaire contient la t�te de la pile.
      pile=pile->suivant;//la t�te prend son successeur.
      free(tmp);//on lib�re l'ancienne t�te.

    }//fin de while(pile).
    //on retourne la t�te de la pile vid�e.
            return ((Cellule*)pile);

}//fin de vider_PPile (Cellule *pile).

/*fct v�rifie si la pile est vide.
Nom:pPile_Vide.
Input:le pinteur de la t�te de la pile.
Output:1 si la pile est vide et 0 sinon.*/
int pPile_Vide (Cellule *pile)
{
    /*on verifie si la pile est vide on retourne 1
    sinon on returne 0*/
            return ((int)!pile);

}

/*Fct d'empiler un element dans une pile.
INPUT:l'ancienne tete de la pile et l'element � empiler.
Output:nouvelle la tete  de la pile.*/
Cellule* empiler_P (Cellule *pile , int elem)
{
    //declaration d'un pointeur\
    de nouvel �l�ment.
            Cellule *nvElem;

    /*creation d'une cellule
    pour un nouvel element.*/
    nvElem=creer_Cellule(elem);

    //on insere le nouvel �l�ment dans la pile.
    /*le suivant du nouvel element re�oit la tete
    de la pile*/
    nvElem->suivant=pile;

    //on retourne la case du nouvel element.
            return ((Cellule*)nvElem);

}

/*fct � d�piler une pile.
nom:depiler.
Input:le pointeur de la t�te de la pile.
Output: le pointeur de la nouvelle t�te
de de la pile.
*/

Cellule* depiler_P(Cellule *pile)
{

    //on d�clare un pointeur temporaire.
            Cellule *tmp;

    tmp=pile;//il re�oit la tete de la pile.

    //la tete re�oit la case suivante
    pile=pile->suivant;

    free(tmp);/*on libere l'espace memoire
    pour le 1�r �l�ment de la liste.*/

            return ((Cellule*)pile);

}

/*fct retourne la taille de la pile.
Input: le pointeur de la t�te de la pile.
Output: le nombre des �l�ments dans la pile.*/

int taille_PPile (Cellule *pile)
{
    //d�claration des variables et pointeurs.
            Cellule *courant;//un pointeurs � parcourir la pile.
            int cmpt=0;//un entier compteur.
    //si la pile est non vide.
    if(pile)
    {
        //courant re�oit la t�te de la pile.
        courant=pile;
        //tant que le courant n'est pas nul on parcourt.
        while(courant){

            cmpt++;//on incr�ment le compteur.
            courant=courant->suivant;//on passe au suivant.

        }//fin de while(courant).

    }//fin de if(pile).

            return ((int)cmpt);//on retourne le compteur.

}//fin de taille_PPile (Cellule *pile).

/*
fct retourne le sommet de la pile.
Nom:sommet_PPile.
Input:le pointeur de la t�te de la pile.
Output:l'�l�ment du sommet de la pile si la pile
est non vide sinon on quitte le programme.
*/

int sommet_PPile (Cellule *pile)
{
    //si la pile est non vide.
    if(!pPile_Vide(pile))
    {
       //on retourne la valeur au sommet.
        return ((int)pile->valeur);

    }//fin de if(!pPile_Vide(pile)).

    //sinon on affiche un message d'erreur et on quitte.
    printf("\nla pile est vide.\n");
    exit(0);

}//fin de sommet_PPile (Cellule *pile).

Cellule* inversPile(Cellule *pile)
{
    Cellule *tmp=NULL;

    while(pile)
    {
        tmp=empiler_P(tmp,pile->valeur);
        pile=depiler_P(pile);
    }

    return (Cellule*)pile;
}

/*fct affiche la pile.
Nom:afficher_PPile.
Input: on passe en argument l�adresse de la pile.
Output:on affiche les �l�ments de la pile � l��cran et
on retourne t�te de la pile.*/

Cellule* afficher_PPile (Cellule *pile)
{

    Cellule *tmp; //une pile temporaire.
/*une variable qui contient � chaque fois le sommet de la pile.*/
    int val;

    printf("\n");

    //tantque la pile n�est pas vide.
    while(!pPile_Vide(pile))
    {
        /*la valeur re�oit la t�te le sommet de la pile et on l�empile dans la pile
        temporaire et depile notre pile pass� en argument.*/
        val=sommet_PPile(pile); /*la valeur re�oit la t�te le sommet de la pile.*/
        printf("%i\t",val); //on affiche le sommet.
        pile=depiler_P(pile); /*depile notre pile pass�e en
            Argument.*/
        tmp=empiler_P(tmp,val); /*on empile la valeur dans la
			pile temporaire.*/

    }

    printf ("\n");

    //tant que la pile temporaire n�set pas vide.
    // while(!pPile_Vide(tmp))
    // {
    //val=sommet_PPile(tmp); /*la valeur re�oit la t�te le
    //sommet de la pile temporaire.*/
    /*pile=empiler_P(pile,val); /*on empile la valeur dans la pile*/
    // tmp=depiler_P(tmp);//depile notre pile temporaire.

    //}//fin de while(!pile_Vide(tmp)).

    pile=inversPile(tmp);


    return (Cellule*)pile;

}

int rech_min(Cellule *pile)
{
            int min;
            Cellule *tmp;
    if(!pile)
    {
        exit(-1);
    }

    min=pile->valeur;


    do
    {
        tmp=empiler_P(tmp,pile->valeur);
        if(pile->valeur<min)
        {
            min=pile->valeur;
        }

        pile=depiler_P(pile);
    }while(pile);

            return min;
}


#endif // PILESPOINT_H_INCLUDED
