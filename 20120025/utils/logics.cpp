#include <cstdlib>
#include <cmath>
#include "./logics.h"
#include "../macros.h"

int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

float randFloat(float min, float max) {
    return min + (max - min) * rand() / (float) RAND_MAX;
}

int clip(int value, int min, int max) {
    if (value < min)
        return min;

    if (value > max)
        return max;

    return value;
}