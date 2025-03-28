#pragma once

#include <stdexcept>
#include <iostream>
#include <vector>

namespace cf {
    typedef struct Vector2f {
        float x;
        float y;

        Vector2f(float x, float y);

        void print() const;
    } Vector2f;

    typedef struct Vector3f {
        float x;
        float y;
        float z;

        Vector3f(float x, float y, float z);
        Vector3f(Vector2f v2, float z);

        std::vector<float> toFloat();

        void print() const;
    } Vector3f;

    template <typename T = float> struct Matrix {
        T* data;
        const int rows;
        const int cols;

        Matrix<T>(int rows, int cols, T value = T(0));
        ~Matrix();

        struct Row {
            T* data;
            int cols;

            Row(T* data, int cols);

            T& operator[](int col);
            const T& operator[](int col) const;

            void print() const;
        };

        Row operator[](int row);
        const Row operator[](int row) const;

        void print() const;
    };
}