#pragma once

#include "../math/vector/vector.hpp"

#include "../input/input.hpp"
#include "../util/time.hpp"

#include "../../vendor/glm/glm/glm.hpp"
#include "../../vendor/glm/glm/gtc/matrix_transform.hpp"
#include "../../vendor/glm/glm/gtc/type_ptr.hpp"

namespace Terrux {
    class Camera {
        private:
            glm::mat4 viewMatrix, projectionMatrix;
            glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
            glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        public:
            float fov;
            float aspect;

            float near;
            float far;

            Math::Vector3 position;

            Camera(Math::Vector3 pos, float fov, float x, float y, float near, float far);

            void cameraMovement();
            void update();
            void updateAspect(float aspect);

            glm::mat4 GetViewMatrix();
            glm::mat4 GetProjectionMatrix();
    };
}
