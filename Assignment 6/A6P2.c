/*
* Name: Jayden Chan
* Date: November 21, 2017
* Assignment: A6P2
* Description: Capitalizes the first character of each word and removes unneeded spaces.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <stdbool.h>

void read_and_capitalize(){
    int ch;
    bool lastWasSpace = true;
    //Get the first character from the user
    ch = getchar();
    //Read chars until newline (\n) is encountered
    while(ch != '\n'){
        if (isspace(ch) && !lastWasSpace) {
            printf(" ");
            lastWasSpace = true;
        } else if(!isspace(ch) && lastWasSpace) {
            ch = toupper(ch);
            printf("%c", ch);
            lastWasSpace = false;
        } else if (!isspace(ch)) {
            printf("%c", ch);
            lastWasSpace = false;
        }
        //Get the next character from the user
        ch = getchar();
    }/*while*/
    printf("\n");
}/*read_and_capitalize*/

int main(void){
    printf("Enter a line of text: ");
    fflush(stdout);
    read_and_capitalize();
    return EXIT_SUCCESS;
}/*main*/
