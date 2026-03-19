#pragma once

static inline float area_triangle(float base, float height) 
{
    return 0.5f * (base * height);
}

static inline float perimeter_triangle(float a, float b, float c)
{
    return a + b + c;
}