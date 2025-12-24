#include "../include/Analytics.h"

using namespace std;
using namespace pqxx;

void listHighPriorityTasks(DbContext& db) {
    try {
        nontransaction tx(*db.getConnection());
        result r = tx.exec(
            "SELECT id, title, priority, due_date, status "
            "FROM tasks "
            "WHERE priority = 'HIGH';"
        );

        cout << "\n--- High priority tasks ---\n";
        for (const auto& row : r) {
            int    id       = row["id"].as<int>();
            string title    = row["title"].as<string>();
            string priority = row["priority"].as<string>();
            string due      = row["due_date"].as<string>();
            string status   = row["status"].as<string>();

            cout << id << " | " << title
                 << " | " << priority
                 << " | " << due
                 << " | " << status << '\n';
        }
        if (r.empty()) {
            cout << "No high priority tasks.\n";
        }
    } catch (const exception& e) {
        cerr << "listHighPriorityTasks error: " << e.what() << endl;
    }
}

void countUsersWithAssignmentsLast30Days(DbContext& db) {
    try {
        nontransaction tx(*db.getConnection());
        result r = tx.exec(
            "SELECT COUNT(DISTINCT user_id) AS users_count "
            "FROM task_assignments "
            "WHERE assigned_date >= CURRENT_DATE - INTERVAL '30 days';"
        );

        int count = r[0]["users_count"].as<int>();
        cout << "\nUsers with assignments in last 30 days: "
             << count << '\n';
    } catch (const exception& e) {
        cerr << "countUsersWithAssignmentsLast30Days error: " << e.what() << endl;
    }
}

void listTasksDueNextWeek(DbContext& db) {
    try {
        nontransaction tx(*db.getConnection());
        result r = tx.exec(
            "SELECT id, title, priority, due_date, status "
            "FROM tasks "
            "WHERE due_date BETWEEN CURRENT_DATE "
            "AND CURRENT_DATE + INTERVAL '7 days';"
        );

        cout << "\n--- Tasks due next week ---\n";
        for (const auto& row : r) {
            int    id       = row["id"].as<int>();
            string title    = row["title"].as<string>();
            string priority = row["priority"].as<string>();
            string due      = row["due_date"].as<string>();
            string status   = row["status"].as<string>();

            cout << id << " | " << title
                 << " | " << priority
                 << " | " << due
                 << " | " << status << '\n';
        }
        if (r.empty()) {
            cout << "No tasks due next week.\n";
        }
    } catch (const exception& e) {
        cerr << "listTasksDueNextWeek error: " << e.what() << endl;
    }
}

void top3UsersByDoneTasks(DbContext& db) {
    try {
        nontransaction tx(*db.getConnection());
        result r = tx.exec(
            "SELECT u.id, u.name, COUNT(*) AS done_tasks "
            "FROM users u "
            "JOIN task_assignments ta ON ta.user_id = u.id "
            "JOIN tasks t             ON t.id      = ta.task_id "
            "WHERE t.status = 'DONE' "
            "GROUP BY u.id, u.name "
            "ORDER BY done_tasks DESC "
            "LIMIT 3;"
        );

        cout << "\n--- Top 3 users by DONE tasks ---\n";
        for (const auto& row : r) {
            int    id   = row["id"].as<int>();
            string name = row["name"].as<string>();
            int    cnt  = row["done_tasks"].as<int>();

            cout << id << " | " << name
                 << " | done tasks: " << cnt << '\n';
        }
        if (r.empty()) {
            cout << "No completed tasks yet.\n";
        }
    } catch (const exception& e) {
        cerr << "top3UsersByDoneTasks error: " << e.what() << endl;
    }
}