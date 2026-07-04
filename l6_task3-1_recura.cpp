#include <iostream>

long long fibo_recura(int Fn)                                   // Функция для расчета на основании вводимого Fn. РЕКУРСИВНАЯ
{   
    if (Fn <= 0) return 0;
    if (Fn == 1) return 1;
    return fibo_recura (Fn - 1) + fibo_recura (Fn - 2);

}

int main ()
{
    int Fn;
    std::cout << "Введите число: " ;
    std::cin >> Fn;             
    std::cout << "Числа Фибоначчи: "; 
    for (int i = 0; i < Fn; i++) 
    {
        std::cout << fibo_recura(i) << " ";
    }
    
    return 0;
}