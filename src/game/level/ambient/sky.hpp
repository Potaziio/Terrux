#include <iostream>

#include "../../../core/tcore.hpp"

namespace Terrux {
    namespace Objects {
        namespace Ambient {
            class Sky {
                public:
                    void SkyStart();
                    Drawing::NDCRect rect;

                private:
                    Utils::Shader shader;
            };
        }
    }
}
