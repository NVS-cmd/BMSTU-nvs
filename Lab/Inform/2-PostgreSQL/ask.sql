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

UPDATE tasks
SET status = 'Выполнена'
WHERE id = 103;

6-3
DELETE FROM tasks
WHERE id = 103;







