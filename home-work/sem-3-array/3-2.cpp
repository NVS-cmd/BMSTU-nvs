#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int mass[] = {3, 5, 8, 15};
    int n = sizeof(mass) / sizeof(mass[0]); 
    int sum = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(mass[i] % 2 == 0) {
            sum++;
        } else {
            if (j < mass[i]) {
                j = mass[i];
            }
        }
    }
    cout << sum << endl;
    cout << j;

    return 0;
}