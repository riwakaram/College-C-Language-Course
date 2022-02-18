/* 
 * File:   final.c
 * Author: riwakaram
 *
 * Created on December 21, 2021, 2:55 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int capitalize(char *s) {
    if (!s) {
        return -1;
    }

    char *p;
    for (p = s; *p; p++) {
        if (*p >= 'a' && *p <= 'z') {
            *p -= 32;
        }
    }

    return 0;
}

#define PART2

int main(int argc, char** argv) {

#ifdef PART1

    if (argc != 3) {
        printf("ERROR: you should provide two argument. Exiting...\n");
        return (EXIT_FAILURE);
    }

    char file_name[100];
    if (sscanf(argv[1], "%s", file_name) == 0) {
        printf("ERROR: you should enter a string (file name). Exiting...\n");
        return (EXIT_FAILURE);
    }

    char word[100];
    if (sscanf(argv[2], "%s", word) == 0) {
        printf("ERROR: you should enter a string (file name). Exiting...\n");
        return (EXIT_FAILURE);
    }

    FILE *fd = fopen(file_name, "r");
    if (!fd) {
        printf("ERROR: Could not open file %s. Exiting...\n", file_name);
        return (EXIT_FAILURE);
    }

    int count = 0;
    char s[128];
    while (fscanf(fd, "%s", s) != EOF) {
        if (strcmp(s, word) == 0) {
            count++;
        }
    }

    printf("In the file %s, there are %d occurrences of the word \"%s\"\n",
            file_name, count, word);

#endif

#ifdef PART2
    
    if(argc == 1){
        printf("Usage: ./search <file name> word\n");
        return(EXIT_FAILURE);
    }

    if (argc != 3) {
        printf("ERROR: you should provide two argument. Exiting...\n");
        return (EXIT_FAILURE);
    }

    char file_name[100];
    if (sscanf(argv[1], "%s", file_name) == 0) {
        printf("ERROR: you should enter a string (file name). Exiting...\n");
        return (EXIT_FAILURE);
    }

    char word[100];
    if (sscanf(argv[2], "%s", word) == 0) {
        printf("ERROR: you should enter a string (file name). Exiting...\n");
        return (EXIT_FAILURE);
    }

    FILE *fd = fopen(file_name, "r");
    if (!fd) {
        printf("ERROR: Could not open file %s. Exiting...\n", file_name);
        return (EXIT_FAILURE);
    }

    char w[100];
    strcpy(w, word);
    capitalize(w);

    int count = 0;
    char s[128];
    while (fscanf(fd, "%s", s) != EOF) {
        capitalize(s);
        if (strcmp(s, w) == 0) {
            count++;
        }
    }

    printf("In the file %s, there are %d occurrences of the word \"%s\"\n",
            file_name, count, word);

#endif
    return (EXIT_SUCCESS);
}
