#include "matrix.h"
#include <iostream>

int main() {
    try {
        double value = 10.5;
        // Создание матриц
        Matrix A = create_matrix(2, 2);
        Matrix B = create_matrix(2, 2);

        // Заполнение данными
        A.data[0][0] = 1; A.data[0][1] = 2;
        A.data[1][0] = 3; A.data[1][1] = 4;

        B.data[0][0] = 5; B.data[0][1] = 6;
        B.data[1][0] = 7; B.data[1][1] = 8;

        // Операции
        Matrix sum = matrix_add(A, B);
        Matrix product = matrix_multiply(A, B);
        Matrix transposeA = matrix_transpose(A);
        Matrix scalarResult = matrix_add_scalar(A, value); 

        // Вывод результатов
        std::cout << "Matrix A:" << std::endl;
        print_matrix(A);

        std::cout << "\nMatrix B:" << std::endl;
        print_matrix(B);

        std::cout << "\nSum A+B:" << std::endl;
        print_matrix(sum);

        std::cout << "\nProduct A*B:" << std::endl;
        print_matrix(product);

        std::cout << "\nTranspose of A:" << std::endl;
        print_matrix(transposeA);

        std::cout << "\nA + " << value << " (scalar addition):" << std::endl;
        print_matrix(scalarResult);

        // Освобождение памяти
        free_matrix(A);
        free_matrix(B);
        free_matrix(sum);
        free_matrix(product);
        free_matrix(transposeA);
        free_matrix(scalarResult); // Освобождаем новую матрицу

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}