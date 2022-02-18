/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab01_ex05.c
 * Author: riwakaram
 *
 * Created on September 12, 2021, 11:30 PM
 */

#include <stdio.h>
#include <wchar.h> // multibyte & wide character support
#include <locale.h> // defines the location specific settings

/*
 * 
 */
int main(int argc, char** argv) {

    wchar_t ch = 0x0600;

    printf("%6c", ' '); // to make space for the row number - for indentation

    for (int colNum = 96; colNum < 112; colNum++) {
        printf("%03x%3c", colNum, ' ');
        //printing the column number in the first row
    }

    for (int i = 0; i < 16; i++) {
        printf("\n%-6x", i);
        // printing the row number before printing the characters of that row

        for (int j = 0; j < 16; j++) {
            if (setlocale(LC_ALL, "") == NULL) {
                fprintf(stderr, "Failed to set locale\n");
                return 1;
            }

            switch (i) {
                case 0:
                    switch (j) {
                        case 2:
                            wprintf(L"%-5lc", ch);
                            break;
                        default:
                            wprintf(L"%-6lc", ch);
                    }
                    break;
                case 4:
                    switch (j) {
                        case 0:
                            wprintf(L"%-2lc", ch);
                            break;
                        default:
                            wprintf(L"%-6lc", ch);
                    }
                    break;
                case 5:
                    switch (j) {
                        case 0:
                            wprintf(L"%-5lc", ch);
                            break;
                        default:
                            wprintf(L"%-6lc", ch);
                    }
                    break;
                case 8:
                    switch (j) {
                        case 0:
                            wprintf(L"%-5lc", ch);
                            break;
                        default:
                            wprintf(L"%-6lc", ch);
                    }
                    break;
                case 11:
                    switch (j) {
                        case 3:
                            wprintf(L"%-5lc", ch);
                            break;
                        default:
                            wprintf(L"%-6lc", ch);
                    }
                    break;
                case 12:
                    switch (j) {
                        case 1:
                            printf("%-6s", "ALM");
                            break;
                        case 3:
                            wprintf(L"%-5lc", ch);
                            break;
                        default:
                            wprintf(L"%-6lc", ch);
                    }
                    break;
                default:
                    wprintf(L"%-6lc", ch);
            }

            ch += 16;
            // the difference between each character and its right-hand neighbor
            // is 16, and given that the code is printing line per line and not
            // column per column, this addition must be done to get the correct
            // characters in their correct places
        }

        ch -= 255;
        // when each line is printed and the code moves on to another line
        // the character that will be printed first is the character right after
        // the one printed just above (position: row - 1, same column, from the
        // one printing now)
        // the difference between the last character of the previous row and the
        // first character of the next row is 255 (2^8 - 1)
        // this subtraction must be done to get the correct characters in their
        // correct places
    }

    return 0;
}

