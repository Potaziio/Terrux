#pragma once

#include <iostream>

#define GLFW_INCLUDE_NONE   
#include "../../vendor/glfw-3.3.5/include/GLFW/glfw3.h"

#include "../math/vector/vector.hpp"

#define KEYS 350
#define BUTTONS 4

namespace Terrux {
    class Input {
        private:
            // Keyboard Input
            
            static bool keyHold[KEYS];
            static bool keyDown[KEYS];
            static bool keyUp[KEYS];

            // Mouse Input

            static bool mouseHold[BUTTONS];
            static bool mouseDown[BUTTONS];
            static bool mouseUp[BUTTONS];
            static bool isDragging;
            static float mouseScroll;

            static Math::Vector2 mousePos;
            static Math::Vector2 lastMousePos;
        public:
            //Keyboard Input
        
            static bool GetKeyDown(int key);
            static bool GetKeyUp(int key);
            static bool GetKey(int key);
            
            static float GetAxisRaw(std::string axis);

            static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
            static void endKeyFrame();

            //Mouse Input

            static void MouseCursorCallback(GLFWwindow* window, double xpos, double ypos);
            static void MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
            static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
            static void endMouseFrame(); 

            static float GetMouseScroll();
            static Math::Vector2 GetLastMousePos();
            static Math::Vector2 GetMousePos();
            static Math::Vector2 GetDeltaMousePos();

            static bool isMouseDragging();
            static bool GetMouseButtonDown(int button);
            static bool GetMouseButtonUp(int button);
            static bool GetMouseButton(int button); 
    };
}
