/* 
 * File:   lab05_ex03.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 8:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv) {

    unsigned int unsigned_i = -1; // (1111.....1111) = 2^32 - 1 = 4294967295
    printf("unsigned_i = %u\n", unsigned_i);
    // = UINT_MAX (largest unsigned 32 bit integer)

    int signed_i = unsigned_i; // this becomes -1
    printf("signed_i = %d\n", signed_i);

    int signed_i2 = unsigned_i + 2; // 4294967295 + 2 = (2^32 - 1) + 2
    // (2 ^ 32 + 1) % 32 = 1
    printf("signed_i2 = %d\n", signed_i2);

    unsigned int unsigned_i2 = unsigned_i + 2; // same as singed_i2
    printf("unsigned_i2 = %u\n", unsigned_i2);

    int signed_i_max = INT_MAX;
    int signed_i_min = INT_MIN;
    int signed_i_overflow = INT_MAX + 1; // INT_MAX + 1 = INT_MIN
    printf("signed_i_overflow = %d\n", signed_i_overflow);

    return (EXIT_SUCCESS);
}

