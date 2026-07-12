#include <iostream>

int swap (int *point_a, int *point_b)					// через третью переменную
{
	int swap_dump = *point_a;                           // Разыменование для извлечения числа в записанного в переменную
		*point_a = *point_b;
		*point_b = swap_dump;
	return 1;
}

int main (int argc, char** argv)
{
	int a = 5, b = 8;

    int* point_a = &a;                                 // Укаpатели для a,b
    int* point_b = &b;

		std::cout << "a = " << a << ", b = " << b << std::endl;

		swap (point_a, point_b);

		std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;
}

