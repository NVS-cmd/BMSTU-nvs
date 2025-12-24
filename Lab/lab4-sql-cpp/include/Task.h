#pragma once

#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "DbContext.h"

using namespace std;
using namespace pqxx;

class Task {
public:
    int    id{};
    string title;
    string priority; // 'Высокий', 'Средний', 'Низкий'
    string dueDate;  // формат: yyyy-mm-dd
    string status;   // 'Выполнена', 'В процессе', 'Отложена'

    Task(DbContext& db) : db(db) {}

    // Операции с БД (все реализуются с транзакциями в Task.cpp)
    void create();             // INSERT
    bool loadById(int taskId); // SELECT по id
    void update();             // UPDATE
    void remove();             // DELETE

private:
    DbContext& db;
};
