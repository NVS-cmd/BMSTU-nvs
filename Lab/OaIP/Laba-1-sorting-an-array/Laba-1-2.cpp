#include <iostream>
using namespace std;

int main() {
    int n;
    int p = 1;

    cout << "Введите количество машин: ";
    cin >> n;

    int i = n;
    while (i >= 1) {
        p = i * p;
        i = i - 1;
    }

    cout << "Факториал: " << p << endl;
    return 0;
}