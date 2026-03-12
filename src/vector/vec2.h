#pragma once

#include <math.h>

typedef struct
{
    float x;
    float y;
} vec2;

static inline vec2 vec2_create(float x, float y) { return (vec2){x, y}; }

static inline vec2 vec2_add(vec2 a, vec2 b) { return (vec2){a.x + b.x, a.y + b.y}; }

static inline float vec2_length(vec2 v) { return sqrtf(v.x * v.x + v.y * v.y); }