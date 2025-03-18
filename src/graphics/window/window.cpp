#include "window.h"

bool glfwIsInit = false;
bool gladIsInit = false;

namespace cf {
    Window::Window(const char* title, int width, int height, bool resizable){
        if(!glfwIsInit){
            if(!glfwInit()){
                throw std::runtime_error("ERR::GLFW::FAILED_INIT");
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            glfwIsInit = true;
        }

        glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);

        if(!window){
            glfwTerminate();
            throw std::runtime_error("ERR::GLFW::FAILED_WINDOW");
        }

        glfwMakeContextCurrent(window);

        if(!gladIsInit){
            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
                glfwTerminate();
                throw std::runtime_error("ERR::GLFW::FAILED_INIT");
            }

            gladIsInit = true;
        }

        glViewport(0, 0, width, height);

        renderer = BatchRenderer();
    }

    Window::~Window() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::bind() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void Window::unbind() {}

    void Window::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::resize(int width, int height){
        glfwSetWindowSize(window, width, height);
    }

    int Window::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    void Window::render() {
        this->clear();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}