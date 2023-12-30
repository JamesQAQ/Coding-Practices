SELECT
    Students.student_id,
    Students.student_name,
    Subjects.subject_name,
    IFNULL(tmp.count, 0) AS attended_exams
  FROM Students
  CROSS JOIN Subjects
  LEFT JOIN (
    SELECT student_id, subject_name, COUNT(*) AS count
    FROM Examinations
    GROUP BY student_id, subject_name) AS tmp
  ON Students.student_id = tmp.student_id
      AND Subjects.subject_name = tmp.subject_name
  ORDER BY Students.student_id ASC, subject_name ASC;
