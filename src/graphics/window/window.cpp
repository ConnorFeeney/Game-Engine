#include "window.h"

bool glfwIsInit = false;
unsigned int windowCount = 0;

namespace cf {
    Window::Window(const char* title, int width, int height, bool resizable) : width(width), height(height) {
        if (!glfwIsInit) {
            if (!glfwInit()) {
                throw std::runtime_error("ERR::GLFW::FAILED_INIT");
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            glfwIsInit = true;
        }

        glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);

        if (!window) {
            glfwTerminate();
            throw std::runtime_error("ERR::GLFW::FAILED_WINDOW");
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
            throw std::runtime_error("ERR::GLFW::FAILED_INIT_GLAD");
        }

        glViewport(0, 0, width, height);

        renderer = new BatchRenderer();
        windowCount++;
    }

    Window::~Window() {
        glfwDestroyWindow(window);
        windowCount--;

        if (windowCount <= 0) {
            glfwTerminate();
            glfwIsInit = false;
        }
    }

    void Window::bind() {
        glfwMakeContextCurrent(window);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void Window::unbind() {
        glfwMakeContextCurrent(nullptr);
    }

    void Window::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::resize(int width, int height) {
        glfwSetWindowSize(window, width, height);
    }

    int Window::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    void Window::draw(Drawable& drawable) {
        renderer->cache(drawable.getVertecies(), drawable.getIndecies(), width, height);
    }

    void Window::render() {
        this->bind();
        //this->clear();

        renderer->render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}