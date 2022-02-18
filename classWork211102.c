/* 
 * File:   classWork211102.c
 * Author: riwakaram
 *
 * Created on November 2, 2021, 2:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// structure
// Example: Point in a 2-D Cartesian coordinate system P(x, y)

typedef struct {
    float x;
    float y;
} Point;

/*
 * Write a function that computes and returns the distance between two points
 */
int dist(Point p1, Point p2, float *d) {
    if (!d) return -1;

    // Compute and print the distance between these two points
    *d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));

    return 0;
}

/*
 * Write a function that prints a point in the form (x, y)
 */
void printPoint(Point p) {
    printf("(%.2f, %.2f)", p.x, p.y);
}

int main(int argc, char** argv) {

    /*
        // dynamic memory allocation -- malloc, calloc, realloc
        int *p;
        p = (int *) malloc(50 * sizeof (int));
        // allocates in memory 50 integers
        // an int array of size 50: p[0], p[1], ... , p[49]

        // creates a float aray of size 20 elements
        // float *p = (float *) malloc(20 * sizeof (float));

        int i;
        for (i = 0; i < 50; i++) {
            p[i] = rand() % 100;
            printf("%5d", p[i]);
        }

        free(p);

        // Declare an int 2_D array of size rows x cols
        int rows = 5, cols = 7;
        int *p2 = (int *) malloc(rows * cols * sizeof (int));
     */

    Point p1;
    p1.x = 2.5;
    p1.y = -1.5;

    Point p2;
    p2.x = 3.2;
    p2.y = 1.3;

    // Compute and print the distance between these two points
    float d;
    dist(p1, p2, &d);

    printf("The distance between the two points ");
    printPoint(p1);
    printf(" and ");
    printPoint(p2);
    printf(" is: %f", d);

    Point *pp;
    pp = &p1;
    pp->x = -1.8;
    pp->y = 5.7;

    printf("\n\n");
    printPoint(p1);

    return (EXIT_SUCCESS);
}

