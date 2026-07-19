#include <iostream>
#include <cstring>
#include <string>

int main (int argc, char** argv) {
    std:: string guess_word;
    std:: string correct_word = "голубика";
    
    std:: cout << "Угадайте слово:";
    std:: cin >> guess_word;

    while ( guess_word != correct_word ) {
        
        std:: cout << "Неправильно!" << std::endl;
        std:: cout << "Угадайте слово еще раз:";
        std:: cin >> guess_word;
    }

    std:: cout << "Правильно! Вы победили!";

    return 0;
}