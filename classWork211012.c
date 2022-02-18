/* 
 * File:   classWork211012.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 2:02 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Logical Operations
 * &&, ||, ! => Boolean value (true or false)
 * 
 * Bitwise Operations (operate on bits)
 * & AND
 * | OR
 * ^ XOR
 * ~ NOT
 * >> shift right
 * << shift left
 */
int main(int argc, char** argv) {

    /*
        unsigned char x = 55;
        unsigned char y = 25;
        unsigned char z = x & y;
        
        // What is x & y
        //         x: 0011 0111
        //         y: 0001 1001
        // z = x & y: 0001 0001 => 17
     

        printf("z = x & y = %u", z);
        z = x | y;
        printf("\nz = x | y = %u", z);
        printf("\n~x = %hhu", ~x);

        z = x^y;
        printf("\nz = x ^ y = %u", z);

        // << shift left 
        z = x << 2;
        printf("\nz = x << 2 = %u", z);
        z = x << 3;
        printf("\nz = x << 3 = %u", z);

        // >> shift right (logical if unsigned)
        z = x >> 3;
        printf("\nz = x >> 3 = %u", z);

        // >> shift right (arithmetic if signed)
        char a = -21; // 0001 0111 => 11101001 >> 3 => 11111101 = -3
        char b = a >> 3;
        printf("\nb = a >> 3 = %d", b);
     */

    /* enumeration
    enum day_of_week {
        Sunday, Monday, Tuesday = 5, Wednesday, Thursday, Friday, Saturday
    };

    // enum day_of_week my_day;

    printf("%d", Wednesday);
     */

    /*
        enum {
            FIRST = 0X01, // 0001
            SECND = 0X02, // 0010
            THIRD = 0X04, // 0100
            FORTH = 0X08, // 1000
              ALL = 0X0F  // 1111
        };
     */

    enum {
        FIRST = 1 << 0, // 0001
        SECND = 1 << 1, // 0010
        THIRD = 1 << 2, // 0100
        FORTH = 1 << 3, // 1000
        ALL = ~(~0 << 4) // 1111 (0000 0000 -> 1111 1111 -> 1111 0000 -> 0000 1111)
    };

    unsigned int flags = 0;
    flags |= SECND | THIRD; // set 2nd and 3rd bits (bits #1 and #2)

    /*
     * flags: 0000 0000 0000 0000 0000 0000 0000 0000
     * SECND: 0000 0000 0000 0000 0000 0000 0000 0010
     * THIRD: 0000 0000 0000 0000 0000 0000 0000 0100
     * flags: 0000 0000 0000 0000 0000 0000 0000 0110
     */

    printf("\n%x", flags); // 0000 -> 0010 -> 0110 == 6
    flags &= ~(FIRST | THIRD); // reset bits 1st and 3rd
    printf("\n%x", flags); // 0010 == 2
    flags ^= FIRST | SECND | THIRD; // toggle 1st, 2nd and 3rd bits
    printf("\n%x", flags); // 0010 => 0101 == 5
    flags &= ~ALL; // reset all bits
    printf("\n%x", flags); // 0101 => ~ALL = 0000 -> 0101 & 0000 = 0000

    return (EXIT_SUCCESS);
}

