#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()

int main () {

    srand(time(0));
    int array_sort [10];
    int temp;
      
    for (size_t i = 0; i < 10; i++)                         // Block I. Fill & Initialize
        {
            array_sort[i] = rand () % 100;
        }
   
    std:: cout << "Массив до сортировки : ";
    for (size_t i = 0; i < 10; i++)                         //Block II. Вывод массива
        { 
            std:: cout << array_sort[i] << " ";
        }
 
    std:: cout << std:: endl;
    
    for (size_t k=0; k < 10; k++)
        {
            for (size_t i = 0; i < 9; i++)                         //Block III. Sort bubble-reversed
                {
                    if (array_sort[i]  > array_sort[i + 1] )
                        {
                            // temp = array_sort[i];                   //via temp
                            // array_sort [i] = array_sort[i + 1];     
                            // array_sort [i + 1] = temp;
                            std::swap(array_sort[i], array_sort [i+1]);   //via swap
                        }
                }
        }
    std:: cout << "Массив после сортировки : ";             //Block IV. Output

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << array_sort [i] << " ";
    }

    return 0;
}