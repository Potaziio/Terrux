#pragma once

#include "../shader/shader.hpp"
#include "../util/color.hpp"

#include "../txgl/vao.hpp"
#include "../txgl/vbo.hpp"
#include "../txgl/ebo.hpp"
#include "../math/vector/vector.hpp"

#include "../transform/transform.hpp"

#include "../../vendor/glm/glm/glm.hpp"
#include "../../vendor/glm/glm/gtc/matrix_transform.hpp"
#include "../../vendor/glm/glm/gtc/type_ptr.hpp"

#include "../../vendor/glew-2.2.0/include/GL/glew.h"

namespace Terrux {
    namespace Drawing {
        class Rect {
            private:
                TXGL::VAO vao;
                TXGL::EBO ebo;
                TXGL::VBO vbo;

                glm::mat4 transform;

                float* vertices;
                unsigned int* indices;

                void genVertices();
                void genIndices();

            public:
                /* EntityProperties::Transform transform; */
                Utils::Shader* shader;
                Utils::RGBA_Color color;

                Math::Vector3 position;
                Math::Vector2 scale;

                Rect(float* vertices, int vsize, int voffset, 
                        unsigned int* indices, int isize, Utils::Shader* shader);
                Rect(Math::Vector3 position, Math::Vector2 scale, 
                        Utils::RGBA_Color color, Utils::Shader* shader);
                Rect();

                void calculateVelocity();
                void render();
                void free();
        };
    }
}

