#include <iostream>
using namespace std;

int x = 0;
int y = 0;
int z = 0;
int main() {
    cout << "Введите людое число: " << endl;
    cin >> x;
    for (int y = 0; y <= x; y++) {
        z = y * y;
        cout << z << endl;
    }

    return 0;
}