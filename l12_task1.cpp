#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{

std::string s;

std::ifstream fin ("in.txt"); // открываем файл


while (fin >> s) {
    std::cout << s << std::endl;
    }
}