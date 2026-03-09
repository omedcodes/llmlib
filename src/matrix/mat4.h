#pragma once

#include "../vector/vec3.h"

typedef struct {
    float data[16];
} mat4;

static inline mat4 mat4_identity(void) {
    return (mat4){.data = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f} };
}

static inline mat4 mat4_multiply(mat4 a, mat4 b) {
    mat4 result = {0};
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            float sum = 0.0f;
            for (int i = 0; i < 4; i++) {
                sum += a.data[row + i * 4] * b.data[i + col * 4];
            }
            result.data[row + col * 4] = sum;
        }
    }
    return result;
}

static inline mat4 mat4_translate(mat4 m, vec3 v) {
    mat4 result = m;
    result.data[12] = m.data[0] * v.x + m.data[4] * v.y + m.data[8] * v.z + m.data[12];
    result.data[13] = m.data[1] * v.x + m.data[5] * v.y + m.data[9] * v.z + m.data[13];
    result.data[14] = m.data[2] * v.x + m.data[6] * v.y + m.data[10] * v.z + m.data[14];
    result.data[15] = m.data[3] * v.x + m.data[7] * v.y + m.data[11] * v.z + m.data[15];
    return result;
}

static inline mat4 mat4_scale(mat4 m, vec3 v) {
    mat4 result = m;
    for (int i = 0; i < 4; i++) result.data[i] *= v.x;
    for (int i = 4; i < 8; i++) result.data[i] *= v.y;
    for (int i = 8; i < 12; i++) result.data[i] *= v.z;
    return result;
}

static inline vec3 mat4_mul_vec3(mat4 m, vec3 v) {
    vec3 result;
    result.x = m.data[0] * v.x + m.data[4] * v.y + m.data[8] * v.z + m.data[12];
    result.y = m.data[1] * v.x + m.data[5] * v.y + m.data[9] * v.z + m.data[13];
    result.z = m.data[2] * v.x + m.data[6] * v.y + m.data[10] * v.z + m.data[14];
    return result;
}