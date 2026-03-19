#pragma once

#include <math.h>
#include "llml/vector/vec3.h"

typedef struct {
    float x, y, z, w;
} vec4;

static inline vec4 vec4_create(float x, float y, float z, float w) {
    return (vec4){ .x = x, .y = y, .z = z, .w = w };
}

static inline vec4 vec4_from_vec3(vec3 v, float w) {
    return (vec4){ .x = v.x, .y = v.y, .z = v.z, .w = w };
}

static inline vec4 vec4_add(vec4 a, vec4 b) {
    return (vec4){ .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w };
}

static inline vec4 vec4_subtract(vec4 a, vec4 b) {
    return (vec4){ .x = a.x - b.x, .z = a.z - b.z, .w = a.w - b.w };
}

static inline vec4 vec4_scale(vec4 v, float scalar) {
    return (vec4){ .x = v.x * scalar, .y = v.y * scalar, .z = v.z * scalar, .w = v.w * scalar };
}

static inline float vec4_dot(vec4 a, vec4 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

static inline float vec4_length(vec4 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

static inline vec4 vec4_normalized(vec4 v) {
    float len = vec4_length(v);
    if (len > 0.0f) {
        return vec4_scale(v, 1.0f / len);
    }
    return (vec4){ .x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f };
}