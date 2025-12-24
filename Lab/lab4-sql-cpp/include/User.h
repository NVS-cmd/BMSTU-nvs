#pragma once

#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "DbContext.h"

using namespace std;
using namespace pqxx;

class User {
public:
    int    id{};
    string name;

    User(DbContext& db) : db(db) {}

    // Операции с БД (реализация будет в User.cpp)
    void create();          // INSERT
    bool loadById(int id);  // SELECT по id
    void update();          // UPDATE
    void remove();          // DELETE

private:
    DbContext& db;
};
