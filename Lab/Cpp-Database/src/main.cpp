#include <iostream>
#include <pqxx/pqxx>
using namespace std;

int main() {
    try {
        // Строка подключения к базе данных
        string conninfo = "host=localhost port=1234 dbname=postgres user=postgres password=";

        // Устанавливаем соединение с базой данных
        pqxx::connection conn(conninfo);

        if (conn.is_open()) {
            cout << "Connected to database: " << conn.dbname() << endl;
        } else {
            cerr << "Failed to connect to the database." << endl;
            return 1;
        }

        // Закрываем соединение
        conn.close();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}








// #include <iostream>
// #include <pqxx/pqxx>
// int main()
// {
//     try
//     {
//         pqxx::connection conn(
//             "host=localhost "
//             "port=5432 "
//             "dbname=postgres "
//             "user=postgres "
//             "password=qwerty"
//         );
//         pqxx::work txn{conn};
//         txn.exec(
//             "CREATE TABLE IF NOT EXISTS users ("
//             "id SERIAL PRIMARY KEY,"
//             "name VARCHAR(100) NOT NULL,"
//             "email VARCHAR(100) UNIQUE NOT NULL,"
//             "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
//             ")"
//         );
//         txn.commit();
//         cout << "Таблица создана/уже существует" << endl;
//     }
//     catch (const exception& e)
//     {
//         cerr << "Ошибка создания таблицы: " << e.what() << endl;
//     }
//     return 0;
// }