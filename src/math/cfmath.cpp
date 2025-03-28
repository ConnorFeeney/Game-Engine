#include "cfmath.h"

namespace cf {
    Vector2f::Vector2f(float x, float y) : x(x), y(y) {}

    void Vector2f::print() const {
        std::cout << "[" << this->x << ", " << this->y << "]\n";
    }

    Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector3f::Vector3f(Vector2f v2, float z) : x(v2.x), y(v2.y), z(z) {}

    std::vector<float> Vector3f::toFloat() {
        std::vector<float> v;

        v.assign({this->x, this->y, this->z});

        return v;
    }

    void Vector3f::print() const {
        std::cout << "[" << this->x << ", " << this->y << ", " << this->z << "]\n";
    }

    template<typename T>
    Matrix<T>::Matrix(int rows, int cols, T value) : rows(rows), cols(cols) {
        data = new T[rows * cols];
        for(int i = 0; i < rows*cols; i++) {
            data[i] = value;
        }
    }

    template<typename T>
    Matrix<T>::~Matrix() {
        delete[] this->data;
    }    

    template<typename T>
    Matrix<T>::Row::Row(T* data, int cols) : data(data), cols(cols) {}

    template<typename T>
    typename Matrix<T>::Row Matrix<T>::operator[](int row) {
        if(row >= rows) {
            throw std::runtime_error("Row out of bounds");
        }
        return Row(this->data[row * cols], cols);
    }

    template<typename T>
    const typename  Matrix<T>::Row Matrix<T>::operator[](int row) const{
        if(row >= rows) {
            throw std::runtime_error("Row out of bounds");
        }
        return Row(this->data[row * cols], cols);
    }

    template<typename T>
    T& Matrix<T>::Row::operator[](int col) {
        if(col >= cols) {
            throw std::runtime_error("Cols out of bounds");
        }
        return this->data[col];
    }
    
    template<typename T>
    const T& Matrix<T>::Row::operator[](int col) const {
        if(col >= cols) {
            throw std::runtime_error("Cols out of bounds");
        }
        return this->data[col];
    }
}