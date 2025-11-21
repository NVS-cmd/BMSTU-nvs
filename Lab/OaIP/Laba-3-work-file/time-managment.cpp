#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// Рабочие переменные
string path = "C:\\tmp\\tasks.txt"; //путь к файлу
int vibor = 1; //выбор меню пользователя
ofstream fout; //работа в файле
ifstream fin; //чтение файла
string task, date; //задача и дата
int prioritet; //приоритет 
string line;

// Скелеты ф-ции
void menu();
void gotoAdd();
void gotoFind();
void gotoPrior();
void gotoSort();
void gotoSortM(string pattern);
void gotoSortMin();
void gotoSortMax();

int main () {
    while (vibor != 0 ) {
        menu();
        cin >> vibor;
        switch(vibor) {
            case 1:
                gotoAdd();
                break;
            case 2:
                gotoFind();
                break;
            case 3:
                gotoPrior();
                break;
            case 4:
                gotoSort();
                break;
            case 0:
                cout << "Программа завершена.";
                break;
            default:
                cout << "Неверный выбор! Попробуй еще раз.\n";
        }
        cout << "Для продолжения нажмите пробел и Enter..." << endl;
        char ch;
        do {
            ch = cin.get();
        } while (ch != ' ');
    }
    return 0;
}

// Ф-ция вывода меню на экран
void menu() {
    cout << "1.Add\n2.Find\n3.Prioritet\n4.Sort\n0.Exit\nВведите ваш выбор:\n";
}

// Ф-ция добавления задачи в файл
void gotoAdd() {
    fout.open(path, ofstream::app);
    if(!fout.is_open()){
        cout << "Ошибка при отрытии файла!" << endl;
    } else {
        while (true){
            cout << "Введите название задачи: " << endl;
            cin.ignore();
            getline(cin, task);
            if (task.empty()) {
                break;
            }
            cout << "1 - ВЫСОКАЯ ВАЖНОСТЬ; 2 - CРЕДНЯЯ ВАЖНОСТЬ; 3 - НИЗКАЯ ВАЖНОСТЬ" << endl;
            cout << "Введите приоритет задачи: " << endl;
            cin >> prioritet;
            if (prioritet < 1 || prioritet > 3) {
                cout << "Нет такого приоритета!\n";
                break;
            }
            cin.ignore();
            cout << "Формат ввода дд.мм.гггг " << endl;
            cout << "Введите сроки выполнения: " << endl;
            getline(cin, date);
            if (date.length() != 10) {
                cout << "Неверный формат даты, попробуйте снова.\n";
                break;
            } else {
                date.replace(2, 1, "/");
                date.replace(5, 1, "/");
                date.replace(5, 1, "/");
            }
            fout << "Задача: " << task << " Приоритет: " << prioritet << " Срок: " << date << endl;
        }
    } fout.close();
}

// Ф-ция поиска
void gotoFind() {
    fin.open(path);
        if (!fin.is_open()){
            cout << "Ошибка при отрытии файла!" << endl;
        } else {
            string search;
            cout << "Введите имя задачи: " << endl;
            cin.ignore();
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
    } fin.close();
}

// Ф-ция сортировки приоритетов
void gotoPrior() {
    fin.open(path);
    if (!fin.is_open()) {
        cout << "Ошибка при открытии файла!" << endl;
    } else {
        int uPriority;
        cout << "Максимальный приоритет задачи: " << endl;
        cin >> uPriority;
        if (uPriority <= 3) {
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
    } fin.close();
}

void gotoSortMax () {
    fin.open(path);
    if (!fin.is_open()) {
        cout << "Ошибка при открытии файла!" << endl;
    } else {
        vector<string> lines;
        while (getline(fin, line)) {
        lines.push_back(line);
    }
        fin.close();
        gotoSortM("Приоритет: 3");
        gotoSortM("Приоритет: 2");   
        gotoSortM("Приоритет: 1");       
    }
}

void gotoSortMin () {
    fin.open(path);
    if (!fin.is_open()) {
        cout << "Ошибка при открытии файла!" << endl;
    } else {
        vector<string> lines;
        while (getline(fin, line)) {
        lines.push_back(line);
    }
        fin.close();
        gotoSortM("Приоритет: 1");
        gotoSortM("Приоритет: 2");   
        gotoSortM("Приоритет: 3");       
    }
}


// Cортировка по выбору
void gotoSortM(string pattern){
    fin.open(path); 
    while (getline(fin, line)) {
        if (line.find(pattern) != string::npos) {
        cout << line << endl;
        }
    } 
    fin.close();
}

void gotoSort() {
    cout << "1.По приоритету к БОЛЬШЕМУ\n2.По приоритету к МЕНЬШЕМУ\nВведите ваш выбор:\n";
    int y;
    cin >> y;
    switch (y) {
    case 1:
        gotoSortMin();
        break;
    case 2:
        gotoSortMax();
        break;
    default:
        break;
    }

}