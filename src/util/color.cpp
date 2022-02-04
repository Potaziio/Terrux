#include "color.hpp"

namespace Terrux::Utils {
    RGBA_Color::RGBA_Color(float r, float g, float b, float a): r(r), g(g), b(b), a(a) {}
    RGBA_Color::RGBA_Color(): r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
    RGB_Color::RGB_Color(float r, float g, float b): r(r), g(g), b(b) {}
    RGB_Color::RGB_Color(): r(0.0f), g(0.0f), b(0.0f) {}
}
