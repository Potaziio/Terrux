#include "time.hpp"

namespace Terrux::Utils {
    Time::Time() {
        endTime = GetMilliseconds();
        dt = endTime - startTime;
        startTime = endTime;
    }

    float Time::GetMilliseconds() {
        return (float)glfwGetTime();
    }

    float Time::deltaTime() {
        return dt;
    }

    float Time::startTime = GetMilliseconds();
    float Time::endTime = GetMilliseconds();
    float Time::dt = -1.0f;
}
