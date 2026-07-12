#include <iostream>

void reverse (int * arai, int size)
{
    int temp = 0;
    for (int k = 0; k < size - 1; k++)
    {
        for (int i = size - 1; i > k; i--)
        {
            if (arai[i] > arai[i - 1])
            {
                temp = arai[i];                        
                arai[i] = arai[i - 1];          
                arai[i - 1] = temp;
            }
        }
    }

}


int main () {

int a [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int * point = a;
    

    std:: cout << "Массив до <reverse> : ";
        for (size_t i = 0; i < 9; i++)                         //Block II. Вывод массива
        { 
            std:: cout << point[i] << " ";
        }
 
    std:: cout << std:: endl;


    reverse (a, 9);
    std:: cout << "Массив после <reverse> : ";             //Block IV. Output
        for (size_t i = 0; i < 9; i++)
        {
            std::cout << a [i] << " ";
        }


    return 0;
}
