#include "../include/User.h"

using namespace std;
using namespace pqxx;

// INSERT
void User::create() {
    try {
        work tx(*db.getConnection());

        result r = tx.exec_params(
            "INSERT INTO users (name) VALUES ($1) RETURNING id;",
            name
        );

        id = r[0]["id"].as<int>();
        tx.commit();
    } catch (const exception& e) {
        cerr << "User::create error: " << e.what() << endl;
        throw;
    }
}

// SELECT по id
bool User::loadById(int userId) {
    work tx(*db.getConnection());

    result r = tx.exec_params(
        "SELECT id, name FROM users WHERE id = $1;",
        userId
    );
    if (r.empty()) {
        return false;
    }

    id   = r[0]["id"].as<int>();
    name = r[0]["name"].as<string>();
    return true;
}

// UPDATE
void User::update() {
    try {
        work tx(*db.getConnection());

        tx.exec_params(
            "UPDATE users SET name = $1 WHERE id = $2;",
            name, id
        );

        tx.commit();
    } catch (const exception& e) {
        cerr << "User::update error: " << e.what() << endl;
        throw;
    }
}

// DELETE
void User::remove() {
    try {
        work tx(*db.getConnection());

        tx.exec_params(
            "DELETE FROM users WHERE id = $1;",
            id
        );

        tx.commit();
    } catch (const exception& e) {
        cerr << "User::remove error: " << e.what() << endl;
        throw;
    }
}
