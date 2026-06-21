#include <iostream>
#include <string>


int main () {


    std::string Gender;
    int Age;
    std::string  Zodiac;


    std::cout << "Введите пол: ";
    std::cin >> Gender;
    std::cout << "Введите знак зодиака: ";
    std::cin >> Zodiac;
    std::cout << "Введите возраст: ";
    std::cin >> Age;


    //Анкета для проверки входных
    std::cout << "\n\nАнкета\n" << std::endl;
    std::cout << "Ваш пол: " << Gender << std::endl; 
    std::cout << "Ваш знак зодиака: " << Zodiac << std::endl;
    std::cout << "Ваш возраст: " << Age << std::endl;




    if ((Gender == "м") && (Age < 40) && (Zodiac == "рыбы" || Zodiac == "скорпион" || Zodiac == "рак"))
    {
        std::cout << "\nСегодня очень плодотворный день.\n"
            "Можно добиться того, что прежде казалось почти невозможным.\n" << std::endl;

    }
    else if ((Gender == "ж") && (15 <= Age <= 50) && (Zodiac == "козерог" || Zodiac == "дева" || Zodiac == "телец"))
    {
        std::cout << "\nСегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок. \n"
            "Будет не только весело, но и интересно : найдётся дело, которое увлечёт всех." << std::endl;

    }
    else
    std::cout << "\nГороскоп для вас находится в разработке. Приходите чуточку позже;)\n" << std::endl;

    return 0;

}