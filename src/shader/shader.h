#define GLSL(src) "#version 460\n" #src "\n"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace cf {
    class Shader {
    public:
        Shader() = default;
        Shader(const char* vertexSrc, const char* fragmentSrc);
        ~Shader();

        void bind();
        void unbind();
    private:
        GLuint shader;
    };
}