#include <stdio.h>
#include "llml.h"

int main() 
{
    /* circle testing */
    double circle_area = area_circle(3.55);
    double circumference = circumference_circle(5.4);
    printf("circle area: %f\ncircle circumference: %f\n", circle_area, circumference);

    /* square testing */
    double square_area = area_square(9.1);
    double sqaure_perimeter = perimeter_square(9.1);
    printf("square area: %f\nsquare perimeter: %f\n", square_area, sqaure_perimeter);
    return 0;
}