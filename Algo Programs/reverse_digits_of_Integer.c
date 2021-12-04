//
// Created by W0L1D on 10/17/2021.
//

#include<stdio.h>


void main() {
    int tmp, given_int, reversed_int = 0, length = 1;
    float gv_decimal;
    printf("Entrer un entier : ");
    scanf("%d", &given_int);
    while((given_int / (length *= 10)));

    gv_decimal = ((float)given_int) / (float)length;



    printf("\n\n valeur conclue ::: %d", length);



    for(int i = 1; i < length; i *=10) {
        tmp = (float)(gv_decimal = gv_decimal * 10);
        gv_decimal -= tmp;
        reversed_int = reversed_int + tmp*i;
    }

    printf("\n\nMethod 1 :: %d",reversed_int);

    reversed_int = 0;
    int tmp2 = given_int;

    float i2 = 0.1f;
    for(int i = length/10; i >= 1; i /=10) {
        tmp2 -= (tmp = tmp2/i)*i;
        reversed_int = reversed_int + tmp*(i2 *=10);
    }


    printf("\n\nLa resultat : %d", reversed_int);



}
