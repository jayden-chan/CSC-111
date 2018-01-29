/*  Name: Jayden Chan
    Date: 2017/10/05
    Assignment: A3
    Description: Prints calculated values to console
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RadiusRange1 (7.3)
#define RadiusInc (0.7)
#define RadiusRange2 (13.2)
#define CylinderHeight1 (8.2)
#define CylinderHeightInc (1.5)

double areaOfCircle(double radius);
double perimeterOfCircle(double radius);
double volumeOfSphere(double radius);
double areaOfSphere(double radius);
double volumeOfCylinder(double radius, double height);
double areaOfCylinder(double radius, double height);
double volumeOfCone(double radius, double height);
double areaOfCone(double radius, double height);

int main() {

    printf("0%7d 0%7d 0%7d 0%7d 0%7d\n", 1234567, 1234567, 1234567, 1234567, 1234567);
    printf("%8s %8s %8s %8s %9s", "Radius", "CircArea", "CircPeri", "CylHei", "CylVol\n");

    double currentRadius = RadiusRange1;
    double currentCylinderHeight = CylinderHeight1;

    while(currentRadius < RadiusRange2) {

        printf("%8.1f %8.2f %8.2f %8.1f %8.2f\n", currentRadius, areaOfCircle(currentRadius), perimeterOfCircle(currentRadius),
               currentCylinderHeight, volumeOfCylinder(currentRadius, currentCylinderHeight));

        currentRadius += RadiusInc;
        currentCylinderHeight += CylinderHeightInc;
    }

    return EXIT_SUCCESS;
}

double areaOfCircle(double radius) {
    return M_PI * radius * radius;
}

double perimeterOfCircle(double radius) {
    return M_PI * (2 * radius);
}

double volumeOfSphere(double radius) {
    return (4/3) * M_PI * pow(radius, 3);
}

double areaOfSphere(double radius) {
    return M_PI * radius * radius * 4;
}

double volumeOfCylinder(double radius, double height) {
    return areaOfCircle(radius) * height;
}

double areaOfCylinder(double radius, double height) {
    return (2 * areaOfCircle(radius)) + (perimeterOfCircle(radius) * height);
}

double volumeOfCone(double radius, double height) {
    return areaOfCircle(radius) * (height / 3);
}

double areaOfCone(double radius, double height) {
    return areaOfCircle(radius) + (M_PI * radius * sqrt(radius * radius + height * height));
}
