#pragma once

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846f
#endif

#include "llml/algebra/algebra.h"
#include "llml/trigonometry/trigonometry.h"
#include "llml/easing/easing.h"

#include "llml/vector/vec2.h"
#include "llml/vector/vec3.h"
#include "llml/vector/vec4.h"
#include "llml/vector/vec4_color.h"

#include "llml/matrix/mat4.h"

#include "llml/area/circle.h"
#include "llml/area/square.h"
#include "llml/area/rectangle.h"
#include "llml/area/triangle.h"

#include "llml/volume/cube.h"
#include "llml/volume/cuboid.h"
#include "llml/volume/sphere.h"
#include "llml/volume/cylinder.h"

#include "llml/physics/collision.h"
#include "llml/random/random.h"