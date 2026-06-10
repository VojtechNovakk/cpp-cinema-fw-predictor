#pragma once

#include <stdexcept>
#include <vector>
#include <cstddef>

class Matrix {
private:
    size_t m_Rows;
    size_t m_Cols;
    std::vector<double> m_Values;
public:
    Matrix(size_t r, size_t c) : m_Rows(r), m_Cols(c), m_Values(r*c, 0.0) {}
    ~Matrix() = default;
    Matrix(const Matrix& other) : m_Rows(other.m_Rows), m_Cols(other.m_Cols), m_Values(other.m_Values) {}
    Matrix& operator=(Matrix other) {
        std::swap(m_Rows, other.m_Rows);
        std::swap(m_Cols, other.m_Cols);
        std::swap(m_Values, other.m_Values);
        return *this;
    }
    size_t rows() const { return m_Rows; }
    size_t cols() const { return m_Cols; }
    double& operator()(size_t r, size_t c) {
        if (r >= m_Rows || c >= m_Cols)
            throw std::out_of_range("Cannot find value with this index!");
        return m_Values[m_Cols*r+c];
    }
    const double& operator()(size_t r, size_t c) const{
        if (r >= m_Rows || c >= m_Cols)
            throw std::out_of_range("Cannot find value with this index!");
        return m_Values[m_Cols*r+c];
    }
};