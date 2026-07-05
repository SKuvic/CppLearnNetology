#include <iostream>


int main ()
{
	int number = 0;
	short shor = 0;
	long loong = 0;
	long long loo_oong = 0;
	float fleet = 0.0f;
	double espresso = 0.0;
	long double kebab = 0.0;
	bool stool = false;

	std::cout << "int: " << &number << " | " << sizeof(number) << " bytes" << std::endl;
	std::cout << "short: " << &shor << " | " << sizeof(shor) << " bytes" << std::endl;
	std::cout << "long: " << &loong << " | " << sizeof(loong) << " bytes" << std::endl;
	std::cout << "long long: " << &loo_oong << " | " << sizeof(loo_oong) << " bytes" << std::endl;
	std::cout << "double: " << &espresso << " | " << sizeof(espresso) << " bytes" << std::endl;
	std::cout << "long double: " << &kebab << " | " << sizeof(kebab) << " bytes" << std::endl;
	std::cout << "bool: " << &stool << " | " << sizeof(stool) << " bytes" << std::endl;


	return 0;
}