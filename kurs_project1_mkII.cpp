#include <iostream>
#include <fstream>
#include <windows.h>

/*
======================================================================
======================================================================
   UTILITY FUNCS
======================================================================
======================================================================
*/

// Созданиe матрицы - Стандартная Функция-Утилити
char** f_matrix_create ( int row, int col) {
    char** fmc_matrix = new char*[row];       // Выделение памяти под массив fmc_matrix [ i ][ j ] указателей - 0й столбец
    for (int i = 0; i < row; i++) {
        fmc_matrix[i] = new char[col];        // Выделение памяти под каждую строку
    }
    return fmc_matrix;
}


// Вывод матрицы - Стандартная Функция-Утилити 
char** f_matrix_out (int row, int col, char** matrix_input) {
    char** fmo_matrix = matrix_input;
    for (int i = 0; i < row; i++){                      //Вывод для ТЕЛА программы
        for (int j = 0; j < col; j++) {
            std:: cout << fmo_matrix [i][j] << " ";
        }
        std:: cout << std:: endl;                       // ТЫ СНОВА ЗАБЫЛ перенос строки
    }
    return fmo_matrix;
}


// Удаление матрицы - Стандартная Функция-Утилити
void f_matrix_drop (int height, char** matrix_name) {
    for (int i = 0; i < height; i++) {
        delete[] matrix_name [i];
    }
    delete[] matrix_name;
}


/*
======================================================================
======================================================================
   GENERAL FUNCS
======================================================================
======================================================================
*/

// Инициализация мира. |||| Return > fwc_matrix -- 1st GEN matrix.
char** f_world_create (int& fwc_height, int& fwc_width, char fwc_cell_life, char fwc_cell_empty) {           // Функция создает и наполняет игровой мир!    RETURN > fwc_matrix.
    //f_world_create ( pntr <Высота игрового поля>, pntr <Ширина игр. поля>, char <"жизнь">, char<"пустота">).
    /*
    ======================================================================
        Алгоритм ф-ции world_create - fwc - [f]unction[w]orld[c]reate:
    ======================================================================
        A) Открытие + Чтение файла in.txt;
        B) Инициализация границ мира - через ф-ию <f_matrix_create>;
        C) Заполнение мира <empty> пустотой;
        D) Наполнение мира <life> по инструкции из in.txt;
        E) Закрыть-прекратить файл in.txt 
        F) Передача/Return <fwc> fwc_matrix >->-> <main> matrix из fwc >> в >> тело main;
         
    */
    
    // Тут мог бы быть блок объявления переменных НО эти две переменные в эксклюзивны для блока D - там им и место.
    // int life_row = 0;
    // int life_col = 0;


    //FWC - BLOCK A.    Открытие + Чтение файла in.txt;
    std:: ifstream file_in ("in.txt");                                      //Чтение файла
    if (!file_in.is_open()) {
        std::cout << "Error: cannot open in.txt" << std::endl;
        return nullptr;
    }

    file_in >> fwc_height;
    file_in >> fwc_width;

    //FWC - BLOCK B.    Инициализация границ мира - через ф-ию <f_matrix_create>;
    char** fwc_matrix = f_matrix_create (fwc_height, fwc_width);                // через Функцию создания матрицы

    //FWC - BLOCK C.    Заполнение мира <empty> пустотой;
    for (int i = 0; i < fwc_height; i++) {                              // BLANK-массив в котором каждой ячейке присвоено empty = "-"
        for (int j = 0; j < fwc_width; j++) {
            fwc_matrix[i][j] = fwc_cell_empty;                          // Заполнение ВСЕХ ячеекна значение переданное в аргументе
        }
    } // BLOCK C FIN.

    //FWC - BLOCK D.    Наполнение мира <life> по инструкции из in.txt;
    int life_row = 0;                                                               // Перменные BLOCK D рядом с местом к которому они относяться!
    int life_col = 0;

    while (file_in >> life_row >> life_col) {                                        // Условие цикла явл. TRUE пока поступают данные из файла - цикл работает
                                                
        if (life_row >= 0 && life_row < fwc_height && life_col >= 0 && life_col < fwc_width) {      // Граничные условия чтобы не было Buffer Overflow - Вызванное Ошибочным заполнением ВНЕ границ массива.                                                                                           
            fwc_matrix[life_row][life_col] = fwc_cell_life;
        }
    } // BLOCK D FIN.

    //FWC - BLOCK E.    Закрыть-прекратить файл in.txt
    file_in.close();

    //FWC - BLOCK F.    Extraction-hook-to-main()
    return fwc_matrix;                                                         //Возврат адресов матрицы GEN.1 <fwc_matrix>, которые будут присвоены к <matrix> из main ()

} //f_world_create FIN.


// Подсчета количества живых соседей у клетки. |||| RETURN > nearby - кол-во живых вокруг 3х3.
int f_scan_radius (int fsr_height, int fsr_width, char** fsr_matrix, int fsr_cell_i, int fsr_cell_j, char fsr_life) {               //RETURN > nearby   - кол-во живых вокруг 3х3.    int fsr_height, int fsr_width - world_height/width соответсвенно. int fsr_cell_i, int fsr_cell_j - передать из ЦИКЛА! char fsr_life == life 
    
    int nearby = 0;                                                 // Счетчик Живых клеток в Радиусе 3х3 указанной клетке на "карте мира"
        //FSR - BLOCK 1     Двигает указатель в радиусе 3х3 вокруг переданных координат кдетки
        for (int di = -1; di <= 1; di++) {                                      // НАЧИНАЯ С GEN 2: "Плавающее окно" для 3х3 для проверки
            for (int dj = -1; dj <= 1; dj++) {                                      // Сперва проходим стобцы <j>, а потом сдвигаем счетчик по <i>
                int near_i = fsr_cell_i + di;                                      // Двигатель указателя по СТРОКАМ вокруг переданных координат клетки [fsr_cell_i][fsr_cell_j];
                int near_j = fsr_cell_j + dj;                                     // Двигатель указателя по СТОБЦАМ вокруг переданных координат клетки [fsr_cell_i][fsr_cell_j];

        //FSR - BLOCK 2     Проверяет ограничивает поле работы 3х3 по границам "Мировой Карты"
                if (near_i < 0 || near_j < 0 || near_i >= fsr_height || near_j >= fsr_width) continue;          //Граничные условия при котором проверка не выходит за пределы массива
                if (near_i == fsr_cell_i && near_j == fsr_cell_j) continue;                                       //отмена проверки центра 3х3. Иначе ЭТОТ посчитает себя крутышом и сломает мне код!

        //FSR - BLOCK 3     Проверка каждой клетки вокруг переданных координат НА состояние жив/не-жив.        
                if (fsr_matrix[near_i][near_j] == fsr_life) {
                    nearby++;                                               //IF TRUE - put alive to other living cell
                }
        } // BLOCK 1 FIN.
        } // BLOCK 1 FIN.

    return nearby;                                                      // Возрват суммы живых вокруг <fsr_cell_j>, <fsr_cell_j>
}   //f_scan_radius FIN.


// Вычисления следующего поколения. |||| RETURN > life_deth_flow
bool f_next_gen (int fng_height, int fng_width, char** fng_matrix_world, char fng_life, char fng_empty){
//  fng-height == world_height; fng_width == world_width; char** fng_mtrx_world - передайте матрицу из main()

    /*
    ======================================================================
        Алгоритм ф-ции f_next_gen:
    ======================================================================
        A) Создание реплики-матрицы main-matrix >> replica-matrix;
        B) Цикл обхода ячеек main-matrix;
            B1) Вложенный цикл f_scan_radius >> return nearby;
            B2) На основе b1 <nearby> принять решение жива клетка main-matrix [i] [j] или нет;
        C) UPDATE main-матрицу путем присваивания к ней значения из временной-матрицы;
        D) DROP Временную-матрицу
        E) return life_death_flow - Для условий проигрыша будет нужно      
    */
    
    int life_around = 0;                                                // Счетчик живых клеток вокруг проверяемой
    bool life_deth_flow = false;

    // BLOCK A)     Инициализировать временную-матрица <temp_matrix>
    char** temp_matrix = f_matrix_create (fng_height, fng_width);                               // Создание матрицы-реплики для записи в нее промежуточного результата и перезапись в main-матрицу. Через функцию
   
    // BLOCK B) Цикл обхода ячеек main-matrix;
    for (int i = 0; i < fng_height; i++) {
        for (int j = 0; j < fng_width; j++) {
            
            //B1) Вложенный цикл f_scan_radius >> return nearby;
            life_around = f_scan_radius (fng_height, fng_width, fng_matrix_world, i, j, fng_life);          //
            
            //B2) На основе b1 <nearby> принять решение жива клетка main-matrix [i] [j] или нет;
            if (fng_matrix_world[i][j] == fng_empty && life_around == 3) {                                                            // Применяем правила игры во ВРЕМЕННУЮ матрицу next_matrix
                temp_matrix [i][j] = fng_life;                                                           // УСЛОВИЕ жизни
                life_deth_flow = true;                                                               // Контроль имзенения состояния мира
            }
            else if (fng_matrix_world[i][j] == fng_life && (life_around < 2 || life_around > 3)) {
                temp_matrix [i][j] = fng_empty;                                                          // УСЛОВИЕ смерти
                life_deth_flow = true;                                                               // Контроль 2 изменения состояния мира
            }
            else {
                temp_matrix[i][j] = fng_matrix_world[i][j];                                                   // Состояние не меняется
            } //FIN. INNER-BLOCK B2)

        }   //BLOCK B) FIN.
        }   //BLOCK B) FIN.

    // BLOCK C) UPDATE main-матрицу путем присваивания к ней значений из временной-матрицы;
    for (int i = 0; i < fng_height; i++) {
        for (int j = 0; j < fng_width; j++) {
            fng_matrix_world [i][j] = temp_matrix [i][j];
        }
    }

    // BLOCK D) DROP Временную-матрицу
    f_matrix_drop (fng_height, temp_matrix);

//BLOCK E.
return life_deth_flow;
}   


// Счетчик живых клеток |||| RETURN > live_cell_counter
int f_cells_alive (int fca_height, int fca_width, char** fca_matrix_world, char fca_life) {
    
    int live_cell_counter = 0;

    for (int i = 0; i < fca_height; i++) {
        for (int j = 0; j < fca_width; j++) {
            if (fca_matrix_world [i] [j] == fca_life) {
                live_cell_counter++;
            }
            else { continue;}
            
        }
        }

    return live_cell_counter;
}

// Условия "ПОБЕДЫ" |||| RETURN > false/true;  
bool f_victory_conds (int cells_alive, bool life_deth_flow, int gen_x) {

        if (cells_alive == 0) {
            std:: cout << " Все клетки погибли :( Игра окончена. " << std:: endl;
            return true; 
        }

        if (gen_x > 1 && !life_deth_flow) {
             std:: cout << " Мир стагнировал. Игра окончена. " << std:: endl;
            return true; 
        }

return false;  
}




int main(int argc, char** argv) {

    int world_height = 0;                               //Высота игрового поля - Кол-во строк массива
    int world_width = 0;                                //Ширина игрового поля - Кол-во колонок массива
    char empty = '-';                                    //Состояние - клетка <Пуста>
    char life = '*';                                    //Состояние - Клетка <Жива>
    int gen_x = 1;                                   //Счетчик поколнеий
    
    // BLOCK I. 
        /*
        BLOCK I. Он существует только потому что мне надо:
        А) Вывод матрицы первого поколения;
        Б) Я хочу оставить вывод-доказательство того, что мир стагнировал. Т.е. вывести последнее поколение + ТО ЖЕ последнее поколение НО уже с сообщением "все погибли"/"мир стагнировал"

        Так бы сунул все в while (gen_x != -1 ) {...} и поменял бы последовательность функций. Кроме инициализации мира конечно же <f_world_create (...) - этот остаеться за бортом while>
        */

    char** matrix = f_world_create (world_height, world_width, life, empty);                                // Ф-ия сама создаст и заполнит нужными символами поле.
    int cells_alive = f_cells_alive (world_height, world_width, matrix, life);                              // Счетчик живых во всем мире
    f_matrix_out (world_height, world_width, matrix);                                                       //
    std::cout << "GEN. " << gen_x << " | Active Cells: " << cells_alive << "\n" << std::endl;     //Итоги после каждого поколения

    while (gen_x != -1) {                                                                               // Цикл игры

        bool world_changed = f_next_gen (world_height, world_width, matrix, life, empty);                   // Генерация поколений + условие смены мира В виде true/false
        gen_x++;

        cells_alive = f_cells_alive (world_height, world_width, matrix, life);                             //Cчет живых

        f_matrix_out (world_height, world_width, matrix);                                                   //вывод матрицы новго поколения
        std::cout << "GEN. " << gen_x << " | Active Cells: " << cells_alive << "\n" << std::endl;          //Итоги после каждого поколения

        if (f_victory_conds (cells_alive, world_changed, gen_x)){                                               // Условие "Победы" + Наделенние его "властью" прервать цикл while
        break;
        }

        Sleep(500); // Пауза 

    }


    return 0;
}
