#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <unordered_map>
#include <string>
#include <filesystem>

namespace CF {
    class Shader {
    private:
        std::unordered_map<std::string, int> shaders;
    public:
        Shader();
        ~Shader();

        int createProgram(const char *name, const char *vertexSrc, const char *fragmentSrc);
        int createProgram(const char *name, const char *vertexSrc, const char *geomSrc, const char *fragmentSrc);

        void useProgram(const char *name);
    };
} // namespace CF

#endif //!SHADER_H