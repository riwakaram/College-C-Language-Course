/* 
 * File:   lab02_ex03.c
 * Author: riwakaram
 *
 * Created on September 28, 2021, 10:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * This first sequence function has a_0 = 1 and a_(i+1) = 2 * a_i + 1 for i > 0
 * _seq01 is the helper function
 */
int _seq01(int n) {
    int i, a = 1;

    for (i = 1; i <= n; i++) {
        a = 2 * a + 1;
    }

    return a;
}

int seq01(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    *s = _seq01(n);

    // success
    return 0;
}

/*
 * This second sequence function has a_0 = 1 and a_(i+1) = 3 * a_i + 2 for i > 0
 * _seq02 is the helper function
 */
int _seq02(int n) {
    int i, a = 1;

    for (i = 1; i <= n; i++) {
        a = 3 * a + 2;
    }

    return a;
}

int seq02(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    *s = _seq02(n);

    // success
    return 0;
}

/*
 * This third sequence function has a_0 = 59 and a_(i+1) = a_i / 2 + 1 for i > 0
 * _seq03 is the helper function
 */
int _seq03(int n) {
    int i, a = 59;

    for (i = 1; i <= n; i++) {
        a = a / 2 + 1;
    }

    return a;
}

int seq03(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    *s = _seq03(n);

    // success
    return 0;
}

/*
 * This fourth sequence function has a_0 = 1, a_1 = 1 and
 * a_(i+1) = a_(i-1) + a_i for i > 1
 * _seq04 is the helper function
 */
int _seq04(int n) {
    int i, a = 1, b = 1;

    for (i = 2; i <= n; i++) {
        int t = b; // temporary variable
        b = a + b;
        a = t;
    }

    return b;
}

int seq04(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    *s = _seq04(n);

    // success
    return 0;
}

/*
 * This fifth sequence function has a_0 = 0, a_1 = 2 and
 * a_(i+1) = 2 * a_(i-1) - a_i for i > 1
 * _seq05 is the helper function
 */
int _seq05(int n) {
    int i, a = 0, b = 2;

    for (i = 2; i <= n; i++) {
        int t = b; // temporary variable
        b = 2 * a - b;
        a = t;
    }

    return b;
}

int seq05(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    *s = _seq05(n);

    // success
    return 0;
}

/*
 * This sixth sequence function has a_0 = 7, a_1 = 11 and
 * a_(i+1) = -a_(i-1) + a_i for i > 1
 * _seq06 is the helper function
 */
int _seq06(int n) {
    int i, a = 7, b = 11;

    for (i = 2; i <= n; i++) {
        int t = b; // temporary variable
        b = -a + b;
        a = t;
    }

    return b;
}

int seq06(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    *s = _seq06(n);

    // success
    return 0;
}

/*
 * This seventh sequence function has a_0 = 1, a_1 = 1, a_2 = 1 and
 * a_(i+1) = a_(i-2) + a_i for i > 2
 * _seq07 is the helper function
 */
int _seq07(int n) {
    int i, a = 1, b = 1, c = 1;

    for (i = 3; i <= n; i++) {
        int t = c; // temporary variable
        c = a + c;
        a = b;
        b = t;
    }

    return c;
}

int seq07(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    *s = _seq07(n);

    // success
    return 0;
}

int main(int argc, char** argv) {

    const int N = 15;

    // sequence01
    int s01;
    if (seq01(N, &s01) == -1) {
        printf("ERROR: Wrong input.\n\n");
    } else {
        printf("The first sequence is:\n");
        printf("a0 = %-10d\n", 1);
        for (int i = 1; i <= N; i++) {
            seq01(i, &s01);
            printf("a%d = %-10d\n", i, s01);
        }
        printf("\n\n");
    }

    // sequence02
    int s02;
    if (seq02(N, &s02) == -1) {
        printf("ERROR: Wrong input.\n\n");
    } else {
        printf("The second sequence is:\n");
        printf("a0 = %-10d\n", 1);
        for (int i = 1; i <= N; i++) {
            seq02(i, &s02);
            printf("a%d = %-10d\n", i, s02);
        }
        printf("\n\n");
    }

    // sequence03
    int s03;
    if (seq03(N, &s03) == -1) {
        printf("ERROR: Wrong input.\n\n");
    } else {
        printf("The third sequence is:\n");
        printf("a0 = %-10d\n", 59);
        for (int i = 1; i <= N; i++) {
            seq03(i, &s03);
            printf("a%d = %-10d\n", i, s03);
        }
        printf("\n\n");
    }

    // sequence04
    int s04;
    if (seq04(N, &s04) == -1) {
        printf("ERROR: Wrong input.\n\n");
    } else {
        printf("The fourth sequence is:\n");
        printf("a0 = %-10d\na1 = %-10d\n", 1, 1);
        for (int i = 2; i <= N; i++) {
            seq04(i, &s04);
            printf("a%d = %-10d\n", i, s04);
        }
        printf("\n\n");
    }

    // sequence05
    int s05;
    if (seq05(N, &s05) == -1) {
        printf("ERROR: Wrong input.\n\n");
    } else {
        printf("The fifth sequence is:\n");
        printf("a0 = %-10d\na1 = %-10d\n", 0, 2);
        for (int i = 2; i <= N; i++) {
            seq05(i, &s05);
            printf("a%d = %-10d\n", i, s05);
        }
        printf("\n\n");
    }

    // sequence06
    int s06;
    if (seq06(N, &s06) == -1) {
        printf("ERROR: Wrong input.\n\n");
    } else {
        printf("The sixth sequence is:\n");
        printf("a0 = %-10d\na1 = %-10d\n", 7, 11);
        for (int i = 2; i <= N; i++) {
            seq06(i, &s06);
            printf("a%d = %-10d\n", i, s06);
        }
        printf("\n\n");
    }

    // sequence07
    int s07;
    if (seq07(N, &s07) == -1) {
        printf("ERROR: Wrong input.\n\n");
    } else {
        printf("The seventh sequence is:\n");
        printf("a0 = %-10d\na1 = %-10d\na2 = %-10d\n", 1, 1, 1);
        for (int i = 3; i <= N; i++) {
            seq07(i, &s07);
            printf("a%d = %-10d\n", i, s07);
        }
        printf("\n\n");
    }

    return (EXIT_SUCCESS);
}

