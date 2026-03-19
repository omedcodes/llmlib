#pragma once
#include <stdint.h>
#include "llml/vector/vec4.h"

static inline vec4 color_rgb(uint8_t r, uint8_t g, uint8_t b) {
    return (vec4){r / 255.0f, g / 255.0f, b / 255.0f, 1.0f};
}

static inline vec4 color_hex(uint32_t hex) {
    return (vec4){
        ((hex >> 16) & 0xFF) / 255.0f,
        ((hex >> 8) & 0xFF) / 255.0f,
        (hex & 0xFF) / 255.0f,
         1.0f
    };
}
