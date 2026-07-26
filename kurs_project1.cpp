#include <iostream>
#include <fstream>
#include <windows.h>



int main(int argc, char** argv) {


    // BLOCK I. FILES & VARIABLES
    std::ifstream file_in("in.txt");    // Чтение из in.txt
    if (!file_in.is_open()) {
        std::cout << "Error: cannot open in.txt" << std::endl;
        return 1;
    }

    int sizei = 0;                      //Строки массива
    int sizej = 0;                      //Столбцы массива
    char empty = '-';                   //Состояние 1 
    char life = '*';                    //Состояние 2
    int gen_x = 1;                      //Счетчик поколнеий //TEST сместил счетчик чтобы начало было с 1
    int alive = 0;                      //Счетчик живых клеток
    int liv_i = 0;                      //Счетчик Строк плавующего окна 3х3
    int liv_j = 0;                      //Счетчик СТОЛБЦОВ плавающего окна 3х3

    // Чтение границ массива из in.txt
    file_in >> sizei;
    file_in >> sizej;                   // Чтение границ массива из in.txt


    // BLOCK II. MATRIX DEFINITION AND FILL
    
    char** matrix = new char*[sizei];       // Выделение памяти под массив matrix [ i ][ j ] указателей - 0й столбец
    for (int i = 0; i < sizei; i++) {
        matrix[i] = new char[sizej];        // Выделение памяти под каждую строку
    }

    
    for (int i = 0; i < sizei; i++) {           // Заполнение массива-BLANK'а символом empty = "-"
        for (int j = 0; j < sizej; j++) {
            matrix[i][j] = empty;
        }
    }

    
    while (file_in >> liv_i >> liv_j) {                                        // Заполнение массив из файла
                                                
        if (liv_i >= 0 && liv_i < sizei && liv_j >= 0 && liv_j < sizej) {      // Граничные условия
            
            matrix[liv_i][liv_j] = life;
        }
    }
    file_in.close(); 



    // BLOCK III Граничные условия
    while (gen_x != -1) {                                                       // УСЛОВИЕ ЗАЦИКЛИНВАНИЯ
        alive = 0;                                                              // Сброс счетчика живых клеток для текущего поколения
        bool liv_deth_flow = false;                                             //Флаг что мир меняется каждый ход


        char** next_matrix = new char*[sizei];                                  //ВРЕМЕННАЯ матрица чтобы фиксировать состояние. Уже было что клетки ходили по ячейкам
        for (int i = 0; i < sizei; i++) {
            next_matrix[i] = new char[sizej];
        }

        for (int i = 0; i < sizei; i++) {                                        // Обходим всю матрицу
            for (int j = 0; j < sizej; j++) {

                if (gen_x == 1) {                                               //Условие ВЫВОДА GEN 1.
                    next_matrix[i][j] = matrix[i][j];
                } 
                else {

                    int nearby = 0;
                    for (int di = -1; di <= 1; di++) {                           // НАЧИНАЯ С GEN 2: "Плавающее окно" для 3х3 для проверки
                        for (int dj = -1; dj <= 1; dj++) {
                            int near_i = i + di;
                            int near_j = j + dj;

                            if (near_i < 0 || near_j < 0 || near_i >= sizei || near_j >= sizej) continue;  //Граничные условия при котором проверка не выходит за пределы массива
                            if (near_i == i && near_j == j) continue;                                       //отмена проверки центра 3х3
                            
                            if (matrix[near_i][near_j] == life) {
                                nearby++;                                                             // Проверка живая ли клетка вокруг которой проверяем    
                            }
                        }
                    }

                    if (matrix[i][j] == empty && nearby == 3) {                                                            // Применяем правила игры во ВРЕМЕННУЮ матрицу next_matrix
                        next_matrix[i][j] = life;                                                           // УСЛОВИЕ жизни
                        liv_deth_flow = true;                                                               // Контроль имзенения состояния мира
                    }
                    else if (matrix[i][j] == life && (nearby < 2 || nearby > 3)) {
                        next_matrix[i][j] = empty;                                                          // УСЛОВИЕ смерти
                        liv_deth_flow = true;                                                               // Контроль 2 изменения состояния мира
                    }
                    else {
                        next_matrix[i][j] = matrix[i][j];                                                   // Состояние не меняется
                    }
                }

                std::cout << next_matrix[i][j] << " ";                                                  // ВЫВОД И СТАТИСТИКА текущей клетки на экран

                if (next_matrix[i][j] == life) {
                    alive++;
                }
            }
            std::cout << std::endl;
        }


        for (int i = 0; i < sizei; i++) {                                                                   // REPLICATE из временной в основную таблицу
            for (int j = 0; j < sizej; j++) {                                                               
                matrix[i][j] = next_matrix[i][j];
            }
        }

        for (int i = 0; i < sizei; i++) {                                                               // Удаляем временную матрицу текущего шага из памяти
            delete[] next_matrix[i];
        }
        delete[] next_matrix;

        std::cout << "GEN. " << gen_x << " | Active Cells: " << alive << "\n" << std::endl;     //Итоги после каждого поколения
         

        // BLOCK V. Victory Condition.

        if (alive == 0) {
            std::cout << " Все клетки погибли :( Игра окончена. " << std::endl;
            break; 
        }

        if (gen_x > 1 && !liv_deth_flow) {
            std::cout << " Мир стагнировал. Игра окончена. " << std::endl;
            break;
        }
        gen_x++;
        Sleep(500); // Пауза 
    }


    // BLOCK VI. CLEANUP 
    for (int i = 0; i < sizei; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;


    return 0;
}   
