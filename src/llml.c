#include <stdio.h>
#include "llml.h"

int main() 
{
    /* circle testing 
    float circle_area = area_circle(3.55f);
    float circumference = circumference_circle(3.55f);
    printf("circle area: %f\ncircle circumference: %f\n", circle_area, circumference);

    square testing 
    float square_area = area_square(9.1f);
    float sqaure_perimeter = perimeter_square(9.1f);
    printf("square area: %f\nsquare perimeter: %f\n", square_area, sqaure_perimeter);

    rectangle testing 
    float rectangle_area = area_rectangle(3.4f, 5.2f);
    float rectangle_perimeter = perimeter_rectangle(3.4f, 5.2f);
    printf("rectangle area: %f\nrectangle perimeter: %f\n", rectangle_area, rectangle_perimeter);

    triangle testing
    float triangle_area = area_triangle(4.5f, 5.5f);
    float triangle_perimeter = perimeter_triangle(2.2f, 3.3f, 4.4f);
    printf("triangle area: %f\ntriangle perimeter: %f\n", triangle_area, triangle_perimeter);

    cube testing
    float cube_volume = volume_cube(7.4f);
    float cube_surface_area = surface_area_cube(7.4f);
    printf("cube volume: %f\ncube_surface_area: %f\n", cube_volume, cube_surface_area);

    cuboid testing
    float cuboid_volume = volume_cuboid(6.4f, 6.1f, 6.3f);
    float cuboid_surface_area = surface_area_cuboid(6.4f, 6.1f, 6.3f);
    printf("cuboid volume: %f\ncuboid_surface_area: %f\n", cuboid_volume, cuboid_surface_area);

    sphere testing
    float sphere_volume = volume_sphere(3.55f);
    float sphere_surface_area = surface_area_sphere(3.55f);
    printf("sphere volume: %f\nsphere_surface_area: %f\n", sphere_volume, sphere_surface_area); 

    cylinder testing
    float cylinder_volume = volume_cylinder(3.55f, 5.2f);
    float cylinder_surface_area = surface_area_cylinder(3.55f, 5.2f);
    printf("cylinder volume: %f\ncylinder_surface_area: %f\n", cylinder_volume, cylinder_surface_area); 
    */
    
    /* Vector 3d testing */
    vec3 vector = vec3_create(1.1f, 1.5f, 1.8f);
    vec3 vector3 = vec3_create(3.4f, 3.6f, 3.9f);

    vec3 v = vec3_add(vector, vector3);
    printf("%f %f %f", v.x, v.y, v.z);
    printf("%f", vec3_length(v));
    return 0;
}