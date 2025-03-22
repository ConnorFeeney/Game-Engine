#include "shader.h"

namespace cf {
    GLuint compileShader(const char* src, GLenum type, char infoLog[512], GLint* param) {
        GLuint shader;

        shader = glCreateShader(type);
        glShaderSource(shader, 1, &src, NULL);
        glCompileShader(shader);

        glGetShaderiv(shader, GL_COMPILE_STATUS, param);
        if(!(*param)) {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
        }

        return shader;
    }

    GLuint linkShader(GLuint vertex, GLuint fragment, char infoLog[512], GLint* param) {
        GLuint ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);

        glGetProgramiv(ID, GL_LINK_STATUS, param);
        if(!(*param)) {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
        }

        return ID;
    }

    Shader::Shader(const char* vertexSrc, const char* fragmentSrc) {
        GLuint vertex, fragment;
        char infoLog[512];
        int success;

        vertex = compileShader(vertexSrc, GL_VERTEX_SHADER, infoLog, &success);
        if(!success) {
            std::cout << "ERR::VERTEX::FAILED_COMPILE\n" << infoLog << "\n";
        }

        fragment = compileShader(fragmentSrc, GL_FRAGMENT_SHADER, infoLog, &success);
        if(!success) {
            std::cout << "ERR::FRAGMENT::FAILED_COMPILE\n" << infoLog << "\n";
        }

        GLuint shader;
        shader = linkShader(vertex, fragment, infoLog, &success);
        if(!success) {
            std::cout << "ERR::SHADER::LINK_FAILED\n" << infoLog << "\n";
        }

        this->shader = shader;

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void Shader::bind() {
        glUseProgram(shader);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }
}