#include "rect.hpp"

namespace Terrux::Drawing {
    void Rect::genVertices() {
        vertices = new float[28];

        vertices[0] = 0.0f;
        vertices[1] = 0.0f;
        vertices[2] = 0.0f;

        vertices[3] = color.r;
        vertices[4] = color.g;
        vertices[5] = color.b;
        vertices[6] = color.a;

        vertices[7] = 1.0f;
        vertices[8] = 0.0f;
        vertices[9] = 0.0f;

        vertices[10] = color.r;
        vertices[11] = color.g;
        vertices[12] = color.b;
        vertices[13] = color.a;

        vertices[14] = 0.0f;
        vertices[15] = -1.0f;
        vertices[16] = 0.0f;

        vertices[17] = color.r;
        vertices[18] = color.g;
        vertices[19] = color.b;
        vertices[20] = color.a;

        vertices[21] = 1.0f;
        vertices[22] = -1.0f;
        vertices[23] = 0.0f;

        vertices[24] = color.r;
        vertices[25] = color.g;
        vertices[26] = color.b;
        vertices[27] = color.a;
    }

    void Rect::genIndices() {
        indices = new unsigned int[6];
        indices[0] = 0;
        indices[1] = 2;
        indices[2] = 1;

        indices[3] = 3;
        indices[4] = 2;
        indices[5] = 1;
    }

    Rect::Rect() {}

    Rect::Rect(Math::Vector3 position, Math::Vector2 scale, Utils::RGBA_Color color, Utils::Shader* shader) 
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

    Rect::Rect(float* vertices, int vsize, int voffset, unsigned int* indices, int isize, Utils::Shader* shader)
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

    void Rect::render() {
        vao.bind();

        shader->use();

        vao.enableAttribPtr(0);
        vao.enableAttribPtr(1);

        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(position.x, position.y, position.z));
        transform = glm::scale(transform, glm::vec3(scale.x, scale.y, 0.0f));

        shader->sendMat4("model", transform);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        vao.disableAttribPtr(0);
        vao.disableAttribPtr(1);

        shader->detach();
        vao.unbind();
    }

    void Rect::free() {
        vbo.free();
        vao.free();
        ebo.free();

        delete indices;
        delete vertices;
    }
}
