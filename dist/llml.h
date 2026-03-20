/* llml - Low Level Math Library */
#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#include <math.h>
#include <stdbool.h>

typedef struct
{
    float x1;
    float x2;
    int solutions;
} quadratic_result;

/*
 * solves a quadratic equation of the form a times x squared plus b times x plus c equals zero
 * using the quadratic formula. returns a struct containing up to two solutions and the solution count.
 * the discriminant b squared minus 4ac determines whether there are 0, 1, or 2 real solutions.
 */
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

/*
 * linearly interpolates between values a and b by the factor t.
 * when t is 0 the result is a, when t is 1 the result is b.
 * values of t outside 0 to 1 will extrapolate beyond the range.
 */
static inline float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

/*
 * clamps a value to within a given min and max range inclusive.
 * returns min if the value is below min and max if the value is above max.
 */
static inline float clamp(float value, float min, float max) {
    if(value < min)
        return min;
    if(value > max)
        return max;
    return value;
}

/*
 * remaps a value from one numeric range to another.
 * a value at in_min maps to out_min and a value at in_max maps to out_max.
 * values outside the input range will be extrapolated linearly.
 */
static inline float map(float value, float in_min, float in_max, float out_min, float out_max) {
    return out_min + (out_max - out_min) * ((value - in_min) / (in_max - in_min));
}

// --- End of algebra/algebra.h ---


/*
 * converts an angle from degrees to radians by multiplying by pi divided by 180.
 */
static inline float llml_deg_to_rad(float degrees) {
    return degrees * (M_PI / 180.0f);
}

/*
 * converts an angle from radians to degrees by multiplying by 180 divided by pi.
 */
static inline float llml_rad_to_deg(float radians) {
    return radians * (180.0f / M_PI);
}

/*
 * calculates the length of the hypotenuse of a right triangle from the two shorter sides
 * using the pythagorean theorem as the square root of a squared plus b squared.
 */
static inline float llml_hypotenuse(float a, float b) {
    return sqrtf((a * a) + (b * b));
}

/*
 * calculates an unknown side length of a triangle using the law of sines.
 * given side b and its opposite angle beta in degrees, and the angle alpha in degrees
 * opposite to the unknown side, returns the length of that unknown side.
 */
static inline float llml_law_sines_side(float b, float alpha_degrees, float beta_degrees) {
    return (b * sinf(llml_deg_to_rad(alpha_degrees))) / sinf(llml_deg_to_rad(beta_degrees));
}

/*
 * calculates the side of a triangle opposite to a given angle using the law of cosines.
 * given two sides b and c and their included angle alpha in degrees, returns the length
 * of the opposite side using the formula square root of b squared plus c squared minus
 * 2 times b times c times the cosine of alpha.
 */
static inline float llml_law_cosines_side(float b, float c, float alpha_degrees) {
    float alpha_radians = llml_deg_to_rad(alpha_degrees);
    return sqrtf((b * b) + (c * c) - 2.0f * b * c * cosf(alpha_radians));
}

/*
 * calculates the angle in degrees from the origin to the point defined by x and y
 * using the two argument arctangent function.
 */
static inline float llml_angle_to_point(float y, float x) {
    return llml_rad_to_deg(atan2f(y, x));
}

// --- End of trigonometry/trigonometry.h ---

#include <math.h>

/*
 * smoothly interpolates t through a cubic hermite curve clamped between 0.0 and 1.0.
 * the output starts and ends with zero slope, producing a gradual ease in and ease out effect.
 * uses the formula t squared times 3 minus 2 times t.
 */
static inline float smoothstep(float t) {
    t = clamp(t, 0.0f, 1.0f);
    return t * t * (3.0f - 2.0f * t);
}

/*
 * applies a quadratic ease in curve to t, accelerating from zero velocity.
 * uses the formula t times t.
 */
static inline float ease_in_quad(float t) {
    return t * t;
}

/*
 * applies a quadratic ease out curve to t, decelerating to zero velocity.
 * uses the formula 1 minus the square of 1 minus t.
 */
static inline float ease_out_quad(float t) {
    return 1.0f - (1.0f - t) * (1.0f - t);
}

/*
 * applies a bounce ease out curve to t, simulating the motion of an object
 * bouncing to a stop at the end of the animation.
 * the output always ends at exactly 1.0.
 */
static inline float ease_out_bounce(float t) {
    const float n1 = 7.5625f;
    const float d1 = 2.75f;

    if (t < 1.0f / d1) {
        return n1 * t * t;
    } else if (t < 2.0f / d1) {
        t -= 1.5f / d1;
        return n1 * t * t + 0.75f;
    } else if (t < 2.5f / d1) {
        t -= 2.25f / d1;
        return n1 * t * t + 0.9375f;
    } else {
        t -= 2.625f / d1;
        return n1 * t * t + 0.984375f;
    }
}

// --- End of easing/easing.h ---


#include <math.h>

typedef struct {
    float x;
    float y;
} vec2;

/*
 * creates a new 2d vector with the given x and y components.
 */
static inline vec2 vec2_create(float x, float y) {
    return (vec2){ .x = x, .y = y };
}

/*
 * adds two 2d vectors together component wise and returns the result.
 */
static inline vec2 vec2_add(vec2 a, vec2 b) {
    return (vec2){ .x = a.x + b.x, .y = a.y + b.y };
}

/*
 * subtracts vector b from vector a component wise and returns the result.
 */
static inline vec2 vec2_subtract(vec2 a, vec2 b) {
    return (vec2){ .x = a.x - b.x, .y = a.y - b.y };
}

/*
 * multiplies each component of a 2d vector by a scalar value and returns the result.
 */
static inline vec2 vec2_scale(vec2 v, float scalar) {
    return (vec2){ .x = v.x * scalar, .y = v.y * scalar };
}

/*
 * calculates the dot product of two 2d vectors using the sum of a.x times b.x and a.y times b.y.
 * useful for finding the angle between two vectors or projecting one vector onto another.
 */
static inline float vec2_dot(vec2 a, vec2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

/*
 * calculates the magnitude of a 2d vector using the pythagorean theorem
 * as the square root of x squared plus y squared.
 */
static inline float vec2_length(vec2 v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

/*
 * returns a unit vector pointing in the same direction as the input vector
 * by dividing each component by the vector length.
 * returns a zero vector if the input length is zero to avoid division by zero.
 */
static inline vec2 vec2_normalized(vec2 v) {
    float len = vec2_length(v);
    if (len > 0.0f) {
        return vec2_scale(v, 1.0f / len);
    }
    return (vec2){ .x = 0.0f, .y = 0.0f };
}

// --- End of vector/vec2.h ---

#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} vec3;

/*
 * creates a new 3d vector with the given x, y, and z components.
 */
static inline vec3 vec3_create(float x, float y, float z)
{
    return (vec3){x, y, z};
}

/*
 * adds two 3d vectors together component wise and returns the result.
 */
static inline vec3 vec3_add(vec3 a, vec3 b)
{
    return (vec3){ .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z };
}

/*
 * subtracts vector b from vector a component wise and returns the result.
 */
static inline vec3 vec3_subtract(vec3 a, vec3 b) 
{
    return (vec3){ .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z };
}

/*
 * multiplies each component of a 3d vector by a scalar value and returns the result.
 */
static inline vec3 vec3_scale(vec3 v, float scalar) 
{
    return (vec3){ .x = v.x * scalar, .y = v.y * scalar, .z = v.z * scalar };
}

/*
 * calculates the magnitude of a 3d vector using the pythagorean theorem
 * as the square root of x squared plus y squared plus z squared.
 */
static inline float vec3_length(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

/*
 * returns a unit vector pointing in the same direction as the input vector
 * by dividing each component by the vector length.
 * returns a zero vector if the input length is zero to avoid division by zero.
 */
static inline vec3 vec3_normalized(vec3 v) 
{
    float len = vec3_length(v);
    if (len > 0.0f) {
        return vec3_scale(v, 1.0f / len);
    }
    return (vec3){0.0f, 0.0f, 0.0f};
}

/*
 * calculates the dot product of two 3d vectors using the sum of
 * a.x times b.x, a.y times b.y, and a.z times b.z.
 * useful for finding the angle between two vectors or projecting one vector onto another.
 */
static inline float vec3_dot(vec3 a, vec3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

/*
 * calculates the cross product of two 3d vectors and returns a new vector
 * that is perpendicular to both input vectors.
 * the resulting vector follows the right hand rule for its direction.
 */
static inline vec3 vec3_cross(vec3 a, vec3 b) 
{
    return (vec3){ .x = a.y * b.z - a.z * b.y, .y = a.z * b.x - a.x * b.z, .z = a.x * b.y - a.y * b.x};
}

// --- End of vector/vec3.h ---


#include <math.h>

typedef struct {
    float x, y, z, w;
} vec4;

/*
 * creates a new 4d vector with the given x, y, z, and w components.
 */
static inline vec4 vec4_create(float x, float y, float z, float w) {
    return (vec4){ .x = x, .y = y, .z = z, .w = w };
}

/*
 * creates a 4d vector from an existing 3d vector and a separate w component.
 */
static inline vec4 vec4_from_vec3(vec3 v, float w) {
    return (vec4){ .x = v.x, .y = v.y, .z = v.z, .w = w };
}

/*
 * adds two 4d vectors together component wise and returns the result.
 */
static inline vec4 vec4_add(vec4 a, vec4 b) {
    return (vec4){ .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w };
}

/*
 * subtracts vector b from vector a component wise and returns the result.
 */
static inline vec4 vec4_subtract(vec4 a, vec4 b) {
    return (vec4){ .x = a.x - b.x, .z = a.z - b.z, .w = a.w - b.w };
}

/*
 * multiplies each component of a 4d vector by a scalar value and returns the result.
 */
static inline vec4 vec4_scale(vec4 v, float scalar) {
    return (vec4){ .x = v.x * scalar, .y = v.y * scalar, .z = v.z * scalar, .w = v.w * scalar };
}

/*
 * calculates the dot product of two 4d vectors using the sum of
 * a.x times b.x, a.y times b.y, a.z times b.z, and a.w times b.w.
 * useful for finding the angle between two vectors or projecting one vector onto another.
 */
static inline float vec4_dot(vec4 a, vec4 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

/*
 * calculates the magnitude of a 4d vector as the square root of
 * x squared plus y squared plus z squared plus w squared.
 */
static inline float vec4_length(vec4 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

/*
 * returns a unit vector pointing in the same direction as the input vector
 * by dividing each component by the vector length.
 * returns a zero vector if the input length is zero to avoid division by zero.
 */
static inline vec4 vec4_normalized(vec4 v) {
    float len = vec4_length(v);
    if (len > 0.0f) {
        return vec4_scale(v, 1.0f / len);
    }
    return (vec4){ .x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f };
}

// --- End of vector/vec4.h ---

#include <stdint.h>

/*
 * creates a vec4 color from red, green, and blue byte values in the range 0 to 255.
 * each channel is normalized to the 0.0 to 1.0 range. the alpha component is set to 1.0.
 */
static inline vec4 color_rgb(uint8_t r, uint8_t g, uint8_t b) {
    return (vec4){r / 255.0f, g / 255.0f, b / 255.0f, 1.0f};
}

/*
 * creates a vec4 color from a 24 bit hexadecimal integer in the format 0xRRGGBB.
 * each channel is extracted and normalized to the 0.0 to 1.0 range. the alpha component is set to 1.0.
 */
static inline vec4 color_hex(uint32_t hex) {
    return (vec4){
        ((hex >> 16) & 0xFF) / 255.0f,
        ((hex >> 8) & 0xFF) / 255.0f,
        (hex & 0xFF) / 255.0f,
         1.0f
    };
}

// --- End of vector/vec4_color.h ---


#include <math.h>

typedef struct {
    float data[16];
} mat4;

/*
 * creates a 4x4 identity matrix where the diagonal elements are 1 and all others are 0.
 */
static inline mat4 mat4_identity(void) {
    return (mat4){.data = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f} };
}

/*
 * multiplies two 4x4 matrices together and returns the resulting matrix.
 * the matrices are stored in column major order.
 */
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

/*
 * applies a translation to a 4x4 matrix by the given 3d vector and returns the result.
 * the translation modifies the last column of the matrix.
 */
static inline mat4 mat4_translate(mat4 m, vec3 v) {
    mat4 result = m;
    result.data[12] = m.data[0] * v.x + m.data[4] * v.y + m.data[8] * v.z + m.data[12];
    result.data[13] = m.data[1] * v.x + m.data[5] * v.y + m.data[9] * v.z + m.data[13];
    result.data[14] = m.data[2] * v.x + m.data[6] * v.y + m.data[10] * v.z + m.data[14];
    result.data[15] = m.data[3] * v.x + m.data[7] * v.y + m.data[11] * v.z + m.data[15];
    return result;
}

/*
 * applies a non uniform scale to a 4x4 matrix by the given 3d vector and returns the result.
 * each column group of the matrix is multiplied by the corresponding scale component.
 */
static inline mat4 mat4_scale(mat4 m, vec3 v) {
    mat4 result = m;
    for (int i = 0; i < 4; i++) result.data[i] *= v.x;
    for (int i = 4; i < 8; i++) result.data[i] *= v.y;
    for (int i = 8; i < 12; i++) result.data[i] *= v.z;
    return result;
}

/*
 * transforms a 3d vector by a 4x4 matrix and returns the resulting 3d vector.
 * assumes the vector has an implicit w component of 1 so translation is applied.
 */
static inline vec3 mat4_mul_vec3(mat4 m, vec3 v) {
    return (vec3){
        m.data[0] * v.x + m.data[4] * v.y + m.data[8] * v.z + m.data[12],
        m.data[1] * v.x + m.data[5] * v.y + m.data[9] * v.z + m.data[13],
        m.data[2] * v.x + m.data[6] * v.y + m.data[10] * v.z + m.data[14]
    };
}

/*
 * transforms a 4d vector by a 4x4 matrix and returns the resulting 4d vector.
 * the w component of the input vector is used in the computation.
 */
static inline vec4 mat4_mul_vec4(mat4 m, vec4 v) {
    return (vec4){
        m.data[0] * v.x + m.data[4] * v.y + m.data[8] * v.z + m.data[12] * v.w,
        m.data[1] * v.x + m.data[5] * v.y + m.data[9] * v.z + m.data[13] * v.w,
        m.data[2] * v.x + m.data[6] * v.y + m.data[10] * v.z + m.data[14] * v.w,
        m.data[3] * v.x + m.data[7] * v.y + m.data[11] * v.z + m.data[15] * v.w
    };
}

/*
 * creates a perspective projection matrix from a vertical field of view in radians,
 * an aspect ratio, and near and far clipping plane distances.
 * maps 3d coordinates into normalized device coordinates for rendering.
 */
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

/*
 * creates an orthographic projection matrix from left, right, bottom, top, near, and far plane values.
 * maps 3d coordinates linearly into normalized device coordinates without perspective distortion.
 */
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

/*
 * creates a view matrix that orients the camera at the eye position looking toward the target position.
 * the up vector defines which direction is considered upward in world space.
 */
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

/*
 * applies a rotation around the z axis by the given angle in degrees to a 4x4 matrix
 * and returns the result.
 */
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

/*
 * applies a rotation around the x axis by the given angle in degrees to a 4x4 matrix
 * and returns the result.
 */
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

/*
 * applies a rotation around the y axis by the given angle in degrees to a 4x4 matrix
 * and returns the result.
 */
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

// --- End of matrix/mat4.h ---


/*
 * calculates the area of a circle using pi times radius squared.
 */
static inline float area_circle(float radius) 
{
    return M_PI * (radius * radius);
}

/*
 * calculates the circumference of a circle using 2 times pi times radius.
 */
static inline float circumference_circle(float radius) 
{
    return 2.0f * M_PI * radius;
}

// --- End of area/circle.h ---


/*
 * calculates the area of a square using side times side.
 */
static inline float area_square(float side) 
{
    return side * side;
}

/*
 * calculates the perimeter of a square using 4 times the side length.
 */
static inline float perimeter_square(float side) 
{
    return 4.0f * side;
}

// --- End of area/square.h ---


/*
 * calculates the area of a rectangle using side a times side b.
 */
static inline float area_rectangle(float a, float b) 
{
    return a * b;
}

/*
 * calculates the perimeter of a rectangle using 2 times the product of a and b.
 */
static inline float perimeter_rectangle(float a, float b) 
{
    return 2.0f * (a * b);
}

// --- End of area/rectangle.h ---


/*
 * calculates the area of a triangle using half times base times height.
 */
static inline float area_triangle(float base, float height) 
{
    return 0.5f * (base * height);
}

/*
 * calculates the perimeter of a triangle by summing all three side lengths a, b, and c.
 */
static inline float perimeter_triangle(float a, float b, float c)
{
    return a + b + c;
}

// --- End of area/triangle.h ---


/*
 * calculates the volume of a cube using side times side times side.
 */
static inline float volume_cube(float side) 
{
    return side * side * side;
}

/*
 * calculates the surface area of a cube using 6 times side squared.
 */
static inline float surface_area_cube(float side) 
{
    return 6.0f * (side * side);
}

// --- End of volume/cube.h ---


/*
 * calculates the volume of a cuboid using the product of its three side lengths a times b times c.
 */
static inline float volume_cuboid(float a, float b, float c) 
{
    return a * b * c;
}

/*
 * calculates the surface area of a cuboid using 2 times the sum of a times b, b times c, and a times c.
 */
static inline float surface_area_cuboid(float a, float b, float c) 
{
    return 2.0f * (a * b + b * c + a * c);
}

// --- End of volume/cuboid.h ---


/*
 * calculates the volume of a sphere using four thirds times pi times radius cubed.
 */
static inline float volume_sphere(float radius) 
{
    return 0.75f * M_PI * (radius * radius * radius);
}

/*
 * calculates the surface area of a sphere using 4 times pi times radius squared.
 */
static inline float surface_area_sphere(float radius)
{
    return (4.0f / 3.0f) * M_PI * (radius * radius * radius);
}

// --- End of volume/sphere.h ---


/*
 * calculates the volume of a cylinder using pi times radius squared times height.
 */
static inline float volume_cylinder(float radius, float height)
{
    return M_PI * (radius * radius) * height;
}

/*
 * calculates the total surface area of a cylinder including both circular caps and the lateral surface.
 * uses the formula 2 times pi times radius times the sum of radius plus height.
 */
static inline float surface_area_cylinder(float radius, float height)
{
    return 2.0f * M_PI * radius * (radius + height);
}

// --- End of volume/cylinder.h ---


#include <stdbool.h>

/*
 * tests whether a 2d point lies within or on the boundary of an axis aligned bounding box.
 * the box is defined by a min corner and a max corner.
 */
static inline bool col_point_in_aabb2d(vec2 point, vec2 min, vec2 max) {
    return (point.x >= min.x && point.x <= max.x) && (point.y >= min.y && point.y <= max.y);
}

/*
 * tests whether two spheres in 3d space are overlapping or touching.
 * uses squared distance comparison to avoid an unnecessary square root operation.
 */
static inline bool col_sphere_vs_sphere(vec3 pos1, float rad1, vec3 pos2, float rad2) {
    vec3 diff = vec3_subtract(pos1, pos2);
    float distance_sq = vec3_dot(diff, diff); 
    float radii_sum = rad1 + rad2;
    return distance_sq <= (radii_sum * radii_sum);
}

/*
 * tests whether a ray intersects a sphere in 3d space.
 * the ray is defined by an origin point and a normalized direction vector.
 * returns false immediately if the sphere center is behind the ray origin.
 */
static inline bool col_ray_vs_sphere(vec3 ray_origin, vec3 ray_dir, vec3 sphere_center, float sphere_rad) {
    vec3 l = vec3_subtract(sphere_center, ray_origin);
    float tca = vec3_dot(l, ray_dir);
    if (tca < 0) return false;
    float d2 = vec3_dot(l, l) - tca * tca;
    return d2 <= (sphere_rad * sphere_rad);
}

// --- End of physics/collision.h ---


#include <stdint.h>

static uint32_t _rng_state = 10000;

/*
 * sets the global seed for the xorshift32 random number generator.
 * a seed value of zero is not allowed and will be replaced with 10000.
 */
static inline void _seed(uint32_t seed) 
{
    if (seed == 0) seed = 10000;
   _rng_state = seed; 
}

/*
 * generates a random unsigned 32 bit integer using the xorshift algorithm.
 * this is significantly faster than the standard rand function.
 */
static inline uint32_t _rand_uint32(void) 
{
    uint32_t x = _rng_state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    _rng_state = x;
    return x;
}

/*
 * generates a random floating point number in the range 0.0 to 1.0 inclusive.
 */
static inline float _rand_float(void) {
    return (float)_rand_uint32() / (float)UINT32_MAX;
}

/*
 * generates a random integer within the inclusive range from min to max.
 */
static inline int _rand_int_range(int _min, int _max) {
    return _min + (_rand_uint32() % (_max - _min + 1));
}

/*
 * generates a random float within the inclusive range from min to max.
 */
static inline float _rand_float_range(float _min, float _max) {
    return _min + _rand_float() * (_max - _min);
}

/*
 * generates a random boolean value that is either true or false with equal probability.
 */
static inline bool _rand_bool(void) {
    return (_rand_uint32() % 2) == 0;
}

/*
 * generates a vec3 with each component set to a random float within the given min to max range.
 */
static inline vec3 _rand_vec3_range(float _min, float _max) {
    return (vec3) {
      _rand_float_range(_min, _max),
      _rand_float_range(_min, _max),
      _rand_float_range(_min, _max)
  };
}

/*
 * generates a random unit vec3 pointing in a uniformly distributed random direction.
 * the result is normalized so its length is 1.
 */
static inline vec3 _rand_vec3_direction(void) {
    vec3 v = _rand_vec3_range(-1.0f, 1.0f);
    return vec3_normalized(v);
}

// --- End of random/random.h ---


