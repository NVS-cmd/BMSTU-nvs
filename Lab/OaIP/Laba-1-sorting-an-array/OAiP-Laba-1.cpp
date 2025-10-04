#include <iostream> 
using namespace std; 
int main() { 
const int size = 10; // Размер массива 
int numbers[size]; // Объявление массива 
int sum = 0; // Переменная для хранения суммы 
cout << "Введите " << size << " целых чисел:" << endl; 
for (int i = 0; i < size; i++) { 
cin >> numbers[i]; 
sum += numbers[i]; // Добавляем текущий элемент к сумме 
} 
cout << "Сумма всех элементов массива: " << sum << endl; 
return 0; 
}