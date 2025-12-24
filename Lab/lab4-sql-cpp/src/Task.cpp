#include "../include/Task.h"

using namespace std;
using namespace pqxx;

// INSERT
void Task::create() {
    try {
        work tx(*db.getConnection());  // начало транзакции

        result r = tx.exec_params(
            "INSERT INTO tasks (title, priority, due_date, status) "
            "VALUES ($1, $2, $3, $4) "
            "RETURNING id;",
            title, priority, dueDate, status
        );

        id = r[0]["id"].as<int>();

        tx.commit(); // фиксируем изменения
    } catch (const exception& e) {
        cerr << "Task::create error: " << e.what() << endl;
        throw; // транзакция откатится автоматически, т.к. commit не был вызван
    }
}

// SELECT по id
bool Task::loadById(int taskId) {
    work tx(*db.getConnection());

    result r = tx.exec_params(
        "SELECT id, title, priority, due_date, status "
        "FROM tasks WHERE id = $1;",
        taskId
    );
    if (r.empty()) {
        return false;
    }

    id       = r[0]["id"].as<int>();
    title    = r[0]["title"].as<string>();
    priority = r[0]["priority"].as<string>();
    dueDate  = r[0]["due_date"].as<string>();
    status   = r[0]["status"].as<string>();
    return true;
}

// UPDATE всех полей по id
void Task::update() {
    try {
        work tx(*db.getConnection());

        tx.exec_params(
            "UPDATE tasks "
            "SET title = $1, priority = $2, due_date = $3, status = $4 "
            "WHERE id = $5;",
            title, priority, dueDate, status, id
        );

        tx.commit();
    } catch (const exception& e) {
        cerr << "Task::update error: " << e.what() << endl;
        throw;
    }
}

// DELETE по id
void Task::remove() {
    try {
        work tx(*db.getConnection());

        tx.exec_params(
            "DELETE FROM tasks WHERE id = $1;",
            id
        );

        tx.commit();
    } catch (const exception& e) {
        cerr << "Task::remove error: " << e.what() << endl;
        throw;
    }
}
