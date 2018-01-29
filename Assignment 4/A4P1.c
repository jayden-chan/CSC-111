/*
 * Name: Jayden Chan
 * Date: 2017/10/17
 * Assignment: A4 Part 1
 * Description: Converts a decimal value into Roman Numerals.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double number = 0;

void convert(double);

int main() {

    for(;;) {
        printf("Enter a number between 1 and 4999: ");
        fflush(stdout);

        int result = fscanf(stdin, "%lf", &number);

        if(result == 0 || (floor(number) != ceil(number))) {
            break;
        }
        if(number > 0 && number < 5000) {
            convert(number);
        }
        else break;
    }

    printf("Invalid value entered. Program will exit.");

    return EXIT_SUCCESS;
}

void convert(double num) {

    printf("The value of %.f in Roman numerals is ", num);

    double c, b, a;

    for(int i = 0; i < (floor(num / 1000)); i++) {
        printf("M");
    }

    c = floor((num - (floor(num/1000) * 1000)) / 100);
    b = floor(((num - (floor(num/1000) * 1000)) - (c * 100)) / 10);
    a = floor(((num - (floor(num/1000) * 1000)) - (c * 100) - (b * 10)));

    if(c == 4) {
        printf("CD");
    }
    else if (c == 9) {
        printf("CM");
    }
    else if(c > 4){
        printf("D");
        for(int i = 0; i < c-5; i++) {
            printf("C");
        }
    }
    else if (c <=4) {
        for(int i = 0; i < c; i++) {
            printf("C");
        }
    }

    if(b == 4) {
        printf("XL");
    }
    else if (b == 9) {
        printf("XC");
    }
    else if(b > 4){
        printf("L");
        for(int i = 0; i < b-5; i++) {
            printf("X");
        }
    }
    else if (b <=4) {
        for(int i = 0; i < b; i++) {
            printf("X");
        }
    }

    if(a == 4) {
        printf("IV");
    }
    else if (a == 9) {
        printf("IX");
    }
    else if(a > 4){
        printf("V");
        for(int i = 0; i < a-5; i++) {
            printf("I");
        }
    }
    else if (a <=4) {
        for(int i = 0; i < a; i++) {
            printf("I");
        }
    }

    printf("\n");

}
