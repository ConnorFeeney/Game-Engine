#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../shader/shader.h"

namespace cf
{
    class Renderable{
    private:
        int x;
        int y;
    public:
        virtual void draw() const;
        virtual void translate();
        virtual void rotate();
    };

    class Window {
    private:
        GLFWwindow* window;
    public:
        Window(const char* name, uint16_t width, uint16_t height);
        ~Window();

        void update();

        void render(Renderable* r);

        bool shouldClose();
    };
} // namespace CF

#endif //!GRAPHICS_H