#include<stdio.h>

double calcArea(double radius);

int main(void)
{
    double radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    area = calcArea(radius);
    printf("The area = %.3lf", area);

    return 0;
}

double calcArea(double radius)
{
    const double pi = 3.14159;
    return pi * radius * radius;
}
