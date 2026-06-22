#include <iostream>
#include <string>

int main() {


	int A;							// Input Me
	int B;							// Input Me
	std:: string strA = " ";		// A to string
	std:: string strB = " ";		// B to string
	std:: string compare;			// Compare-operator to string
    int uno;                        // Для склейки чисел от 0 до 9 и от 21 (вкл) до 99
    int deci;                       // Для склейки чисел ...дцать
    int tempA;	                    // Буфер и ввод в решение для А
    int tempB;                      // Буфер и ввод в решение для Б

	std:: cout << "Введите целое число: " ;
	std:: cin >> A;
	std:: cout << "Введите целое число: " ;
	std:: cin >> B ;
	
	//BOUNDARY CONDITION BLOCK
	if (A < -100 || A > 100 || B < -100 || B > 100) {
		std:: cout << "Ошибка! Одно из чисел вне диапазона!";
		return 1;
	}

	//NUM-TO-TEXT BLOCK
		//CONVERT A
			// A NEGATIVE NUMS
			// UNO
			// DECI

		//CONVERT B
			// B NEGATIVE NUMS
			// UNO
			// DECI

	// ASSEMBLY


        //BLOCK [A] CONVERT
///////////////////////////////////////////////////////////////////

        strA += (A < 0) ? "минус " : "";        // подстановка в результат знака числа
        tempA = (A < 0) ? -A : A;              // удаление знака "-" т.к. он мешает замене числа на строчку

        if (tempA == 0) { strA = "ноль"; }       // сспециальная замена под число 0
            else if (tempA >= 10 && tempA <= 19)            // замены от 10 до 19.
            {
                switch (tempA) {
                case 10: strA += "десять"; break;
                case 11: strA += "одиннадцать"; break;
                case 12: strA += "двенадцать"; break;
                case 13: strA += "тринадцать"; break;
                case 14: strA += "четырнадцать"; break;
                case 15: strA += "пятнадцать"; break;
                case 16: strA += "шестнадцать"; break;
                case 17: strA += "семнадцать"; break;
                case 18: strA += "восемнадцать"; break;
                case 19: strA += "девятнадцать"; break;
                }
            } 
        else {
            uno = tempA % 10;                                           // Деление с остатком чтобы разложить число на запчасти
            deci = tempA / 10;
            
            switch (deci) {
                case 2: strA += "двадцать"; break;
                case 3: strA += "тридцать"; break;
                case 4: strA += "сорок"; break;
                case 5: strA += "пятьдесят"; break;
                case 6: strA += "шестьдесят"; break;
                case 7: strA += "семьдесят"; break;
                case 8: strA += "восемьдесят"; break;
                case 9: strA += "девяносто"; break;
            }

            
            strA += (deci > 0 && uno > 0) ? " " : "";   // Если-да то добавит Пробел для двухзначного числа. Либо уберет пробел при однозначном

            switch (uno) {
                case 1: strA += "один"; break;
                case 2: strA += "два"; break;
                case 3: strA += "три"; break;
                case 4: strA += "четыре"; break;
                case 5: strA += "пять"; break;
                case 6: strA += "шесть"; break;
                case 7: strA += "семь"; break;
                case 8: strA += "восемь"; break;
                case 9: strA += "девять"; break;
            }
        }

        //BLOCK [B] CONVERT
///////////////////////////////////////////////////////////////////
        strB += (B < 0) ? "минус " : "";
        tempB = (B < 0) ? -B : B;

        if (tempB == 0) { strB = "ноль"; }
            else if (tempB >= 10 && tempB <= 19) 
            {
            switch (tempB) {
                case 10: strB += "десять"; break;
                case 11: strB += "одиннадцать"; break;
                case 12: strB += "двенадцать"; break;
                case 13: strB += "тринадцать"; break;
                case 14: strB += "четырнадцать"; break;
                case 15: strB += "пятнадцать"; break;
                case 16: strB += "шестнадцать"; break;
                case 17: strB += "семнадцать"; break;
                case 18: strB += "восемнадцать"; break;
                case 19: strB += "девятнадцать"; break;
            }
        } 
        else {
            deci = tempB / 10;
            uno = tempB % 10;

            switch (deci) {
                case 2: strB += "двадцать"; break;
                case 3: strB += "тридцать"; break;
                case 4: strB += "сорок"; break;
                case 5: strB += "пятьдесят"; break;
                case 6: strB += "шестьдесят"; break;
                case 7: strB += "семьдесят"; break;
                case 8: strB += "восемьдесят"; break;
                case 9: strB += "девяносто"; break;
            }

            strB += (deci > 0 && uno > 0) ? " " : "";

            switch (uno) {
                case 1: strB += "один"; break;
                case 2: strB += "два"; break;
                case 3: strB += "три"; break;
                case 4: strB += "четыре"; break;
                case 5: strB += "пять"; break; break;
                case 6: strB += "шесть"; break;
                case 7: strB += "семь"; break;
                case 8: strB += "восемь"; break;
                case 9: strB += "девять"; break;
            }
        }

    // ASSEMBLY BLOCK
    std::string action = (A > B) ? " больше чем " : ((A < B) ? " меньше чем " : " равно ");
    
    std::cout << strA << action << strB << std::endl;

    return 0;
}
