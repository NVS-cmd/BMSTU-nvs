#pragma once
#include <pqxx/pqxx>
#include <memory>
using namespace std;

class DbContext {
public:
    explicit DbContext(const string& connStr)
        : conn(make_shared<pqxx::connection>(connStr)) {}

    shared_ptr<pqxx::connection> getConnection() { return conn; }

private:
    shared_ptr<pqxx::connection> conn;
};
