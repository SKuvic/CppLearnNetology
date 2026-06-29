#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()


int main () {

    srand(time(0));
    int arr_ten [10];
      
        for (size_t i = 0; i < 10; i++)                         // Заполнение i-'элементов массива счетчиком; i++ ЭТО i=i+1 - шаг массива
            {
                arr_ten[i] = rand () / 1001;                      //i+1 - стартовое значение привязанный к i. = (i + 1) * 2 - дает шаг +2 к следующему элементу.
            }                                                   //rand ()/1001; - Случайное двухзначное

        // for (size_t i = 0; i < 9; i++)                       //Цикл для вывода массива через For - стандартный
        //     {
        //         std:: cout << arr_ten[i] << ", ";
        //     }

        // std:: cout << arr_ten[9];                            // Индивидуальное обращение-вызов по индексу 9, чтобы дописать последнее значение без ','
        
        for (size_t i = 0; i < 10; i++)                          //for c Вложенным циклом if-else c авто-отсечением запятой
            {
                if (i < 9) {
                    std:: cout << arr_ten[i] << ", ";
                }
                else {
                    std:: cout << arr_ten[i] << " ";
                }
             }
 
    return 0;

}
