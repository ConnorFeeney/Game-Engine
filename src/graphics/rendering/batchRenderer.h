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

        void cache(std::vector<Vector3f>& vertices, std::vector<unsigned int>& indecies, int width, int height);
        void setShader(Shader& Shader);

        void bind();
        void unbind();

        void render();
    private:
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;

        std::vector<float> vertices;
        std::vector<unsigned int> indecies;
        bool bufferUpdate = false;

       Shader* shader;

       void clearCache();
    };
}