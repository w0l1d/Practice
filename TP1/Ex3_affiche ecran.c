#include<stdio.h>


void line_break() { // declaration du fonction pour le retourne a la ligne
	printf("\n\n");
}

void main() 
{
	// declaration des variables necessaires
	int i, j;
	char vari_c, c, var_c;
//	char vari_string[];
	
	// Entier
	
	// partie a :
	i = 1258; // affectation de la valeur 1258 au variable i
	printf("la variable entier i a pour valeur pour valeur %d.", i); //affichage de la valeur de i
	
	line_break();
	
	//partie b :
	i = 10; j = 12;
	printf("la somme de %d et de %d.", i, j, i+j);
	
	line_break();
	line_break();
	
	
	//Caracteres
	//partie a :
	printf("La premier lettre de l'alphabet est le %c", 'a');
	
	line_break();
	
	//partie b:
	vari_c = 'Z';
	printf("la dernier lettre de l'alphabet en majiscule est le %c.", vari_c);
	
	line_break();
	
	
	//partie c :
	printf("%c et %c ont les codes ASCII %d et %d", 97, 65, 97, 65);
	

	line_break();
	line_break();
	
	
	
	//Affiche formatee des chaine de caractres
	
	//partie a :
	printf("%s", "c'est une chaine de caracteres");
	
	line_break();
	
	//partie b: 
	char vari_string[] = "une variable de type chaine de caracteres";
	printf("de quelle type est la variable vari_string?\nreponse : %s", vari_string);
		
	
	line_break();
	line_break();
	
	
	//les differantes formats possibles en langage C
	
	//partie 1 :
	printf("%s\n", "cinq"); // affiche la chaine de caractere complet
	printf("%2s\n", "cinq"); // compilateur ignore la longeur de chaine dec aracteres donnee parce qu'il est plus longue que la taille donnee
	printf("%10s\n", "cinq"); // compilateur remplace des caracteres par espace blanche pour obtenir un chaine de caracteres du longeur donnee
	
	
	line_break();
	
	printf("%2.3f\n%11.6f\n\n", 3.1415, 3.1415);
	printf("%5.5f\n%8.5f\n\n", 314.0, 314.0);
	printf("%6.6s\n%6.3s", "string", "string");


	line_break();
	line_break();	
	
	
	//partie 2:
	
	
	printf("entrer la valeur de votre entier ? : ");
	scanf("%d", &i); getchar();
	line_break();
	printf("l'entier i saisi est %d", i);
	
	line_break();
	printf("entrer un caractere au clavier : ");
	scanf("%c", &c);
	line_break();
	printf("le caractere lu est %c", c);
	

	line_break();
	line_break();	
	
	//partie 3 : 
	
	getchar(); // lecture perdue
	var_c = getchar(); // lecture d'un caractere effectue a la variable var_c 
	
	printf("%c",var_c);	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

}



