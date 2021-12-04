#include <stdio.h>
#include <stdlib.h>

#define FL '\n'


char maj_to_minus(char car)
{
    return ((char) car+('a'-'A'));
}

char minus_to_maj(char car)
{
    return ((char) car+('A'-'a'));
}

int fob(int n) {
    if (n<=2)
        return 1;
    return fob(n-1) + fob(n-2);
}

void main() 
{
    /*char char_lu;

    printf("entrer une phrase : ");

    while ((char_lu = ((char)getchar())) != FL)
        if (('a' < char_lu) && (char_lu < 'z'))
            printf("%c", minus_to_maj(char_lu));
        else if (('A' < char_lu) && (char_lu < 'Z'))
            printf("%c", maj_to_minus(char_lu));
        else if (char_lu == ' ')
            printf("BLC");
        else if (char_lu == '\t')
            printf("TAB");
        else
            printf("%c", char_lu);*/

    int n = 50;
    printf("\n\nresultat %d : %d\n\n\n", n, fob(n));


}