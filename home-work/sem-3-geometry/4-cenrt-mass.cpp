#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    double x1, y1; // A
    double x2, y2; // B
    double x3, y3; // C

    cout << "Введите координаты вершины A: ";
    cin >> x1 >> y1;

    cout << "Введите координаты вершины B: ";
    cin >> x2 >> y2;

    cout << "Введите координаты вершины C: ";
    cin >> x3 >> y3;

    double C1 = x1 + x2 + x3;
    C1 /= 3;
    double C2 = y1 + y2 + y3;
    C2 /= 3;

    cout << "Координаты центра масс треугольника равен: (" << C1  << ":" << C2 << ")" << endl;

    return 0;
}
