SELECT `Name`
FROM `STUDENTS`
WHERE `Marks` > 75
ORDER BY right(`Name`, 3), `ID`;