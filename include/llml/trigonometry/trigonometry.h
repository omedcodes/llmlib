#pragma once

static inline float llml_deg_to_rad(float degrees) {
    return degrees * (M_PI / 180.0f);
}

static inline float llml_rad_to_deg(float radians) {
    return radians * (180.0f / M_PI);
}

static inline float llml_hypotenuse(float a, float b) {
    return sqrtf((a * a) + (b * b));
}

static inline float llml_law_sines_side(float b, float alpha_degrees, float beta_degrees) {
    return (b * sinf(llml_deg_to_rad(alpha_degrees))) / sinf(llml_deg_to_rad(beta_degrees));
}

static inline float llml_law_cosines_side(float b, float c, float alpha_degrees) {
    float alpha_radians = llml_deg_to_rad(alpha_degrees);
    return sqrtf((b * b) + (c * c) - 2.0f * b * c * cosf(alpha_radians));
}

static inline float llml_angle_to_point(float y, float x) {
    return llml_rad_to_deg(atan2f(y, x));
}