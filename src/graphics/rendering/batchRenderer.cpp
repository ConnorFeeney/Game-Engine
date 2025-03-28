#include "batchRenderer.h"

namespace cf {

    void screenToNDC(Vector3f& v, int width, int height) {
        v.x = ((2 * v.x) / width) - 1;
        v.y = 1 - ((2 * v.y) / height);
    }

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

    void BatchRenderer::cache(std::vector<Vector3f> &vertices, std::vector<unsigned int> &indecies, int width, int height) {
        int indecieOffset = this->vertices.size();
        for(int i = 0; i < indecies.size(); i++) {
            this->indecies.push_back(indecies[i] + indecieOffset);
        }

        for(int i = 0; i < vertices.size(); i++){
            screenToNDC(vertices[i], width, height);
            std::vector<float> v = vertices[i].toFloat();
            this->vertices.insert(this->vertices.end(), v.begin(), v.end());
        }

        std::cout << "Vertices Cached: " << this->vertices.size() / 3 << " | Indices Cached: " << this->indecies.size() << "\n";

        std::cout << "Cached Vertices: ";
        for (const auto& vertex : this->vertices) {
            std::cout << vertex << " ";
        }
        std::cout << "\nCached Indices: ";
        for (const auto& index : this->indecies) {
            std::cout << index << " ";
        }
        std::cout << "\n";
        bufferUpdate = true;
    }

    void BatchRenderer::clearCache() {
        this->vertices.clear();
        this->indecies.clear();
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
            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indexDataSize, &indecies[0]);

            bufferUpdate = false;
        }

        glDrawElements(GL_TRIANGLES, indecies.size(), GL_UNSIGNED_INT, 0);
        this->clearCache();
        this->unbind();
    }
}