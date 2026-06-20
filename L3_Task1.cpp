#include <iostream>

int main() {

    bool A = true;
    bool B = false;
    bool Solv;
    
    std::cout << std::boolalpha;

    //Block I. Оператор OR

    std::cout << "Оператор: ||" << std::endl;

    Solv = (A || A);
    std::cout << A << "\t" << A << "\t" << Solv << std::endl;

    Solv = (B || A);
    std::cout << B << "\t" << A << "\t" << Solv << std::endl;

    Solv = (A || B);
    std::cout << A << "\t" << B << "\t" << Solv << std::endl;

    Solv = (B || B);
    std::cout << B << "\t" << B << "\t" << Solv << std::endl;


    //Block II. Оператор AND

    std::cout << "\nОператор: &&" << std::endl;

    Solv = (A && A);
    std::cout << A << "\t" << A << "\t" << Solv << std::endl;

    Solv = (B && A);
    std::cout << B << "\t" << A << "\t" << Solv << std::endl;

    Solv = (A && B);
    std::cout << A << "\t" << B << "\t" << Solv << std::endl;

    Solv = (B && B);
    std::cout << B << "\t" << B << "\t" << Solv << std::endl;


    return 0;
}