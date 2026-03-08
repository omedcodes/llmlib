#include <stdio.h>
#include "llml.h"

int main() 
{
    /* circle testing */
    float circle_area = area_circle(3.55f);
    float circumference = circumference_circle(3.55f);
    printf("circle area: %f\ncircle circumference: %f\n", circle_area, circumference);

    /* square testing */
    float square_area = area_square(9.1f);
    float sqaure_perimeter = perimeter_square(9.1f);
    printf("square area: %f\nsquare perimeter: %f\n", square_area, sqaure_perimeter);

    /* rectangle testing */
    float rectangle_area = area_rectangle(3.4f, 5.2f);
    float rectangle_perimeter = perimeter_rectangle(3.4f, 5.2f);
    printf("rectangle area: %f\nrectangle perimeter: %f\n", rectangle_area, rectangle_perimeter);
    return 0;
}