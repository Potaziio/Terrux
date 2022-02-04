#pragma once

#define RGBANORM(x, y, z, w) x / 255.0f, y / 255.0f, z / 255.0f, w / 255.0f
#define RGBNORM(x, y, z) x / 255.0f, y / 255.0f, z / 255.0f

#define unimplemented() printf("This function '%s' is unimplemented...", __FUNCTION__); \
    exit(1)

namespace Terrux {
    namespace Utils {

        struct RGB_Color {
            float r;
            float g;
            float b;

            RGB_Color(float r, float g, float b);
            RGB_Color();
        };

        struct RGBA_Color{
            float r;
            float g;
            float b;
            float a;

            RGBA_Color(float r, float g, float b, float a);
            RGBA_Color();
        };
    }
}
