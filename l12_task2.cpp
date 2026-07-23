#include <iostream>
#include <fstream>

int main() {
    
    std::ifstream file("in.txt");

    int size = 0;

    file >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        file >> arr[i];
    }


    for (int i = size - 1; i >= 0; --i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    file.close();
    delete[] arr;

    return 0;
}