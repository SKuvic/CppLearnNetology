#include <iostream>

int main() {

    double A1;
    double B2;
    double C3;
    double Max;
    double Mid;
    double Min;

    std::cout << "Введите первое число: "; std::cin >> A1;
    std::cout << "Введите второе число: "; std::cin >> B2;
    std::cout << "Введите третье число: "; std::cin >> C3;


    //// Через IF-ELSE-IF-ELSE
   
    //if (A1 > B2 && A1 > C3)                           // Max
    //    Max = A1;
    //else if (B2 > A1 && B2 > C3)
    //    Max = B2;
    //else
    //    Max = C3;

    //if (A1 < B2 && A1 < C3)                           //Min
    //    Min = A1;
    //else if (B2 < A1 && B2 < C3)
    //    Min = B2;
    //else
    //    Min = C3;

    //Mid = A1 + B2 + C3 - Max - Min;                    //Mid


    // Тернарный

    Max = A1 > B2                                       //Max - Тернарный
        ? A1 > C3
        ? A1 : C3
        : B2 > C3
        ? B2 : C3;

    Min = A1 < B2                                       //Min - Тернарный
        ? A1 < C3
        ? A1 : C3
        : B2 < C3
        ? B2 : C3;

    Mid = (A1 != Max && A1 != Min)                     //Mid - Тернарный
         ? A1 : (B2 != Max && B2 != Min)
         ? B2 : C3;


    std::cout << "\nРезультат: " << Max << " " << Mid << " " << Min << std::endl;


    return 0;

}