#pragma once

#include "llml/vector/vec3.h"
#include "llml/trigonometry/trigonometry.h"
#include <math.h>

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
    return (vec3){
        m.data[0] * v.x + m.data[4] * v.y + m.data[8] * v.z + m.data[12],
        m.data[1] * v.x + m.data[5] * v.y + m.data[9] * v.z + m.data[13],
        m.data[2] * v.x + m.data[6] * v.y + m.data[10] * v.z + m.data[14]
    };
}

static inline vec4 mat4_mul_vec4(mat4 m, vec4 v) {
    return (vec4){
        m.data[0] * v.x + m.data[4] * v.y + m.data[8] * v.z + m.data[12] * v.w,
        m.data[1] * v.x + m.data[5] * v.y + m.data[9] * v.z + m.data[13] * v.w,
        m.data[2] * v.x + m.data[6] * v.y + m.data[10] * v.z + m.data[14] * v.w,
        m.data[3] * v.x + m.data[7] * v.y + m.data[11] * v.z + m.data[15] * v.w
    };
}

static inline mat4 mat4_perspective(float fov_radians, float aspect, float near_p, float far_p) {
    mat4 result = {0};
    float tan_half_fov = tanf(fov_radians / 2.0f);
    result.data[0] = 1.0f / (aspect * tan_half_fov);
    result.data[5] = 1.0f / tan_half_fov;
    result.data[10] = far_p / (near_p - far_p);
    result.data[11] = -1.0f;
    result.data[14] = -(far_p * near_p) / (far_p - near_p);
    return result;
}

static inline mat4 mat4_ortho(float left, float right, float bottom, float top, float near_p, float far_p) {
    mat4 result = mat4_identity();
    result.data[0] = 2.0f / (right - left);
    result.data[5] = 2.0f / (top - bottom);
    result.data[10] = -1.0f / (far_p - near_p);
    result.data[12] = -(right + left) / (right - left);
    result.data[13] = -(top + bottom) / (top - bottom);
    result.data[14] = -near_p / (far_p - near_p);
    return result;
}

static inline mat4 mat_look_at(vec3 eye, vec3 target, vec3 up) {
    vec3 f = vec3_normalized(vec3_subtract(target, eye));
    vec3 s = vec3_normalized(vec3_cross(f, up));
    vec3 u = vec3_cross(s, f);
    mat4 result = mat4_identity();
    result.data[0] = s.x;
    result.data[4] = s.y;
    result.data[8] = s.z;
    result.data[1] = u.x;
    result.data[5] = u.y;
    result.data[9] = u.z;
    result.data[2] = -f.x;
    result.data[6] = -f.y;
    result.data[10] = -f.z;
    result.data[12] = -vec3_dot(s, eye);
    result.data[13] = -vec3_dot(u, eye);
    result.data[14] = vec3_dot(f, eye);
    return result;
}

static inline mat4 mat4_rotate_z(mat4 m, float degrees) {
    float rad = llml_deg_to_rad(degrees);
    float c = cosf(rad);
    float s = sinf(rad);
    mat4 rot = mat4_identity();
    rot.data[0] = c;
    rot.data[4] = -s;
    rot.data[1] = s;
    rot.data[5] = c;
    return mat4_multiply(m, rot);
}

static inline mat4 mat4_rotate_x(mat4 m, float degrees) {
    float rad = llml_deg_to_rad(degrees);
    float c = cosf(rad);
    float s = sinf(rad);
    mat4 rot = mat4_identity();
    rot.data[5] = c;
    rot.data[9] = -s;
    rot.data[6] = s;
    rot.data[10] = c;
    return mat4_multiply(m, rot);
}

static inline mat4 mat4_rotate_y(mat4 m, float degrees) {
    float rad = llml_deg_to_rad(degrees);
    float c = cosf(rad);
    float s = sinf(rad);
    mat4 rot = mat4_identity();
    rot.data[0] = c;
    rot.data[8] = s;
    rot.data[2] = -s;
    rot.data[10] = c;
    return mat4_multiply(m, rot);
}