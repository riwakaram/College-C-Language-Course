/* 
 * File:   classWork211021.c
 * Author: riwakaram
 *
 * Created on October 21, 2021, 2:00 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Files
 * Streams: A stream is a channel of communication between a process and 
 * a device
 * What is a process: It is a program (application) in run mode
 * A device: - input device (keyboard, mouse, scanner, camera, microphone)
 *           - output device (screen, printer)
 *           - I/O device (file)
 * 
 * standard devices:
 *  - standard input (stdin) --> keyboard (fd = 0)
 *  - standard output (stdout) --> screen (console) (fd = 1)
 *  - standard error (stderr) --> screen (fd = 2)
 * 
 * file descriptor (handle) pointers with unique values
 * 
 */
int main(int argc, char** argv) {

    /*
        fprintf(stderr, "Hello World\n");

        int x;

        while (fscanf(stdin, "%d", &x) != EOF) { // EOF == End of file
            fprintf(stdout, "%d\n", x);
        }
     */

    /*
        FILE *fd = fopen("my_first_file.txt", "w");
        // This creates a new stream with file descriptor fd

        int i;
        for (i = 0; i < 100; i++) {
            fprintf(fd, "%5d", i);
            if ((i + 1) % 10 == 0)
                fprintf(fd, "\n");
        }

        fclose(fd);
     */

    /*
        FILE *fd = fopen("my_2nd_file.txt", "r");
        FILE *fd_out = fopen("my_2nd_file_cap.txt", "w");
        char c;
        while (fscanf(fd, "%c", &c) != EOF) {
            if (c >= 'a' && c <= 'z') c -= 32;
            fprintf(fd_out, "%c", c);
        }
     */

    /*
     * Write code to count the number of characters in a text file
     * 
     */

    char file_name[] = "my_2nd_file.txt";
    FILE *fd = fopen(file_name, "r");

    if (fd == NULL) {
        printf("ERROR reading file %s", file_name);
        return (EXIT_FAILURE);
    }

    char c;
    int count = 0;

    while (fscanf(fd, "%c", &c) != EOF) {
        count++;
    }

    printf("The file size is %d\n", count);

    fclose(fd);

    return (EXIT_SUCCESS);
}
