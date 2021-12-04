#include<stdio.h>


void line_break() {
	printf("\n");
}


void main() 
{
	// Declare Variables
	int a,b; // Declaration de deux entiers
	float f; //declaration d'un reel
	
	
	/*
	*		Partie 1
	*/
	
	a=2; // affectation de la valeur 2 a la variable a
	
	a++; // incrementation de la variable a par 1
	
	printf("\n la valeur de a vaut %d : ", a); // affichage de la valeur de a
	++a; // incrementation de la variable a par 1
	
	printf("\n la valeur de a vaut %d : ", a); // affichage de la valeur de a
	a--; // decrementation de la variable a par 1
	
	printf("\n la valeur de a vaut %d : ", a); // affichage de la valeur de a
	--a; // decrementation de la variable a par 1
	
	b = a++; // affectation de la valeur de 'a' a 'b' puis l'incrementation de a par 1
	printf("\n la valeur de b = %d et la valeur de a = %d : ", b, a); // affichage de la valeur de a et b
	
	b = --a; // decrementation de la variable a par 1 puis l'affectation de sa valeur a 'b'
	printf("\n la valeur de b = %d et la valeur de a = %d : ", b, a); // affichage de la valeur de a et b

	
	
	
	/*
	*		Partie 2
	*/
	
	f=50.0; //affectation de la valeur 50 a f
	
	f = f*1/10; //
	printf("\n La valeur de f est : %f", f);
	
	
	f=50.0; // Reinitialisation de f
	f *= 1/10;
	printf("\n La valeur de f est : %f", f);
	
	
	
	
	/*
	*		Partie 3
	*/
	a = 10; // Initialisation de la variable a par la valeur 10
	a<0?-a:a; // NB: on doit affectee la valeur retourner par le bloc a un variable;
	printf("\n la valeur de a = %d", a); // affichage de la valeur de a
	
	a = -10; // Reinitialisation de a
	a<0?-a:a; // NB: on doit affectee la valeur retourner par le bloc a un variable;
	printf("\nla valeur de a est %d", a); // affichage de la valeur de a
	
	
	
	
	
	/*
	*		Partie 4
	*/
	printf("sans mention de la base: \t%o\t%x\t%X", 123, 123, 123);
	printf("avec mention de la base: \t%o\t%x\t%X", 123, 123, 123);
	
	
	
	line_break();
	line_break();
	
	
	printf("%+d", 1);
	line_break();
	printf("%d", 1);
	line_break();
	printf("+%d", 1);
	
	
	line_break();
	line_break();
	 
	
	
	printf("%d\n"	// largueur par default
			"%2d\n" // Largueur insuffisante
			"%8d", // Largueur excessive
			1234, 1234, 1234);
	
	
	line_break();
	line_break();
	
	printf("%d\n"
			"%2d\n"
			"%08d",
			1234, 1234, 1234);
			
			
			
	line_break();
	line_break();
	
	printf(" affichage de \n%8.6d", 23);
	
	
	line_break();
	line_break();
	
	printf("affichage a droite %8d* par default\n affichage a gauche :%-8d*", 23, 23);
	
	
	
	line_break();
	line_break();
	
	
	printf("%f", 1.234);
	printf("%e %e %e", 0.1234, 1.234, 12.34);
	printf("%g %g %g", 123.0, 123, 123.4);
	printf("%g", 1.234e2);
	printf("%g %G", 0.0000123, 1234567.0);
	
	
	
	line_break();
	line_break();
	
	
	printf("%+f\t%+e", 12.34, 12.34);
	
	line_break();
	line_break();
	
	
	printf("*%8g*\t%08g", 1.234, 1.234);


    line_break();
    line_break();

    printf("*%8g*\ta droit \n *%-8g*\t a gauche", 1.234, 1.234);

    line_break();
    line_break();

    printf("=%5.3f\n=%10.6f", 1.2345, 1.2345);


    line_break();
    line_break();

    printf("%s", "une chaine");
    printf("une chaine");
    printf("*%12s", "une chaine");


    line_break();
    line_break();


    printf("*%-12s*", "une chaine");
    printf("%6.1s\n%6.2s\n%6.3s\n%6.4s\n%6.5s\n%6.6s",
            "chaine", "chaine", "chaine", "chaine", "chaine", "chaine");


    line_break();
    line_break();







}
