CREATE DATABASE task_management_db;
\c task_management_db

CREATE TYPE priority AS ENUM ('HIGH', 'MEDIUM', 'LOW');
CREATE TYPE status AS ENUM ('DONE', 'IN_PROGRESS', 'POSTPONED');
CREATE TABLE tasks (
	id INT GENERATED ALWAYS AS IDENTITY (START WITH 100) PRIMARY KEY,
	title TEXT NOT NULL,
	priority priority NOT NULL,
	due_date DATE NOT NULL,
	status status NOT NULL
);

CREATE TABLE users (
	id INT GENERATED ALWAYS AS IDENTITY (START WITH 100) PRIMARY KEY,
	name TEXT
);

CREATE TABLE task_assignments (
	assignment_id INT GENERATED ALWAYS AS IDENTITY (START WITH 1) PRIMARY KEY,
	task_id INT,
	user_id INT,
	FOREIGN KEY (task_id) REFERENCES tasks(id),
	FOREIGN KEY (user_id) REFERENCES users(id)
);

ALTER TABLE task_assignments 
ADD COLUMN assigned_date DATE DEFAULT CURRENT_DATE;