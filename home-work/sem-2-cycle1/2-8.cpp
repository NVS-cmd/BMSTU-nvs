#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);

    int count = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'y' ||
            c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'Y' ||
            c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }

    std::cout << "Гласных букв: " << count << std::endl;
    return 0;
}