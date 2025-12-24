#pragma once

#include <iostream>
#include <pqxx/pqxx>
#include "DbContext.h"

using namespace std;
using namespace pqxx;

class TaskAssignment {
public:
    int assignmentId{};
    int taskId{};
    int userId{};

    TaskAssignment(DbContext& db) : db(db) {}

    // Операции с БД (реализация будет в TaskAssignment.cpp)
    void create();             // INSERT
    bool loadById(int id);     // SELECT по assigment_id
    void update();             // UPDATE
    void remove();             // DELETE

private:
    DbContext& db;
};
