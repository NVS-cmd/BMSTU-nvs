#include <iostream>
#include <pqxx/pqxx>
#include "../include/DbContext.h"
#include "../include/Task.h"
#include "../include/User.h"
#include "../include/TaskAssignment.h"
#include "../include/Analytics.h"
#include "../include/Logger.h"

using namespace std;
using namespace pqxx;

void printMenu() {
    cout << "\n===== Task Manager =====\n";
    cout << "1. Add task\n";
    cout << "2. Add user\n";
    cout << "3. Assign task to user\n";
    cout << "4. Change task status\n";
    cout << "5. List HIGH priority tasks\n";
    cout << "6. Count users with assignments last 30 days\n";
    cout << "7. List tasks due next week\n";
    cout << "8. Top-3 users by DONE tasks\n";
    cout << "0. Exit\n";
    cout << "Choose option: ";
}

void addTask(DbContext& db) {
    Task task(db);

    cout << "Title: ";
    getline(cin >> ws, task.title);

    cout << "Priority (HIGH/MEDIUM/LOW): ";
    cin >> task.priority;

    cout << "Due date (YYYY-MM-DD): ";
    cin >> task.dueDate;

    cout << "Status (IN_PROGRESS/DONE/POSTPONED): ";
    cin >> task.status;

    try {
        task.create();
        cout << "Task created, id = " << task.id << endl;
    } catch (const exception& e) {
        cerr << "addTask error: " << e.what() << endl;
    }
}

void addUser(DbContext& db) {
    User user(db);

    cout << "User name: ";
    getline(cin >> ws, user.name);

    try {
        user.create();
        cout << "User created, id = " << user.id << endl;
    } catch (const exception& e) {
        cerr << "addUser error: " << e.what() << endl;
    }
}

void assignTask(DbContext& db) {
    int taskId, userId;
    cout << "Task id: ";
    cin >> taskId;
    cout << "User id: ";
    cin >> userId;

    TaskAssignment ta(db);
    ta.taskId = taskId;
    ta.userId = userId;

    try {
        ta.create();
        cout << "Assignment created, id = " << ta.assignmentId << endl;
    } catch (const exception& e) {
        cerr << "assignTask error: " << e.what() << endl;
    }
}

void changeTaskStatus(DbContext& db) {
    int taskId;
    string newStatus;

    cout << "Task id: ";
    cin >> taskId;
    cout << "New status (IN_PROGRESS/DONE/POSTPONED): ";
    cin >> newStatus;

    Task task(db);
    if (!task.loadById(taskId)) {
        cout << "Task not found\n";
        return;
    }

    task.status = newStatus;

    try {
        task.update();
        cout << "Status updated\n";
    } catch (const exception& e) {
        cerr << "changeTaskStatus error: " << e.what() << endl;
    }
}

Logger logger;

int main() {
    LOG("PROGRAM", "Task Manager started");

    try {
        DbContext db("dbname=task_management_db user=postgres password=1234 host=localhost port=1234");

        int choice = -1;
        while (true) {
            printMenu();
            if (!(cin >> choice)) break;

            switch (choice) {
                case 1: addTask(db);                             break;
                case 2: addUser(db);                             break;
                case 3: assignTask(db);                          break;
                case 4: changeTaskStatus(db);                    break;
                case 5: listHighPriorityTasks(db);               break;
                case 6: countUsersWithAssignmentsLast30Days(db); break;
                case 7: listTasksDueNextWeek(db);                break;
                case 8: top3UsersByDoneTasks(db);                break;
                case 0: 
                    cout << "Exit...\n";
                    return 0;
                default:
                    cout << "Unknown option\n";
            }
        }
    } catch (const exception& e) {
        LOG_ERROR("DATABASE", "Connection failed");
        cerr << "MAIN ERROR: " << e.what() << endl;
    }

    return 0;
}
