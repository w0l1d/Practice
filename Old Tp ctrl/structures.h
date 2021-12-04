#ifndef STUCTURES_H_INCLUDED
#define STUCTURES_H_INCLUDED

typedef struct Cellule{

        int valeur;//le champ qui contient l'element
        struct Cellule *suivant;//le pointeur vers la prochaine case

}Cellule;

typedef struct
{

    Cellule *tete;//la tete de la file.
    Cellule *queue;//la queue de la file.

}MaFile;
typedef struct Noeud
{
    int elem;
    struct Noeud *gauche;
    struct Noeud *droit;

}Noeud;

typedef struct
{
    int tab[NBMAX];
    int nbElem;
}MaListe;

//definir la structure de la pile
typedef struct
{
        int tab[NBMAX];//le tableau d'elements
        int nbElem;//le nombre d'elements de la pile
}TPile;

///la structure de l'arbre.
typedef struct NdExp
{
    struct NdExp *filsGche; ///le fils gauche.
    struct NdExp *filsDrt;  ///le fils droit.
    char elem[10];          ///le contenu du NdExp.

} NdExp;


#endif // STUCTURES_H_INCLUDED
