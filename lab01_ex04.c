/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab01_ex04.c
 * Author: riwakaram
 *
 * Created on September 12, 2021, 11:29 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char ch = 0x0000;

    printf("%4c", ' '); // to make space for the row number - for indentation

    for (int colNum = 0; colNum < 8; colNum++) {
        printf("%03d%c", colNum, ' ');
        //printing the column number in the first row
    }

    for (int i = 0; i < 16; i++) {
        printf("\n%-4x", i);
        // printing the row number before printing the characters of that row

        for (int j = 0; j < 8; j++) {
            switch (i) {
                case 0:
                    switch (j) {
                        case 0:
                            printf("%-4s", "NUL");
                            break;
                        case 1:
                            printf("%-4s", "DLE");
                            break;
                        case 2:
                            printf("%-4s", "SP");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 1:
                    switch (j) {
                        case 0:
                            printf("%-4s", "SOH");
                            break;
                        case 1:
                            printf("%-4s", "DC1");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 2:
                    switch (j) {
                        case 0:
                            printf("%-4s", "STX");
                            break;
                        case 1:
                            printf("%-4s", "DC2");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 3:
                    switch (j) {
                        case 0:
                            printf("%-4s", "ETX");
                            break;
                        case 1:
                            printf("%-4s", "DC3");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 4:
                    switch (j) {
                        case 0:
                            printf("%-4s", "EOT");
                            break;
                        case 1:
                            printf("%-4s", "DC4");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 5:
                    switch (j) {
                        case 0:
                            printf("%-4s", "ENQ");
                            break;
                        case 1:
                            printf("%-4s", "NAK");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 6:
                    switch (j) {
                        case 0:
                            printf("%-4s", "ACK");
                            break;
                        case 1:
                            printf("%-4s", "SYN");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 7:
                    switch (j) {
                        case 0:
                            printf("%-4s", "BEL");
                            break;
                        case 1:
                            printf("%-4s", "ETB");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 8:
                    switch (j) {
                        case 0:
                            printf("%-4s", "BS");
                            break;
                        case 1:
                            printf("%-4s", "CAN");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 9:
                    switch (j) {
                        case 0:
                            printf("%-4s", "HT");
                            break;
                        case 1:
                            printf("%-4s", "EM");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 10:
                    switch (j) {
                        case 0:
                            printf("%-4s", "LF");
                            break;
                        case 1:
                            printf("%-4s", "SUB");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 11:
                    switch (j) {
                        case 0:
                            printf("%-4s", "VT");
                            break;
                        case 1:
                            printf("%-4s", "ESC");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 12:
                    switch (j) {
                        case 0:
                            printf("%-4s", "FF");
                            break;
                        case 1:
                            printf("%-4s", "FS");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 13:
                    switch (j) {
                        case 0:
                            printf("%-4s", "CR");
                            break;
                        case 1:
                            printf("%-4s", "GS");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 14:
                    switch (j) {
                        case 0:
                            printf("%-4s", "SO");
                            break;
                        case 1:
                            printf("%-4s", "RS");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                case 15:
                    switch (j) {
                        case 0:
                            printf("%-4s", "SI");
                            break;
                        case 1:
                            printf("%-4s", "US");
                            break;
                        case 7:
                            printf("%-4s", "DEL");
                            break;
                        default:
                            printf("%-4c", ch);
                    }
                    break;
                default:
                    printf("Error!");
            }
            ch += 16;
            // the difference between each character and its right-hand neighbor
            // is 16, and given that the code is printing line per line and not
            // column per column, this addition must be done to get the correct
            // characters in their correct places
        }

        ch -= 127;
        // when each line is printed and the code moves on to another line
        // the character that will be printed first is the character right after
        // the one printed just above (position row - 1 same column from the one
        // printing now)
        // the difference between the last character of the previous row and the
        // first character of the next row is 127 (2^7 - 1)
        // this subtraction must be done to get the correct characters in their
        // correct places
    }

    return (EXIT_SUCCESS);
}

