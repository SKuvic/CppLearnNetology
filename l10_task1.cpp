#include <iostream>


int main (int argc, char** argv) {
    
    int size = 0;


    std:: cout << "Введите размер массива: ";
    std:: cin >> size;

    int* arr = new int[size];                       //Выделение памяти под массив+указатель на него

    for (int i = 0; i < size; i++) {                //Заполнение массива через консоль
        std:: cout <<" Arr["<< i << "] = ";
        std:: cin >> arr [i];
    }


    std:: cout << "Введенный массив: ";                       //Вывод массива
    for (int i = 0; i < size; i++) {
        std:: cout << arr [i] << " ";
    }


    delete [] arr;

    return 0;
}