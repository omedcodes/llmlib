#pragma once

#include <math.h>
#include <stdbool.h>

typedef struct
{
    float x1;
    float x2;
    int solutions;
} quadratic_result;

static inline quadratic_result llml_solve_quadratic(float a, float b, float c) {
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