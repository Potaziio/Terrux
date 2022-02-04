#include "math.hpp"

namespace Terrux::Math {
    float randFloat(float min, float max) {
        return ((max - min) * ((float)rand() / (float)RAND_MAX)) + min;
    }

    int randInt(int min, int max) {
        return min + rand() / (RAND_MAX / (max - min + 1) + 1);
    }
    void clampF(float* val, float min, float max) {
        if (*val > max) {
            *val = max;
        } else if (*val < min) {
            *val = min;
        } 
    }

    void clampI(int* val, int min, int max) {
        if (*val > max) {
            *val = max;
        } else if (*val < min) {
            *val = min;
        } 
    } 
}
