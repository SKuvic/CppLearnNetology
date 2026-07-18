#include <iostream>

int** create_two_dim_array(int rows, int cols) {                                //Создать 2д матрицы
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void fill_two_dim_array(int** matrix, int rows, int cols) {                     //Заполнение массива
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }
}


void print_two_dim_array(int** matrix, int rows, int cols) {                    //вывод массива
    std::cout << "Таблица умножения:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void delete_two_dim_array(int** matrix, int rows, int cols) {                   //Очистка памяти
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows = 0;
    int cols = 0;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;


    int** point_matrex = create_two_dim_array(rows, cols);
    fill_two_dim_array(point_matrex, rows, cols);
    print_two_dim_array(point_matrex, rows, cols);
    delete_two_dim_array(point_matrex, rows, cols);

    point_matrex = nullptr;

    return 0;
}
