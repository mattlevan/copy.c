//Bradley Taniguchi
//02/01/16
//Project 1

#include <stdio.h> //input output?
#include <stdlib.h> //forgot what this does

int fileexists(char *filename) { //checks if file exists NOTE 0 is FALSE!
    FILE *filenameptr;
    printf("%s",filename);
    if ((filenameptr = fopen(filename, "r")) == NULL ) {
        printf("File Could not be opened");
        return 0; //return FALSE
    } else { //file COULD be opened
//        fclose(filenameprt); //user after reading/copy
        return 1; //TRUE
    }
}
void copythefiles(char *src, char *dst) {//does the heavy lifting

}
void promptuser() { //primary function to check
    int mybool; //note 0 is false
    char *filename; //character pointer to array of strings
    printf("Enter Name of file to copy\n");
    scanf("%s", filename);
    printf("Checking if %s exists\n",filename);
    mybool = fileexists(filename);
    if (mybool) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    
}
void awesomeprompt() { //totally uneccessary but awesome
}
int main() {
    printf("START MAIN\n");
    awesomeprompt();
    promptuser();
}
