#include <iostream>

int fibo (int Fn)                                   // Функция для расчета на основании вводимого Fn. БЕЗ РЕКУРСИИ
{   
    long long f_n1 = 0;                                   //F[n-1]
    long long f_n2 = 1;                                   //F[n-2]
    long long f_nn = 0;                                   //F[n] 

    switch (Fn)                                     // Я ни разу не делал задание через Switch-Case
    {
        case 0:                                     //Отсечка при вооде индекса '0'
            std::cout << "0 ";
            return 0;
            break;
        case 1:
            std::cout << "0 1 ";                    //Отсечка при вооде индекса '1'
            return 1;
            break;
        default:
            std::cout << "0 1 ";
            break;
    }

    for (size_t i = 2; i < Fn; i++)
    {   
        f_nn = f_n1 + f_n2;
        std::cout << f_nn << " ";                      // Отправить <f_nn> на ВЫВОД до того как ОБНОВЯТСЯ другие переменные - Фиксируем сумму
        f_n1 = f_n2;                                   // ОБНОВИТЬ <f_n1>  (F[n - 1]   "свдигом" из    <f_n2> (F[n - 2])
        f_n2 = f_nn;                                   // ОБНОВИТЬ <f_n2>  из  <f_nn>

    }

    return Fn;
}

int main ()
{
    int Fn = 0;
    std::cout << "Введите число: " ;
    std::cin >> Fn;             
    std::cout << "Числа Фибоначчи: "; 
    fibo (Fn);
    
    return 0;
}