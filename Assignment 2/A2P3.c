/*
 *  Author:      Jayden Chan
 *  Date:        Sep 18, 2017
 *  Assignment:  A2 Part 3
 *  Description: Approximates the value of sqrt(117)
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    double x = 1.0;
    double y = 0;
    const int count = 10;

    printf("Computing square roots using Newton's Method \n");

    for(int i = 0; i < count; i++) {
        printf("Iteration %d: %.10f\n", (i+1), x);
        y = x - ((x*x - 117) / (2*x));
        x = y;
    }

    printf("The square root of 117.0 with 10 iterations is %.10f\n", x);
    printf("The square of %.10f is %.20f", x, x*x);

    return EXIT_SUCCESS;
}
