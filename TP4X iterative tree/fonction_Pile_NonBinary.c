// declaration des Bibliothèques
#include <stdio.h>
#include <stdlib.h>



typedef struct Nd {
    int info;
    struct Nd *filsgch;
    struct Nd *frere;
}noeud;

typedef struct PPile {
    struct Nd *noeud;
    struct PPile *svt;
}ppile;

noeud* create_noeud(int val) {
    noeud* ne = (noeud*) malloc(sizeof(noeud));
    if (!ne) {
        printf("\n\n Erreur d'allocation de memoire\n");
        exit(0);
    }

    ne->filsgch = ne->frere = NULL;
    ne->info = val;
    return ((noeud*) ne);
}


ppile* create_noeud_pile(noeud* ne)
{
    ppile *ne_pile= (ppile*) malloc(sizeof(ppile ));
    if (!ne_pile) {
        printf("\n\n Erreur d'allocation de memoire\n");
        exit(0);
    }

    ne_pile->noeud= ne;
    ne_pile->svt=NULL;
    return((ppile*)ne_pile);
}

ppile* empiler(ppile *pile, noeud *root)
{
    ppile *ne_pile = create_noeud_pile(root);

    ne_pile->svt = pile;
    return ((ppile*) ne_pile);
}

ppile* depiler(ppile* pile)
{
    if (!pile)
        return ((ppile*) NULL);

    ppile* tmp;
    tmp = pile;
    pile = pile->svt;
    free(tmp);

    return ((ppile*) pile);
}


noeud* insert_arb_no(noeud *root, int val)
{     int gd,frere, gch;

// si l'arbre n'existe pas
    if (!root)
    {
        noeud *ne = create_noeud(val);
        return ((noeud*) ne);
    }

    printf("vous voulez inserer a fils gauche (tapez : 1) ,a frere (tapez : 2)")  ;
    scanf("%d",&gd);getchar();

    switch(gd)
    {
        case 1 :     root->filsgch=insert_arb_no(root->filsgch, val);
            break;

        case 2 :      root->frere = insert_arb_no(root->frere, val);
            break;

    }
    return((noeud*)root);
}





void  affiche_postfixe_no_recu(noeud *root) {
    if (!root)
        return;

    affiche_postfixe_no_recu(root->filsgch);
    printf("%d\t",root->info);
    if (root->filsgch)
      affiche_postfixe_no_recu(root->filsgch->frere);


}



void  affiche_postfixe_no_itir(noeud *root)
{
    ppile *pile;
    pile=NULL;
    noeud *tmp;
    tmp=root;
    pile=empiler(pile,tmp);
    while(pile)
    {
        tmp=tmp->filsgch;
        while(tmp)
        {
            pile=empiler(pile,tmp);
            tmp=tmp->filsgch;
        }
        tmp=pile->noeud;
        pile=depiler(pile);
        printf("%d \t", tmp->info );

        if(tmp->frere) {
            tmp=tmp->frere;
            pile=empiler(pile,tmp);
        }
    }
}


int main()
{
    noeud *root;
    root=NULL;
    ppile *pile;
    pile=NULL;
    root=insert_arb_no(root, 4);printf("\n" );
    root=insert_arb_no(root,5);printf("\n" );
    root=insert_arb_no(root, 7);printf("\n" );
    root=insert_arb_no(root, 8);printf("\n" );
    root=insert_arb_no(root, 3);printf("\n" );
    root=insert_arb_no(root, 1);printf("\n" );
    root=insert_arb_no(root, 0);printf("\n" );

    printf("\n" );

    printf("\n" );
    affiche_postfixe_no_itir(root);

    printf("\n\n");
    affiche_postfixe_no_recu(root);
    printf("\n\n");


    return(1);
}