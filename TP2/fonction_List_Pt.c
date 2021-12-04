//
// Created by W0L1D on 11/7/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct PtList {
    int val;
    struct PtList *svt;
}PList;




    int supprimer_pos_PtList(PList *list, int pos) {
        //list n'exist pas
        if (!list)
            return -1;

        //on ne peut pas supprimer le premier element
        if (pos == 1)
            return -2;

        PList *curr = list,
        tmp;
        int indice = 1;

        while (curr->svt)
        {
            if (pos == indice+1) //si on est en precedant de pos
                break;
            indice++;
            curr = curr->svt;
        }

        //element n'est pas trouver
        // position donnee est erronee
        if (indice != pos)
            return -3;

        tmp = curr->svt; // tmp == element a supprimer
        curr->svt = tmp->svt;
        free(tmp);
        return 1;
    }




