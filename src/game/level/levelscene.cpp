#include "levelscene.hpp"

namespace Terrux {
    Shader meshShader;

    Rect player;
    Rect ground;

    Objects::Ambient::Sky sky;

    void Level::OnStart() {
        meshShader.load("../assets/shaders/vertex/rect.glsl", 
                "../assets/shaders/fragment/rect.glsl");

        player = Rect(Vector3(0.0f, 0.0f, -5.0f), Vector2(0.3f, 0.3f), 
                RGBA_Color(1.0f, 0.0f, 0.0f, 1.0f), &meshShader);

        ground = Rect(Vector3(-6.0f, -2.9f, -4.0f), Vector2(12.0f, 0.2f),
                RGBA_Color(RGBANORM(0.0f, 255.0f, 0.0f, 255.0f)), &meshShader);

        sky.SkyStart();

        DynamicRects.push_back(&player);
        DynamicRects.push_back(&ground);
        StaticRects.push_back(&sky.rect);
    }

    void Level::OnUpdate() {
        for (int i = 0; i < StaticRects.size(); ++i) {
            StaticRects[i]->render(); 
        } 

        for (int i = 0; i < DynamicRects.size(); ++i) {
            DynamicRects[i]->render(); 
        }

        Vector2 movement = Vector2(Input::GetAxisRaw("Horizontal"), 
                Input::GetAxisRaw("Vertical"));
        movement.Normalize();

        player.position += Vector3(movement * Time::deltaTime() * 5.0f, 0.0f);

        game->camera->position = Vector3::Lerp(game->camera->position, 
                Vector3(player.position.x, player.position.y, 0.0f)
                + Vector3(movement.x, movement.y, 0.0f), 
                1.0f * Time::deltaTime());

        meshShader.sendMat4("projection", game->camera->GetProjectionMatrix());
        meshShader.sendMat4("view", game->camera->GetViewMatrix());
        game->camera->update();
        meshShader.detach();
    }

    void Level::OnFixedUpdate() {

    }

    void Level::OnExit() {
        for (int i = 0; i < StaticRects.size(); ++i) {
            StaticRects[i]->free(); 
        } 

        for (int i = 0; i < DynamicRects.size(); ++i) {
            DynamicRects[i]->free(); 
        }
    }
}
