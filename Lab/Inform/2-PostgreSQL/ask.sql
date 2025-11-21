SELECT (title, priority, due_date) FROM tasks;

SELECT t.title, t.priority, t.due_date, t.status
FROM tasks t
JOIN task_assigments ta ON t.id = ta.task_id
WHERE ta.user_id = 101;

SELECT (title, priority, due_date) FROM tasks WHERE priority = 'Высокий' AND due_date < '2025-11-19';

SELECT status, COUNT(*) AS task_count
FROM tasks
GROUP BY status;

































5-1 
SELECT title, priority, due_date FROM tasks;


5-2 
SELECT t.title, t.priority, u.name
FROM tasks AS t
JOIN task_assigments AS ta ON t.id = ta.task_id
JOIN users AS u ON ta.user_id = u.id
WHERE u.name = 'Alex';


5-3
SELECT t.title, t.priority, t.due_date
FROM tasks AS t
WHERE (t.due_date < '2025-12-10');

5-4 
SELECT status, COUNT(*) AS status_count
FROM tasks
GROUP BY status;

6-1
SELECT t.title, t.due_date, u.name
FROM tasks t
JOIN task_assigments ta ON t.id = ta.task_id
JOIN users u ON ta.user_id = u.id
WHERE (t.due_date < '22-11-2025');

6-2

SELECT t.title, t.status, t.id, ta.id 
FROM tasks t
JOIN task_assigments ta ON t.id = ta.task_id;
UPDATE ta.tas











