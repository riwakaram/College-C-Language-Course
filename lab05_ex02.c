/* 
 * File:   lab05_ex02.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 8:33 AM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int a = 25, b = 10;
    printf("Initial values: a = %d, b = %d\n", a, b);
    a = a ^ b; // a holds a_old ^ b_old
    b = a ^ b; // b holds a_old which is (a_old ^ b_old) ^ b_old
    a = a ^ b; // this line means a <--  (a_old ^ b_old) ^ a_old
               // since b holds a_old.
               // So, as a result, a gets the value of b_old.
    printf("New swapped values: a = %d, b = %d\n", a, b);


    return (EXIT_SUCCESS);
}
