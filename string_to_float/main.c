//
// Created by W0L1D on 12/3/2021.
//
#include<stdio.h>
#include<stdlib.h>

#define SP '+' // signe positive '+'
#define SN '-' //signe negative '-'
#define PT '.' //signe point '.'
#define LB '\n' //retour a la ligne '\n'



int is_Num(char ch) {
    return ((int)
            ('0' <= ch) && (ch <= '9')
    );
}

int to_Num(char ch) {
    if (is_Num(ch))
        return ((int) ch - '0');
    return ((int) -1);
}

int trait_sign(char *ch) {
    *ch = getchar();
    if(*ch == SN)
    {
        *ch = getchar();
        return ((int) -1);
    }
    if (*ch == SP)
        *ch = getchar();
    return((int) 1);
}


void trait_int(double *num, char *ch) {
    *num = 0;
    int tmp = 0;
    while(is_Num(*ch))
    {
        (*num) = (*num)*10 + (double)to_Num(*ch);
        *ch = getchar();
    }
}

void trait_Point(char *ch) {
    if (*ch == PT)
    {
        *ch = getchar();
        return;
    }
    if (*ch == LB)
        return;

    printf("\nErreur : Caractere Invalide\n\n");
    exit(-1);
}


void trait_reel(double *num, char *ch) {
    double pow = 1, reel;
    while(is_Num(*ch)) {
        reel = ((double)to_Num(*ch)) * (pow /= 10);
        *num = (*num) + reel;
        *ch = getchar();
    }
}

void valider_resultat(char ch) {
    if (ch == LB)
        return;
    printf("\nErreur : Caractere Invalide\n\n");
    exit(-1);
}

void main() {
    double num = 0;
    int signe;
    char char_lu;
    printf("\nEntrer le reel : ");

    signe = trait_sign(&char_lu);
    trait_int(&num, &char_lu);
    trait_Point(&char_lu);
    trait_reel(&num, &char_lu);
    valider_resultat(char_lu);
    num *= (double)signe;
    printf("\n\n la resultat est : %f", num);



}





