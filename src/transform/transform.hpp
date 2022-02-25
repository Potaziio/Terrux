#pragma once

#include "../math/vector/vector.hpp"

#include "../../vendor/glm/glm/glm.hpp"
#include "../../vendor/glm/glm/gtc/matrix_transform.hpp"
#include "../../vendor/glm/glm/gtc/type_ptr.hpp"

namespace Terrux {
    namespace EntityProperties {
        class Transform {
            private:
                glm::mat4 transform;
            public:
                Math::Vector3 position;
                Math::Vector3 velocity;
                Math::Vector2 scale;

                Transform(Math::Vector3 position, Math::Vector2 scale);

                glm::mat4 GetTransformMat() { return transform; }
        };
    }
}
