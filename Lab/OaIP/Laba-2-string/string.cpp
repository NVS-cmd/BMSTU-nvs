#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    char *stri[20];
    const char search = ' ';
    cout << "Введите строку из 10 слов: ";

    cin.getline(stri, 20);
    char strchr(stri, fin);

    char *result = strchr(stri, search); 
    if (result != nullptr) { 
    cout << "Символ '" << search << "' найден в строке: " << result << 
    endl; 
    } else { 
        cout << "Символ '" << search << "' не найден в строке." << std::endl; 
    } 

    cout << "\nВывод: " << stri;
    return 0;
}