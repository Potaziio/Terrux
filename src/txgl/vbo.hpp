#pragma once 

#include "../../vendor/glew-2.2.0/include/GL/glew.h"

namespace Terrux {
    namespace TXGL {
        struct VBO {
            unsigned int* vbo;
            void generate();
            void bind();
            void sendData(GLsizeiptr size, const void* data, GLenum usage);
            void free();
        };
    }
}
