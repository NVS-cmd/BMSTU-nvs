CREATE TYPE priority AS ENUM ('Высокий', 'Средний', 'Низкий')
CREATE TYPE status AS ENUM ('Выполнена', 'В процессе', 'Отложена')
CREATE TABLE tasks (
	id SERIAL PRIMARY KEY,
	title VARCHAR (50) NOT NULL,
	priority priority NOT NULL,
	due_date DATE NOT NULL,
	status status NOT NULL
);
CREATE TABLE users (
	id SERIAL PRIMARY KEY,
	name VARCHAR (50)
);
CREATE TABLE task_assigments (
	assigment_id SERIAL PRIMARY KEY,
	FOREIGN KEY task_id INT REFERENCES tasks(id),
	FOREIGN KEY user_id INT REFERENCES users(id)
);
INSERT INTO users (name)
	VALUES (Vlad),
	VALUES (Alex),
	VALUES (Vasiliy);
INSERT INTO tasks (title, priority, due_date, status)
	VALUES ('Сделать отчёт', 'Средний', '07.10.2025', 'Выполнена'),
	VALUES ('Переустановить ОС', 'Низкий', '10.12.2025', 'Отложена'),
	VALUES ('Сделать резервные копии', 'Высокий', '20.11.2025', 'В процессе'),
	VALUES ('Настроить Базу данных', 'Низкий', '22.10.2025', 'Выполнена'),
	VALUES ('Подготовить презентацию', 'Средний', '10.09.2025', 'Выполнена'),
	VALUES ('Написать статью', 'Высокий', '20.11.2025', 'В процессе');
INSERT INTO task_assigments (task_id, user_id)
	VALUES (1,2),
	VALUES (2,4),
	VALUES (3,6),
	VALUES (1,5),
	VALUES (2,3),
	VALUES (3,1);



