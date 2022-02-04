#include "ebo.hpp"

namespace Terrux::TXGL {
    void EBO::generate() {
        ebo = new unsigned int;
        glGenBuffers(1, ebo);
    }
    
    void EBO::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    }

    void EBO::sendData(GLsizeiptr size, const void* data, GLenum usage) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
    }

    void EBO::free() {
        glDeleteBuffers(1, ebo);
        delete ebo;
    }
}
