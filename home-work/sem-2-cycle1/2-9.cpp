#include <iostream>
using namespace std;

int x = 0;
int z = 0;
int y = 0;
int sum = 0;

int main() {
    cout << "введите число: " << endl;
    cin >> x;
    if (x % 2 == 0 || x % 5 == 0) {
        for (int y = 0; y <= x; y++) {
        sum += y;
        }
    }
    cout << sum;
    return 0;
}