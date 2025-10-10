#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    string stroka;
    cout << "Введите предложение: ";
    getline(cin, stroka);
    
    // Рабочие переменные
    stroka += ' ';
    int probel[10] = {}; // Массив пробелов
    int a = 0; // Счетчик идекса пробела
    int s = size(stroka); // Кол-во символов в строке
    int countB = 0; // Буква Б (1 задание)
    int sizeSlovo = 0; //Размер длинного слова (2 задание)
    probel[0] = -1; // Начало строки
    a = 1; // (2 задание)
    int countD = 0; // (3 задание)
    int last = stroka.size() - 2; // индекс последнего символа (3 задание)
    int y = 0; // счетчик слов (5 задание)

    

    // Цикл пробелов
    for (int i = 0; i < s; i++)
    {
        if (stroka[i] == ' ')
        {
            probel[a] = i;
                                // Задание 1 - Найти количество слов, оканчивающих на буквы b
            if (stroka[i-1] == 'b')
            {
                countB++;
            }
                                // Задание 2 - Найти длину самого длинного слова 
        
        int b = probel[a] - probel[a-1] - 1;
        if (sizeSlovo < b)
            {
                sizeSlovo = b;
            }
        a++;
        }
    }
                            // Задание 3 - Подсчитать количество букв d в последнем слове строки 
    int f = last;
    while (f >= 0 && stroka[f] != ' ') {
        f--;
    }
        f++;
        for (f; f <= last; f++) {
            if (stroka[f] == 'd') 
            {
                countD++;
            }
        }
                            // Задание 4 - Заменить все строчные буквы на буквы верхнем регистре
    for (int i = 0; i < s; i++)
    {
        stroka[i] = toupper(stroka[i]);
    }
                            // Задание 5 - Найти количество слов, у которых совпадает второй и предпоследний символ 
    for (int i = 1; i < a; i++) {
    int start = probel[i-1] + 1;
    int end = probel[i] - 1;
    if (stroka[start + 1] == stroka[end - 1]) {
        y++;
    }
    
} 

    cout << "Слов, оканчивающихся на 'b': " << countB << endl;
    cout << "Длина самого длинного слова: " << sizeSlovo << endl;
    cout << "Количество букв 'd' в последнем слове: " << countD << endl;
    cout << "Строка в верхнем регистре: " << stroka << endl;
    cout << "Количество слов с одинаковыми второй и предпоследней буквами: " << y << endl;

    return 0;
}