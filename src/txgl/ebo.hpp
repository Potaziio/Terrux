#pragma once

#include "../../vendor/glew-2.2.0/include/GL/glew.h"

namespace Terrux {
    namespace TXGL {
        struct EBO {
            unsigned int* ebo;
            void generate();
            void bind();
            void sendData(GLsizeiptr size, const void* data, GLenum usage);
            void free();
        };
    }
}
