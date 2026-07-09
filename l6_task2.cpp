#include <iostream>

int pow (int value, int power)
{
    int result = 1;

    for (int i = 0; i < power; i++)
    {
        result *= value;
    }

   return result;
}


int main (int argc, char** argv)
{
    int value = 5, power = 2, result = 1;

    std::cout << value << " в степени " << power << " = " <<  pow (value, power) << std::endl;

    value = 3;
    power = 3;
    result = 1;

    std::cout << value << " в степени " << power << " = " <<  pow (value, power) << std::endl;
    value = 4;
    power = 4;
    result = 1;

    std::cout << value << " в степени " << power << " = " <<  pow (value, power) << std::endl;

    return 0;
}