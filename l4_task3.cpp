#include <iostream>



int main () {

    int input_num;
    int multiplier = 1;
    int result;

        std:: cout << "Введите целое число: " << std:: endl;
        std:: cin >> input_num;

        do {
            result = input_num * multiplier;
            std:: cout << input_num << " X " << multiplier << " = " << result << std:: endl;
            multiplier ++;
        }
        while (multiplier < 11);

return 0;
}