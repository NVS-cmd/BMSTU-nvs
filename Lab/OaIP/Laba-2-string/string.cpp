#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string stroka;
    string stroka1;
    cout << "Введите 10 слов используя латинские символы: ";
    getline(cin, stroka1);

    stroka = stroka1 + ' ';
    
    int probel = 0;
    int probel1 = 0; // 3 задача
    int i = 0;
    int LastBukvaD = 0;
    int b = 0; // 2 задача
    int s = size(stroka);
    int bukvaB = 0;
    char findBuk = 'b';
    //                                     1 Задача - Найти количество слов, оканчивающих на буквы b 
    // for(int i = 0; i <= s; i++)
    // {
    //     if(stroka[i] == ' ') // Ищем пробелы, и делаем -1 (понимаем что это конец слова)
    //     {
    //         probel += 1;
    //         if(stroka[i-1] == findBuk) // Цикл поска нужной буквы в конце слова
    //         {
    //             bukvaB += 1;
    //         }
    //     }
    // }
    
    // cout << stroka << "\n" << s << "\n" << probel << "\n" << bukvaB;

    // //                                            2 задача - Найти длину самого длинного слова "Hello5Bro9my12name17is20Vlad25"
    //     for(int i = 0; i <= s; i++)
    // {
    //     if(stroka[i] == ' ') 
    //     {
    //         int a = i - probel - 1;
    //         probel = i;
    //         if (b < a)
    //         {
    //             b = a;
    //         }
    //     }
    // }
    // cout << b << endl;

        //                                            3 задача - Подсчитать количество букв d в последнем слове строки 
        for(int i = 0; i < s; i++)
        {
            b = stroka1.rfind(' ');
            for (b; b <= s; b++)
            {
                if (stroka[b] == 'd')
                {
                    LastBukvaD += 1;
                }
            }
        }

    cout << LastBukvaD << endl;

    return 0;
}