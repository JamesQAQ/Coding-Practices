(SELECT `CITY`, length(`CITY`)
FROM `STATION`
WHERE (length(`CITY`)) IN (SELECT min(length(`CITY`)) FROM `STATION`)
ORDER BY `CITY` LIMIT 1)
UNION
(SELECT `CITY`, length(`CITY`)
FROM `STATION`
WHERE (length(`CITY`)) IN (SELECT max(length(`CITY`)) FROM `STATION`)
ORDER BY `CITY` LIMIT 1);