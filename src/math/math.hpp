#pragma once

#include <cmath>
#include <math.h>

namespace Terrux {
    namespace Math {
        float randFloat(float min, float max);
        int randInt(int min, int max);
        void clampF(float* val, float min, float max);
        void clampI(int* val, int min, int max);
    }
}
