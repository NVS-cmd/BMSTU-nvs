#include <iostream>
using namespace std;

float a = 0;
float b = 0;
float s = 0;
int main() {
    cout << "Введите длину прямоугольника, затем его ширину" << endl;
    cin >> a;
    cin >> b;
    s = a * b;
    cout << "Площадь треугольника равна: " << s;

    return 0;
}