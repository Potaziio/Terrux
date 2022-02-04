#include "ndcrect.hpp"

namespace Terrux::Drawing {
    void NDCRect::genVertices() {
        vertices = new float[28];
        vertices[0] = position.x;
        vertices[1] = position.y;
        vertices[2] = position.z;
        
        vertices[3] = color.r;
        vertices[4] = color.g;
        vertices[5] = color.b;
        vertices[6] = color.a;

        vertices[7] = position.x + scale.x;
        vertices[8] = position.y;
        vertices[9] = position.z;

        vertices[10] = color.r;
        vertices[11] = color.g;
        vertices[12] = color.b;
        vertices[13] = color.a;

        vertices[14] = position.x;
        vertices[15] = position.y - scale.y;
        vertices[16] = position.z;

        vertices[17] = color.r;
        vertices[18] = color.g;
        vertices[19] = color.b;
        vertices[20] = color.a;

        vertices[21] = position.x + scale.x;
        vertices[22] = position.y - scale.y;
        vertices[23] = position.z;

        vertices[24] = color.r;
        vertices[25] = color.g;
        vertices[26] = color.b;
        vertices[27] = color.a;
    }

    void NDCRect::genIndices() {
        indices = new unsigned int[6];
        indices[0] = 0;
        indices[1] = 2;
        indices[2] = 1;
        
        indices[3] = 3;
        indices[4] = 2;
        indices[5] = 1;
    }

    NDCRect::NDCRect() {}

    NDCRect::NDCRect(Math::Vector3 position, Math::Vector2 scale, Utils::RGBA_Color color, Utils::Shader* shader) 
    : position(position), scale(scale), color(color), shader(shader)
    {
        genIndices();
        genVertices();

        vao.generate();
        vbo.generate();
        ebo.generate();

        vao.bind();

        vbo.bind();
        vbo.sendData(sizeof(float) * 28, vertices, GL_STATIC_DRAW);

        ebo.bind();
        ebo.sendData(sizeof(unsigned int) * 6, indices, GL_STATIC_DRAW);

        vao.attribPtr(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
        vao.attribPtr(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), sizeof(float) * 3);
    }

    NDCRect::NDCRect(float* vertices, int vsize, int voffset, unsigned int* indices, int isize, Utils::Shader* shader)
    : shader(shader), position(Math::Vector3()), scale(Math::Vector2()), color(Utils::RGBA_Color())
    {
        this->vertices = new float[vsize];
        this->indices = new unsigned int[isize];

        std::copy(vertices, vertices + vsize, this->vertices);
        std::copy(indices, indices + isize, this->indices);

        vao.generate();
        vbo.generate();
        ebo.generate();

        vao.bind();
        vbo.bind();
        vbo.sendData(sizeof(float) * vsize, this->vertices, GL_STATIC_DRAW);

        ebo.bind();
        ebo.sendData(sizeof(unsigned int) * isize, this->indices, GL_STATIC_DRAW);

        vao.attribPtr(0, 3, GL_FLOAT, GL_FALSE, voffset * sizeof(float), 0);
        vao.attribPtr(1, 4, GL_FLOAT, GL_FALSE, voffset * sizeof(float), sizeof(float) * 3);
    }

    void NDCRect::render() {
        vao.bind();
        shader->use();
        vao.enableAttribPtr(0);
        vao.enableAttribPtr(1);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        vao.disableAttribPtr(0);
        vao.disableAttribPtr(1);
        shader->detach();
        vao.unbind();
    }

    void NDCRect::free() {
        vbo.free();
        vao.free();
        ebo.free();

        delete indices;
        delete vertices;
    }
}
