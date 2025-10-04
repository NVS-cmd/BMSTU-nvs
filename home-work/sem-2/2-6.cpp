#include <iostream>
using namespace std;

int x = 0;
int z = 0;
int y = 0;
int main() {
    cout << "Введите людое число, а я напишу четное оно или нет: " << endl;
    cin >> x;

    if (x < 18) {
        cout << "Меньше 18";
    } else if (x >= 18 && x <= 60){
        cout << "От 18 до 60";
    } else {
        cout << "Больше 60";
    }

    return 0;
}