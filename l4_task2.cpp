#include <iostream>


int main() {

	int input_num;												//Ввод числа
	int modulo = 0;												//остаток от частного
	int digit;													//Extraction of Остаток из целого числа
	
		std::cout << "Введите целое число: " << std::endl;
		std::cin >> input_num;

		do {

			digit = input_num % 10;								//Извлечение остатка из Ввода и запись его в digit
			modulo = modulo + digit;							//К аккумулятору суммы чисел modulo = 0 прибавляем остаток digit. Старт аккума с числа  '0'
			input_num /= 10 ;									//Деление INT сносит знак после запятой и !ПЕРЕЗАПИСЫВАЕТ! в input_num целое число.
																//Цель - делить input на 10 до тех пор пока input = 10 [>>] например: 10/10=1 
																//затем финальная итерация 1/10 = 0.1 [>>] .1 НЕ отбрасывается-записывается в input_sum потому что INT.
																 //Условие while Соблюдено
															}

		while (input_num > 0);									//Повторяем до тех пор пока

	std::cout << "Сумма цифр: " << modulo << std::endl;

return 0;

}