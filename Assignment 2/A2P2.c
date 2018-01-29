/*
 *  Author:      Jayden Chan
 *  Date:        Sep 18, 2017
 *  Assignment:  A2 Part 2
 *  Description: Arithmetic, Leonardo, and Harmonic sequences.
 */

#include <stdio.h>
#include <stdlib.h>

/* ArithmeticSequence(start, increment, count)
   Print an arithmetic sequence with the provided properties:
    - start: first value in the sequence
    - increment: the increment value between each pair of values in the sequence
    - count: number of terms to generate
*/

/* Leonardo(input)
 * Helper function for the Leonardo sequence function
 */
int Leonardo(int input) {
    if(input == 0 || input == 1) {
        return 1;
    }
    else {
        return Leonardo(input - 1) + Leonardo(input - 2) + 1;
    }
}/*Leonardo*/


void ArithmeticSequence(int start, int increment, int count){
    printf("Arithmetic sequence: ");

    int term = start;
    
    for(int i = 0; i < count; i++) {
        printf("%d ", term);
        term += increment;
    }
    printf("\n");
}/*ArithmeticSequence*/

/* LeonardoSequence(k, count)
   Print count terms of the Leonardo sequence starting with the kth term
*/void LeonardoSequence(int k, int count){
    printf("LeonardoSequence: ");

    int num = (k-1);
    for(int i = 0; i < count; i++) {
        printf("%d ", Leonardo(num));
        num++;
    }

    printf("\n");
}/*LeonardoSequence*/

/* HarmonicSequence(k, count)
   Print count terms of the harmonic sequence starting with the kth term
*/
void HarmonicSequence(int k, int count){
    printf("HarmonicSequence: ");
    double term = k;

    for(int i = 0; i < count; i++) {
        printf("%.3f ", (1/term));
        term++;
    }

    printf("\n");
}/*HarmonicSequence*/

/* Do not change any code below this line */
int main(void){
    ArithmeticSequence(17, 6, 5);
    ArithmeticSequence(34, 6, 8);
    LeonardoSequence(2, 7);
    LeonardoSequence(5, 7);
    HarmonicSequence(1, 6);
    HarmonicSequence(3, 6);
    return EXIT_SUCCESS;
}/*main*/
