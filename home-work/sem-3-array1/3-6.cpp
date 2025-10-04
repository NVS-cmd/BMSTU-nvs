#include <iostream>
using namespace std;

float mass[4] = {};
int n = sizeof(mass) / sizeof(mass[0]); 
int temp = 0;

int main() {
    for (int i = 0; i < n; i++) {
        cout << "Введите " << i + 1 << " значение: ";
        cin >> mass[i];
    }
    float summ = 0;
    float nmin = 0;
    float nmax = 0;
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
    if (nmin == 1 && nmax == 0) {
        for (int i = 0; i < n; i++) {
            mass[i]/=2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    return 0;
}