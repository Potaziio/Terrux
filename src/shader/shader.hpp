#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../../vendor/glew-2.2.0/include/GL/glew.h"

#include "../../vendor/glm/glm/glm.hpp"
#include "../../vendor/glm/glm/gtc/matrix_transform.hpp"
#include "../../vendor/glm/glm/gtc/type_ptr.hpp"

namespace Terrux {
    namespace Utils {
        class Shader {
            private:
                unsigned int shaderProgram;
                std::string vPath;
                std::string fPath;
                bool beingUsed;
                std::string shaderSources[2];
                char* fragmentSource;
                char* vertexSource;
                unsigned int vertexShader;
                unsigned int fragmentShader;
            public:
                Shader();
                void load(std::string vpath, std::string fpath);
                void use();
                void compile();
                void detach();
                void free();
                unsigned int getProgram();
                std::string getFragPath();
                std::string getVertPath();

                void sendFloat(const char* varName, float val);
                void sendInt(const char* varName, int val);
                void sendMat4(const char* varName, glm::mat4 mat);
                void sendMat3(const char* varName, glm::mat3 mat);
                void sendMat2(const char* varName, glm::mat2 mat);
        };
    }
}
