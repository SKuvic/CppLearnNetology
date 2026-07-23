#include <iostream>
#include <fstream>


int main (int argc, char** argv) {

    std::ofstream file("out.txt");

    int size = 0;


    std:: cout << "Введите размер массива: ";
    std:: cin >> size;

    file << size << std:: endl; 

    int* arr = new int[size];                       //Выделение памяти под массив+указатель на него

    for (int i = 0; i < size; i++) {                //Заполнение массива через консоль
        std:: cout <<" Arr["<< i << "] = ";
        std:: cin >> arr [i];
    }

    for (int i = 0; i < size; i++) {                //Вывод массива В ФАЙЛ
        file << arr [i] << " "; 
    }

    delete [] arr;

    return 0;
}