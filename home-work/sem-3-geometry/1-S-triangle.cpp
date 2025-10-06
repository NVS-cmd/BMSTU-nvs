#include <iostream>
#include <cmath>
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

    double s = 0.5 * fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));

    cout << "Площадь треугольника равна: " << s << endl;

    return 0;
}
