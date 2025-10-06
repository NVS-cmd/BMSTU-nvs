#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    double x1, y1; // A
    double x2, y2; // B
    double x3, y3; // C
    double x4, y4; // D

    cout << "Введите координаты вершины A: ";
    cin >> x1 >> y1;

    cout << "Введите координаты вершины B: ";
    cin >> x2 >> y2;

    cout << "Введите координаты вершины C: ";
    cin >> x3 >> y3;

    cout << "Введите координаты вершины D: ";
    cin >> x4 >> y4;

    double CD = y3 - y4;
    double AD = x4 - x1;
    double AC = sqrt(pow(AD, 2) + pow(CD, 2));

    cout << "Длина диагонали треугольника равна: " << AC << endl;

    return 0;
}
