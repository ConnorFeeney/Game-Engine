#pragma once

namespace cf {
    typedef struct Vector2f{
        float x;
        float y;

        Vector2f(float x, float y);
    } Vector2f;

    typedef struct Vector3f{
        float x;
        float y;
        float z;

        Vector3f(float x, float y, float z);
    } Vector3f;

    typedef struct Matrix {
        int rows;
        int cols;
        float* data;

        Matrix(int rows, int cols, float value = 0.0f);
        ~Matrix();

        typedef struct Row{
            float* rowData;
            int cols;

            Row(float* rowData, int cols);

            float& operator[](int col);

            const float& operator[](int col) const;
        } Row;

        Row operator[](int row);
        const Row operator[](int row) const;

        Matrix operator*(Matrix& other);
    } Matrix;
}