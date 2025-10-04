#include <iostream>
using namespace std;

float sm = 0;
float m = 0;
int main() {
    cout << "Введите длину (в см.): " << endl;
    cin >> sm;
    m = sm / 100; 
    cout << m << " Метра(ов)" << endl; 

    return 0;
}