/* 
 * copy.c
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
#include <stdbool.h> // include booleans, must compile with C99

bool file_exists(char *file_name) {  // checks if file exists
    FILE *file_name_ptr = fopen(file_name, "r");

    if (!file_name_ptr) {
        perror("File could not be opened for reading.");
        return false;
    }

    return true;
}

void copy(char *src, char *dst) {  // does the heavy lifting after checking
    printf("Copying %s to %s\n", src, dst);
    //WORK
}

void prompt_user() {  // primary function to be ran, asks user for inputs
    bool file_exists, loop_flag; // file_exists var name is ok (scope)
    char *in_ptr, *out_ptr;  // char pointer to array of chars 
    char in_str[32], out_str[32]; // 32 char width is fine 
    // in_ptr = in_str;  // needs to use fgets() 
    // out_ptr = out_str; // needs to use fgets()
    loop_flag = true;  // to loop if input is bad
    while (loop_flag) {
        printf("Enter Name of file to copy\n");
        scanf("%s", in_ptr);
        printf("Checking if %s exists...\n", in_ptr);
        file_exists = fileexists(in_ptr);
        if (file_exists) {
            printf("%s File Exists!\n",in_ptr);
            loop_flag=0;  // end loop
        } else {
            printf("%s File Doesn't Exist!\n\n", in_ptr);
        }  // end else
    }  // end while
    loop_flag=1; // reuse loop_flag to ask for output file_name
    while (loop_flag) {
        printf("Enter Name of outputfile \n");
        scanf("%s", out_ptr);
        printf("Checking if %s doesn't exist...\n",out_ptr);
        file_exists = fileexists(out_ptr);//reuse file_exists
        if (file_exists) { //if 1 true, so DO NOT overwrite
            printf("%s File Exists!\n\n", out_ptr);
        } else { //so there is not file, print to it
           printf("%s File Doesn't Exist!\n",out_ptr);
           copy(in_ptr, out_ptr);
           loop_flag=0; //break loop
        }  // end else
    }  // end while
    
}
void awesome_prompt() {  // totally uneccessary but awesome, prints ASCII prompt
    printf("Some Awesome Prompt\n");  // will add later
}
int main() {
    awesome_prompt();
    prompt_user();
    printf("End Program...\n");
    return 0; 
}
