#include <iostream>

int sum (int a, int b)
{
    int s = 0;
	s = a + b;
	return s;
}

int diff (int a, int b)
{
	int dif = 0;
	dif = a - b;
	return dif;
}

int multiplication (int a, int b)
{
	int mult = 0;
	mult = a * b;
	return mult;
}

double division (double a, double b)
{
	double div = 0;
	div = a / b;
	return div;
}

int main(int argc, char** argv)
{
	int a = 5, b = 10;

	int s = sum(a, b);
	int dif = diff(a, b);
	int mult = multiplication(a, b);
	double div = division(a, b);

	std::cout << a << " + " << b << " = " << s << std::endl;
	std::cout << a << " - " << b << " = " << dif << std::endl;
	std::cout << a << " * " << b << " = " << mult << std::endl;
	std::cout << a << " / " << b << " = " << div << std::endl;
	
	return 0;
}