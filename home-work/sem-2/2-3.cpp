#include <iostream>
using namespace std;

float c = 0;
float f = 0;
int main() {
    cout << "Введите градусы Цельсия, а я их переведу их в Фаренгейты: " << endl;
    cin >> c;
    f = c * 9 / 5 + 32;
    cout << f << "F";

    return 0;
}