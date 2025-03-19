#include "cfmath.h"

namespace cf {
    Vector2f::Vector2f(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Matrix::Matrix(int rows, int cols, float value = 0.0f) : rows(rows), cols(cols){
        data = new float[rows * cols];
        for(int i = 0; i < rows * cols; i++){
            data[i] = value;
        }
    }

    Matrix::~Matrix() {
        delete data;
    }

    Matrix::Row::Row(float* rowData, int cols) : rowData(rowData), cols(cols) {}

    float& Matrix::Row::operator[](int col) {
        return rowData[col];
    }

    const float& Matrix::Row::operator[](int col) const{
        return rowData[col];
    }

    Matrix::Row Matrix::operator[](int row){
        return Row(&data[row * cols], cols);
    }

    Matrix Matrix::operator*(Matrix& other){
        Matrix result(rows, other.cols);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < other.cols; j++){
                for(int k = 0; k < cols; k++) {
                    result[i][j] += (*this)[i][k] * other[k][j];
                }
            }
        }

        return result;
    }
}