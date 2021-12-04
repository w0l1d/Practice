#ifndef EXPARITH_H_INCLUDED
#define EXPARITH_H_INCLUDED

/*fonctions pour transformer les caractéres en des valeurs*/
///*********************************************
///fonction de transformation
///le nom: transformation
///les entrées: le caractére lu
///les sorties: le caractére transformé en entier
///le rôle: transformation d'un caractére
///qui compris entre 0 et 9 en un entier
///**********************************************
int transformation(char car_lu)
{
    //menu de choix
switch(car_lu)
{
case '0' : return 0;
case '1' : return 1;
case '2' : return 2;
case '3' : return 3;
case '4' : return 4;
case '5' : return 5;
case '6' : return 6;
case '7' : return 7;
case '8' : return 8;
case '9' : return 9;
default: printf("erreur"); exit(-1);
}///fin switch(car_lu)
}///fin transformation(char car_lu)

///******************************************
///le nom:transformation_finale
///les entrées:une chaine de caractére
///les sorties:une valeur réel
///le rôle:transformer une chaine
///de caractére numérique on un valeur
///******************************************
float transformation_finale(char *chaine)
{
int compt_vergule=0,///compteur des vergules
rang=1,///pour la transformation de la partie décimale
k;///la transformation du caractére lu
float val=0;///la valeur à retourner
char car_lu;///le caractére lu
int cpt=0;///pour parcourire la chaine
int signe=1;///pour le signe

///transformation de la partie entiere
while((car_lu=chaine[cpt])!='\0')
{
    ///traitement de signe
    /*s'il n'est pas au début,on va pas le traiter là.
    On va le traiter dans la partie default
     de la fonction transformation */
    if (cpt==0)
    {
        ///si le signe est au début
        if((car_lu =='+')||(car_lu =='-'))
        {
         ///si c'est négatif
          if (car_lu =='-') signe=-1;
        ///pour masquer les instructions suivantes
        cpt++;
        continue;
        }///fin if(cpt==0)

    }///fin  if ((car_lu =='+')||(car_lu =='-'))

    ///si c'est un blanc ou retour chariot on quitte
    if (car_lu == rc || car_lu == bl) break;
    ///incrémentation pour la prochaine lecture
    cpt++;
    ///si c'est une virgule on passe à
    ///la transformation de lma partie décimale
    if(car_lu=='.')
    {
    compt_vergule++;
     break;
    }///fin  if(car_lu=='.')

    ///transformation de la valeur
    else
    {
    ///transformation de caractére
    k=transformation(car_lu);
    ///ajout à la valeur
    val=val*10+k;
    }
}///while((car_lu=chaine[cpt])!='\0')

///transformation de la partie décimale
while((compt_vergule==1)&&(car_lu=chaine[cpt])!='\0')
{
    ///si c'est un blanc ou retour chariot on quitte
    if (car_lu == rc || car_lu == bl) break;
    ///incrémentation pour la prochaine lecture
      cpt++;
    ///si c'est une autre virgule on quitte
    if(car_lu=='.')
    {
        compt_vergule++;
        printf("\nerreur.");
        exit(-1);
    }///fin if(car_lu=='.')

     ///transformation
    else
    {
     k=transformation(car_lu);
     val+=(k*pow(10,-1*rang));
         rang++;
    }///fin else
}///fin while(compt_vergule==1)

///traitement du signe
val*=signe;
///valeur finale
return (float)val;
}///fin transformation_finale(char *chaine)

///******************************************
///le nom: creerArbreArith
///les entrées:une chaine de caractére
///les sorties:le NdExp creerArbreArith
///le rôle:creerArbreArith de la mémoire pour une nouvelle insertion
///******************************************
NdExp *creerArbreArith(char elem[10])
{
    NdExp *nd=NULL;///.
    ///l'allocation de l'espace memoire pour le NdExp.
    nd=(NdExp*)malloc(sizeof(NdExp));
    /// si la mémoire est insuffisante
    if(!nd)
    {
        printf("\n mémoire insuffisante.");
        exit(-1);
    }
    ///si non
    ///insertion et initialisation
    nd->filsDrt=nd->filsGche=NULL;
    strcpy(nd->elem,elem);

    return (NdExp*)nd;

}
///******************************************
///le nom:insertElemArb
///les entrées:pointeur sur un arbre,
///la chaine de caractére à insérer
///les sorties:pointeur sur un arbre
///le rôle:insérer un nouveau NdExp
///******************************************
NdExp *insertElemArb(NdExp *arbre , char elem[10])
{
    NdExp *nd;///le nouvel NdExp
  ///si l'arbre est vide
    if(!arbre)
    {
        nd=creerArbreArith(elem);
        return (NdExp*)nd;
    }///fin if(!arbre)
  ///l'arbre contient des éléments
  ///traitement des cas pour respecter la priorité
  ///si on a une addition ou une soustraction,
  ///on va l'inserer à la racine
    if((!strcmp(elem,"+"))||(!strcmp(elem,"-")))
    {
        nd=creerArbreArith(elem);
        nd->filsGche=arbre;
        return (NdExp*)nd;
    }///fin if((!strcmp(elem,"+"))||(!strcmp(elem,"-")))
    ///la multiplication et la soustraction sont
    /// toujours en bas de l'addition et la soustraction
    ///pour lestraiter en premier dans l'évaluation
    if((!strcmp(elem,"*"))||(!strcmp(elem,"/")))
    {
        nd=creerArbreArith(elem);
        if((!strcmp(arbre->elem,"+"))||(!strcmp(arbre->elem,"-")))
        {
        nd->filsGche=arbre->filsDrt;
        arbre->filsDrt=nd;
        return (NdExp*)arbre;
        }///fin if
        else
        {
         nd->filsGche=arbre;
         return (NdExp*)nd;
        }///fin else

    }///fin if((!strcmp(elem,"*"))||(!strcmp(elem,"/")))

    arbre->filsDrt=insertElemArb(arbre->filsDrt,elem);
    return (NdExp*)arbre;
}///fin *insertElemArb(NdExp *arbre , char elem[10])

///******************************************
///le nom:nature_car
///les entrées:un caractére
///les sorties:1 si c'est un opérateur,
///0 si c'est un autre caractére
///le rôle:est de déterminer la nature
///d'un caractére passé par argument
///*****************************************
int nature (char car)
{
 switch(car)
 {
   case '+':
   case '-':
   case '/':
   case '*':return (int)1;break;
   default: return (int)0;
 }///fin switch(car)
}///fin nature(char car)

///******************************************
///le nom:lecture_exp
///les entrées:aucune entrée
///les sorties:l'arbre de l'expression
///le rôle:est de lire une expression arithmétique,
///et de la représenter sous forme d'un arbre
///******************************************
NdExp *lecture_exp()
{
    char chaine_lu[10],
        op[2],
        car_lu;
    int cpt=0;
    NdExp *arb=NULL;
    printf("\nentrer votre expression: \n");
    while((car_lu=getchar())!='\n')
    {
        if(!nature(car_lu))
        {
            chaine_lu[cpt]=car_lu;
            cpt++;
        }///fin if(!nature(car_lu))
        else
        {
            if(cpt)
            {
                chaine_lu[cpt]='\0';
                cpt=0;
                arb=insertElemArb(arb,chaine_lu);
                op[0]=car_lu;
                op[1]='\0';
                arb=insertElemArb(arb,op);
            }
            else
            {
                //cpt=0;
                chaine_lu[cpt]=car_lu;
                cpt++;

            }

        }/// fin else

    }///fin while((car_lu=getchar())!='\n')
    if(cpt)
    {
    chaine_lu[cpt]='\0';
    arb=insertElemArb(arb,chaine_lu);
    }

    return (NdExp*)arb;
}///fin *lecture_exp()

///******************************************
/**
le nom:nature_Nd.
les entrées:une chaine de caractères.
les sorties:un entier.
le rôle:elle retourne 1 s'il s'agit
d'un operateur, 0 sinon.
**/
///******************************************

int nature_Nd(char op[2])
{

    if(!strcmp(op,"+")) return ((int)1);

    if(!strcmp(op,"-")) return ((int)1);

    if(!strcmp(op,"*")) return ((int)1);

    if(!strcmp(op,"/")) return ((int)1);

    return ((int)0);


}

///******************************************
///le nom:evaluer_exp
///les entrées:un arbre arithmétique
///les sorties:resultat de l'évaluation
///le rôle:évaluer un expression mathématique,
///et retourner sa valeur
///******************************************
float evaluer_exp(NdExp *arbre)
{

    if(arbre)
    {
        ///s’il sagit d’un opérateur.
        if(nature_Nd(arbre->elem))
        {
            ///si le fils droit est nul on quitte le programme.
            if(!arbre->filsDrt)
            {
                printf("\nerreur.");
                exit(-1);
            }
            ///s’il s’agit d’une somme.
            if(!strcmp(arbre->elem,"+"))
            return evaluer_exp(arbre->filsGche)+evaluer_exp(arbre->filsDrt);
            ///s’il s’agit d’une soustraction.
            if(!strcmp(arbre->elem,"-"))
            return evaluer_exp(arbre->filsGche)-evaluer_exp(arbre->filsDrt);
            ///s’il s’agit d’une multiplication.
            if(!strcmp(arbre->elem,"*"))
            return evaluer_exp(arbre->filsGche)*evaluer_exp(arbre->filsDrt);
            ///s’il s’agit d’une division.
            if(!strcmp(arbre->elem,"/"))
            {
                if(evaluer_exp(arbre->filsDrt)!=0)
                return evaluer_exp(arbre->filsGche)/evaluer_exp(arbre->filsDrt);

                printf("\nerreur.\n");
                exit(-1);
            }
        }
        ///sinon on tansforme le contenu du nœud à un réel.
        return ((float)transformation_finale(arbre->elem));

    }
    ///si le nœud est nul on retourne 0.
    return ((float)0);
}
///******************************************

/**
le nom :afficherInfixe.
les entrées :la racine d'un arbre.
les sorties :
le rôle :afficher les éléments de l'arbre
d'une façon infixée.
 **/
///******************************************
void afficherInfixe(NdExp *Arb)
{
       if (Arb)
       {
           afficherInfixe(Arb->filsGche);
           printf("%s", Arb->elem);
           afficherInfixe(Arb->filsDrt);
       }
}
///******************************************

/**
le nom:razArb.
les entrées:un arbre.
les sorties:l'arbre vidée.
le rôle:vider un arbre.
**/
///******************************************
NdExp *razArb(NdExp *arbre)
{
    ///si l'arbre est non vide alors.
    if(arbre)
    {
        NdExp *tmp;
        ///on libere le noued.
        tmp=arbre;
        ///on libère à gauche.
        arbre->filsGche=razArb(arbre->filsGche);
        ///on libère à droite.
        arbre->filsDrt=razArb(arbre->filsDrt);
        arbre=NULL;
        free(tmp);

    }
    return (NdExp*)arbre;
}
///****************************************

#endif // EXPARITH_H_INCLUDED
