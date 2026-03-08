#pragma once

#include <math.h>

typedef struct 
{
    float x;
    float y;
    float z;
} vec3;

static inline vec3 vec3_create(float x, float y, float z)
{
    return (vec3){x, y, z};
}

static inline vec3 vec3_add(vec3 a, vec3 b)
{
    return (vec3){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
}

static inline float vec3_length(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}