#include <stdio.h>
#include <llml/llml.h>
#include <llml/llml_test.h>

bool run_vec_tests() {
    LLML_START_UNIT_TESTING("Vector Operations");
    
    vec3 a = {1.0f, 1.0f, 1.0f};
    vec3 b = {2.0f, 2.0f, 2.0f};
    vec3 res = vec3_add(a, b);
    
    LLML_ASSERT(res.x == 3.0f, "vec3 addition x-axis");
    LLML_ASSERT(vec3_length(a) > 1.7f, "vec3 length calculation");
    
    return true;
}

int main() {
    run_vec_tests();

    mat4 view = mat4_identity();
    vec4 point = {10.0f, 5.0f, 2.0f, 1.0f};
    
    double start = get_time_nano();
    
    for(int i = 0; i < 1000000; i++) {
        point = mat4_mul_vec4(view, point);
        // keep changing the matrix so it can't be "cached"
        view.data[0] += 0.0000001f; 
    }
    
    double end = get_time_nano();
    
    printf("\nBenchmark Results:\n");
    printf("1 Million Matrix-Vector Multiplications: %f seconds\n", end - start);
    
    // CRITICAL: Print the result so the compiler doesn't skip the loop!
    printf("Final Point Result: [%.2f, %.2f, %.2f]\n", point.x, point.y, point.z);
    
    return 0;
}
