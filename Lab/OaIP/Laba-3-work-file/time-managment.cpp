#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <limits>
using namespace std;

string path = "C:\\tmp\\tasks.txt";
string task, date;
int prioritet;

int main() { 
    int vibor; 
    do {
        cout << "1. Добавить\n"; 
        cout << "2. Поиск\n"; 
        cout << "3. Сортировка\n"; 
        cout << "4. Вывод\n"; 
        cout << "0. Завершить программу\n"; 

        cout << "Введите ваш выбор: "; 
        cin >> vibor;
        cin.ignore();

        ofstream fout;
        ifstream fin;

        switch (vibor) { 
            case 1: 
                    fout.open(path, ofstream::app);
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
                            cin >> prioritet;
                            cout << "Формат ввода 01/01/25 " << endl;
                            cout << "Введите сроки выполнения: " << endl;
                            getline(cin, date);
                            fout << "Задача: " << task << " Приоритет: " << prioritet << " Срок: " << date << endl;
                        }
                    }
                fout.close(); 
                break; 
            case 2: 
                    fin.open(path);
                    if (!fin.is_open()){
                        cout << "Ошибка при отрытии файла!" << endl;
                    } else {
                        string search;
                        cout << "Введите имя задачи: " << endl;
                        getline(cin, search);
                        string line;
                        bool found = false;
                        while (getline(fin, line)) {
                            if (line.find(search) != string::npos) { 
                                cout << "Найдено: " << line << endl;
                                found = true;
                                break;
                            }
                        }
                        if (!found)
                            cout << "Совпадений не найдено." << endl;
                    }
                    fin.close(); 
                break; 
            case 3: {
                fin.open(path);
                if (!fin.is_open()) {
                    cout << "Ошибка при открытии файла!" << endl;
                } else {
                    int uPriority;
                    cout << "Максимальный приоритет задачи: " << endl;
                    cin >> uPriority;
                    string line;
                    bool found = false;
                    while (getline(fin, line)) {
                        size_t pos = line.find("Приоритет:");
                        if (pos != string::npos) {
                            pos += 10;
                            while (pos < line.size() && !isdigit(line[pos])) pos++;
                            int tPriority = 0;
                            while (pos < line.size() && isdigit(line[pos])) {
                                tPriority = tPriority * 10 + (line[pos] - '0');
                                pos++;
                            }
                            if (tPriority != 0 && tPriority <= uPriority) {
                                cout << line << endl;
                                found = true;
                            }
                        }
                    }
                    if (!found)
                        cout << "Совпадений не найдено." << endl;
                }
                fin.close();
                break;
            } 
            case 0: 
                cout << "Программа завершена.\n"; 
                break; 
            
        default: 
                cout << "Неверный выбор. Попробуйте снова.\n"; 
            } 
        } while (vibor != 0); 
    return 0; 
}