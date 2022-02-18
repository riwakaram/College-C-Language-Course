/* 
 * File:   lab04_ex05.c
 * Author: riwakaram
 *
 * Created on November 1, 2021, 9:46 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This function reads from the file labScores and stores all the grades into 
 * the array a of size (row, col)
 * Returns -1 for invalid input and 0 for successful completion
 */
int read_scores(int row, int col, int a[row][col]) {
    if (!a || row <= 0 || col <= 0) return -1;

    char file_name[] = "labScores.txt";
    FILE *fd = fopen(file_name, "r");

    if (!fd) {
        printf("ERROR reading file %s", file_name);
        return (EXIT_FAILURE);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fscanf(fd, "%d", &a[i][j]);
        }
    }

    fclose(fd);

    return 0;
}

/*
 * This function prints the grades of all the labs for each student
 * Returns -1 for invalid input and 0 for successful completion
 */
int print_scores(int row, int col, int a[row][col]) {
    if (!a || row <= 0 || col <= 0) return -1;

    printf("The scores of each student for each lab are:");

    for (int i = 0; i < row; i++) {
        printf("\nStudent %2d: ", (i + 1));
        for (int j = 0; j < col; j++) {
            printf("%-5d", a[i][j]);
        }
    }

    return 0;
}

/*
 * This function computes the average of each student for all the labs
 * Returns -1 for invalid input and 0 for successful completion
 */
int StudentAvg(int row, int col, int a[row][col], float avg[row]) {
    if (!a || row <= 0 || col <= 0) return -1;

    int sum;
    for (int i = 0; i < row; i++) {
        sum = 0;
        for (int j = 0; j < col; j++) {
            sum += a[i][j];
        }
        avg[i] = (sum / (float) col);
    }

    return 0;
}

/*
 * This function computes the average of each lab for all the students
 * Returns -1 for invalid input and 0 for successful completion
 */
int LabAvg(int row, int col, int a[row][col], float avg[row]) {
    if (!a || row <= 0 || col <= 0) return -1;

    int sum;
    for (int i = 0; i < col; i++) {
        sum = 0;
        for (int j = 0; j < row; j++) {
            sum += a[j][i];
        }
        avg[i] = (sum / (float) row);
    }

    return 0;
}

/*
 * This function prints an array of student lab averages
 * Returns -1 for invalid input and 0 for successful completion
 */
int print_student_averages(int row, float a[row]) {
    if (!a || row <= 0) return -1;

    printf("\n\nThe averages for each student are:");

    for (int i = 0; i < row; i++) {
        printf("\nStudent %2d: %6.2f", (i + 1), a[i]);
    }

    return 0;
}

/*
 * This function prints an array of lab averages
 * Returns -1 for invalid input and 0 for successful completion
 */
int print_lab_averages(int col, float a[col]) {
    if (!a || col <= 0) return -1;

    printf("\n\nThe averages for each lab are:");

    for (int i = 0; i < col; i++) {
        printf("\nLab %2d: %6.2f", (i + 1), a[i]);
    }

    return 0;
}

int main(int argc, char** argv) {

    const int rows = 25, cols = 12;

    int labScores [rows][cols];
    read_scores(rows, cols, labScores);
    print_scores(rows, cols, labScores);

    float stdAvg [rows];
    StudentAvg(rows, cols, labScores, stdAvg);
    print_student_averages(rows, stdAvg);

    float labAvg [cols];
    LabAvg(rows, cols, labScores, labAvg);
    print_lab_averages(cols, labAvg);

    return (EXIT_SUCCESS);
}
