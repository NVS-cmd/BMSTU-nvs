#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1; // A
    double x2, y2; // B
    double x3, y3; // C
    double x4, y4; // D

    cout << "Введите координаты точки A: ";
    cin >> x1 >> y1;

    cout << "Введите координаты точки B: ";
    cin >> x2 >> y2;

    cout << "Введите координаты точки C: ";
    cin >> x3 >> y3;

    cout << "Введите координаты точки D: ";
    cin >> x4 >> y4;

    double opr = (y4 - y3) * (x1 - x2) - (x4 - x4) * (y1 - y2);
    if (opr != 0)
    {
        double Ua = ((x4 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2)) / opr;
        double Ub = ((x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2)) / opr;
        if(0 <= Ua <= 1 && 0 <= Ub <= 1)
        {
            cout << "Отрезки пересекаются";
        }
    } else {
            cout << "Отрезки непересекаются";
    }
    
    return 0;
}
