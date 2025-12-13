-- создание БД с поддержкой кириллицы
CREATE DATABASE rk2 
    WITH ENCODING 'WIN1251' 
    LC_COLLATE 'Russian_Russia.1251' 
    LC_CTYPE 'Russian_Russia.1251'
    TEMPLATE template0;
-- соединение
\c rk2

-- Студенты
CREATE TABLE students (
    student_id INT GENERATED ALWAYS AS IDENTITY (START WITH 100) PRIMARY KEY, 
    full_name TEXT, 
    group_number TEXT
);

-- Предметы
CREATE TABLE subjects ( 
    subject_id INT GENERATED ALWAYS AS IDENTITY (START WITH 100) PRIMARY KEY,
    subject_name TEXT
);

-- Оценки
CREATE TABLE grades (
    grade_id INT GENERATED ALWAYS AS IDENTITY (START WITH 1) PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    subject_id INT REFERENCES subjects(subject_id),
    grade INT
);

-- Посещаемость
CREATE TABLE attendance (
    attendance_id INT GENERATED ALWAYS AS IDENTITY (START WITH 1) PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    date_attended DATE,
    status TEXT
);

-- Заметки
CREATE TABLE notes (
    note_id INT GENERATED ALWAYS AS IDENTITY (START WITH 1) PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    note_text TEXT
);