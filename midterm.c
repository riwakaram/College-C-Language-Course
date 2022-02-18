/* 
 * File:   midterm.c
 * Author: riwakaram
 *
 * Created on October 26, 2021, 5:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Number 1:
 * Computing the value of the induced local field of the neuron
 * Returns -1 for invalid input and 0 for successful running
 */
float field(float x[], float w[], float b, int m, float *v) {
    // checking for invalid input
    if (!x || !w || m <= 0 || !v) return -1;

    *v = b; // initializing v to b

    for (int i = 0; i < m; i++) {
        *v += (w[i] * x[i]);
    }

    // indicate success
    return 0;
}

/*
 * Number 2:
 * Implementing the signum function for a float value v
 */
int sign(float v) {
    if (v > 0) {
        return 1;
    } else if (v == 0) {
        return 0;
    } else {
        return -1;
    }
}

/*
 * Number 3:
 * Returns a random value between a and b
 */
float frand(float a, float b) {
    float r = 0, x = 0, y = 0;

    x = ((b * rand()) / RAND_MAX);
    y = -((a * rand()) / RAND_MAX);

    r = (x - y) / 2;

    return r;
}

/*
 * Printing the elements of a float array 
 */
int print_float_array(float a[], int n) {
    if (!a || n <= 0) {
        return -1;
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("%4.4f ", a[i]);
    }

    return 0;
}

int main(int argc, char** argv) {

    /*
        const int N = 10;

        srand(time(0));

        // vector x
        float x[N];
        for (int i = 0; i < N; i++) {
            x[i] = frand(-5.5, 10.0);
        }

        // vector of weights w
        float w[N];
        for (int i = 0; i < N; i++) {
            w[i] = frand(-50.0, 50.0);
        }

        // bias b
        float b = frand(-1.0, 1.0);

        // field v
        float v = 0;
        field(x, w, b, N, &v);

        // output
        printf("x: [");
        print_float_array(x, N);
        printf(" ]");

        printf("\n");

        printf("w: [");
        print_float_array(w, N);
        printf(" ]");

        printf("\n\nb: %4.4f", b);
        printf("\nThe induced field of the neuron is %4.4f", v);

        // checking for the class
        if (sign(v) == 1) {
            printf("\nThe data belongs to class 1");
        } else if (sign(v) == -1) {
            printf("\nThe data belongs to class 2");
        } else {
            printf("\nThe data does not belong to any class");
        }
     */

    const int N = 10, M = 100;

    int class1 = 0, class2 = 0;

    srand(time(0));

    printf("neuron     v      y  class\n");
    printf("--------------------------\n");

    for (int j = 0; j < M; j++) {

        // vector x
        float x[N];
        for (int i = 0; i < N; i++) {
            x[i] = frand(-5.5, 10.0);
        }

        // vector of weights w
        float w[N];
        for (int i = 0; i < N; i++) {
            w[i] = frand(-50.0, 50.0);
        }

        // bias b
        float b = frand(-1.0, 1.0);

        // field v
        float v = 0;
        field(x, w, b, N, &v);

        // checking for the class
        int class;
        if (sign(v) == 1) {
            class = 1;
            class1++;
        } else if (sign(v) == -1) {
            class = 2;
            class2++;
        }


        if (sign(v) == 1 || sign(v) == -1) {
            printf("%4d%10.4f%6d%4d", j, v, sign(v), class);
        } else {
            printf("%4d%10.4f%6d%s", j, v, sign(v), "no class");
        }

        printf("\n");

    }

    printf("\n%d belong to class 1 and %d to class 2", class1, class2);

    return (EXIT_SUCCESS);
}
