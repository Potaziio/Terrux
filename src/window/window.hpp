#pragma once

#include <iostream>
#include <string>

#include "../input/input.hpp"
#include "../util/color.hpp"
#include "../game/game.hpp"

#define GLFW_INCLUDE_NONE
#include "../../vendor/glfw-3.3.5/include/GLFW/glfw3.h"


namespace Terrux {
    // Forward declaration
    struct Game;

    struct Window {
        Game* game;
        GLFWwindow* window;
        std::string name;
        int width;
        int height;
        int swapInterval;
        Utils::RGBA_Color color;

        void ChangeWindowName(std::string name);
        void OnStart();
        void OnUpdate();
        void OnExit();
    };
}
