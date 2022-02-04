#include "window.hpp"

namespace Terrux {
    void OnWindowResize(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);

        // Catch the window and change the width and height
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->width = width;
        win->height = height;
    }

    void Window::OnStart() {
        if (!glfwInit()) {
            std::cout << "ERROR::GLFW::INIT::FAILED" << std::endl;
            exit(EXIT_FAILURE);
        }

        window = glfwCreateWindow(width, height, (char*)name.c_str(), NULL, NULL);

        if (!window) {
            glfwTerminate();
            std::cout << "ERROR::GFLW::WINDOW::INIT::FAILED" << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);

        glfwSwapInterval(1);

        GLenum err;
        if ((err = glewInit()) != GLEW_OK) {
            std::cout << "ERROR::GLEW::INIT::FAILED" << std::endl;
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

        glEnable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Pass the window
        glfwSetWindowUserPointer(window, (void*)this);

        glfwSetFramebufferSizeCallback(window, OnWindowResize);
        glfwSetKeyCallback(window, Input::KeyCallback);
        glfwSetCursorPosCallback(window, Input::MouseCursorCallback);
        glfwSetScrollCallback(window, Input::MouseScrollCallback);
        glfwSetMouseButtonCallback(window, Input::MouseButtonCallback);

        srand(time(NULL));

        game = new Game();
    }

    void Window::OnUpdate() {
        const float timeDelta = 1000.0f/3000.0f;
        float dt = 0.0f;
        game->window = this;
        game->OnStart();

        while(!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(color.r, color.g, color.b, color.a);

            game->OnUpdate();

            if (dt > timeDelta) {
                game->OnFixedUpdate();
                dt = 0.0f;
            }

            dt += Time::deltaTime();

            if (Input::GetKeyDown(GLFW_KEY_ESCAPE)) {
                break;
            }

            glfwSwapBuffers(window);

            Input::endKeyFrame();
            Input::endMouseFrame();
            Utils::Time time;

            glfwPollEvents();
        }
    }

    void Window::OnExit() {
        std::cout << "Exiting..." << std::endl;
        game->OnExit();
        glfwTerminate();
        delete game;
    }

    void Window::ChangeWindowName(std::string name) {
        glfwSetWindowTitle(window, (char*)name.c_str());
        name = name;
    }
}
