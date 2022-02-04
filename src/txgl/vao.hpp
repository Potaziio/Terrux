#pragma once

#include "../../vendor/glew-2.2.0/include/GL/glew.h"

namespace Terrux {
    namespace TXGL {
        struct VAO {
            unsigned int* vao;
            void generate();
            void bind();
            void unbind();
            void enableAttribPtr(int index);
            void disableAttribPtr(int index);
            void attribPtr(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, size_t offset);
            void free();
        };
    }
}
