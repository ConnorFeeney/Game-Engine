#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char** argv){
    if(!glfwInit()){
        std::cout << "ERR::GLFW::FAILED_TO_INIT\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "window", NULL, NULL);
    glfwMakeContextCurrent(window);

    int version = gladLoadGL();
    if(version == 0){
        std::cout << "ERR::GLAD::FAILED_TO_LOAD\n";
        return -1;
    }

    glClearColor(0, 0, 0, 0);
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}