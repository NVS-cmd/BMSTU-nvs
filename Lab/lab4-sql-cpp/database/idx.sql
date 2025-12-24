CREATE INDEX idx_tasks_due_date ON tasks (due_date);
CREATE INDEX idx_tasks_status ON tasks (status);
CREATE INDEX idx_task_assignments_task_id ON task_assignments (task_id);