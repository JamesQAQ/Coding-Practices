SELECT employee_id
  FROM (
    SELECT * FROM Employees
      UNION
      SELECT * FROM Salaries) AS tmp
  GROUP BY employee_id
  HAVING COUNT(*) < 2
  ORDER BY employee_id ASC;
