//Bradley Taniguchi
//Matt Levan
//02/01/16
//Project 1

#include <stdio.h>  // input output?
#include <stdlib.h>  // forgot what this does

int fileexists(char *filename) {  // checks if file exists NOTE 0 is FALSE!
    FILE *filenameptr;
    if ((filenameptr = fopen(filename, "r")) == NULL ) {
//        printf("File Could not be opened"); //redundant print
        return 0; //return FALSE
    } else { //file COULD be opened
        return 1;  // TRUE
    }
}
void copythefiles(char *src, char *dst) {  // does the heavy lifting after checking
    printf("Copying %s to %s\n", src, dst);
    //WORK
}
void promptuser() {  // primary function to be ran, asks user for inputs
    int fileexistsbool, loopflag;  // note 0 is false
    char *inputfileptr, *outputptr;  // character pointer to array of strings
    char inputfilestring[32], outputstring[32]; // No 100% sure about this
    inputfileptr = inputfilestring;  // and this
    outputptr = outputstring;
    loopflag = 1;  // to loop if input is bad
    while(loopflag) {
        printf("Enter Name of file to copy\n");
        scanf("%s", inputfileptr);
        printf("Checking if %s exists...\n", inputfileptr);
        fileexistsbool = fileexists(inputfileptr);
        if (fileexistsbool) {
            printf("%s File Exists!\n",inputfileptr);
            loopflag=0;  // end loop
        } else {
            printf("%s File Doesn't Exist!\n\n", inputfileptr);
        }  // end else
    }  // end while
    loopflag=1; // reuse loopflag to ask for output filename
    while(loopflag) {
        printf("Enter Name of outputfile \n");
        scanf("%s", outputptr);
        printf("Checking if %s doesn't exist...\n",outputptr);
        fileexistsbool = fileexists(outputptr);//reuse fileexistsbool
        if (fileexistsbool) { //if 1 true, so DO NOT overwrite
            printf("%s File Exists!\n\n", outputptr);
        } else { //so there is not file, print to it
           printf("%s File Doesn't Exist!\n",outputptr);
           copythefiles(inputfileptr, outputptr);
           loopflag=0; //break loop
        }  // end else
    }  // end while
    
}
void awesomeprompt() {  // totally uneccessary but awesome, prints ASCII prompt
    printf("Some Awesome Prompt\n");  // will add later
}
int main() {
    awesomeprompt();
    promptuser();
    printf("End Program...\n");
    return 0; 
}
