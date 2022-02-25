#include "sky.hpp"

namespace Terrux::Objects::Ambient {
    float skyVertices[] = { 
        -1.0f,  1.0f,  0.0f,  0.07f,  0.674f, 0.98f, 1.0f,  // Top Left
        1.0f,  1.0f,  0.0f,  0.07f,  0.674f, 0.98f, 1.0f,  // Top Right
        -1.0f, -1.0f,  0.0f,  1.30f,  0.862f, 1.0f,  1.0f,  // Bottom Left
        1.0f, -1.0f,  0.0f,  1.30f,  0.862f, 1.0f,  1.0f  // Bottom Right
    };

    unsigned int skyIndices[] = {
        0, 2, 1, 3, 2, 1
    };

    void Sky::SkyStart() {
        shader.load("../assets/shaders/vertex/sky.glsl", 
                "../assets/shaders/fragment/sky.glsl");

        rect = Drawing::NDCRect(skyVertices, 28, 7, skyIndices, 6, &shader);
    }
}
