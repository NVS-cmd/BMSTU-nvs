CREATE TYPE priority AS ENUM ('Высокий', 'Средний', 'Низкий');
CREATE TYPE status AS ENUM ('Выполнена', 'В процессе', 'Отложена');
CREATE TABLE tasks (
	id INT GENERATED ALWAYS AS IDENTITY (START WITH 100) PRIMARY KEY,
	title VARCHAR (50) NOT NULL,
	priority priority NOT NULL,
	due_date DATE NOT NULL,
	status status NOT NULL
);

CREATE TABLE users (
	id INT GENERATED ALWAYS AS IDENTITY (START WITH 100) PRIMARY KEY,
	name VARCHAR (50)
);

CREATE TABLE task_assigments (
	assigment_id INT GENERATED ALWAYS AS IDENTITY (START WITH 1) PRIMARY KEY,
	task_id INT,
	user_id INT,
	FOREIGN KEY (task_id) REFERENCES tasks(id),
	FOREIGN KEY (user_id) REFERENCES users(id)
);

INSERT INTO users (name)
VALUES ('Vlad'),
	('Alex'),
	('Vasiliy');

INSERT INTO tasks (title, priority, due_date, status)
VALUES ('Сделать отчёт', 'Средний', '07.10.2025', 'Выполнена'),
	('Переустановить ОС', 'Низкий', '10.12.2025', 'Отложена'),
	('Сделать резервные копии', 'Высокий', '20.11.2025', 'В процессе'),
	('Настроить Базу данных', 'Низкий', '22.10.2025', 'Выполнена'),
	('Подготовить презентацию', 'Средний', '10.09.2025', 'Выполнена'),
	('Написать статью', 'Высокий', '20.11.2025', 'В процессе');

INSERT INTO task_assigments (user_id, task_id)
VALUES (101,102),
	(102,104),
	(100,100),
	(101,105),
	(102,103),
	(100,101);


Запросы:
SELECT (title, priority, due_date) FROM tasks;

SELECT t.title, t.priority, t.due_date, t.status
FROM tasks t
JOIN task_assigments ta ON t.id = ta.task_id
WHERE ta.user_id = 101;

SELECT (title, priority, due_date) FROM tasks WHERE priority = 'Высокий' AND due_date < '2025-11-19';

SELECT status, COUNT(*) AS task_count
FROM tasks
GROUP BY status;
