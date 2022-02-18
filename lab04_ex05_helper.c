/* 
 * File:   lab04_ex05_helper.c
 * Author: riwakaram
 *
 * Created on November 1, 2021, 10:08 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Fills a matrix with random numbers between 50 and 99
 * Returns -1 for invalid input and 0 for success
 */
int random_fill_array(int row, int col, int a[row][col]) {
    // check if input is well-formed
    if (!a || row <= 0 || col <= 0) {
        return -1;
    }

    srand(time(0));

    int r, c;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            a[r][c] = (rand() % 50) + 51;
        }
    }


    // indicate success
    return 0;
}

/*
 * Prints an int matrix
 * Returns -1 for invalid input and 0 for success
 */
int print_int_matrix(int row, int col, int a[row][col]) {
    if (!a || row <= 0 || col <= 0) return -1;

    int r, c;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            printf("%5d", a[r][c]);
        }
        printf("\n");
    }

    return 0;
}

int main(int argc, char** argv) {

    const int rows = 25, cols = 12;

    int x[rows][cols];
    random_fill_array(rows, cols, x);

    char file_name[] = "labScores.txt";
    FILE *fd = fopen(file_name, "w");

    if (!fd) {
        printf("ERROR reading file %s", file_name);
        return (EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fd, "%5d", x[i][j]); // enters the lab scores in the file
        }
        fprintf(fd, "\n");
    }

    fclose(fd);

    return (EXIT_SUCCESS);
}
