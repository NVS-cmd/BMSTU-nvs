#include <iostream>
using namespace std;

int mass[10] = {};
int n = sizeof(mass) / sizeof(mass[0]); 
int temp = 0;

int main() {
    for (int i = 0; i < n; i++) {
        cout << "Введите " << i + 1 << " значение: ";
        cin >> mass[i];
    }

    int nmin = 0;
    int nmax = 0;
    int min = mass[0];
    int max = mass[0];

    for(int i = 0; i < n; i++) {
        if(min > mass[i]) {
            min = mass[i];
            nmin = i;
        } else if (max < mass[i]) {
            max = mass[i];
            nmax = i;
        }
    }
    if (nmax == 1 || nmin == 4) {
        for (int i = nmin;  i < n; i++) {
            mass[i] = max;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    return 0;
}