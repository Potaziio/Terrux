#pragma once

#include <iostream>

#include "../shader/shader.hpp"
#include "../util/color.hpp"
#include "../util/time.hpp"
#include "../window/window.hpp"
#include "../input/input.hpp"
#include "../math/math.hpp"
#include "../txgl/vao.hpp"
#include "../txgl/vbo.hpp"
#include "../txgl/ebo.hpp"

#include "../rect/ndcrect.hpp"

#include "../../vendor/glm/glm/glm.hpp"
#include "../../vendor/glm/glm/gtc/matrix_transform.hpp"
#include "../../vendor/glm/glm/gtc/type_ptr.hpp"

#define GLFW_INCLUDE_NONE
#include "../../vendor/glfw-3.3.5/include/GLFW/glfw3.h"
#include "../../vendor/glew-2.2.0/include/GL/glew.h"

using namespace Terrux::Utils;
using namespace Terrux::Math;
using namespace Terrux::TXGL;
using namespace Terrux::Drawing;

namespace Terrux {
    // Forward declaration
    class Window;

    struct Game {
        Window* window;

        void OnStart();
        void OnUpdate();
        void OnFixedUpdate();
        void OnExit();
    };
}
