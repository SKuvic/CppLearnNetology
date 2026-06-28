#include <iostream>


int main () {

    srand(time(0));
    int array_rand [10];
    int max;
    int min;
      
    for (size_t i = 0; i < 10; i++)                         // Заполнение random max 99
        {
            array_rand[i] = rand ()%100;
        }
    
    max = array_rand[0];                                    // 1st элемент массива для инициализации переменных min/max
    min = array_rand[0];

    for (size_t i = 0; i < 10; i++)                         //Вывод массива
        { 
            std:: cout << array_rand[i] << " ";
        }
 
    for (size_t i = 0; i < 10; i++)                         //Сравнение-поиск min/max
        {
            if (array_rand[i]  > max )
                {
                    max = array_rand[i];
                }
            if (array_rand[i]  < min )
                {
                        min = array_rand[i];
                }
        }
    
    std:: cout << "\nМинимальный элемент: " << min << std:: endl;
    std:: cout << "Максимальный элемент: " << max << std:: endl;

    return 0;
}