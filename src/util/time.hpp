#pragma once

#define GLFW_INCLUDE_NONE
#include "../../vendor/glfw-3.3.5/include/GLFW/glfw3.h"

namespace Terrux {
    namespace Utils {
        class Time {
            private:
                static float dt;
                static float startTime;
                static float endTime;
            public:
                Time();
                static float deltaTime();
                static float GetMilliseconds();
        };
    }
}
