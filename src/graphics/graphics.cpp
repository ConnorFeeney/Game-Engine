#include "graphics.h"

bool glfwIsInit = false;
bool gladIsInit = false;

cf::Window::Window(const char* name, uint16_t width, uint16_t height) {
    if (!glfwIsInit) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwIsInit = true;
    }

    window = glfwCreateWindow(width, height, name, NULL, NULL);
    if (!window) {
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window); // Attach OpenGL context

    if (!gladIsInit) {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("GLAD Failed to Init");
        }
        gladIsInit = true;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

cf::Window::~Window(){
    glfwSetWindowShouldClose(window, GLFW_TRUE);
    glfwTerminate();
}

void cf::Window::update(){
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool cf::Window::shouldClose(){
    return glfwWindowShouldClose(window);
}