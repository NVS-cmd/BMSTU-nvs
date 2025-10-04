#include <iostream>
using namespace std;

int main() {
    int i = 0;
    cout << "Введите скорость автомобиля: " << endl;
     cin >> i;
     if(i <= 59)
     {
        cout << "Скорость в пределах нормы" << endl;
     } else if (i >= 81) 
     {
         cout << "Превышение скорости!" << endl;
     } else
     {
         cout << "Вы приближаетесь к превышению скорости" << endl;
     }
     return 0;
}