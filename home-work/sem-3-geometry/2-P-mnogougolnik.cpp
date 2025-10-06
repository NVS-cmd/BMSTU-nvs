#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n = 4;
    vector<double> x(n), y(n);

    for (int i = 0; i < n; ++i) {
        cout << "Введите координаты вершины " << i+1 << ": ";
        cin >> x[i] >> y[i];
    }

    double p = 0;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        double dx = x[j] - x[i];
        double dy = y[j] - y[i];
        p += sqrt(dx*dx + dy*dy);
    }

    cout << "Периметр многоугольника: " << p << endl;

    return 0;
}
