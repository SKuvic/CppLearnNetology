#include <iostream>

long long fibo (int Fn) {
    if (Fn == 0) return 0;
    if (Fn == 1) return 1;

    long long f_n2 = 0; 
    long long f_n1 = 1; 
    long long f_nn = 0; 

    for (int i = 2; i <= Fn; ++i)
    {
        f_nn = f_n1 + f_n2;
        f_n2 = f_n1;
        f_n1 = f_nn;
    }

    return f_nn; 
}

int main ()
{
    int count = 0;
    std::cout << "Введите Число: ";
    std::cin >> count;
    std::cout << "Числа Фибоначчи: ";
    
    for (int i = 0; i < count; ++i)
    {
        std::cout << fibo(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}