//
// Created by W0L1D on 10/12/2021.
//

#include<stdio.h>


void main()
{
    char a_min = 'a', a_max = 'A', c;

    int val;

    printf("Entrer le caractere : ");
    scanf("%c", &c);


    printf("\n Code ASCII de %c est %d\n\n", c, c);

    if ((c>= 'a' && c <= 'z') || (c>= 'A' && c>= 'Z'))
    {
        if(c >= a_min)
            printf("la valeur en Miniscule : %c", (c-(a_min - a_max)));
        else
            printf("la valeur en Majiscule : %c", (c+(a_min - a_max)));
    } else
        printf("le caractere %c n'est pas une lettre de l'alphabet.", c);

}
