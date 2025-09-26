#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

/**
 * @brief Структура матрицы
 */
struct Matrix {
    double** data;  // двумерный массив данных
    int rows;       // количество строк
    int cols;       // количество столбцов
    
    /**
     * @brief Конструктор по умолчанию
     */
    Matrix() : data(nullptr), rows(0), cols(0) {}
};

// Базовые операции
Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix& m);
Matrix matrix_add(const Matrix& a, const Matrix& b);
Matrix matrix_multiply(const Matrix& a, const Matrix& b);
Matrix matrix_transpose(const Matrix& m);
Matrix matrix_add_scalar(const Matrix& m, double value); // Новая функция

// Вспомогательные функции
void print_matrix(const Matrix& m);
Matrix matrix_from_array(double* data, int rows, int cols);

#endif