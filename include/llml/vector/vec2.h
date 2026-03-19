#pragma once

#include <math.h>

typedef struct {
    float x;
    float y;
} vec2;

static inline vec2 vec2_create(float x, float y) {
    return (vec2){ .x = x, .y = y };
}

static inline vec2 vec2_add(vec2 a, vec2 b) {
    return (vec2){ .x = a.x + b.x, .y = a.y + b.y };
}

static inline vec2 vec2_subtract(vec2 a, vec2 b) {
    return (vec2){ .x = a.x - b.x, .y = a.y - b.y };
}

static inline vec2 vec2_scale(vec2 v, float scalar) {
    return (vec2){ .x = v.x * scalar, .y = v.y * scalar };
}

static inline float vec2_dot(vec2 a, vec2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

static inline float vec2_length(vec2 v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

static inline vec2 vec2_normalized(vec2 v) {
    float len = vec2_length(v);
    if (len > 0.0f) {
        return vec2_scale(v, 1.0f / len);
    }
    return (vec2){ .x = 0.0f, .y = 0.0f };
}