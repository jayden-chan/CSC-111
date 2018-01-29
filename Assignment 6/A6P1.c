/*
* Name: Jayden Chan
* Date: November 21, 2017
* Assignment: A6P1
* Description: Scrambles the middle letters of words.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <string.h> 
#include <time.h> 

#define BIGLINE (500)
#define BIGWORD (100)
#define INPUT_FILENAME    ("A6P1TestingSherlock.txt")
#define OUTPUT_FILENAME   ("A6P1SherlockEncoded.txt")

void processFile(FILE*, FILE*);
FILE* openFile(char*);
FILE* createFile(char*);
int randInt(int lower, int upper);
void swap(char a[], int index1, int index2);

int main(void) {
    printf("Starting text encoding...\n\n");
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
    FILE* ifp = openFile(INPUT_FILENAME);
    FILE* ofp = createFile(OUTPUT_FILENAME);

    processFile(ifp, ofp);

    fclose(ofp);
    fclose(ifp);
    printf("\nEncoding finished\n");
    return EXIT_SUCCESS;
} /*main*/

void processFile(FILE* ifp, FILE* ofp) {
    char line[BIGLINE];
    char word[BIGWORD];
    char *ptr;
    int counter = 0;
    printf("Begin file processing\n");
    while (fgets(line, BIGLINE, ifp) != NULL){
        ptr = line;
        while(sscanf(ptr, "%s", word) != -1) {
            if(strlen(word) >= 4){
                for(int i = 0; i < 9; i++) {
                    swap(word, randInt(1, (int)strlen(word)-2), randInt(1, (int)strlen(word)-2));
                }
            }
            printf("%s ", word);
            fprintf(ofp, "%s ", word);
            counter++;
            if(counter == 50) {
                printf("\n");
                fprintf(ofp, "\n");
                counter = 0;
            }
            ptr += strlen(word) + 1;
        }
    }/*while*/
    printf("\n");
    printf("End file processing\n");
} /* processFile */

int randInt(int lower, int upper) {
    return (rand() % (upper - lower + 1) + lower);
}

void swap(char a[], int index1, int index2) {
    char temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}

FILE* openFile(char* fnam) {
    FILE* ifp = fopen(fnam, "r");
    if (ifp == NULL) {
        printf("Cannot open input file %s\n", fnam);
        exit(EXIT_FAILURE);
    } /* if */
    return ifp;
}/*openFile*/

FILE* createFile(char* fnam) {
    FILE* ifp = fopen(fnam, "w");
    if (ifp == NULL) {
        printf("Cannot create output file %s\n", fnam);
        exit(EXIT_FAILURE);
    } /* if */
    return ifp;
}/*createFile*/
