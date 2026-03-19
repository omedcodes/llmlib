#pragma once

static inline float area_circle(float radius) 
{
    return M_PI * (radius * radius);
}

static inline float circumference_circle(float radius) 
{
    return 2.0 * M_PI * radius;
}