#pragma once

#include "vec3.h"

typedef struct
{
    float x;
    float y;
    float z;
    float w;
} vec4;

static inline vec4 vec4_create(float x, float y, float z, float w) {
    return (vec4){x, y, z, w};
}

static inline vec4 vec4_from_vec3(vec3 v, float w) {
    return (vec4){v.x, v.y, v.z, w};
}