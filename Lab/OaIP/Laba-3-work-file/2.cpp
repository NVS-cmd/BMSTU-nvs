#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

string path = "C:\\tmp\\tasks.txt";
string task {" "};
string prioritet {" "};
string date {" "};

int main() {

    // ofstream fout;
    // fout.open(path, ofstream::app);
    // if(!fout.is_open()){
    //     cout << "Ошибка при отрытии файла!" << endl;
    // } else {
    //     while (true){
    //         cout << "Введите название задачи: " << endl;
    //         getline(cin, task);
    //         if (task.empty()) {
    //             break;
    //         }
    //         cout << "1 - ВЫСОКАЯ ВАЖНОСТЬ; 2 - CРЕДНЯЯ ВАЖНОСТЬ; 3 - НИЗКАЯ ВАЖНОСТЬ" << endl;
    //         cout << "Введите приоритет задачи: " << endl;
    //         getline(cin, prioritet);
    //         cout << "Формат ввода 01/01/25 " << endl;
    //         cout << "Введите сроки выполнения: " << endl;
    //         getline(cin, date);
    //         fout << "Задача: " << task << " Приоритет: " << prioritet << " Срок: " << date << endl;
    //     }
    // }
    // fout.close();

    // ifstream fin;
    // fin.open(path);
    // if (!fin.is_open()){
    //     cout << "Ошибка при отрытии файла!" << endl;
    // } else {
    //     string search;
    //     cout << "Введите имя задачи: " << endl;
    //     cin >> search;
    //     string line;
    //     bool found = false;
    //     while (getline(fin, line)) {
    //         if (line.find(search) != string::npos) { 
    //             cout << "Найдено: " << line << endl;
    //             found = true;
    //             break;
    //         }
    //     }
    //     if (!found)
    //         cout << "Совпадений не найдено." << endl;
    // }
    // fin.close();

    return 0;
}