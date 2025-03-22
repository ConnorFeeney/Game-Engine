#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include <cfmath.h>
#include <shader.h>

namespace cf {
    class BatchRenderer {
    public:
        BatchRenderer();
        ~BatchRenderer() = default;

        void cache(std::vector<Vector2f>& vertices, std::vector<unsigned int>& indecies);
        void setShader(Shader& Shader);

        void bind();
        void unbind();

        void render();
        void clear();
    private:
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;

        std::vector<float> vertices;
        std::vector<unsigned int> indecies;
        bool bufferUpdate = false;
        bool newFrame = true;

       Shader* shader;

       void clearCache();
    };
}