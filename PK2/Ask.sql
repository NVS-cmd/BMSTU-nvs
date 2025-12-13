-- Заменить 108 на нужный student_id
SELECT *
FROM students s2
WHERE s2.group_number = (
        SELECT group_number 
        FROM students 
        WHERE student_id = 108
    )
  AND s2.student_id BETWEEN 108-2 AND 108+3
ORDER BY s2.student_id;

-- Средний балл студента
SELECT * FROM student_avg_grades WHERE student_id = 108;

-- Средний балл по информатике 
SELECT subj.subject_name, 
ROUND(AVG(g.grade)::numeric, 2) AS avg_grade
FROM grades g
JOIN subjects subj ON g.subject_id = subj.subject_id
WHERE subj.subject_name = 'Информатика'
GROUP BY subj.subject_name;

-- текстовый поиск
SELECT n.note_id, n.student_id, n.note_text
FROM notes n
WHERE n.note_tsv @@ plainto_tsquery('russian', 'информатика');

-- Посещаемость
BEGIN;

UPDATE attendance
SET status = 'present'
WHERE student_id = 108 
AND date_attended = '2025-09-01'::date;

COMMIT;
