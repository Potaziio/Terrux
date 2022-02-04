#include "input.hpp"

namespace Terrux {
    // Keyboard Input

    void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            keyHold[key] = true;
            keyDown[key] = true;
        } else if (action == GLFW_RELEASE) {
            keyHold[key] = false;
            keyUp[key] = true;
        }
    }

    void Input::endKeyFrame() {
        for (int i = 0; i < KEYS; ++i) {
            keyDown[i] = false;
            keyUp[i] = false;
        }    
    }

    float Input::GetAxisRaw(std::string axis) {
        if (axis == "Horizontal") {
            if (GetKey(GLFW_KEY_D)) {
                return 1.0f;
            } else if (GetKey(GLFW_KEY_A)) {
                return -1.0f;
            }
        }

        if (axis == "Vertical") {
            if (GetKey(GLFW_KEY_W)) {
                return 1.0f;
            } else if (GetKey(GLFW_KEY_S)) {
                return -1.0f;
            }
        }

        return 0.0f;
    }

    bool Input::GetKeyDown(int key) {
        return keyDown[key];
    }

    bool Input::GetKeyUp(int key) {
        return keyUp[key];
    }

    bool Input::GetKey(int key) {
        return keyHold[key];
    }

    bool Input::keyHold[KEYS];
    bool Input::keyDown[KEYS];
    bool Input::keyUp[KEYS];

    // Mouse Input

    void Input::MouseCursorCallback(GLFWwindow* window, double xpos, double ypos) {
        Input::lastMousePos = Math::Vector2(mousePos.x, mousePos.y);
        Input::mousePos = Math::Vector2((float)xpos, (float)ypos);
    }

    void Input::MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
        mouseScroll = (float)yOffset;
    }

    void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        if (action == GLFW_PRESS) {
            if (button < BUTTONS) {
                mouseHold[button] = true;
                mouseDown[button] = true;
            }
        }
        else if (action == GLFW_RELEASE) {
            mouseHold[button] = false;
            mouseUp[button] = true;
            isDragging = false;
        }
    }

    void Input::endMouseFrame() {
        lastMousePos = Math::Vector2(mousePos.x, mousePos.y);
        mouseScroll = 0.0f;
        isDragging = mouseHold[0];

        for (int i = 0; i < BUTTONS; ++i) {
            mouseDown[i] = false;
            mouseUp[i] = false;
        }
    }


    Math::Vector2 Input::GetMousePos() {
        return mousePos; 
    }

    Math::Vector2 Input::GetLastMousePos() {
        return lastMousePos; 
    }

    Math::Vector2 Input::GetDeltaMousePos() {
        return mousePos - lastMousePos;
    }

    float Input::GetMouseScroll() {
        return mouseScroll;
    }

    bool Input::isMouseDragging() {
        return isDragging;
    }

    bool Input::GetMouseButton(int button) {
        if (button < BUTTONS) { return mouseHold[button]; }
        return false;
    } 

    bool Input::GetMouseButtonDown(int button) {
        if (button < BUTTONS) { return mouseDown[button]; }
        return false;
    }

    bool Input::GetMouseButtonUp(int button) {
        if (button < BUTTONS) { return mouseUp[button]; }
        return false;
    }

    // Static variables

    bool Input::mouseHold[BUTTONS];
    bool Input::mouseDown[BUTTONS];
    bool Input::mouseUp[BUTTONS];
    bool Input::isDragging;
    float Input::mouseScroll;

    Math::Vector2 Input::mousePos;
    Math::Vector2 Input::lastMousePos;
}
