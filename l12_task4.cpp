#include <iostream>
#include <fstream>


int main (int argc, char** argv) {

    std::fstream file("in.txt");

    int sizei = 0;
    int sizej = 0;

    file >> sizei;
    file >> sizej;

    int** matrix = new int*[sizei];                      // Выделение памяти через массив-указатель-указателей
    for (int i = 0; i < sizei; i++) {
        matrix[i] = new int[sizej];
    }

    for (int i = 0; i < sizei; i++) {                    // ЧТЕНИЕ из in.txt в нормальном порядке - слева на право
        for (int j = 0; j < sizej; j++) {
            file >> matrix[i][j];
        }
    }


    // for (int i = 0; i < sizei; i++) {                    // ВЫВОД в консоль нормальный порядок

    //     for (int j = 0; j < sizej; j++) {
    //         std::cout << matrix[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    for (int i = 0; i < sizei; i++) {                    // ВЫВОД в консоль обратный порядок. ТОЛЬКО строки справа налево от прочитанного

        for (int j = sizej - 1; j >= 0; j--) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    // Освобождаем память
    for (int i = 0; i < sizei; i++) {
        delete[] matrix[i];
    }

    file.close(); 

    delete[] matrix;

    return 0;
}