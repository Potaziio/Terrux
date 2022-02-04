#include "window/window.hpp"

int main(int args, char* argc[]) {
    int width = 1600;
    int height = 900;

    if (args > 2) { 
        width = std::stoi(argc[1]);
        height = std::stoi(argc[2]);
    }

    Terrux::Window window = {
        .name = "Terrux 0.0.1 Linux-86_64",
        .width = width,
        .height = height,
        .swapInterval = 0,
        .color = Terrux::Utils::RGBA_Color(1.0f, 1.0f, 1.0f, 1.0f)
    };

    window.OnStart();
    window.OnUpdate();
    window.OnExit();

    return 0;
}
