#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1; // A
    double x2, y2; // B
    double x3, y3; // C

    cout << "Введите координаты точки A: ";
    cin >> x1 >> y1;

    cout << "Введите координаты точки B: ";
    cin >> x2 >> y2;

    cout << "Введите координаты точки C: ";
    cin >> x3 >> y3;

    double ABx = (x2 - x1);
    double ABy = (y2 - y1);
    double ACx = (x3 - x1);
    double ACy = (y3 - y1);
    double sk = ABx * ACy - ABy * ACx;
    if (sk == 0)
    {
        cout << "\nТочки лежат на прямой";
    } else {
        cout << "\nТочки нележат на прямой";
    }
    return 0;
}
