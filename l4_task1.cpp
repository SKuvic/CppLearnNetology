#include <iostream>

int main () {
    
    int user_input;
    int sum_input = 0;

        do {
            std:: cout << "Введите целое число или число '0', чтобы закончить: " << std:: endl;
            std:: cin >> user_input;
            sum_input += user_input;
        }
        while ( user_input != 0 );  

        std:: cout << "Сумма: " << sum_input <<  std:: endl;

        

return 0;

}