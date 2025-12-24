#pragma once

#include <iostream>
#include <pqxx/pqxx>
#include "DbContext.h"

using namespace std;
using namespace pqxx;

void listHighPriorityTasks(DbContext& db);
void countUsersWithAssignmentsLast30Days(DbContext& db);
void listTasksDueNextWeek(DbContext& db);
void top3UsersByDoneTasks(DbContext& db);