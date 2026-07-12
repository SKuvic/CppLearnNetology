#include <iostream>


int print (int* arai, int size) {

    for (size_t i = 0; i < size; i++)                         //Вывод массива
    { 
        std:: cout << arai [i] << " ";
    }
    std:: cout << std:: endl;
    return 0;
}

int main (int argc, char** argv)
{
    int a [5] = {1, 3, 5, 7, 9};
    print (a, 5);
    
    int b [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print (b, 10);

    int c [8] = {2, 4, 6, 8, 10, 42, 11, 56};
    print (c, 8);
    
    return 0;

}