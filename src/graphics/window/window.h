#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

#include <rendering/renderTarget.h>


namespace cf {
    class Window : public RenderTarget {
    public:
        Window(const char* title, int width, int height, bool resizable = false);
        ~Window();

        void bind() override;
        void unbind() override;

        void clear() override;
        void resize(int width, int height) override;

        void draw(Drawable& drawable) override {};

        void render() override;

        int shouldClose(); 
    private:
        GLFWwindow* window;
    };
}