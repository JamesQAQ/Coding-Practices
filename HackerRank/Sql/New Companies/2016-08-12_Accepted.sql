SELECT a.company_code, a.founder,
count(DISTINCT b.lead_manager_code),
count(DISTINCT c.senior_manager_code),
count(DISTINCT d.manager_code),
count(DISTINCT e.employee_code)
FROM Company as a, Lead_Manager as b, Senior_Manager as c, Manager as d, Employee as e
WHERE a.company_code = b.company_code
AND b.company_code = c.company_code
AND c.company_code = d.company_code
AND d.company_code = e.company_code
GROUP BY a.company_code, a.founder
ORDER BY a.company_code;