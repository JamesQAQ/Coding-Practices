SELECT `start_date`, MIN(`end_date`) AS `min_end_date`
FROM (SELECT `start_date`
      FROM `Projects`
      WHERE `start_date` NOT IN (SELECT `end_date` FROM `Projects`)) a,
     (SELECT `end_date`
      FROM `Projects`
      WHERE `end_date` NOT IN (SELECT `start_date` FROM `Projects`)) b
WHERE `start_date` < `end_date`
GROUP BY `start_date`
ORDER BY DATEDIFF(`start_date`, `end_date`) DESC, `start_date`;
