/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   quiz01.c
 * Author: riwakaram
 *
 * Created on September 21, 2021, 1:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {

    float pi = acos(-1); // float pi initialized to acos(-1)
    float *p = &pi; // pointer p to the float pi
    float **pp; //double pointer pp

    pp = &p; //double pointer pp points to the pointer p
    **pp = pi / 4;
    // the value where the double pointer points (pi) will be the initial value
    // of pi over 4

    printf("%.6f", *p);
    //printing the value where the pointer p points so the float variable pi

    return (EXIT_SUCCESS);
}

