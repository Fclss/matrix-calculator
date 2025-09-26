#include "matrix.h"
#include <cassert>
#include <iostream>

void test_create_and_free() {
    std::cout << "Testing create_matrix and free_matrix..." << std::endl;
    
    // Тест создания нормальной матрицы
    Matrix m = create_matrix(3, 4);
    assert(m.rows == 3);
    assert(m.cols == 4);
    assert(m.data != nullptr);
    
    // Проверка инициализации нулями
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            assert(m.data[i][j] == 0.0);
        }
    }
    
    free_matrix(m);
    assert(m.data == nullptr);
    assert(m.rows == 0);
    assert(m.cols == 0);
    
    // Тест создания матрицы с невалидными размерами
    try {
        create_matrix(-1, 5); // Убрали переменную invalid
        assert(false); // Не должно сюда попасть
    } catch (const std::exception& e) {
        assert(std::string(e.what()) == "Matrix dimensions must be positive integers");
    }
    
    std::cout << "create_and_free tests passed!" << std::endl;
}

void test_matrix_addition() {
    std::cout << "Testing matrix addition..." << std::endl;
    
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    // Заполнение тестовыми данными
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;
    
    Matrix result = matrix_add(A, B);
    
    assert(result.data[0][0] == 6);  // 1+5
    assert(result.data[0][1] == 8);  // 2+6
    assert(result.data[1][0] == 10); // 3+7
    assert(result.data[1][1] == 12); // 4+8
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
    
    std::cout << "addition tests passed!" << std::endl;
}

void test_matrix_multiplication() {
    std::cout << "Testing matrix multiplication..." << std::endl;
    
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;
    
    Matrix result = matrix_multiply(A, B);
    
    assert(result.data[0][0] == 19); // 1*5 + 2*7
    assert(result.data[0][1] == 22); // 1*6 + 2*8
    assert(result.data[1][0] == 43); // 3*5 + 4*7
    assert(result.data[1][1] == 50); // 3*6 + 4*8
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
    
    std::cout << "multiplication tests passed!" << std::endl;
}

void test_matrix_transpose() {
    std::cout << "Testing matrix transpose..." << std::endl;
    
    Matrix A = create_matrix(2, 3);
    
    // Заполнение: [[1, 2, 3], [4, 5, 6]]
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
    A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;
    
    Matrix result = matrix_transpose(A);
    
    assert(result.rows == 3);
    assert(result.cols == 2);
    
    assert(result.data[0][0] == 1); // [0][0] -> [0][0]
    assert(result.data[0][1] == 4); // [1][0] -> [0][1]
    assert(result.data[1][0] == 2); // [0][1] -> [1][0]
    assert(result.data[1][1] == 5); // [1][1] -> [1][1]
    assert(result.data[2][0] == 3); // [0][2] -> [2][0]
    assert(result.data[2][1] == 6); // [1][2] -> [2][1]
    
    free_matrix(A);
    free_matrix(result);
    
    std::cout << "transpose tests passed!" << std::endl;
}

void test_matrix_scalar_addition() {
    std::cout << "Testing matrix scalar addition..." << std::endl;
    
    // Создаем тестовую матрицу 2x2
    Matrix A = create_matrix(2, 2);
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    
    double scalar = 5.0;
    
    // Тестируем сложение со скаляром
    Matrix result = matrix_add_scalar(A, scalar);
    
    // Проверяем результаты
    assert(result.rows == 2);
    assert(result.cols == 2);
    assert(result.data[0][0] == 6.0);  // 1 + 5
    assert(result.data[0][1] == 7.0);  // 2 + 5
    assert(result.data[1][0] == 8.0);  // 3 + 5
    assert(result.data[1][1] == 9.0);  // 4 + 5
    
    // Тест с отрицательным скаляром
    Matrix result2 = matrix_add_scalar(A, -2.0);
    assert(result2.data[0][0] == -1.0);  // 1 - 2
    assert(result2.data[0][1] == 0.0);   // 2 - 2
    assert(result2.data[1][0] == 1.0);   // 3 - 2
    assert(result2.data[1][1] == 2.0);   // 4 - 2
    
    // Тест с нулевым скаляром (матрица должна остаться неизменной)
    Matrix result3 = matrix_add_scalar(A, 0.0);
    assert(result3.data[0][0] == 1.0);
    assert(result3.data[0][1] == 2.0);
    assert(result3.data[1][0] == 3.0);
    assert(result3.data[1][1] == 4.0);
    
    free_matrix(A);
    free_matrix(result);
    free_matrix(result2);
    free_matrix(result3);
    
    std::cout << "scalar addition tests passed!" << std::endl;
}

void test_invalid_operations() {
    std::cout << "Testing invalid operations..." << std::endl;
    
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3); // Несовместимые размеры!
    
    // Тест несовместимого сложения
    try {
        matrix_add(A, B); // Убрали переменную result
        assert(false); // Не должно сюда попасть!
    } catch (const std::exception& e) {
        assert(std::string(e.what()) == "Matrix dimensions must match for addition");
    }
    
    // Тест несовместимого умножения
    Matrix C = create_matrix(2, 3);
    Matrix D = create_matrix(4, 2); // Несовместимые размеры!
    
    try {
        matrix_multiply(C, D); // Убрали переменную result
        assert(false); // Не должно сюда попасть!
    } catch (const std::exception& e) {
        assert(std::string(e.what()) == "Number of columns in A must equal number of rows in B");
    }
    
    // Тест скалярного сложения с невалидной матрицей
    Matrix invalid;
    invalid.rows = 2;
    invalid.cols = 2;
    invalid.data = nullptr;
    
    try {
        matrix_add_scalar(invalid, 5.0); // Убрали переменную result
        assert(false); // Не должно сюда попасть!
    } catch (const std::exception& e) {
        assert(std::string(e.what()) == "Invalid matrix for scalar addition");
    }
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
    free_matrix(D);
    
    std::cout << "invalid operations tests passed!" << std::endl;
}

int main() {
    try {
        test_create_and_free();
        test_matrix_addition();
        test_matrix_multiplication();
        test_matrix_transpose();
        test_matrix_scalar_addition();
        test_invalid_operations();
        
        std::cout << "\nAll tests passed successfully!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}