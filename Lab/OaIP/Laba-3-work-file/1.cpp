#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

string path = "C:\\tmp\\tasks.txt";
string task {" "};
string prioritet {" "};
string date {" "};

int main() {

    ofstream fout;

    fout.open(path, ofstream::app);
    // Добавление задач
    if(!fout.is_open()){
        cout << "Ошибка при отрытии файла!" << endl;
    } else {
        while (true){
            cout << "Введите название задачи: " << endl;
            getline(cin, task);
            if (task.empty()) {
                break;
            }
            cout << "1 - ВЫСОКАЯ ВАЖНОСТЬ; 2 - CРЕДНЯЯ ВАЖНОСТЬ; 3 - НИЗКАЯ ВАЖНОСТЬ" << endl;
            cout << "Введите приоритет задачи: " << endl;
            getline(cin, prioritet);
            cout << "Введите сроки выполнения: " << endl;
            getline(cin, date);
            fout << "Задача: " << task << " Приоритет: " << prioritet << " Срок: " << date << endl;
        }
    }
    fout.close();

    return 0;
}