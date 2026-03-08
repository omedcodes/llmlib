#pragma once

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

static inline double area_circle(double radius) 
{
    return M_PI * (radius * radius);
}

static inline double circumference_circle(double radius) 
{
    return 2.0 * M_PI * radius;
}