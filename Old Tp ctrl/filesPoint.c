//d�claration des librairies standards
#include <stdio.h>
#include <stdlib.h>
#include "filesPoint.h"



//NOM: creer_cellule.
//Entr�e: un entier � stocker dans la cellule.
//sortie: pointeur vers la cellule.
//R�le: cr�er une cellule d'une liste.
Cellule* creer_Cellule (int valeur)
{
    //declarer un pointeur cellule
            Cellule *cel;

    //allouer de l'espace memeoire
    cel=(Cellule*)malloc(sizeof(Cellule));

    //si l'allocation a echoue
    if(!cel)
    {

        printf("\nprobleme de la memoire\n");//on affiche un msg d'erreur
        exit(-1);//on quitte le programme

    }//fin de if(!cel)

    //sinon on cree notre cellule
    cel->element=valeur;
    cel->suivant=NULL;

            return ((Cellule*)cel);//on retourne la cellule

}//fin de creer_Cellule (int valeur).

//NOM: creer_PFile.
//Entr�e: .
//sortie: pointeur vers la pile cr�e.
//R�le: cr�er une file.
MaFile* creer_PFile()
{
    //declaration de la file � creer.
            MaFile *file;

    //on alloue de l'espace m�moire pour\
    une nouvelle fille.
    file=(MaFile*)malloc(sizeof(MaFile));

    //si l'allocation a �chou� alors:
    if (!file)
    {
        /*on affiche un message d'erreur
        et on quite le programme principale*/
        printf("\nprobleme de la memoire.\n");
        exit(-1);
    }//fin de if (!file).

    /*la t�te et la queue de la pile pointe sur
    NULL*/
        file->tete=NULL;
        file->queue=NULL;

    //on retourne la file.
            return ((MaFile*)file);

}//fin de creer_PFile().

//NOM: pFile_Vide.
//Entr�e: une file.
//sortie: 1 si la file est vide et 0 sinon.
//R�le: v�rifie la file est vide.
int pFile_Vide (MaFile file)
{
    //retourne 1 si la file est vide et 0 sinon.
        return ((int)((!file.tete)&&(!file.queue)));

}//fin de pFile_Vide (MaFile file).

//NOM: enfiler_P.
//Entr�e: l'adresse de la file et un entier.
//sortie: l'adresse de la nouvelle file.
//R�le: enfiler un entier dans une file.
void enfiler_P (MaFile *file , int val)
{

            Cellule *nvElem;//une nouvelle cellule

    /*si la file n'existe pas
    alors la fct retourne la tete de
    la file*/
    if (!file)  file=creer_PFile();

    //creer une nouvelle cellule
    nvElem=creer_Cellule(val);

    //si la file est vide
    if(pFile_Vide(*file)){

        //la tete et la queue vont recevoir le nouvel elem
        file->tete=file->queue=nvElem;



    }//fin de if(pFile_Vide(file)).
    //sinon
    else
    {
        file->queue->suivant=nvElem;//le suivant de la queue devient le nouvel element
        file->queue=nvElem;//le nouvel elem devient la queue
    }


}//fin de enfiler_P (MaFile *file , int val).

//NOM: defiler_P.
//Entr�e: l'adresse de la file.
//sortie: l'adresse de la nouvelle file.
//R�le: suprimer le 1�r �l�ment dz la file.
MaFile* defiler_P(MaFile *file)
{
    //on d�clare une cellule temporaire.
                Cellule *tmp;

    /*si la file n'existe pas ou bienla file
    est vide alors on retourne la file.*/
    if((!file)||(pFile_Vide(*file))) return ((MaFile*)file);

    /*s'il ya 1 seul �l�ment dans la file
    alors la queue sera nulle.*/
    if(!file->tete->suivant)

        file->queue=NULL;

    /*on stoque la tete de la file
    dans la cellule temporaire.*/
    tmp=file->tete;
    /*la tete de la file pointe sur sa
    suivante.*/
    file->tete=file->tete->suivant;
    //on libere l'adresse pour l'ancienne tete.
    free(tmp);

    return ((MaFile*)file);
    //on retourne la file d�pil�e.

}//fin de defiler_P(MaFile *file).

//NOM: acceder_Tete.
//Entr�e: une file.
//sortie: l'�l�ment de la t�te.
//R�le: acc�der � la t�te de la file.
int acceder_Tete (MaFile file)
{
    /*si la file est no vide on retourne l'�l�ment dans la
    la t�te de la file*/
    if((!pFile_Vide(file)))  return (int)file.tete->element;

    //sinon.
    else
    {
        //on affiche un message d'erreur.
        printf("\nimpossible d'acceder a la tere de la liste.\n");
        //on quitte le programme principale.
        exit(0);
    }//fin de else.
}//fin de acceder_Tete (MaFile file).

//NOM: afficher_PFile.
//Entr�e: l'adresse de la file.
//sortie: l'adresse de la file.
//R�le: afficher une file.
MaFile* afficher_PFile(MaFile *file)
{
    //declaration d'un pointeur temporaire.
            MaFile *tmp;
    /*declaration d'un entier qui contiendra la
    tete de la file*/
            int val;
    //on initialise la file.
    tmp=creer_PFile();

    printf("\n");

    //tant que la file n'est pas vide alors:
    while(!pFile_Vide(*file))
    {
        //l'entier contient la t�te de  la file.
        val=acceder_Tete(*file);
        //on affiche l'entier.
        printf("%i\t",val);
        //on d�file.
        file=defiler_P(file);
        //on enfile l'entier dans une nouvelle file.
        enfiler_P(tmp ,val);

    }//fin while(!pFile_Vide(*file)).

     printf("\n");

    //on retourne la nouvelle file.
            return (MaFile*)tmp;

}//fin de afficher_PFile(MaFile *file).

//NOM: vider_PFile.
//Entr�e: l'adresse de la file.
//sortie: l'adresse de la file vid�e.
//R�le: vider une file.
MaFile* vider_PFile(MaFile *file)
{
    /*tant que la file est non vide
    on d�file.*/
    while(pFile_Vide(*file))
    {
        defiler_P(file);
    }//fin de while(pFile_Vide(*file)).

    //on retourne la file vid�e.
            return (MaFile*)file;
}//fin de vider_File(MaFile *file).


