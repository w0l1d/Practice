#include <stdio.h>
#include <stdlib.h>



/*
Nom:ARB_Est_Vide.
Rôle:vérifie si l'arbre est vide.
Entrée:la racine de l'arbre.
Sortie:1 si l'arbre est vide, 0 sinon.
*/
int ARB_Est_Vide(Noeud *Arb)
{
    return (int)(!Arb);
}//fin ARB_Est_Vide(Noeud *Arb).

Noeud *creerArbre(int elem)
{
        Noeud *nvElem;

    nvElem=(Noeud*)malloc(sizeof(Noeud));

    if(!nvElem)
    {
        printf("\nprobleme de la memoire.");
        exit(-1);
    }//fin d'if(!nvElem).

    nvElem->elem=elem;
    nvElem->gauche=nvElem->droit=NULL;

        return (Noeud*)nvElem;
}//fin de *creerArbre(int elem).

Noeud *insertElemOrd(Noeud *arbre , int elem)
{
    Noeud *nvElem;//le noeud à insérer.

    //si la racine n'éxiste pas.
    if(!arbre)
    {
        //on crée un nouveau noeud.
        nvElem=creerArbre(elem);
        //on le retourne.
        return (Noeud*)nvElem;

    }//fin d'if(!arbre).

    if(elem<arbre->elem)
    {
        //on insère à gauche.
        arbre->gauche=insertElemOrd(arbre->gauche,elem);
    }//fin d'if(nvElem->elem<arbre->elem).

    else
    {
        //on insère à droite.
        arbre->droit=insertElemOrd(arbre->droit,elem);
    }//fin d'else.
    //on retourne la racine du nouveau arbre.
        return (Noeud*)arbre;
}

Noeud *insertElem(Noeud *arbre , int elem)
{
    //si la racine n'existe pas.
    if(!arbre)
    {
        Noeud *nvNd;
        nvNd=creerArbre(elem);
            return (Noeud*)nvNd;
    }

    short int val;

    printf("\nvous voulez inserer: \n");
    printf("1-a gauche.\n2-a droite.\n");
    printf("saisissez votre choix: ");
    scanf("%i",&val);

    switch (val)
    {
    case 1:
        arbre->gauche=insertElem(arbre->gauche ,elem);
        break;

    case 2:
        arbre->droit=insertElem(arbre->droit,elem);
        break;

    default:
        printf("\nchoix invalide.");
        exit(0);
        break;
    }

        return (Noeud*)arbre;

}

/*void valNoeud(Noeud *nd , int *ret)
{
    if(nd)
    {
        *ret=nd->elem;
    }
}*/

void rechElem(Noeud *Arbre , int elem , int *bOOl)
{
    if(Arbre)
    {
        if(elem==Arbre->elem)   *bOOl++;
        rechElem(Arbre->gauche,elem,bOOl);
        rechElem(Arbre->droit,elem,bOOl);
    }
}

int trouverElem(Noeud *Arbre , int elem)
{
        int bOOl;

    bOOl=0;

    if(Arbre)   rechElem(Arbre,elem,&bOOl);

    return (int)bOOl;
}

void rechMin(Noeud *arbre,int *min)
{
    if(arbre)
    {
        if(arbre->elem<*min)    *min=arbre->elem;

        rechMin(arbre->gauche,min);
        rechMin(arbre->droit,min);
    }
}

int minArbre(Noeud *arbre )
{
        int min;

    if(arbre)
    {
        min=arbre->elem;
        rechMin(arbre,&min);
    }

        return (int)min;
}

void rechMax(Noeud *arbre,int *max)
{
    if(arbre)
    {
        if(arbre->elem > *max)    *max=arbre->elem;

        rechMax(arbre->gauche,max);
        rechMax(arbre->droit,max);
    }
}

int maxArbre(Noeud *arbre )
{
        int max;

    if(arbre)
    {
        max=arbre->elem;
        rechMax(arbre,&max);
    }

        return (int)max;
}

void affichePrefixe(Noeud *arbre)
{
    if(arbre)
    {
        printf("%i\t",arbre->elem);

        affichePrefixe(arbre->gauche);

        affichePrefixe(arbre->droit);
    }
}

void afficheInfixe(Noeud *arbre)
{
    if(arbre)
    {
        afficheInfixe(arbre->gauche);

        printf("%i\t",arbre->elem);

        afficheInfixe(arbre->droit);
    }
}

Noeud *replace(Noeud *arbre,Noeud *sousArb)
{
    if(sousArb->gauche) arbre=replace(arbre,sousArb->gauche);

    else
    {
        arbre->elem=sousArb->elem;
        sousArb=sousArb->droit;
    }

        return (Noeud*)arbre;

}

Noeud *supArbElemOrd(Noeud *arbre , int val)
{
    if(!arbre)  return (Noeud*)arbre;

    if(val < arbre->elem) arbre->gauche=supArbElemOrd(arbre->gauche,val);

    else if(val > arbre->elem)    arbre->droit=supArbElemOrd(arbre->droit,val);

    else
    {
        if(!arbre->gauche)  arbre=arbre->droit;

        else if(!arbre->droit)   arbre=arbre->gauche;

        else arbre=replace(arbre,arbre->droit);

    }

    return arbre;

}

Noeud *supArbElem(Noeud *arbre, int elem)
{
    if(arbre)
    {
        //si l'element est trouvé.
        //on le suprime de l'arbre.
        if(arbre->elem==elem)
        {
            if(!arbre->gauche)  arbre=arbre->droit;

            else if(!arbre->droit)   arbre=arbre->gauche;

            else    arbre=replace(arbre,arbre->droit);
        }
        else
        {
        //on cherche à ghauce.
        arbre->gauche=supArbElem(arbre->gauche,elem);
        //on cherche à droite.
        arbre->droit=supArbElem(arbre->droit,elem);
        }

    }

    return ((Noeud*)arbre);

}

void affichePostfixe(Noeud *arbre)
{
    if(arbre)
    {
        affichePostfixe(arbre->gauche);

        affichePostfixe(arbre->droit);

        printf("%i\t",arbre->elem);
    }
}

int max(int a , int b)
{
    if(a>=b)    return (int)a;

    return (int)b;
}

int profendeur (Noeud *arbre)
{
    if(!arbre)  return (int)0;

    return (int)(max(profendeur(arbre->gauche),profendeur(arbre->droit))+1);
}
/*
void afficheArb(Noeud *arbre)
{
    Noeud *nd;
    int ind;

    for(int ind=0;ind<profendeur(arbre),ind++)
    {

    }

}
*/

