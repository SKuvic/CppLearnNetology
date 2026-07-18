#include <iostream>

double* create_array (int size) {
    double* arr_func = new double[size];                       //Выделение памяти под массив+указатель на него

    for (int i = 0; i < size; i++) {
        arr_func[i] = 0.0;
    }
    return arr_func;
}



int main (int argc, char** argv) {
    
    int input_size = 0;


    std:: cout << "Введите размер массива: ";
    std:: cin >> input_size;

    double* arr = create_array(input_size);                   //передача указателя массива В функцию


    std:: cout << "Введенный массив: ";                       //Вывод массива
    for (int i = 0; i < input_size; i++) {
        std:: cout << arr [i] << " ";
    }

    delete [] arr;

    return 0;
}