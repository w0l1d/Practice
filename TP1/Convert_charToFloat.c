

    //declaration des librairies utilise
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>

    #define FL '\n' // constant retour à la ligne
    #define PT '.' // constant point
    #define NS '-' // signe negative
    #define PS '+' // signe positive


    void main()
    {   // Debut du programme

        //Declaration des variables necessaires
        char char_lu; // caractere lu
        double result; // reel apres la transformation
        float power = 1.0f; // la valeur utilisee pour le decalage du chiffre du partie reel
        // initialisation à 0 pour commencer par la partie entier
        short en_decimal = 0,
        // initialisation à 0 pour designer la premier iteration de la boucle
        // 1 si le nombre est positive et -1 si il est negative
        signe = 0;


        printf("Entrer le Reel (0-9) : "); //demander à l'utilisateur d'entrer un reel ou entier

        // lecture du caractere
        // test si il est egal à un retour à la ligne pour sortir de la boucle
        while((char_lu = getchar()) != FL)
        {
            //executer seulement pendant la premiere iteration
            if (!signe)
            {
                signe = (char_lu == NS)? -1: 1; // si le premier caractere lu est '-'
                if ((char_lu == NS) || (char_lu == PS)) continue; // ignorer le reste des instructions pour cette iteration
            }

            if (((char_lu < '0') || ('9' < char_lu))) // si le caractere n'appartient pas à l'intervalle '0'- '9'
            {
                // si le caractere lu est un point et lu pour la premiere fois et on n'a pas deja traiter le point
                if ((!en_decimal) && (char_lu == PT))
                {
                    en_decimal = 1; // designe le traitement du partie decimal a commencer
                    continue; // ignorer le reste des instructions pour cette iteration
                }

                // affichage du message d'erreur
                // sortir du programme
                printf("ERREUR : Caractere incorrecte");
                exit(0);
            }
            if (!en_decimal) // si on traite la partie entier
                result = result * 10 + atoi(&char_lu);
            else // si on traite la partie reel
                result = result + atoi(&char_lu) * (power/=10);
        }

        //changer le signe de la valeur s'il est negative
        result *= (double)signe;

        printf("le chiffre lu est %+f", result); // Edition des resultats

    } // Fin de Programme


