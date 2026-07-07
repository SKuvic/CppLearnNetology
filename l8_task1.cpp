#include <iostream>

int counting_function()
{
    int static counter = 0;
    counter ++;
    std:: cout << "Количество вызовов функции counting_function(): " << counter << std:: endl;
    return 1;
}

int main(int argc, char** argv)
{
    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }

    return 0;
}