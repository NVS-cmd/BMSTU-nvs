#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int mass[] = {3, 5, 8, 10};
    int n = sizeof(mass) / sizeof(mass[0]); 
    int sum = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        int j = pow(2, i+1);
        cout << j << endl;
        if(mass[i] > j) {
            sum++;
            
        }
    }
    cout << sum;

    return 0;
}