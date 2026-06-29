#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()

int main () {

    srand(time(0));
    int array_bis [3][6];
    // MIN/MAX numbers-values
    int max = 0;
    int min = 0;
    // MIN/MAX - i,j placers-holders-reassigners-rewriters
    int mini = 0;
    int maxi = 0;
    int minj = 0;
    int maxj = 0;
      
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
                        maxi = i;
                        maxj = j;
                    }
                if (array_bis[i][j]  < min )
                    {
                        min = array_bis[i][j];
                        mini = i;
                        minj = j;
                    }

            }
        }

    std:: cout << std:: endl;
    
    std:: cout << "Минимальный элемент: " << "[ " << mini << " ] " << "[ " << minj << " ] = " << min << std:: endl;
    std:: cout << "Максимальный элемент: "<< "[ " << maxi << " ] " << "[ " << maxj << " ] = " << max << std:: endl;


    return 0;
}
