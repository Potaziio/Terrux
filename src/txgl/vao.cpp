#include "vao.hpp"

namespace Terrux::TXGL {
    void VAO::generate() {
        vao = new unsigned int;
        glGenVertexArrays(1, vao);
    }

    void VAO::bind() {
        glBindVertexArray(*vao);
    }

    void VAO::unbind() {
        glBindVertexArray(0);
    }
    
    void VAO::attribPtr(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, size_t offset) {
        glVertexAttribPointer(index, size, type, normalized, stride, (void*)offset);
        glEnableVertexAttribArray(index);
    }

    void VAO::enableAttribPtr(int index) {
        glEnableVertexAttribArray(index);
    }
    
    void VAO::disableAttribPtr(int index) {
        glDisableVertexAttribArray(index);
    }

    void VAO::free() {
        glDeleteVertexArrays(1, vao);
        delete vao;
    }
}
