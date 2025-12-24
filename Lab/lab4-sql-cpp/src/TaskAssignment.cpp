#include "../include/TaskAssignment.h"

using namespace std;
using namespace pqxx;

// INSERT
void TaskAssignment::create() {
    try {
        work tx(*db.getConnection());

        result r = tx.exec_params(
            "INSERT INTO task_assignments (task_id, user_id) "
            "VALUES ($1, $2) "
            "RETURNING assignment_id;",
            taskId, userId
        );

        assignmentId = r[0]["assignment_id"].as<int>();
        tx.commit();
    } catch (const exception& e) {
        cerr << "TaskAssignment::create error: " << e.what() << endl;
        throw;
    }
}

// SELECT по assigment_id
bool TaskAssignment::loadById(int id) {
    work tx(*db.getConnection());

    result r = tx.exec_params(
        "SELECT assignment_id, task_id, user_id "
        "FROM task_assignments "
        "WHERE assignment_id = $1;",
        id
    );
    if (r.empty()) {
        return false;
    }

    assignmentId = r[0]["assignment_id"].as<int>();
    taskId       = r[0]["task_id"].as<int>();
    userId       = r[0]["user_id"].as<int>();
    return true;
}

// UPDATE
void TaskAssignment::update() {
    try {
        work tx(*db.getConnection());

        tx.exec_params(
            "UPDATE task_assignments "
            "SET task_id = $1, user_id = $2 "
            "WHERE assignment_id = $3;",
            taskId, userId, assignmentId
        );

        tx.commit();
    } catch (const exception& e) {
        cerr << "TaskAssignment::update error: " << e.what() << endl;
        throw;
    }
}

// DELETE
void TaskAssignment::remove() {
    try {
        work tx(*db.getConnection());

        tx.exec_params(
            "DELETE FROM task_assignments "
            "WHERE assignment_id = $1;",
            assignmentId
        );

        tx.commit();
    } catch (const exception& e) {
        cerr << "TaskAssignment::remove error: " << e.what() << endl;
        throw;
    }
}
