#pragma once

static inline float volume_cuboid(float a, float b, float c) 
{
    return a * b * c;
}

static inline float surface_area_cuboid(float a, float b, float c) 
{
    return 2 * (a * b + b * c + a * c);
}