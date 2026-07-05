#include <iostream>

// int swap (int &a, int &b)					// через третью переменную
// {
// 	int swap_dump = a;
// 		a = b;
// 		b = swap_dump;
// 	return 1;
// }


// int swap (int &a, int &b)					// через std:: swap (a, b). Через (скрытую) 3-ю переменную
// {
// 	std:: swap (a, b);
// 	return 1;
// }


int swap (int &a, int &b)						// Через арифметику. Без 3-ей переменной
{
	a = a + b;
	b = a - b;
	a = a - b;
	return 1;
}


int main (int argc, char** argv)
{
	int a = 5, b = 8;

		std::cout << "a = " << a << ", b = " << b << std::endl;

		swap (a, b);

		std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;
}

