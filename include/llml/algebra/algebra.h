#pragma once

#include <math.h>
#include <stdbool.h>

typedef struct
{
    float x1;
    float x2;
    int solutions;
} quadratic_result;

static inline quadratic_result quadratic_formula(float a, float b, float c) {
    quadratic_result res = {0};
    float discriminant = (b * b) - (4.0f * a * c);
    if (discriminant < 0) {
        res.solutions = 0;
    } else if (discriminant == 0) {
        res.x1 = -b / (2.0f * a);
        res.solutions = 1;
    } else {
        float sqrt_d = sqrtf(discriminant);
        res.x1 = (-b + sqrt_d) / (2.0f * a);
        res.x2 = (-b - sqrt_d) / (2.0f * a);
        res.solutions = 2;
    }
    return res;
}

static inline float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

static inline float clamp(float value, float min, float max) {
    if(value < min)
        return min;
    if(value > max)
        return max;
    return value;
}

static inline float map(float value, float in_min, float in_max, float out_min, float out_max) {
    return out_min + (out_max - out_min) * ((value - in_min) / (in_max - in_min));
}