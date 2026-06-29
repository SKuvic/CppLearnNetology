#include <iostream>


int main () {

    srand(time(0));
    int array_bis [3][6];
    int max;
    int min;
      
    for (size_t i = 0; i < 3; i++)                      // Block I. Инициализация массива 3х6
        {
            for (size_t j = 0; j < 6; j++ ) 
            {
                array_bis [i][j] = rand () % 100;
            }
        }

    // const int row = 3;                                     // Block I-a. Инициализация массива 3х6. Альт запись, если надо влиять на массив извне через переменные - row, col
    // const int col = 6;

    // for (size_t i = 0; i < row; i++) 
    //     {
    //         for (size_t j = 0; j < col; j++)
    //         {
    //             array_bis [i] [j] = rand () % 100;
    //         }
    //     }


    max = array_bis[0][0];                                  // Block 1,5 элемент массива для инициализации переменных min/max
    min = array_bis[0][0];

    for (size_t i = 0; i < 3; i++)                          //Block II  вывод массива
        { 
            for (int j = 0; j < 6; j++)
            {
                std::cout << array_bis[i][j] << "\t";
            }
             std::cout << std::endl;
        }
   

    for (size_t i = 0; i < 3; i++)                         //Сравнение-поиск min/max
        {                                                  //Как и в остальных блоках также вкладываем for-в-for
            for (int j = 0; j < 6; j++) 
            {

                if (array_bis[i][j]  > max )
                    {
                        max = array_bis[i][j];
                    }
                if (array_bis[i][j]  < min )
                    {
                            min = array_bis[i][j];
                    }
            }
        }

    std:: cout << std:: endl;
    
    std:: cout << "Минимальный элемент: " << min << std:: endl;
    std:: cout << "Максимальный элемент: " << max << std:: endl;

    return 0;
}