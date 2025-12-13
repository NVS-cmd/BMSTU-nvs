CREATE INDEX ind_students ON students (group_number);

CREATE INDEX ind_grades ON grades (student_id);

ALTER TABLE notes 
ADD COLUMN note_tsv tsvector 
GENERATED ALWAYS AS (to_tsvector('russian', note_text)) STORED;

CREATE INDEX idx_notes_tsv_gin 
ON notes USING GIN (note_tsv);