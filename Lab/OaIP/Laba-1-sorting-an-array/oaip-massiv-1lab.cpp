#include <iostream>
using namespace std;

int sum = 0;
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) { 
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int size = 10;
    int arr[size];
    cout << "Введите 10 целых чисел:" << endl;
    
    for (int i = 0; i < size; i++) {
        cout << "Число " << i+1 << ": ";
        cin >>  arr[i];
    }
        cout << "\nЭлементы массива: ";
    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "\nСумма всех элементов массива: " << sum << endl;


    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    cout << "Максимальный элемент массива: " << maxElement << endl;

    insertionSort(arr, size);
    cout << "\nОтсортированные элементы массива (по убыванию): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
