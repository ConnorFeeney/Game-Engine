#include "batchRenderer.h"

namespace cf {
    BatchRenderer::BatchRenderer() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        const char* vertexSrc = GLSL(
            layout (location = 0) in vec3 aPos;

            void main() {
                gl_Position = vec4(aPos, 1.0);
            }
        );

        const char* fragmentSRC = GLSL(
            out vec4 FragColor;

            void main() {
                FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
            }
        );

        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4092, nullptr, GL_DYNAMIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 4092, nullptr, GL_DYNAMIC_DRAW);

        shader = new Shader(vertexSrc, fragmentSRC);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindVertexArray(0);
    }

    void BatchRenderer::cache(std::vector<Vector2f>& vertices, std::vector<unsigned int>& indecies) {
        if(newFrame){
            this->vertices.clear();
            this->indecies.clear();
        }

        std::vector<float> vert;
        vert.reserve(sizeof(float) * vertices.size() * 3);

        for(int i = 0; i < vertices.size(); i++){
            vert.push_back(vertices[i].x);
            vert.push_back(vertices[i].y);
            vert.push_back(0);
        }

        this->vertices.insert(this->vertices.end(), vert.begin(), vert.end());
        
        for(int i = 0; i < indecies.size(); i++){
            this->indecies.push_back(indecies[i] + this->indecies.size());
        }

        bufferUpdate = true;
    }

    void BatchRenderer::bind() {
        glBindVertexArray(VAO);
        shader->bind();
    }

    void BatchRenderer::unbind() {
        glBindVertexArray(0);
        shader->unbind();
    }

    void BatchRenderer::render() {
        this->bind();
        if(bufferUpdate) {
            int vertexDataSize = sizeof(float) * vertices.size();
            GLint vertextBufferSize;

            glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &vertextBufferSize);

            if(vertexDataSize > vertextBufferSize){
                glBufferData(GL_ARRAY_BUFFER, vertexDataSize * 2, nullptr, GL_DYNAMIC_DRAW);
            } else if(vertexDataSize < vertextBufferSize / 4) {
                glBufferData(GL_ARRAY_BUFFER, vertexDataSize, nullptr, GL_DYNAMIC_DRAW);
            }

            int indexDataSize = sizeof(float) * indecies.size();
            GLint indexBufferSize;

            glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &indexBufferSize);

            if(indexDataSize > indexBufferSize){
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexDataSize * 2, nullptr, GL_DYNAMIC_DRAW);
            } else if(indexDataSize < indexBufferSize / 4) {
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexDataSize, nullptr, GL_DYNAMIC_DRAW);
            }

            glBufferSubData(GL_ARRAY_BUFFER, 0, vertexDataSize, &vertices[0]);
            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indexBufferSize, &indecies[0]);

            bufferUpdate = false;
        }

        glDrawElements(GL_TRIANGLES, indecies.size(), GL_UNSIGNED_INT, 0);
        this->unbind();
    }
}