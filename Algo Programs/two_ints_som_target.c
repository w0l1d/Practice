//
// Created by W0L1D on 10/19/2021.
//


/* PROGRAM
 * Write a C program
 * get the indices of the two numbers
 * of a given array of integers,
 * such that the sum of the two numbers
 * equal to a specific target
 */


/*
 * TEST
 * Original Array: 4  2  1  5
 * Target Value: 7
 * Indices of the two numbers whose sum equal to target value: 7
 * 1 3
 */


#include "stdio.h"



void main()
{
    int idx1 = -1, idx2 = -1, target = 19;
    int values[16] = {1, 5, 9, 4 , 48 ,748, 545, 8, 54, 87, 12, 14, 10, 7, 111, 17};

    for (int i = 0; i < 16; ++i) {
        for (int j = i+1; j < 16; ++j)
            if (target == (values[i]+values[j])) {
                idx1 = i;
                idx2 = j;
                break;
            }
        if(idx1 > 0)
            break;
    }

    printf("\ntarget %d.",target);
    printf("\nvaleur 1 : %d.",values[idx1]);
    printf("\nvaleur 2 : %d.",values[idx2]);
    printf("\nLes indexes sont : val1 = %d, val2 = %d.", idx1, idx2);
}