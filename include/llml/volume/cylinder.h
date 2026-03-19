#pragma once

static inline float volume_cylinder(float radius, float height)
{
    return M_PI * (radius * radius) * height;
}

static inline float surface_area_cylinder(float radius, float height)
{
    return 2 * M_PI * radius * (radius + height);
}
