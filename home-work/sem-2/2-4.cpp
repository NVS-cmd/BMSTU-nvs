#include <iostream>
using namespace std;

int x = 0;
int z = 0;
int main() {
    cout << "Введите людое число, а я напишу четное оно или нет: " << endl;
    cin >> x;
    int z = x % 2;
    if (z == 0) {
        cout << "Число четное";
    } else {
        cout << "Число нечетное";
    }

    return 0;
}