#include "vbo.hpp"

namespace Terrux::TXGL {
    void VBO::generate() {
        vbo = new unsigned int;
        glGenBuffers(1, vbo);
    }
    
    void VBO::bind() {
        glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    }

    void VBO::sendData(GLsizeiptr size, const void* data, GLenum usage) {
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    void VBO::free() {
        glDeleteBuffers(1, vbo);
        delete vbo;
    }
}
