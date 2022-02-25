#pragma once 

#include <iostream>
#include <vector>

#include "ambient/sky.hpp"
#include "../../rect/ndcrect.hpp"
#include "../../rect/rect.hpp"
#include "../../shader/shader.hpp"
#include "../../input/input.hpp"
#include "../../util/time.hpp"
#include "../game.hpp"

using namespace Terrux::Drawing;
using namespace Terrux::Math;
using namespace Terrux::Utils;

namespace Terrux {
    class Game;

    struct Level {
        Game* game;
        std::vector<Drawing::Rect*> DynamicRects;
        std::vector<Drawing::NDCRect*> StaticRects;

        void OnStart();
        void OnUpdate();
        void OnFixedUpdate();
        void OnExit();
    };
}
