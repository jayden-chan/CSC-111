/*  Name: Jayden Chan
    Date: 2017/10/05
    Assignment: A3
    Description: Randomly calculates missing values of right cone based on user input.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double volume(double, double);
double radius(double, double);
double height(double, double);

int completedCalculations = 1;
int randNum = 1;
double r, h, v;

int main() {

    printf("Welcome to my cone calculator\n");

    while(completedCalculations <= 5 || randNum != 0) {

        randNum = rand() % 4;
        switch(randNum) {
            case 1:
                printf("Enter r, h: ");
                fflush(stdout);
                scanf("%lf%lf", &r, &h);
                printf("%d ConeCalc: r = %.2f h = %.2f v = %.2f\n", completedCalculations, r, h, volume(r, h));
                completedCalculations++;
                break;
            case 2:
                printf("Enter r, v: ");
                fflush(stdout);
                scanf("%lf%lf", &r, &v);
                printf("%d ConeCalc: r = %.2f h = %.2f v = %.2f\n", completedCalculations, r, height(r, v), v);
                completedCalculations++;
                break;
            case 3:
                printf("Enter h, v: ");
                fflush(stdout);
                scanf("%lf%lf", &h, &v);
                printf("%d ConeCalc: r = %.2f h = %.2f v = %.2f\n", completedCalculations, radius(h, v), h, v);
                completedCalculations++;
                break;
            default:
                break;
        }
    }
    printf("Bye\n");

    return EXIT_SUCCESS;
}

double volume(double radius, double height) {
    return M_PI * radius * radius * (height / 3);
}

double radius(double height, double volume) {
    return sqrt((3 * volume) / (M_PI * height));
}

double height(double radius, double volume) {
    return 3 * (volume / (M_PI * radius * radius));
}
