#pragma once

static inline float volume_sphere(float radius) 
{
    return 0.75f * M_PI * (radius * radius * radius);
}

static inline float surface_area_sphere(float radius)
{
    return (4.0f / 3.0f) * M_PI * (radius * radius * radius);
}