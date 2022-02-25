#include "game.hpp"

namespace Terrux {
    void Game::OnStart() {
        window->color = RGBA_Color(1.0f, 1.0f, 1.0f, 1.0f);
        camera = new Camera(Vector3(0.0f, 0.0f, 0.0f), 75.0f, window->width, window->height, 0.1f, 100.0f);
        level->OnStart();
    }

    void Game::OnUpdate() {
        level->OnUpdate();
        camera->cameraMovement();
    }

    void Game::OnFixedUpdate() {
        level->OnFixedUpdate();
    }

    void Game::OnExit() {
        delete camera;
        level->OnExit();
    }
}
