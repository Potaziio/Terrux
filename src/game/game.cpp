#include "game.hpp"

namespace Terrux {
    Shader shader;

    float vertices[] = {
       -1.0f,  1.0f,  0.0f,  0.07f,  0.674f, 0.98f, 1.0f,  // Top Left
        1.0f,  1.0f,  0.0f,  0.07f,  0.674f, 0.98f, 1.0f,  // Top Right
       -1.0f, -1.0f,  0.0f,  1.30f,  0.862f, 1.0f,  1.0f,  // Bottom Left
        1.0f, -1.0f,  0.0f,  1.30f,  0.862f, 1.0f,  1.0f  // Bottom Right
    };

    unsigned int indices[] = {
        0, 2, 1, 3, 2, 1
    };

    NDCRect sky;

    void Game::OnStart() {
        window->color = RGBA_Color(1.0f, 1.0f, 1.0f, 1.0f);
        shader.load("../assets/shaders/vertex/sky.glsl", "../assets/shaders/fragment/sky.glsl");

        sky = NDCRect(vertices, 28, 7, indices, 6, &shader);
    }

    void Game::OnUpdate() {
        sky.render();
    }

    void Game::OnFixedUpdate() {
    }

    void Game::OnExit() {
        sky.free();
        shader.free();
    }
}
