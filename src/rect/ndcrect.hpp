#pragma once

#include <cstring>

#include "../shader/shader.hpp"
#include "../util/color.hpp"

#include "../txgl/vao.hpp"
#include "../txgl/vbo.hpp"
#include "../txgl/ebo.hpp"

#include "../math/vector/vector.hpp"

#include "../../vendor/glew-2.2.0/include/GL/glew.h"

namespace Terrux {
    namespace Drawing {
        class NDCRect {
            private:
                TXGL::VAO vao;
                TXGL::EBO ebo;
                TXGL::VBO vbo;

                float* vertices;
                unsigned int* indices;

                Utils::Shader* shader;

                void genVertices();
                void genIndices();
            public:
                Utils::RGBA_Color color;
                Math::Vector3 position;
                Math::Vector2 scale;

                NDCRect(float* vertices, int vsize, int voffset, 
                        unsigned int* indices, int isize, Utils::Shader* shader);

                NDCRect(Math::Vector3 position, Math::Vector2 scale,
                        Utils::RGBA_Color color, Utils::Shader* shader);

                NDCRect();

                
                void free();
                void render();
        };
    }
}
