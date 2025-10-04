#include <iostream>

using namespace std;

int k = 0;
int main() {
    cout << "Введите число: " << endl;
    cin >> k;
    if (k > 0) {
        cout << "Число положительное " << endl;
    } else if(k < 0) {
        cout << "Число отрицательное " << endl;
    } else {
        cout << "Число = 0 " << endl;
    }
    return 0;
}