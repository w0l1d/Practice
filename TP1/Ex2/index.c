#include<stdio.h>

void main()
{
    char mon_nom[20], mon_prenom[20]; //declaration des chaine de caracteres pour le nom et prenom
    int mon_age; // declaration du entier pour mon age 

    printf("Entrer votre nom : "); // demande au utilisateur d'entrer son nom
    scanf("%s", mon_nom); getchar(); // lire la valeur entre pour le nom

    printf("Entrer votre prenom : "); // demande au utilisateur d'entrer son prenom
    scanf("%s", mon_prenom); getchar(); // lire la valeur entre pour le prenom

    printf("Entrer votre age : "); // demande au utilisateur d'entrer son age
    scanf("%d", &mon_age); // lire la valeur entre pour l'age

    printf("\n\n mon nom est \t%s\n mon prenom est \t%s\n mon age est \t%d", //affichage des information nom, prenom, age
    mon_nom, mon_prenom, mon_age); // passer les variable utilise dans la chaine de caracteres formate

}
