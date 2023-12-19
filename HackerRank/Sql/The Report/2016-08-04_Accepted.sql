SELECT
    CASE
        WHEN b.Grade >= 8 THEN a.name
        ELSE NULL
    END
       , b.Grade
       , a.Marks
FROM `Students` AS a, `Grades` AS b
WHERE b.Min_Mark <= a.Marks AND a.Marks <= b.Max_Mark
ORDER BY b.Grade DESC, a.Name, a.Marks;