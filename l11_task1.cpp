#include <iostream>
#include <cstring>
#include <string>

int main(int argc, char** argv)
{
//OPTION A
// char name_chr [30] = "" ;
// char surname_chr [30] = "";
// char spacebar_chr [2] = " ";            //1 байт на NULL, 1 байт на пробел
// char fullname_chr [62] = "";            // Я желаю чтобы полное имя шло в отдельную переменную c УВЕЛИЧЕННОЙ памятью
                                        
// std:: cout << "Введите имя: ";
// std:: cin.getline(name_chr, 30);         // Я желаю Имя с пробелами
// std:: cout << "Введите фамилию: ";
// std:: cin.getline(surname_chr, 30);

// std:: cout << "Здравствуйте, " << strcat ((strcat((strcat (fullname_chr, name_chr)), spacebar_chr)), surname_chr) <<"!";

// strcat(fullname_chr, name_chr);     // Альт запись вместо вложенного Strcat - который НЕ читаемый
// strcat(fullname_chr, spacebar_chr); 
// strcat(fullname_chr, surname_chr);

// //OPTION B
std::string name_std;                           // ЧЕРЕЗ std::string
std::string surname_std;

std:: cout << "Введите имя: ";
std:: getline(std::cin, name_std);
std:: cout << "Введите фамилию: ";
std:: getline(std::cin, name_std);
std::cout << "Здравствуйте, " + name_std + " " + surname_std + "!";  //через Конкатенацию - CONCAT

return 0;
}