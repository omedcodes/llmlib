#pragma once

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

static inline float area_circle(float radius) 
{
    return M_PI * (radius * radius);
}

static inline float circumference_circle(float radius) 
{
    return 2.0 * M_PI * radius;
}