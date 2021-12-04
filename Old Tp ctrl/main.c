#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NBMAX 100
#define rc '\n' ///retour chariot
#define bl ' ' ///un blanc.
#include "structures.h"
#include "filesPoint.h"
#include "pilesPoint.h"
#include "LSC.h"
#include "arbresBin.h"
#include "listes.h"
#include "pilesTab.h"
#include "expArith.h"



int main()
{
    MaFile* file;
    Cellule *pile;
    Noeud *arbre;
    NdExp *arb=NULL;
    float val;

    arbre=NULL;
    pile=NULL;

    arbre=insertElemOrd(arbre,2);
    arbre=insertElemOrd(arbre,0);
    arbre=insertElemOrd(arbre,1);
    arbre=insertElemOrd(arbre,-4);
    arbre=insertElemOrd(arbre,21);
    arbre=insertElemOrd(arbre,15);
    arbre=insertElemOrd(arbre,111);

    affichePrefixe(arbre);
    printf("\n");
    affichePostfixe(arbre);
    printf("\n");
    afficheInfixe(arbre);
    printf("\n");

    supArbElemOrd(arbre,111);

    affichePrefixe(arbre);
    printf("\n");
    affichePostfixe(arbre);
    printf("\n");
    afficheInfixe(arbre);


    file=creer_PFile();

    pile=empiler_P(pile,2);
    pile=empiler_P(pile,4);
    pile=empiler_P(pile,6);
    pile=empiler_P(pile,1);
    pile=depiler_P(pile);



    afficher_PPile(pile);

    pile=vider_PPile(pile);

    enfiler_P(file,3);
    enfiler_P(file,4);
    enfiler_P(file,13);
    //defiler_P(file);
    enfiler_P(file,16);

    file=afficher_PFile(file);

    file=vider_PFile(file);

    arb=lecture_exp();
    val=evaluer_exp(arb);
    afficherInfixe(arb);
    printf("=%f\n",val);

    return 0;
}
