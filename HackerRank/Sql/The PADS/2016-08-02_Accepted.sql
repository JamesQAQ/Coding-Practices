(SELECT CONCAT(`Name`, '(', SUBSTRING(`Occupation`, 1, 1), ')')
FROM `OCCUPATIONS`
ORDER BY `Name` LIMIT 10000)
UNION
(SELECT * FROM
(SELECT CONCAT('There are total ', COUNT(*), ' ', LOWER(`Occupation`), 's.') AS `tmp`
FROM `OCCUPATIONS`
GROUP BY `Occupation`) AS `count_list`
ORDER BY `tmp` LIMIT 4);
