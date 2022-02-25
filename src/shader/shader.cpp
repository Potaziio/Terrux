#include "shader.hpp"

namespace Terrux {
    namespace Utils {
        Shader::Shader() {}

        void Shader::compile() {
            // ===============================
            // VERTEX SHADER
            // ===============================

            vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vertexSource, NULL);
            glCompileShader(vertexShader);

            int success;
            char infoLog[512];
            glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

            if (!success) {
                glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
                exit(EXIT_FAILURE);
            }

            // ===============================
            // FRAGMENT SHADER
            // ===============================

            fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
            glCompileShader(fragmentShader);

            glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

            if (!success) {
                glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
                exit(EXIT_FAILURE);
            }

            shaderProgram = glCreateProgram();

            glAttachShader(shaderProgram, vertexShader);
            glAttachShader(shaderProgram, fragmentShader);
            glLinkProgram(shaderProgram);

            glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

            if (!success) {
                glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
                exit(EXIT_FAILURE);
            }

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

        }

        void Shader::load(std::string vpath, std::string fpath) {
            std::string myText;

            std::ifstream VertexFile(vpath);
            std::ifstream FragmentFile(fpath);

            if (VertexFile && FragmentFile) {
                vPath = vpath;
                fPath = fpath;
            } else {
                std::cout << "ERROR::SHADER::FILE::NOT::FOUND" << std::endl;
            }

            while (getline(VertexFile, myText)) {
                shaderSources[0] += myText;
                shaderSources[0] += "\n";
            }

            while (getline(FragmentFile, myText)) {
                shaderSources[1] += myText;
                shaderSources[1] += "\n";
            }

            vertexSource = (char*)shaderSources[0].c_str();
            fragmentSource = (char*)shaderSources[1].c_str();

            VertexFile.close();
            FragmentFile.close();

            compile();
        }

        void Shader::use() {
            if (!beingUsed) {
                glUseProgram(shaderProgram);
                beingUsed = true;
            }
        }

        void Shader::detach() {
            beingUsed = false;
            glUseProgram(0);
        }

        void Shader::free() {
            glDeleteProgram(shaderProgram);
            printf("Deleting shader: %s, %s\n", vPath.c_str(), fPath.c_str());
        }

        unsigned int Shader::getProgram() {
            return shaderProgram;
        }

        // Sending info methods

        void Shader::sendMat4(const char* name, glm::mat4 mat) {
            use();
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name), 1, GL_FALSE, glm::value_ptr(mat));
        }

        void Shader::sendFloat(const char* name, float val) {
            use();
            glUniform1f(glGetUniformLocation(shaderProgram, name), val);
        }

        void Shader::sendInt(const char* name, int val) {
            use();
            glUniform1i(glGetUniformLocation(shaderProgram, name), val);
        }
    }
}
