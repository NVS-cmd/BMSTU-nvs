#include <iostream>
using namespace std;

int x = 0;
int z = 0;
int y = 0;
int main() {
    cout << "Введите людое число, а я напишу четное оно или нет: " << endl;
    cin >> x;
    int z = x % 3;
    cout <<  z << endl;
    int y = x % 5;
    cout <<  y << endl;
    if (z == 0 && y == 0) {
        cout << "Делится на оба числа";
    } else if (z > 0 && y == 0){
        cout << "Делится только на 5";
    } else if (z == 0 && y > 0){
        cout << "Делится только на 3";
    } else {
        cout << "Не делится без остатка";
    }

    return 0;
}