#pragma once
#include <math.h>

typedef struct {
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
    return (vec3){ .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z };
}

static inline vec3 vec3_subtract(vec3 a, vec3 b) 
{
    return (vec3){ .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z };
}

static inline vec3 vec3_scale(vec3 v, float scalar) 
{
    return (vec3){ .x = v.x * scalar, .y = v.y * scalar, .z = v.z * scalar };
}

static inline float vec3_length(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

static inline vec3 vec3_normalized(vec3 v) 
{
    float len = vec3_length(v);
    if (len > 0.0f) {
        return vec3_scale(v, 1.0f / len);
    }
    return (vec3){0.0f, 0.0f, 0.0f};
}

static inline float vec3_dot(vec3 a, vec3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static inline vec3 vec3_cross(vec3 a, vec3 b) 
{
    return (vec3){ .x = a.y * b.z - a.z * b.y, .y = a.z * b.x - a.x * b.z, .z = a.x * b.y - a.y * b.x};
}