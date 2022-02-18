/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab01_ex02.c
 * Author: riwakaram
 *
 * Created on September 12, 2021, 11:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int a = 5, b = 10, c;
    int *p = &a, *q = &b;
    c = p - q;

    printf("%p a = %d", p, *p);
    printf("\n%p b = %d", q, *q);
    printf("\n%p c = %d", &c, c);
    printf("\n%p p --> %p *p = %d", &p, p, *p);
    printf("\n%p q --> %p *q = %d", &q, q, *q);

    return (EXIT_SUCCESS);
}

