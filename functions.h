/* 
 * File:   functions.h
 * Author: riwakaram
 *
 * Created on October 26, 2021, 5:11 PM
 */

#ifndef MIDTERM_H
#define MIDTERM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    /*
     * Write a function that prints an int matrix
     * Return 0 if successful, -1 if the array is NULL
     */
    int print_int_matrix(int row, int col, int a[row][col]) {
        if (a == NULL || row <= 0 || col <= 0) return -1;

        int r, c;
        for (r = 0; r < row; r++) {
            for (c = 0; c < col; c++) {
                printf("%5d", a[r][c]);
            }
            printf("\n");
        }

        return 0;
    }

    /*
     * Write a function that computes and returns the sum of the values on the 
     * perimeter of an int matrix
     * Return 0 if successful, -1 for a NULL pointer
     */
    int perimeter(int row, int col, int a[row][col], int *per) {
        if (a == NULL || row <= 0 || col <= 0) return -1;

        *per = 0;
        int r, c;
        for (r = 0; r < row; r++) {
            for (c = 0; c < col; c++) {
                if (r == 0 || r == (row - 1) || c == 0 || c == (col - 1)) {
                    *per += a[r][c];
                }
            }
        }

        return 0;
    }

    /*
     * Write a function that creates a matrix of squares of the sum of the indices 
     * of rows and columns
     * 
     *      0  1  2  3  4  5 
     * -----------------------
     *  0 | 0  1  4  9 16 25
     *  1 | 1  4  9 16 25 36
     *  2 | 4  9 16 25 36 49
     * 
     */
    int squares(int row, int col, int a[row][col]) {
        if (a == NULL || row <= 0 || col <= 0) return -1;

        int r, c;
        for (r = 0; r < row; r++) {
            for (c = 0; c < col; c++) {
                a[r][c] = (r + c) * (r + c);
            }
        }

        return 0;
    }

    /*
     * Sums the elements of a, an array of length len, and writes the sum to where 
     * sum references. Returns 0, unless a or sum is NULL or len is negative or 0,
     * in which case returns -1.
     */
    int sumArray(int *a, int len, int *sum) {
        if (!a || !sum || len <= 0) {
            return -1;
        }

        *sum = 0; // initializing sum to zero so we can add to it the elements of a

        for (int i = 0; i < len; i++) {
            *sum += a[i];
        }

        // success
        return 0;
    }

    /*
     * This function computes the dot product of two vectors and stores that value
     * in a reference.
     * It returns -1 if any of the references are null references, -2 if n is
     * negative or equal to 0 and 0 for a success run
     */
    int dotProduct(int x[], int y[], int n, int *dp) {
        // check if input is well-formed
        if (x == NULL || y == NULL || dp == NULL) {
            return -1;
        }
        if (n <= 0) {
            return -2;
        }

        // compute the dot product
        *dp = 0;
        int i;
        for (i = 0; i < n; i++) {
            *dp += x[i] * y[i];
        }

        // indicate success
        return 0;
    }

    /*
     * This function fill an array of size n with random values between 10 and 99
     * It returns -1 if x is a null reference or n is negative or equal to 0 and 0
     * for a success run
     */
    int random_fill_array(int *x, int n) {
        // check if input is well-formed
        if (!x || n <= 0) {
            return -1;
        }

        srand(time(0));

        // filling the arrays a and b with random values between 10 and 99
        int i;
        for (i = 0; i < n; i++) {
            x[i] = (rand() % 90) + 10;
        }

        // indicate success
        return 0;
    }

    /*
     * Write a function that takes an array of size n, and fill the array with
     * random numbers in the range [0, 999]
     * The function returns 0 if successful and -1 if a wrong input is provided
     */
    int random_int_array(int a[], int n) {
        if (!a || n <= 0) {
            return -1;
        }

        int i;
        for (i = 0; i < n; i++) {
            // rand returns a random integer in [0, 32767]
            a[i] = rand() % 1000;
        }

        return 0;
    }

    /* 
     * Write a function that prints an integer array, ten on each line
     * The function returns 0 if successful and -1 if a wrong input is provided
     */
    int print_int_array(int a[], int n) {
        if (!a || n <= 0) {
            return -1;
        }

        int i;
        for (i = 0; i < n; i++) {
            printf("%4d", a[i]);
            if ((i + 1) % 10 == 0) {
                printf("\n");
            }
        }

        return 0;
    }

    /*
     * Write a function that capitalizes a string
     */
    int capitalize(char *s) {
        if (!s) {
            return -1;
        }

        char *p;

        // for(p = s; *p != '\0'; p++)
        for (p = s; *p; p++) {
            if (*p >= 'a' && *p <= 'z') {
                *p -= 32; // or 0x20
            }
        }

        return 0;
    }

    /*
     * Returns the length of the string.
     * Returns 0 if str is NULL and otherwise the length of str.
     */
    int strlen(char *str) {
        if (str == NULL) {
            return 0;
        }

        char *p;

        for (p = str; *p != '\0'; p++);

        return p - str;
    }

    /*
     * Write a function that takes two integer arrays and zips them.
     * Example: a[4] = {1, 2, 3, 4}
     *          b[4] = {5, 6, 7, 8}
     *          z[8] = {1, 5, 2, 6, 3, 7, 4, 8}
     */
    int zip(int *a, int *b, int *z, int n) {
        if (!a || !b || !z || n <= 0) {
            return -1;
        }

        // int *pa = a, *pb = b, *pz = z;
        int *pa, *pb, *pz;

        for (pa = z, pb = b, pz = z; pa - a < n; pa++, pb++, pz++) {
            *pz = *pa;
            pz++;
            *pz = *pb;
        }

        return 0;
    }

    /*
     * Zips together two strings into a third, alternating their
     * characters. E.g., 
     *   s1: "whatever" (length 8)
     *   s2: "I am" (length 4)
     *     when zipped together, they form
     *   z: "wIh aatmever" (length 12)
     * 
     * Returns -1 if the input is malformed and 0 otherwise
     */
    int stringzip(char *s1, char *s2, char *z) {
        if (!s1 || !s2 || !z) return -1;


        while (*s1 && *s2) {
            *z++ = *s1++;
            *z++ = *s2++;
        }
        while (*s1)
            *z++ = *s1++;
        while (*s2)
            *z++ = *s2++;
        *z = '\0';

        return 0;
    }

    /*
     * Write a function that takes two arrays and their sizes and 
     * copies one into another in reverse order
     * The function returns 0 if successful and -1 if a wrong input is provided
     */
    int copy_reversed(int *source, int *dest, int n) {
        if (!source || !dest || n <= 0) {
            return -1;
        }

        int i;

        for (i = 0; i < n; i++) {
            *(dest + n - i - 1) = *source;
            source++;
        }

        return 0;
    }

    /* 
     * Computes the sum of two n-dimensional vectors, x and y, and stores it in 
     * vector sum. Returns 0 if successful, -1 if any of x, y, or sum is NULL and 
     * -2 if n <= 0.
     */
    int vectorSum(int x[], int y[], int n, int sum[]) {
        if (!x || !y || !sum) {
            return -1;
        }
        if (n <= 0) {
            return -2;
        }

        for (int i = 0; i < n; i++) {
            sum[i] = x[i] + y[i];
        }

        // indicates success
        return 0;
    }

    /*
     * Computes the minimum and maximum elements of the array a of length n, storing
     * them in the memory cells to which min and max, respectively, point.
     * Returns 0 if successful, -1 if one or more of a, min, or max is NULL and -2
     * if n <= 0.
     */
    int minmax(int * a, int n, int * min, int * max) {
        // check if input is well-formed
        if (!a || !min || !max) {
            return -1;
        }
        if (n <= 0) {
            return -2;
        }

        // assigning m1 and m2 to the first element in the array
        int m1 = a[0], m2 = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] < m1) {
                // a[i] is even smaller than previously seen elements
                m1 = a[i];
            }
            if (a[i] > m2) {
                // a[i] is even larger than previously seen elements
                m2 = a[i];
            }
        }

        *min = m1;
        *max = m2;

        // success
        return 0;
    }

    /*
     * Writes the message of msgIn into msgOut , except with all lowercase letters.
     * Returns 0 if successful and -1 if either of msgIn or msgOut is NULL.
     */
    int whisper(char * msgIn, char * msgOut) {
        // check if input is well-formed
        if (!msgIn || !msgOut) {
            return -1;
        }

        char *p;
        p = msgIn; // pointer to msgIn

        while (*p) { // checking if *p is NULL, else continue
            if (*p >= 'A' && *p <= 'Z') {
                *msgOut = *p + ('a' - 'A'); // set to lowercase
            } else {
                *msgOut = *p;
            }
            p++;
            msgOut++;
        }

        *msgOut = '\0'; // terminate msgOut

        // indicate success
        return 0;
    }

    /*
     * Writes str1 followed by str2 into the memory pointed to by out.
     * Returns 0 if successful and -1 if any of the parameters are NULL.
     */

    int concat01(char * str1, char * str2, char * out) {
        // check for well-formed input
        if (str1 == NULL || str2 == NULL || out == NULL) return -1;

        // write str1 to out, skipping the terminator
        int i = 0;
        while (str1[i]) {
            out[i] = str1[i];
            i++;
        }

        // write str2 to out
        int j = 0;
        while (str2[j]) {
            out[i] = str2[j];
            i++;
            j++;
        }

        // terminate out
        out[i] = '\0';

        // indicate success
        return 0;
    }

    int concat02(char * str1, char * str2, char * out) {
        // check for well-formed input
        if (!str1 || !str2 || !out) return -1;

        // write str1 to out, skipping the terminator 
        while (*str1) *out++ = *str1++;

        // write str2 to out
        while (*str2) *out++ = *str2++;

        // terminate out
        * out = '\0';

        // indicate success 16 
        return 0;
    }

    /*
     * Write a function that concatenates two strings
     * s1 = "Good", s2 = " morning" ==> s = s1 + s2 = "Good morning"
     */
    int concat03(char *s1, char *s2, char *s) {
        if (!s1 || !s2 || !s) {
            return -1;
        }

        char *p, *q;
        for (p = s1, q = s; *p; *q++ = *p++);
        for (p = s2; *p; *q++ = *p++);
        *q = '\0';

        return 0;
    }

    /*
     * Reverses a string
     */
    int reverse(char *s) {
        if (!*s) {
            return -1;
        }

        char *p = s;
        for (; *p; p++); // pointing at the null
        p--; // pointing at the last char

        while (p > s) {
            char t = *p;
            *p-- = *s;
            *s++ = t;
        }

        return 0;
    }

    /*
     * Copy string in into the buffer referenced by out.
     */
    int copyString(char * in, char * out) {
        if (!in || !out) return -1;

        while (*in) *out++ = *in++;
        *out = '\0';

        return 0;
    }

    /*
     * Copies at most n-1 characters of string in into the buffer pointed to by out.
     * If n is reached, returns -2. Otherwise, returns -1 for malformed input and 0
     * upon successful completion.
     */
    int copyStringN(char * in, char * out, int n) {
        // check for well-formed input
        if (!in || !out || n <= 0) {
            return -1;
        }

        char *p = in, *q = out;
        int i;
        for (i = 0; i < (n - 1) && *p; i++) {
            *q++ = *p++;
        }
        *q = '\0';

        if (i == (n - 1)) return -2;

        // indicate success
        return 0;
    }

    /*
     * Removes all vowels from string in and writes the result to out.
     * Returns 0 if successful and -1 if either in or out is NULL.
     */
    int xvowelize(char * in, char * out) {
        // check for well-formed input
        if (!in || !out) return -1;

        char *p = in;
        while (*p) {
            if ((*p != 'a') &&
                    (*p != 'e') &&
                    (*p != 'i') &&
                    (*p != 'o') &&
                    (*p != 'u')) {
                *out++ = *p++;
            } else {
                p++;
            }
        }

        *out = '\0';

        return 0;
    }

    /*
     * Returns whether str1 and str2 are equal.
     * Returns 0 if either str1 or str2 is NULL or if they are not equal;
     * returns 1 if they are equal
     */
    int streq(char * str1, char * str2) {
        // check for well-formed input
        if (!str1 || !str2) return 0;

        char *p = str1, *q = str2;
        for (; *p; p++, q++) {
            if (*p != *q) {
                return 0;
            }
        }

        return 1;
    }

    /*
     * Returns 0 if str or suf is NULL or if suf is not a suffix of str.
     * Otherwise returns 1.
     */
    int suffix(char * str, char * suf) {
        // check for well-formed input
        if (!str || !suf) return 0;

        char *p = str, *q = suf;

        // finding the length of str and placing p at the end of str
        int n;
        for (n = 0; *p; p++, n++);

        // finding the length of suf and placing q at the end of suf
        int m;
        for (m = 0; *q; q++, m++);

        // if the supposed suffix has a length greater or equal to that of the
        // string, no possibility of it being a suffix
        if (n <= m) return 0;

        for (int i = m; i >= 0; i--, p--, q--) {
            if (*p != *q) return 0;
        }

        // indicate success
        return 1;
    }

    /*
     * Returns whether str contains an instance of substr.
     * Returns 0 if either str or substr is NULL or substr is not in str;
     * returns 1 if substr is in str.
     */
    int hasSubstring(char * str, char * substr) {
        // check for well-formed input
        if (!str || !substr) return 0;

        char *p = str, *q = substr;

        // finding the length of str and placing p at the end of str
        int n;
        for (n = 0; *p; p++, n++);

        // finding the length of substr and placing q at the end of substr
        int m;
        for (m = 0; *q; q++, m++);

        // if the supposed substring has a length greater or equal to that of the
        // string, no possibility of it being a substring.
        if (n <= m) return 0;

        char *temp = p;

        for (p = str; *p; p++) {
            q = substr;
            if ((*p == *q) && (m <= (temp - p))) {
                int count = 0;
                for (q = substr; *q; p++, q++) {
                    if (*p != *q) {
                        p -= count;
                        break;
                    } else {
                        count++;
                        if (count == m) return 1;
                    }
                }
            }
        }

        return 0;
    }

    /*
     * Compares str1 and str2 according to "dictionary" (aka, "lexicographic") 
     * order, where characters are ordered by their ASCII values.
     * Returns -1 if str1 comes before str2; 0 if either str1 or str2 is NULL or 
     * if they are equal; and 1 if str1 comes after str2.
     */
    int strcmp(char * str1, char * str2) {
        // check for well-formed input
        if (!str1 || !str2) return 0;

        char *p = str1, *q = str2;

        int lenStr1;
        char *pp = p;
        for (lenStr1 = 0; *pp; pp++, lenStr1++);

        int countEqual = 0;
        for (; *p || *q; p++, q++) {
            if (*p == *q) {
                countEqual++;
                if (countEqual == lenStr1) {
                    return 0; // they are equal
                }
            } else if (*p > *q) {
                return 1; // str1 comes after str2
            } else if (*p < *q) {
                break;
            }
        }

        // str1 comes before str2
        return -1;
    }

    /* 
     * Write a function that swaps the values of two integers
     */
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }



#ifdef __cplusplus
}
#endif

#endif /* MIDTERM_H */

