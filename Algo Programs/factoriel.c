#include<stdio.h>

int fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact = fact*i;
    }
    return (int) fact;
}


int fact_recu(int n) {
    if (n==0) return 1;
    return (int) (n * fact_recu(n-1));
}


void main() {

    int n;
    printf("Entrer un entier : ");

    scanf("%d", &n);

    printf("LA valeur avec fact normal : %d\n", fact(n));
    printf("LA valeur avec fact recursive : %d", fact_recu(n));

}