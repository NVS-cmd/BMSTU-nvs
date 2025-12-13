-- студенты
INSERT INTO students (full_name, group_number)
    VALUES
        ('Иванов Иван Иванович', '1Б'),
        ('Петров Петр Петрович', '2Ф'),
        ('Сидоров Сергей Александрович', '13Г'),
        ('Егорова Ольга Павловна', '2Ф'),
        ('Смирнова Анна Дмитриевна', '6В'),
        ('Кузнецов Денис Олегович', '1Г'),
        ('Новикова Екатерина Сергеевна', '3Б'),
        ('Федоров Михаил Андреевич', '2Ф');

-- предметы
INSERT INTO subjects (subject_name)
    VALUES 
        ('Математический анализ'),
        ('Аналитическая геометрия'),
        ('Информатика');

-- оценки
INSERT INTO grades (student_id, subject_id, grade)
    SELECT s.student_id, subj.subject_id, (s.student_id % 6)
    FROM students s
    CROSS JOIN subjects subj;

-- посещаемость
INSERT INTO attendance (student_id, date_attended,status)
    SELECT s.student_id, d::date,
       CASE 
           WHEN random() > 0.2 THEN 'Присутствие' 
           ELSE 'Пропуск' 
       END
    FROM students s
    CROSS JOIN generate_series('2025-09-01'::date, '2025-09-02', '1 day') d;

-- заметки
INSERT INTO notes (student_id, note_text)
SELECT s.student_id,
       CASE s.student_id % 8
           WHEN 0 THEN 'Положительная динамика'
           WHEN 1 THEN 'Хорошо знает информатику'
           WHEN 2 THEN 'Нужно подтянуть математику'
           ELSE 'Активный студент'
       END
FROM students s;