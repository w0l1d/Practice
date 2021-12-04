//
// Created by W0L1D on 10/18/2021.
//


#include<stdio.h>
#include<string.h>

short char_exist(char c, char *str) {
    int i=0;
    while(str[i++])
        if (str[i] == c)
            return 1;
    return 0;
}

void main() {
    char chars_lu[50], long_str[50];
    int i = 0, str_lng = 0, str_max_lng;


    printf("Entrer une chaine de caracters : ");
    fgets(chars_lu, 100, stdin);

    while(chars_lu[i++])
    {
        if(char_exist(chars_lu[i], long_str))
        {
            str_lng = str_lng > strlen()
        }

    }
    printf("valeur de i : %d", i);
}

