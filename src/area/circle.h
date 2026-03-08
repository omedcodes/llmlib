#pragma once

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

static inline double circle_area(double radius) 
{
    return M_PI * (radius * radius);
}

static inline double circle_circumference(double radius) 
{
    return 2.0 * M_PI * radius;
}