SELECT
    e1.employee_id,
    e2.name,
    e1.reports_count,
    e1.average_age
  FROM (
    SELECT
        reports_to AS employee_id,
        COUNT(*) AS reports_count,
        ROUND(AVG(age), 0) AS average_age
      FROM Employees
      GROUP BY reports_to
      HAVING reports_to IS NOT NULL) AS e1
  INNER JOIN Employees AS e2
  ON e1.employee_id = e2.employee_id
  ORDER BY e1.employee_id ASC;
