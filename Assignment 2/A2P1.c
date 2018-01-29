/*
 *  Author:      Jayden Chan
 *  Date:        Sep 14, 2017
 *  Assignment:  A2 Part 1
 *  Description: Converts celsius to fahrenheit.
 */

#include <stdio.h>
#include <stdlib.h>

const double maxCelsius = 60.0;
double celsius = -40;

double CtoF(double input);

int main() {

    while(celsius <= maxCelsius) {
        printf("%.1f degs C = %.1f degs F\n", celsius, CtoF(celsius));
        celsius += 5;
    }

    return EXIT_SUCCESS;
}

double CtoF(double input) {
    return ((input * 1.8) + 32.0);
}
