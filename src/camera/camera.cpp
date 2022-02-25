#include "camera.hpp"

namespace Terrux {
    Camera::Camera(Math::Vector3 pos, float fov, float x, float y, float near, float far)
    : position(pos), fov(fov), aspect(x/y), near(near), far(far)
    {
        viewMatrix = glm::mat4(1.0f);
        viewMatrix = glm::lookAt(glm::vec3(pos.x, pos.y, pos.z), cameraFront + glm::vec3(pos.x, pos.y, pos.z), cameraUp);

        projectionMatrix = glm::mat4(1.0f);
        projectionMatrix = glm::perspective(glm::radians(fov), x / y, near, far);
    }

    void Camera::update() {
        viewMatrix = glm::mat4(1.0f);
        viewMatrix = glm::lookAt(glm::vec3(position.x, position.y, position.z), 
                cameraFront + glm::vec3(position.x, position.y, position.z), cameraUp);

        projectionMatrix = glm::mat4(1.0f);
        projectionMatrix = glm::perspective(glm::radians(fov), aspect, near, far);
    }
    
    void Camera::updateAspect(float aspect) {
        this->aspect = aspect;
    }

    glm::mat4 Camera::GetViewMatrix() {
        return viewMatrix;
    }

    glm::mat4 Camera::GetProjectionMatrix() {
        return projectionMatrix;
    }
    
    void Camera::cameraMovement() {
        float zoomOffset = Input::GetMouseScroll();
        fov -= zoomOffset * Utils::Time::deltaTime() * 2000.0f;
    }
}
