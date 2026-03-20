#pragma once
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define LLML_START_UNIT_TESTING(name) printf("Unit Testing: %s\n", name)

#define LLML_ASSERT(cond, message) if (!(cond)) { printf("[FAIL] %s\n", message); return false; } else { printf("[PASS] %s\n", message); }

/*
* returns current time in seconds
* uses clock() as a reliable fallback for mingw if timespec_get fails
*/
static inline double get_time_nano() {
    return (double)clock() / CLOCKS_PER_SEC;
}