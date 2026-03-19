#pragma once

static inline float volume_cube(float side) 
{
    return side * side * side;
}

static inline float surface_area_cube(float side) 
{
    return 6.0f * (side * side);
}