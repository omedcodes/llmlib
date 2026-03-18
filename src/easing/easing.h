#pragma once
#include <math.h>

static inline float smoothstep(float t) {
    t = clamp(t, 0.0f, 1.0f);
    return t * t * (3.0f - 2.0f * t);
}

static inline float ease_in_quad(float t) {
    return t * t;
}

static inline float ease_out_quad(float t) {
    return 1.0f - (1.0f - t) * (1.0f - t);
}

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
