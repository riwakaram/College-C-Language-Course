/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab01_ex01.c
 * Author: riwakaram
 *
 * Created on September 9, 2021, 8:52 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int num = 123;
    int *pr2; //pointer for num
    int **pr1; //double pointer for pr2

    //I'm reading the address of variable num and storing it in pointer pr2
    pr2 = &num;

    pr1 = &pr2; //storing the address of pointer pr2 into another pointer pr1

    /*Possible ways to find the value of variable num*/
    printf("Value of num is: %d", num);
    printf("\nValue of num using pr2 is: %d", *pr2);
    printf("\nValue of num using pr1 is: %d", **pr1);

    /*Possible ways to find the address of variable num*/
    printf("\n\nAddress of num is: %p", &num);
    printf("\nAddress of num using pr2 is: %p", pr2);
    printf("\nAddress of num using pr1 is: %p", *pr1);

    /*Find value of pointer*/
    printf("\n\nValue of pointer pr2 is: %p", pr2);
    printf("\nValue of pointer pr2 using pr1 is: %p", *pr1);

    /*Ways to find address of pointer*/
    printf("\n\nAddress of pointer pr2 is: %p", &pr2);
    printf("\nAddress of pointer pr2 using pr1 is: %p", *pr1);

    /*Double pointer value and address*/
    printf("\n\nValue of pointer pr1 is: %p", pr1);
    printf("\nAddress of pointer pr1 is: %p", &pr1);

    return (EXIT_SUCCESS);
}

