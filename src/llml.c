#include <stdio.h>
#include <llml/llml.h>

int main() {
    vec4 orange = color_hex(0xFF5733);
    printf("Orange Hex (0xFF5733) to Vec4: [%.2f, %.2f, %.2f, %.2f]\n", 
            orange.x, orange.y, orange.z, orange.w);

    float t = 0.5f;
    printf("Smoothstep at 0.5: %f (Should be 0.5)\n", smoothstep(t));
    printf("Bounce at 0.5: %f\n", ease_out_bounce(t));

    vec3 p1 = {0,0,0};
    vec3 p2 = {1,1,1};
    if (col_sphere_vs_sphere(p1, 1.0f, p2, 1.0f)) {
        printf("Spheres are colliding!\n");
    }

    return 0;
}
