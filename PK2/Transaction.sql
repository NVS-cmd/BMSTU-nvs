BEGIN;

WITH new_st AS (
    INSERT INTO students (full_name, group_number) 
    VALUES ('Смирнов Дмитрий Владимирович', '2Ф')
    RETURNING student_id
)

INSERT INTO grades (student_id, subject_id, grade)
SELECT 
    ns.student_id,
    subj.subject_id,
    CASE subj.subject_name
        WHEN 'Математический анализ' THEN 5
        WHEN 'Аналитическая геометрия' THEN 4
        WHEN 'Информатика' THEN 5
    END
FROM new_st ns
CROSS JOIN subjects subj;

COMMIT;
