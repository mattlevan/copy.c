/* 
 * copy_file.c
 *
 * A simple C program for copying text files and observing system calls.
 *
 * Bradley Taniguchi
 * Matt Levan
 * 02/01/16 -- Spring 2016
 * Project 1
 * CSC-341 Operating Systems
 * Dr. Bin Tang 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

bool file_exists(char *file_name) {
    FILE *file_ptr = fopen(file_name, "r");

    if (!file_ptr) {
        return false;
    }
    return true;
}

void copy(char *out_str, char *in_str) {
    // int c to store one char at a time
    int c;
    
    // declare and open files for copy
    FILE *in_ptr = fopen(in_str, "r");
    FILE *out_ptr = fopen(out_str, "w");

    if (!in_ptr) {
        perror("Source file can't be opened: ");
        exit(1);
    }

    if (!out_ptr) {
        perror("Destination file can't be opened: ");
        exit(1);
    }
    
    // copy file one char at a time 
    while ((c = fgetc(in_ptr)) != EOF) {
        fputc(c, out_ptr);
    }

    // success
    printf("\nSuccess!\n");

    // close files
    fclose(in_ptr);
    fclose(out_ptr);
}

void prompt_user() {  // primary function to be ran, asks user for inputs
    char str[32], in_str[32], out_str[32]; // 32 char width is fine 
    char *str_ptr = str;
    char *in_ptr = in_str;
    char *out_ptr = out_str;

    // get name of source file 
    while (strcmp(in_str, "")) { // while in_str is empty
        printf("Enter name of source file: ");
        scanf("%s", str_ptr); // get input from keyboard (stdin)
        
        if (file_exists(str_ptr)) {
            strcpy(in_str, str);
            break;
        }
        else {
            printf("File can't be opened!\n");
            continue;
        }
    }

    // get name of destination file 
    while (strcmp(out_str, "")) { // while out_str is empty
        printf("Enter name of destination file: ");
        scanf("%s", str_ptr); // get input from keyboard (stdin)
        
        if (!file_exists(str_ptr)) {
            strcpy(out_str, str);
            break;
        }
        else {
            printf("File already exists!\nY to overwrite, or N don't\n");
            //only overwrites if Y, doesn't for everything else
            scanf("%s", str_ptr);
            if(!(strcmp(str_ptr, "Y"))) { //
                strcpy(out_str, str);
                printf("Overwriting!\n");
                break;
            } 
            else {
                printf("Not Overwriting\n");
                continue;
            }
        }
    }
    copy(out_str, in_str);
}

int main() {

    prompt_user();
    
    return EXIT_SUCCESS; 
}
